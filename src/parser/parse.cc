/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include <cctype>
#include <sstream>

#include "parser/context.h"
#include "parser/error.h"
#include "parser/lexer.h"
#include "parser/statement.h"
#include "parser/token.h"

namespace sqltoast {

parse_result_t parse(parse_input_t& subject) {
    parse_result_t res;
    res.code = PARSE_OK;
    parse_context_t ctx(res, subject);

    skip_ws(ctx);
    if (ctx.cursor == ctx.end_pos) {
        res.code = PARSE_INPUT_ERROR;
        res.error.assign("Nothing to parse.");
        return res;
    }

    tokenize(ctx);

    while (res.code == PARSE_OK && ! ctx.tokens.empty()) {
        token_t &top_tok = ctx.tokens.front();
        token_type_t& tt = top_tok.type;
        switch (tt) {
            case TOKEN_TYPE_KEYWORD:
                parse_statement(ctx);
                break;
            case TOKEN_TYPE_COMMENT:
                // Just remove the comment from the token stack...
                ctx.tokens.pop_front();
                break;
            case TOKEN_TYPE_PUNCTUATOR:
            {
                std::stringstream estr;
                estr << "Parse subject must either begin with a keyword or a "
                        "comment, but found punctuation." << std::endl;
                create_syntax_error_marker(ctx, estr, parse_position_t(ctx.cursor));
            }
            break;
            case TOKEN_TYPE_IDENTIFIER:
            {
                std::stringstream estr;
                estr << "Parse subject must either begin with a keyword or a "
                        "comment, but found identifier." << std::endl;
                create_syntax_error_marker(ctx, estr, parse_position_t(ctx.cursor));
            }
            break;
            default:
                break;
        }
    }

    return res;
}

} // namespace sqltoast

/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#ifndef SQLTOAST_PARSER_LITERAL_H
#define SQLTOAST_PARSER_LITERAL_H

#include "context.h"

namespace sqltoast {

// Moves the supplied parse context's cursor to the next literal found in the
// context's input stream and adds a token with type literal to the tokens
// stack.Returns whether a literal was found.
bool token_literal(parse_context_t& ctx);

} // namespace sqltoast

#endif /* SQLTOAST_PARSER_LITERAL_H */

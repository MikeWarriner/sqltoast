/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include <iostream>
#include <sstream>
#include <string>

#include "error.h"

namespace sqltoast {

void create_syntax_error_marker(parser_context_t& ctx, std::stringstream& es, parser_position_t err_pos) {
    std::string original(ctx.start_pos, ctx.end_pos);
    std::string location(original);
    auto start_pos = err_pos - ctx.start_pos;
    for (auto cur = location.begin(); cur != location.end(); cur++) {
        auto loc_pos = cur - location.begin() + 1;
        if (loc_pos < start_pos) {
            *cur = ' ';
        } else {
            *cur = '^';
        }
    }

    es << original << std::endl << location;
}

} // namespace sqltoast

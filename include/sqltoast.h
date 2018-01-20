// DO NOT EDIT. Only edit the lnclude/sqltoast.h.in file, since sqltoast.h is
// generated during build.
#ifndef SQLTOAST_H
#define SQLTOAST_H

#define SQLTOAST_VERSION_MAJOR 0
#define SQLTOAST_VERSION_MINOR 1

#if defined(__GNUC__) || defined(__clang__)
#define SQLTOAST_UNREACHABLE() __builtin_unreachable()
#else
#define SQLTOAST_UNREACHABLE() assert(!"code should not be reachable")
#endif

#include <memory>
#include <string>
#include <vector>

#include "statement.h"

namespace sqltoast {

// Dialects of SQL that can be parsed by sqltoast
typedef enum sql_dialect {
    SQL_DIALECT_ANSI_2003
} sql_dialect_t;

// Possible return codes from parsing
enum parse_result_code {
    PARSE_OK,
    PARSE_INPUT_ERROR,
    PARSE_SYNTAX_ERROR
};

typedef std::vector<char> parse_input_t;

typedef struct parse_result {
    parse_result_code code;
    std::string error;
    // As each SQL statement in an input stream is successfully parsed, a
    // sqltoast::statement derived object will be dynamically allocated and
    // pushed onto this vector
    std::vector<std::unique_ptr<statement>> statements;
} parse_result_t;

parse_result_t parse(parse_input_t& subject);

} // namespace sqltoast

#endif /* SQLTOAST_H */
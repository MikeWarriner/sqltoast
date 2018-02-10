/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include "parser/compare.h"
#include "parser/keyword.h"

namespace sqltoast {

// NOTE(jaypipes): These keywords are inserted in order of FREQUENCY of
// appearance in SQL statements, not alphabetically.
kw_jump_table_t _init_kw_jump_table(char lead_char) {
    kw_jump_table_t t;

    switch (lead_char) {
        case 'a':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_ACTION, "ACTION"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_ALL, "ALL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_AUTHORIZATION, "AUTHORIZATION"));
            return t;
        case 'b':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_BIT, "BIT"));
            return t;
        case 'c':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CREATE, "CREATE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CHAR, "CHAR"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CHARACTER, "CHARACTER"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CASCADE, "CASCADE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CURRENT_DATE, "CURRENT_DATE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CURRENT_TIME, "CURRENT_TIME"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CURRENT_TIMESTAMP, "CURRENT_TIMESTAMP"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CURRENT_USER, "CURRENT_USER"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CHECK, "CHECK"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_COLLATE, "COLLATE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_CONSTRAINT, "CONSTRAINT"));
            return t;
        case 'd':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DELETE, "DELETE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DISTINCT, "DISTINCT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DATE, "DATE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DAY, "DAY"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DEC, "DEC"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DECIMAL, "DECIMAL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DEFAULT, "DEFAULT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DROP, "DROP"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_DOUBLE, "DOUBLE"));
            return t;
        case 'f':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_FLOAT, "FLOAT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_FULL, "FULL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_FOREIGN, "FOREIGN"));
            return t;
        case 'g':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_GLOBAL, "GLOBAL"));
            return t;
        case 'h':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_HOUR, "HOUR"));
            return t;
        case 'i':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_INTERVAL, "INTERVAL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_INT, "INT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_INTEGER, "INTEGER"));
            return t;
        case 'k':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_KEY, "KEY"));
            return t;
        case 'l':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_LOCAL, "LOCAL"));
            return t;
        case 'm':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_MATCH, "MATCH"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_MINUTE, "MINUTE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_MONTH, "MONTH"));
            return t;
        case 'n':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NOT, "NOT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NO, "NO"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NULL, "NULL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NATIONAL, "NATIONAL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NCHAR, "NCHAR"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_NUMERIC, "NUMERIC"));
            return t;
        case 'o':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_ON, "ON"));
            return t;
        case 'p':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_PRECISION, "PRECISION"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_PRIMARY, "PRIMARY"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_PARTIAL, "PARTIAL"));
            return t;
        case 'r':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_REAL, "REAL"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_REFERENCES, "REFERENCES"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_RESTRICT, "RESTRICT"));
            return t;
        case 's':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SELECT, "SELECT"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SCHEMA, "SCHEMA"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SECOND, "SECOND"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SET, "SET"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SESSION_USER, "SESSION_USER"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_SYSTEM_USER, "SYSTEM_USER"));
            return t;
        case 't':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_TABLE, "TABLE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_TIME, "TIME"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_TIMESTAMP, "TIMESTAMP"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_TEMPORARY, "TEMPORARY"));
            return t;
        case 'u':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_UPDATE, "UPDATE"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_USER, "USER"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_UNIQUE, "UNIQUE"));
            return t;
        case 'v':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_VARCHAR, "VARCHAR"));
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_VARYING, "VARYING"));
            return t;
        case 'w':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_WITH, "WITH"));
            return t;
        case 'y':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_YEAR, "YEAR"));
            return t;
        case 'z':
            t.emplace_back(kw_jump_table_entry_t(SYMBOL_ZONE, "ZONE"));
            return t;
    }
    return t;
}

kw_jump_table_t kw_jump_tables::a = _init_kw_jump_table('a');
kw_jump_table_t kw_jump_tables::b = _init_kw_jump_table('b');
kw_jump_table_t kw_jump_tables::c = _init_kw_jump_table('c');
kw_jump_table_t kw_jump_tables::d = _init_kw_jump_table('d');
kw_jump_table_t kw_jump_tables::f = _init_kw_jump_table('f');
kw_jump_table_t kw_jump_tables::g = _init_kw_jump_table('g');
kw_jump_table_t kw_jump_tables::h = _init_kw_jump_table('h');
kw_jump_table_t kw_jump_tables::i = _init_kw_jump_table('i');
kw_jump_table_t kw_jump_tables::k = _init_kw_jump_table('k');
kw_jump_table_t kw_jump_tables::l = _init_kw_jump_table('l');
kw_jump_table_t kw_jump_tables::m = _init_kw_jump_table('m');
kw_jump_table_t kw_jump_tables::n = _init_kw_jump_table('n');
kw_jump_table_t kw_jump_tables::o = _init_kw_jump_table('o');
kw_jump_table_t kw_jump_tables::p = _init_kw_jump_table('p');
kw_jump_table_t kw_jump_tables::r = _init_kw_jump_table('r');
kw_jump_table_t kw_jump_tables::s = _init_kw_jump_table('s');
kw_jump_table_t kw_jump_tables::t = _init_kw_jump_table('t');
kw_jump_table_t kw_jump_tables::u = _init_kw_jump_table('u');
kw_jump_table_t kw_jump_tables::v = _init_kw_jump_table('v');
kw_jump_table_t kw_jump_tables::w = _init_kw_jump_table('w');
kw_jump_table_t kw_jump_tables::y = _init_kw_jump_table('y');
kw_jump_table_t kw_jump_tables::z = _init_kw_jump_table('z');

tokenize_result_t token_keyword(parse_position_t cursor) {
    kw_jump_table_t* jump_tbl;
    switch (*cursor) {
        case 'a':
        case 'A':
            jump_tbl = &kw_jump_tables::a;
            break;
        case 'b':
        case 'B':
            jump_tbl = &kw_jump_tables::b;
            break;
        case 'c':
        case 'C':
            jump_tbl = &kw_jump_tables::c;
            break;
        case 'd':
        case 'D':
            jump_tbl = &kw_jump_tables::d;
            break;
        case 'f':
        case 'F':
            jump_tbl = &kw_jump_tables::f;
            break;
        case 'g':
        case 'G':
            jump_tbl = &kw_jump_tables::g;
            break;
        case 'h':
        case 'H':
            jump_tbl = &kw_jump_tables::h;
            break;
        case 'i':
        case 'I':
            jump_tbl = &kw_jump_tables::i;
            break;
        case 'k':
        case 'K':
            jump_tbl = &kw_jump_tables::k;
            break;
        case 'l':
        case 'L':
            jump_tbl = &kw_jump_tables::l;
            break;
        case 'm':
        case 'M':
            jump_tbl = &kw_jump_tables::m;
            break;
        case 'n':
        case 'N':
            jump_tbl = &kw_jump_tables::n;
            break;
        case 'o':
        case 'O':
            jump_tbl = &kw_jump_tables::o;
            break;
        case 'p':
        case 'P':
            jump_tbl = &kw_jump_tables::p;
            break;
        case 'r':
        case 'R':
            jump_tbl = &kw_jump_tables::r;
            break;
        case 's':
        case 'S':
            jump_tbl = &kw_jump_tables::s;
            break;
        case 't':
        case 'T':
            jump_tbl = &kw_jump_tables::t;
            break;
        case 'u':
        case 'U':
            jump_tbl = &kw_jump_tables::u;
            break;
        case 'v':
        case 'V':
            jump_tbl = &kw_jump_tables::v;
            break;
        case 'w':
        case 'W':
            jump_tbl = &kw_jump_tables::w;
            break;
        case 'y':
        case 'Y':
            jump_tbl = &kw_jump_tables::y;
            break;
        case 'z':
        case 'Z':
            jump_tbl = &kw_jump_tables::z;
            break;
        default:
            return tokenize_result_t(TOKEN_NOT_FOUND);
    }

    parse_position_t start = cursor;
    // Find the next delimiter character...
    while (std::isalnum(*cursor) || *cursor == '_')
        cursor++;

    const std::string lexeme(start, cursor);
    size_t lexeme_len = lexeme.size();
    for (auto entry : *jump_tbl) {
        size_t entry_len = entry.kw_str.size();
        if (lexeme_len != entry_len)
            continue;
        if (ci_find_substr(lexeme, entry.kw_str) == 0) {
            return tokenize_result_t(entry.symbol, start, cursor);
        }
    }
    return tokenize_result_t(TOKEN_NOT_FOUND);
}

} // namespace sqltoast

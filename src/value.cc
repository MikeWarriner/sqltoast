/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include "sqltoast.h"

namespace sqltoast {

std::ostream& operator<< (std::ostream& out, const set_function_t& sf) {
    switch (sf.func_type) {
        case SET_FUNCTION_TYPE_COUNT_STAR:
            out << "COUNT(*)";
            break;
        case SET_FUNCTION_TYPE_COUNT_DISTINCT:
            out << "COUNT(DISTINCT " << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_COUNT:
            out << "COUNT(" << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_AVG_DISTINCT:
            out << "AVG(DISTINCT " << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_AVG:
            out << "AVG(" << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_MIN_DISTINCT:
            out << "MIN(DISTINCT " << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_MIN:
            out << "MIN(" << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_MAX_DISTINCT:
            out << "MAX(DISTINCT " << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_MAX:
            out << "MAX(" << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_SUM_DISTINCT:
            out << "SUM(DISTINCT " << *sf.value << ")";
            break;
        case SET_FUNCTION_TYPE_SUM:
            out << "SUM(" << *sf.value << ")";
            break;
        default:
            break;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const value_expression_t& ve) {
    switch (ve.type) {
        case VALUE_EXPRESSION_TYPE_LITERAL:
            out << "literal[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_LITERAL_DATE:
            out << "date[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_LITERAL_TIME:
            out << "time[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_LITERAL_TIMESTAMP:
            out << "timestamp[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_LITERAL_INTERVAL:
            out << "interval[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_COLUMN:
            out << "column-reference[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_GENERAL:
            out << "general-value[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_PARAMETER:
            out << "parameter[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
        case VALUE_EXPRESSION_TYPE_SET_FUNCTION:
            {
                const set_function_t& sf = static_cast<const set_function_t&>(ve);
                out << sf;
            }
            break;
        case VALUE_EXPRESSION_TYPE_NUMERIC_EXPRESSION:
            {
                const numeric_expression_t& ne =
                    static_cast<const numeric_expression_t&>(ve);
                out << ne;
            }
            break;
        case VALUE_EXPRESSION_TYPE_STRING_EXPRESSION:
            {
                const character_value_expression_t& cve =
                    static_cast<const character_value_expression_t&>(ve);
                out << cve;
            }
            break;
        case VALUE_EXPRESSION_TYPE_SCALAR_SUBQUERY:
            out << "scalar-subquery";
            break;
        default:
            out << "value-expression[" << std::string(ve.lexeme.start, ve.lexeme.end) << ']';
            break;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const numeric_term_t& nt) {
    if (! nt.right) {
        out << *nt.left->value;
    } else {
        out << *nt.left->value;
        if (nt.op == NUMERIC_OP_MULTIPLY)
            out << " * ";
        else
            out << " / ";
        out << *nt.right->value;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const numeric_expression_t& ne) {
    // numeric expressions are the container for things that may be evaluated
    // to a number. However, numeric expressions that have only a single
    // element can be reduced to just that one element
    if (! ne.right) {
        if (! ne.left->right)
            out << *ne.left;
        else
            out << "numeric-expression[" << *ne.left << "]";
    } else {
        out << "numeric-expression[";
        out << *ne.left;
        if (ne.op == NUMERIC_OP_ADD)
            out << " + ";
        else
            out << " - ";
        out << *ne.right << "]";
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const character_value_expression_t& cve) {
    out << "character-value-expression["<< *cve.value;
    if (cve.collation)
        out << " COLLATE " << cve.collation;
    out << "]";
    return out;
}

std::ostream& operator<< (std::ostream& out, const row_value_constructor_t& rvc) {
    switch (rvc.rvc_type) {
        case RVC_TYPE_DEFAULT:
            out <<"DEFAULT";
            break;
        case RVC_TYPE_NULL:
            out <<"NULL";
            break;
        case RVC_TYPE_VALUE_EXPRESSION:
            {
                const row_value_expression_t& val = static_cast<const row_value_expression_t&>(rvc);
                out << val;
            }
            break;
        default:
            out << "row-value-constructor[UNKNOWN]";
            break;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const row_value_expression_t& rve) {
    out << *rve.value;
    return out;
}

} // namespace sqltoast

/*
 * LeetCode 770. Basic Calculator IV
 * 題意（繁體中文）：計算含變數、整數、括號及 +、-、* 的代數式；先用給定的
 * evalvars/evalints 代入變數，再把結果展開並合併同類項。輸出各項字串，
 * 依總次數由高到低排列；次數相同時依變數名稱字典序排列。零係數項不輸出。
 *
 * 範例："e + 8 - a + 5"，e=1 -> ["-1*a","14"]。
 *       "(e + 8) * (e - 8)"，不代入變數 -> ["1*e*e","-64"]。
 * 限制：算式長度最多 250；變數最多 100 個，名稱長度最多 20；代入值介於 -100 到 100。
 * 解法步驟：
 *   1. 用遞迴下降剖析器依優先順序計算括號、乘法、加減。
 *   2. 每個運算值都存成「係數 + 排序後的變數乘積」清單；同類項相加時合併係數。
 *   3. 乘法對兩邊的項做笛卡兒積，合併並排序變數，再把相同乘積合併。
 *   4. 依次數與變數字典序排序，最後轉成 LeetCode 要求的字串陣列。
 * 複雜度：令 P、Q 為中間多項式項數，乘法時間與 P*Q 成正比；空間與展開後項數成正比。
 * LeetCode C API：char** basicCalculatorIV(char* expression, char** evalvars,
 *       int evalvarsSize, int* evalints, int evalintsSize, int* returnSize)
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONOMIAL_CAPACITY 256

typedef struct {
    long long coefficient;
    int degree;
    char monomial[MONOMIAL_CAPACITY];
} Term;

typedef struct {
    Term *terms;
    int size;
    int capacity;
} Polynomial;

typedef struct {
    char *expression;
    int position;
    char **evalvars;
    int *evalints;
    int evalvarsSize;
} Parser;

static Polynomial emptyPolynomial(void) {
    Polynomial polynomial = {NULL, 0, 0};
    return polynomial;
}

static void freePolynomial(Polynomial *polynomial) {
    free(polynomial->terms);
    polynomial->terms = NULL;
    polynomial->size = polynomial->capacity = 0;
}

static void addTerm(Polynomial *polynomial, long long coefficient,
                    const char *monomial, int degree) {
    if (coefficient == 0) return;
    for (int i = 0; i < polynomial->size; ++i) {
        if (strcmp(polynomial->terms[i].monomial, monomial) != 0) continue;
        polynomial->terms[i].coefficient += coefficient;
        if (polynomial->terms[i].coefficient == 0) {
            polynomial->terms[i] = polynomial->terms[polynomial->size - 1];
            --polynomial->size;
        }
        return;
    }
    if (polynomial->size == polynomial->capacity) {
        int capacity = polynomial->capacity == 0 ? 4 : polynomial->capacity * 2;
        Term *grown = (Term *)realloc(polynomial->terms,
                                      (size_t)capacity * sizeof *grown);
        if (grown == NULL) return;
        polynomial->terms = grown;
        polynomial->capacity = capacity;
    }
    Term *term = &polynomial->terms[polynomial->size++];
    term->coefficient = coefficient;
    term->degree = degree;
    strcpy(term->monomial, monomial);
}

static Polynomial constantPolynomial(long long value) {
    Polynomial result = emptyPolynomial();
    addTerm(&result, value, "", 0);
    return result;
}

static Polynomial variablePolynomial(const char *variable) {
    Polynomial result = emptyPolynomial();
    addTerm(&result, 1, variable, 1);
    return result;
}

static Polynomial combinePolynomials(const Polynomial *left,
                                     const Polynomial *right, int sign) {
    Polynomial result = emptyPolynomial();
    for (int i = 0; i < left->size; ++i)
        addTerm(&result, left->terms[i].coefficient,
                left->terms[i].monomial, left->terms[i].degree);
    for (int i = 0; i < right->size; ++i)
        addTerm(&result, sign * right->terms[i].coefficient,
                right->terms[i].monomial, right->terms[i].degree);
    return result;
}

static int nextFactor(const char *monomial, int *position,
                      const char **factor, int *length) {
    if (monomial[*position] == '\0') return 0;
    *factor = monomial + *position;
    while (monomial[*position] != '\0' && monomial[*position] != '*')
        ++(*position);
    *length = (int)(monomial + *position - *factor);
    if (monomial[*position] == '*') ++(*position);
    return 1;
}

static int compareFactors(const char *a, int aLength, const char *b, int bLength) {
    int common = aLength < bLength ? aLength : bLength;
    int order = memcmp(a, b, (size_t)common);
    if (order != 0) return order;
    return (aLength > bLength) - (aLength < bLength);
}

static void appendFactor(char *output, int *length, const char *factor, int factorLength) {
    if (*length > 0) output[(*length)++] = '*';
    memcpy(output + *length, factor, (size_t)factorLength);
    *length += factorLength;
    output[*length] = '\0';
}

static void multiplyMonomials(const char *left, const char *right,
                              char *output, int *degree) {
    int leftPosition = 0, rightPosition = 0, outputLength = 0;
    const char *leftFactor = NULL, *rightFactor = NULL;
    int leftLength = 0, rightLength = 0;
    int hasLeft = nextFactor(left, &leftPosition, &leftFactor, &leftLength);
    int hasRight = nextFactor(right, &rightPosition, &rightFactor, &rightLength);
    output[0] = '\0';
    *degree = 0;
    while (hasLeft || hasRight) {
        if (!hasRight || (hasLeft && compareFactors(leftFactor, leftLength,
                                                     rightFactor, rightLength) <= 0)) {
            appendFactor(output, &outputLength, leftFactor, leftLength);
            hasLeft = nextFactor(left, &leftPosition, &leftFactor, &leftLength);
        } else {
            appendFactor(output, &outputLength, rightFactor, rightLength);
            hasRight = nextFactor(right, &rightPosition, &rightFactor, &rightLength);
        }
        ++(*degree);
    }
}

static Polynomial multiplyPolynomials(const Polynomial *left,
                                      const Polynomial *right) {
    Polynomial result = emptyPolynomial();
    char monomial[MONOMIAL_CAPACITY];
    for (int i = 0; i < left->size; ++i) {
        for (int j = 0; j < right->size; ++j) {
            int degree;
            multiplyMonomials(left->terms[i].monomial,
                              right->terms[j].monomial, monomial, &degree);
            addTerm(&result,
                    left->terms[i].coefficient * right->terms[j].coefficient,
                    monomial, degree);
        }
    }
    return result;
}

static void skipSpaces(Parser *parser) {
    while (parser->expression[parser->position] == ' ') ++parser->position;
}

static Polynomial parseExpression(Parser *parser);

static Polynomial parseFactor(Parser *parser) {
    skipSpaces(parser);
    char current = parser->expression[parser->position];
    if (current == '(') {
        ++parser->position;
        Polynomial inside = parseExpression(parser);
        skipSpaces(parser);
        if (parser->expression[parser->position] == ')') ++parser->position;
        return inside;
    }
    if (current == '+' || current == '-') {
        ++parser->position;
        Polynomial value = parseFactor(parser);
        if (current == '-')
            for (int i = 0; i < value.size; ++i)
                value.terms[i].coefficient = -value.terms[i].coefficient;
        return value;
    }
    if (isdigit((unsigned char)current)) {
        long long value = 0;
        while (isdigit((unsigned char)parser->expression[parser->position])) {
            value = value * 10 + parser->expression[parser->position] - '0';
            ++parser->position;
        }
        return constantPolynomial(value);
    }

    char variable[21];
    int length = 0;
    while (parser->expression[parser->position] >= 'a' &&
           parser->expression[parser->position] <= 'z') {
        variable[length++] = parser->expression[parser->position++];
    }
    variable[length] = '\0';
    for (int i = 0; i < parser->evalvarsSize; ++i)
        if (strcmp(parser->evalvars[i], variable) == 0)
            return constantPolynomial(parser->evalints[i]);
    return variablePolynomial(variable);
}

static Polynomial parseTerm(Parser *parser) {
    Polynomial result = parseFactor(parser);
    for (;;) {
        skipSpaces(parser);
        if (parser->expression[parser->position] != '*') break;
        ++parser->position;
        Polynomial right = parseFactor(parser);
        Polynomial product = multiplyPolynomials(&result, &right);
        freePolynomial(&result);
        freePolynomial(&right);
        result = product;
    }
    return result;
}

static Polynomial parseExpression(Parser *parser) {
    Polynomial result = parseTerm(parser);
    for (;;) {
        skipSpaces(parser);
        char operation = parser->expression[parser->position];
        if (operation != '+' && operation != '-') break;
        ++parser->position;
        Polynomial right = parseTerm(parser);
        Polynomial combined = combinePolynomials(&result, &right,
                                                  operation == '+' ? 1 : -1);
        freePolynomial(&result);
        freePolynomial(&right);
        result = combined;
    }
    return result;
}

static int compareTerms(const void *left, const void *right) {
    const Term *a = (const Term *)left;
    const Term *b = (const Term *)right;
    if (a->degree != b->degree) return b->degree - a->degree;
    return strcmp(a->monomial, b->monomial);
}

char** basicCalculatorIV(char* expression, char** evalvars, int evalvarsSize,
                         int* evalints, int evalintsSize, int* returnSize) {
    (void)evalintsSize;
    *returnSize = 0;
    Parser parser = {expression, 0, evalvars, evalints, evalvarsSize};
    Polynomial result = parseExpression(&parser);
    qsort(result.terms, (size_t)result.size, sizeof *result.terms, compareTerms);

    char **answer = result.size == 0 ? NULL :
        (char **)malloc((size_t)result.size * sizeof *answer);
    if (result.size > 0 && answer == NULL) {
        freePolynomial(&result);
        return NULL;
    }
    for (int i = 0; i < result.size; ++i) {
        char text[MONOMIAL_CAPACITY + 32];
        if (result.terms[i].degree == 0)
            snprintf(text, sizeof text, "%lld", result.terms[i].coefficient);
        else
            snprintf(text, sizeof text, "%lld*%s",
                     result.terms[i].coefficient, result.terms[i].monomial);
        answer[i] = (char *)malloc(strlen(text) + 1);
        if (answer[i] == NULL) {
            for (int j = 0; j < i; ++j) free(answer[j]);
            free(answer);
            freePolynomial(&result);
            return NULL;
        }
        strcpy(answer[i], text);
    }
    *returnSize = result.size;
    freePolynomial(&result);
    return answer;
}

static int matches(char *expression, char **vars, int varsSize, int *values,
                   const char **expected, int expectedSize) {
    int resultSize = 0;
    char **result = basicCalculatorIV(expression, vars, varsSize, values,
                                      varsSize, &resultSize);
    int passed = resultSize == expectedSize;
    for (int i = 0; passed && i < resultSize; ++i)
        if (strcmp(result[i], expected[i]) != 0) passed = 0;
    for (int i = 0; i < resultSize; ++i) free(result[i]);
    free(result);
    return passed;
}

int main(void) {
    char expression1[] = "e + 8 - a + 5";
    char *vars1[] = {"e"};
    int values1[] = {1};
    const char *expected1[] = {"-1*a", "14"};
    char expression2[] = "e - 8 + temperature - pressure";
    char *vars2[] = {"e", "temperature"};
    int values2[] = {1, 12};
    const char *expected2[] = {"-1*pressure", "5"};
    char expression3[] = "(e + 8) * (e - 8)";
    const char *expected3[] = {"1*e*e", "-64"};
    int passed = matches(expression1, vars1, 1, values1, expected1, 2) &&
                 matches(expression2, vars2, 2, values2, expected2, 2) &&
                 matches(expression3, NULL, 0, NULL, expected3, 2);
    puts(passed ? "PASS: 770 basic-calculator-iv" : "FAIL: 770 basic-calculator-iv");
    return passed ? 0 : 1;
}

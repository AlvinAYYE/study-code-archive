/*
 * LeetCode 399. Evaluate Division／除法求值
 *
 * 題目（繁體中文）
 *   給定一組變數比值方程式，例如 a / b = 2，以及多個查詢，例如 a / c。
 *   對每個查詢回傳可推導出的數值；若變數未出現在方程式中，或兩變數之間
 *   沒有可推導的路徑，回傳 -1.0。輸入方程式有效，且彼此不矛盾。
 *
 * 範例 1：方程式 a/b=2、b/c=3；查詢 a/c、b/a、a/e、a/a、x/x，
 *   輸出 [6.0, 0.5, -1.0, 1.0, -1.0]。
 * 範例 2：方程式 a/b=0.5；查詢 a/b、b/a、a/c、x/y，輸出
 *   [0.5, 2.0, -1.0, -1.0]。
 * 限制：方程式與查詢各最多 20 組；變數名長度 1..5，僅含小寫字母與數字；
 *   每個方程式比值大於 0 且不超過 20。
 *
 * 解題步驟：
 *   1. 把每個方程式中的變數編成節點；a/b=v 代表 a 到 b 的比值是 v，
 *      反方向 b 到 a 的比值就是 1/v。
 *   2. 建立「任兩變數目前可否互通」與「兩者相除的結果」表格，並設定已知
 *      變數除以自己等於 1。
 *   3. 用 Floyd-Warshall 的三層迴圈嘗試透過中間變數 k 串接比值：
 *      a/b × b/c = a/c。
 *   4. 查詢變數都已知且可互通時回傳表格值，否則回傳 -1.0。
 *   設變數數量為 V、查詢數為 Q；時間 O(V^3+Q)，空間 O(V^2)。
 *
 * LeetCode C API：double* calcEquation(char*** equations, int equationsSize,
 * int* equationsColSize, double* values, int valuesSize, char*** queries,
 * int queriesSize, int* queriesColSize, int* returnSize)。回傳陣列由呼叫端釋放。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUATIONS 20
#define MAX_VARIABLES (MAX_EQUATIONS * 2)

static int findVariable(char **names, int count, const char *name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(names[i], name) == 0) return i;
    }
    return -1;
}

static int addVariable(char **names, int *count, char *name) {
    int existing = findVariable(names, *count, name);
    if (existing >= 0) return existing;
    if (*count >= MAX_VARIABLES) return -1;
    names[*count] = name;
    return (*count)++;
}

/* ---------- LeetCode submission / 提交區 ---------- */
double *calcEquation(char ***equations, int equationsSize,
                     int *equationsColSize, double *values, int valuesSize,
                     char ***queries, int queriesSize, int *queriesColSize,
                     int *returnSize) {
    (void)equationsColSize;
    (void)valuesSize;
    (void)queriesColSize;
    if (returnSize == NULL) return NULL;
    *returnSize = 0;
    if (equations == NULL || values == NULL || queries == NULL ||
        equationsSize < 0 || equationsSize > MAX_EQUATIONS || queriesSize < 0)
        return NULL;

    double *answers = (double *)malloc((size_t)queriesSize * sizeof *answers);
    if (queriesSize > 0 && answers == NULL) return NULL;

    char *names[MAX_VARIABLES];
    int left[MAX_EQUATIONS], right[MAX_EQUATIONS];
    int variableCount = 0;
    for (int i = 0; i < equationsSize; ++i) {
        if (equations[i] == NULL || equations[i][0] == NULL ||
            equations[i][1] == NULL) {
            free(answers);
            return NULL;
        }
        left[i] = addVariable(names, &variableCount, equations[i][0]);
        right[i] = addVariable(names, &variableCount, equations[i][1]);
        if (left[i] < 0 || right[i] < 0) {
            free(answers);
            return NULL;
        }
    }

    double ratio[MAX_VARIABLES][MAX_VARIABLES] = {{0.0}};
    unsigned char reachable[MAX_VARIABLES][MAX_VARIABLES] = {{0}};
    for (int i = 0; i < variableCount; ++i) {
        ratio[i][i] = 1.0;
        reachable[i][i] = 1;
    }
    for (int i = 0; i < equationsSize; ++i) {
        ratio[left[i]][right[i]] = values[i];
        ratio[right[i]][left[i]] = 1.0 / values[i];
        reachable[left[i]][right[i]] = 1;
        reachable[right[i]][left[i]] = 1;
    }

    /* 經過 k 串接 i/k 與 k/j，即可求出 i/j。 */
    for (int k = 0; k < variableCount; ++k) {
        for (int i = 0; i < variableCount; ++i) {
            if (!reachable[i][k]) continue;
            for (int j = 0; j < variableCount; ++j) {
                if (reachable[k][j] && !reachable[i][j]) {
                    ratio[i][j] = ratio[i][k] * ratio[k][j];
                    reachable[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < queriesSize; ++i) {
        if (queries[i] == NULL || queries[i][0] == NULL || queries[i][1] == NULL) {
            free(answers);
            return NULL;
        }
        int numerator = findVariable(names, variableCount, queries[i][0]);
        int denominator = findVariable(names, variableCount, queries[i][1]);
        if (numerator < 0 || denominator < 0 ||
            !reachable[numerator][denominator]) {
            answers[i] = -1.0;
        } else {
            answers[i] = ratio[numerator][denominator];
        }
    }
    *returnSize = queriesSize;
    return answers;
}
/* ---------- end submission ---------- */

static int closeEnough(double actual, double expected) {
    double difference = actual - expected;
    if (difference < 0.0) difference = -difference;
    return difference < 1e-9;
}

int main(void) {
    char *equation0[] = {"a", "b"};
    char *equation1[] = {"b", "c"};
    char **equations[] = {equation0, equation1};
    int equationColumns[] = {2, 2};
    double values[] = {2.0, 3.0};
    char *query0[] = {"a", "c"};
    char *query1[] = {"b", "a"};
    char *query2[] = {"a", "e"};
    char *query3[] = {"a", "a"};
    char *query4[] = {"x", "x"};
    char **queries[] = {query0, query1, query2, query3, query4};
    int queryColumns[] = {2, 2, 2, 2, 2};
    const double expected[] = {6.0, 0.5, -1.0, 1.0, -1.0};
    int resultSize = 0;
    double *answers = calcEquation(equations, 2, equationColumns, values, 2,
                                   queries, 5, queryColumns, &resultSize);
    int passed = answers != NULL && resultSize == 5;
    for (int i = 0; passed && i < resultSize; ++i)
        passed = closeEnough(answers[i], expected[i]);
    free(answers);

    puts(passed ? "PASS: 399 evaluate-division" : "FAIL: 399 evaluate-division");
    return passed ? 0 : 1;
}

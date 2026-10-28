/*
 * LeetCode 682. Baseball Game
 * Title-CN: 棒球比賽
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/baseball-game/
 *
 * [題目翻譯]
 * 依序處理操作字串，計算所有有效回合的總分。整數表示新增該分數；
 * "C" 撤銷上一個分數；"D" 新增上一個分數的兩倍；"+" 新增前兩個
 * 分數的總和。回傳操作完成後的總分。
 *
 * [範例]
 * operations = ["5","2","C","D","+"]，回傳 30。
 * 分數變化： [5] -> [5,2] -> [5] -> [5,10] -> [5,10,15]。
 *
 * [限制]
 * 操作數量為 1 到 1000；數字介於 -30000 到 30000；操作必定有效，
 * 且答案與中間計算都可用 32 位元整數表示。
 *
 * [解題思路]
 * 用陣列當作堆疊，只保留尚有效的分數。每種操作都只讀寫堆疊尾端：
 * C 將大小減一，D 將頂端乘二後推入，+ 將兩個頂端相加後推入，數字則直接推入。
 * 最後加總堆疊。時間 O(n)，空間 O(n)。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int calPoints(char** operations, int operationsSize) {
    int* scores = (int*)malloc((size_t)operationsSize * sizeof(int));
    int size = 0;
    int total = 0;

    for (int i = 0; i < operationsSize; ++i) {
        const char* operation = operations[i];
        if (strcmp(operation, "C") == 0) {
            --size;
        } else if (strcmp(operation, "D") == 0) {
            scores[size] = 2 * scores[size - 1];
            ++size;
        } else if (strcmp(operation, "+") == 0) {
            scores[size] = scores[size - 1] + scores[size - 2];
            ++size;
        } else {
            scores[size++] = atoi(operation);
        }
    }

    for (int i = 0; i < size; ++i) {
        total += scores[i];
    }
    free(scores);
    return total;
}
/* ---------- end submission ---------- */

static int runCase(char** operations, int operationsSize, int expected) {
    int actual = calPoints(operations, operationsSize);
    if (actual != expected) {
        printf("  fail: got %d, expected %d\n", actual, expected);
        return 0;
    }
    return 1;
}

int main(void) {
    char* example1[] = {"5", "2", "C", "D", "+"};
    char* example2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    char* example3[] = {"1", "C"};
    int ok = runCase(example1, 5, 30) && runCase(example2, 8, 27) &&
             runCase(example3, 2, 0);
    printf("%s: 682 baseball-game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

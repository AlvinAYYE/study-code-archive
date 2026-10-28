/*
 * LeetCode 0519. Random Flip Matrix（隨機翻轉矩陣）
 * Difficulty: Medium
 * 題意：給定 m 列 n 欄的全零矩陣。flip 隨機挑一個尚未翻轉的格子，回傳其座標並將它設為 1；reset 將所有格子恢復成 0。flip 保證呼叫時至少還有一個零格。
 * 範例：
 *   1. 建立 3x1 矩陣；連續 flip 會不重複地回傳 [0,0]、[1,0]、[2,0] 的某種順序。reset 後這些位置都可再次被選中。
 * 限制：
 *   - 1 <= m, n <= 10^4
 *   - 每次 flip 呼叫時至少有一個尚未翻轉的格子
 *   - flip 和 reset 的呼叫總數不超過 1000
 * 解法：
 *   1. 把矩陣攤平成 0 到 m*n-1 的索引，不實際配置整張矩陣。
 *   2. 把目前剩餘索引看成一個從 0 到 remaining-1 的虛擬陣列；隨機選中一個索引後，將最後一個可用值搬到該位置。
 *   3. 用稀疏映射只記錄被搬動過的位置，避免為最多 10^8 個格子配置記憶體。
 *   4. 將選到的扁平索引換算成 row = index / n、column = index % n。reset 只需清空映射並還原 remaining。
 * 複雜度：每次 flip 時間 O(q)，reset 時間 O(1)；額外空間 O(q)，q 是 reset 以來已翻轉的格數，至多 1000。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
typedef struct {
    int rows;
    int columns;
    int totalCells;
    int remaining;
    int mapSize;
    int mapKeys[1000];
    int mapValues[1000];
    uint32_t randomState;
} Solution;

static uint32_t nextRandom(Solution *obj) {
    uint32_t value = obj->randomState;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    obj->randomState = value;
    return value;
}

static uint32_t randomBelow(Solution *obj, uint32_t bound) {
    uint32_t threshold = (uint32_t)(0u - bound) % bound;
    uint32_t value;
    do {
        value = nextRandom(obj);
    } while (value < threshold);
    return value % bound;
}

static int mappedValue(Solution *obj, int key) {
    for (int i = 0; i < obj->mapSize; i++) {
        if (obj->mapKeys[i] == key) {
            return obj->mapValues[i];
        }
    }
    return key;
}

static void removeMapping(Solution *obj, int key) {
    for (int i = 0; i < obj->mapSize; i++) {
        if (obj->mapKeys[i] == key) {
            obj->mapSize--;
            obj->mapKeys[i] = obj->mapKeys[obj->mapSize];
            obj->mapValues[i] = obj->mapValues[obj->mapSize];
            return;
        }
    }
}

static void setMapping(Solution *obj, int key, int value) {
    if (key == value) {
        removeMapping(obj, key);
        return;
    }
    for (int i = 0; i < obj->mapSize; i++) {
        if (obj->mapKeys[i] == key) {
            obj->mapValues[i] = value;
            return;
        }
    }
    obj->mapKeys[obj->mapSize] = key;
    obj->mapValues[obj->mapSize] = value;
    obj->mapSize++;
}

Solution* solutionCreate(int m, int n) {
    Solution *obj = (Solution *)calloc(1, sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }
    obj->rows = m;
    obj->columns = n;
    obj->totalCells = m * n;
    obj->remaining = obj->totalCells;
    obj->randomState = 0xA341316Cu;
    return obj;
}

int* solutionFlip(Solution* obj, int* retSize) {
    if (obj->remaining <= 0) {
        *retSize = 0;
        return NULL;
    }

    int chosenSlot = (int)randomBelow(obj, (uint32_t)obj->remaining);
    int chosenCell = mappedValue(obj, chosenSlot);
    int lastSlot = obj->remaining - 1;
    int lastCell = mappedValue(obj, lastSlot);

    if (chosenSlot != lastSlot) {
        setMapping(obj, chosenSlot, lastCell);
    }
    removeMapping(obj, lastSlot);
    obj->remaining--;

    int *coordinate = (int *)malloc(sizeof(int) * 2);
    if (coordinate == NULL) {
        *retSize = 0;
        return NULL;
    }
    coordinate[0] = chosenCell / obj->columns;
    coordinate[1] = chosenCell % obj->columns;
    *retSize = 2;
    return coordinate;
}

void solutionReset(Solution* obj) {
    obj->remaining = obj->totalCells;
    obj->mapSize = 0;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/* ---- generated tests ---- */
int main(void) {
    Solution *obj = solutionCreate(3, 2);
    if (obj == NULL) {
        return 1;
    }

    bool seen[6] = {false};
    bool passed = true;
    for (int i = 0; i < 6; i++) {
        int size = 0;
        int *cell = solutionFlip(obj, &size);
        if (cell == NULL || size != 2 ||
            cell[0] < 0 || cell[0] >= 3 ||
            cell[1] < 0 || cell[1] >= 2) {
            passed = false;
        } else {
            int flat = cell[0] * 2 + cell[1];
            if (seen[flat]) {
                passed = false;
            }
            seen[flat] = true;
        }
        free(cell);
    }

    solutionReset(obj);
    int size = 0;
    int *cell = solutionFlip(obj, &size);
    passed = passed && cell != NULL && size == 2 &&
             cell[0] >= 0 && cell[0] < 3 && cell[1] >= 0 && cell[1] < 2;
    free(cell);
    solutionFree(obj);
    printf("%s: 0519 RandomFlipMatrix tests=7\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

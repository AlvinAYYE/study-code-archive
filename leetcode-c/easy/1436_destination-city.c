/*
 * Title-CN: 終點城市
 * LeetCode 1436. Destination City
 *
 * 題意完整翻譯：
 *   給定路徑陣列 paths，其中每一組 [cityA, cityB] 表示可從 cityA 直接前往
 *   cityB。路徑保證形成沒有環的單一路線。請回傳沒有任何 outgoing path 的終點城市。
 *
 * 範例：
 *   1. London -> New York -> Lima -> Sao Paulo，回傳 Sao Paulo。
 *   2. D -> B -> C -> A，所有路徑最後都到 A，回傳 A。
 *   3. A -> Z，回傳 Z。
 *
 * 限制：
 *   - 1 <= paths.length <= 100
 *   - 每筆路徑恰有兩個城市，城市名稱長度為 1 到 10
 *   - cityA != cityB，城市名稱只含大小寫英文字母與空格
 *
 * 解題步驟：
 *   1. 每筆路徑的終點城市可能就是答案。
 *   2. 對每個終點，掃描所有路徑的起點；若它曾是起點，就代表還有 outgoing path，不能是終點。
 *   3. 第一個從未作為起點的城市就是唯一目的地，直接回傳原字串。
 *
 * 複雜度：
 *   時間：O(P^2 × L)，P 是路徑數、L 是城市名稱長度。
 *   空間：O(1) 額外空間；答案直接指向輸入中的城市字串。
 *
 * LeetCode C API：
 *   char* destCity(char*** paths, int pathsSize, int* pathsColSize);
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>

char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    int i;
    int j;

    (void)pathsColSize;

    for (i = 0; i < pathsSize; ++i) {
        char* candidate = paths[i][1];
        int hasOutgoingPath = 0;

        for (j = 0; j < pathsSize; ++j) {
            if (strcmp(candidate, paths[j][0]) == 0) {
                hasOutgoingPath = 1;
                break;
            }
        }

        if (!hasOutgoingPath) {
            return candidate;
        }
    }

    return NULL; /* 題目保證一定存在唯一終點。 */
}

int main(void) {
    char* firstPaths[][2] = {
        {"London", "New York"},
        {"New York", "Lima"},
        {"Lima", "Sao Paulo"}
    };
    char** first[] = {firstPaths[0], firstPaths[1], firstPaths[2]};
    int columns1[] = {2, 2, 2};

    char* secondPaths[][2] = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    char** second[] = {secondPaths[0], secondPaths[1], secondPaths[2]};
    int columns2[] = {2, 2, 2};

    assert(strcmp(destCity(first, 3, columns1), "Sao Paulo") == 0);
    assert(strcmp(destCity(second, 3, columns2), "A") == 0);
    puts("PASS 1436 destCity");
    return 0;
}

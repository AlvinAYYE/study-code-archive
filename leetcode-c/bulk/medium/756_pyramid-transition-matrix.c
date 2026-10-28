/*
 * LeetCode 0756. Pyramid Transition Matrix（金字塔轉換矩陣）
 * 題意：由底層字串開始疊積木；allowed 中每個三字母規則表示兩個底色可疊成一個指定頂色。
 *       判斷是否存在一種選法，能一路建到只剩一個積木。
 * 範例：bottom="BCD", allowed=["BCC","CDE","CEA","FFF"] -> true，可建出 CE 再建 A。
 * 限制：bottom 長度 2..6；allowed 最多 216 條；顏色只有 A 到 F；規則不重複。
 * 解法：把每對相鄰底色能選的頂色存成 6 位元遮罩；回溯枚舉下一層，並以列字串記憶化。
 * 複雜度：最多探索 O(6^L) 種列狀態（L<=6），空間 O(6^L)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static unsigned char topChoices[6][6];
static signed char memo[7][46656];

static int encodeRow(const char *row, int length) {
    int code = 0;
    for (int i = 0; i < length; i++) {
        code = code * 6 + (row[i] - 'A');
    }
    return code;
}

static bool canBuildPyramid(const char *row, int length);

static bool makeNextRow(const char *row, int length, char *nextRow,
                        int position) {
    if (position == length - 1) {
        nextRow[position] = '\0';
        return canBuildPyramid(nextRow, length - 1);
    }

    int left = row[position] - 'A';
    int right = row[position + 1] - 'A';
    unsigned char choices = topChoices[left][right];
    for (int color = 0; color < 6; color++) {
        if ((choices & (1u << color)) != 0) {
            nextRow[position] = (char)('A' + color);
            if (makeNextRow(row, length, nextRow, position + 1)) {
                return true;
            }
        }
    }
    return false;
}

static bool canBuildPyramid(const char *row, int length) {
    if (length == 1) {
        return true;
    }
    int code = encodeRow(row, length);
    if (memo[length][code] != -1) {
        return memo[length][code] == 1;
    }

    char nextRow[7];
    bool possible = makeNextRow(row, length, nextRow, 0);
    memo[length][code] = possible ? 1 : 0;
    return possible;
}

/* ---- community solution ---- */
bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    memset(topChoices, 0, sizeof(topChoices));
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < allowedSize; i++) {
        int left = allowed[i][0] - 'A';
        int right = allowed[i][1] - 'A';
        int top = allowed[i][2] - 'A';
        topChoices[left][right] |= (unsigned char)(1u << top);
    }
    return canBuildPyramid(bottom, (int)strlen(bottom));
}

/* ---- generated tests ---- */
int main(void) {
    char bottomOne[] = "BCD";
    char *allowedOne[] = {"BCC", "CDE", "CEA", "FFF"};
    char bottomTwo[] = "AAAA";
    char *allowedTwo[] = {"AAB", "AAC", "BCD", "BBE", "DEF"};
    char bottomThree[] = "AB";
    char *allowedThree[] = {"ABF"};
    bool passed = pyramidTransition(bottomOne, allowedOne, 4) &&
                  !pyramidTransition(bottomTwo, allowedTwo, 5) &&
                  pyramidTransition(bottomThree, allowedThree, 1);
    printf("%s: 0756 pyramidTransition tests=3\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

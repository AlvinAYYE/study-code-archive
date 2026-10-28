/*
 * LeetCode 591. Tag Validator（標籤驗證器）
 *
 * 題意（繁體中文）：
 *   給定一段程式碼字串，判斷它是否符合標籤格式。整段程式碼必須由一個
 *   完整的根標籤包住；標籤名稱只能由 1 到 9 個大寫英文字母組成，開始標籤
 *   與結束標籤名稱必須一致，而且巢狀標籤必須正確配對。標籤內容可以包含
 *   一般文字、其他完整標籤，或 <![CDATA[ ... ]]> 區段。CDATA 中的內容視為
 *   純文字，即使出現看似標籤的字串也不解析。任何未配對的尖括號、錯誤標籤
 *   或根標籤外的內容都會使字串無效。
 *
 * 範例：
 *   1. "<DIV>This is the first line <![CDATA[<div>]]></DIV>" 回傳 true。
 *      CDATA 內的小寫標籤文字不需要配對。
 *   2. "<DIV>>> ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>" 回傳 true。
 *      一般文字可包含 >，CDATA 在第一個 ]]> 結束。
 *   3. "<A> <B> </A> </B>" 回傳 false，因為標籤沒有依巢狀順序閉合。
 *
 * 限制：1 <= code.length <= 500；字元限於英文字母、數字、<、>、/、!、[、]、.、空格。
 *
 * 解題步驟：
 *   1. 從左到右掃描，遇到一般文字時必須位於某個開啟的標籤內。
 *   2. 遇到 <![CDATA[ 時，只能在標籤內出現；跳過直到第一個 ]]>，其中內容
 *      不當成標籤解析。
 *   3. 遇到開始標籤就檢查名稱格式並推入堆疊；遇到結束標籤就檢查它是否和
 *      堆疊頂端一致，再彈出。根標籤一旦結束，後面不能再有任何字元。
 *   4. 掃描結束時必須恰好解析完一個根標籤，且堆疊為空。
 *
 * 複雜度：令 L 為字串長度，時間 O(L)，堆疊空間 O(L)。
 * LeetCode C API：bool isValid(char* code)
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool parseTagName(const char *code, int start, bool closing,
                         char name[10], int *nextPosition) {
    int position = start + (closing ? 2 : 1);
    int length = 0;
    while (code[position] != '\0' && code[position] != '>') {
        if (code[position] < 'A' || code[position] > 'Z' || length == 9)
            return false;
        name[length++] = code[position++];
    }
    if (code[position] != '>' || length == 0) return false;
    name[length] = '\0';
    *nextPosition = position + 1;
    return true;
}

bool isValid(char *code) {
    if (code == NULL || code[0] == '\0') return false;
    int length = (int)strlen(code);
    char stack[501][10];
    int depth = 0;
    int position = 0;
    bool rootStarted = false;

    while (position < length) {
        if (code[position] != '<') {
            if (depth == 0) return false; /* 根標籤外不允許任何文字。 */
            ++position;
            continue;
        }

        if (strncmp(code + position, "<![CDATA[", 9) == 0) {
            if (depth == 0) return false;
            int end = position + 9;
            while (end + 2 < length &&
                   !(code[end] == ']' && code[end + 1] == ']' && code[end + 2] == '>'))
                ++end;
            if (end + 2 >= length) return false; /* 沒有 CDATA 結尾。 */
            position = end + 3;
            continue;
        }

        bool closing = code[position + 1] == '/';
        char name[10];
        int nextPosition;
        if (!parseTagName(code, position, closing, name, &nextPosition)) return false;

        if (closing) {
            if (depth == 0 || strcmp(stack[depth - 1], name) != 0) return false;
            --depth;
            position = nextPosition;
            if (depth == 0 && position != length) return false;
        } else {
            if (depth == 0) {
                if (rootStarted || position != 0) return false;
                rootStarted = true;
            }
            strcpy(stack[depth++], name);
            position = nextPosition;
        }
    }

    return rootStarted && depth == 0;
}

int main(void) {
    char code1[] = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    char code2[] = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    char code3[] = "<A>  <B> </A>   </B>";
    char code4[] = "<A></A><B></B>";
    char code5[] = "<ABCDEFGHIJ></ABCDEFGHIJ>";
    char code6[] = "<A><![CDATA[<B></B>]]></A>";
    int passed = isValid(code1) && isValid(code2) && !isValid(code3) &&
                 !isValid(code4) && !isValid(code5) && isValid(code6);
    puts(passed ? "PASS: 591 tag-validator" : "FAIL: 591 tag-validator");
    return passed ? 0 : 1;
}

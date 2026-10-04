/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】依固定碼表把 0、1 組成的位元字串還原為字母。碼表是
 * A=10、B=01、C=11、D=001、E=000。 【輸入】一行只包含 0 和 1
 * 的字串。【輸出】解碼後的字母；若遇到不能配對的位元組合，印出編碼不合法。 【閱讀順序】i
 * 表示尚未解碼的位置。程式先試兩位碼；若沒有符合，再試三位碼。找到後印出對應字母，並把 i
 * 前進相同位數；若兩種長度都不符合，就停止並回報錯誤。
 * 【C 語法】字串是以 '\0' 結尾的 char 陣列；strlen 計算字串長度，strncmp
 * 比較指定數量的字元，putchar 印出單一字元。固定碼表存在 code 陣列，字母存在 ch
 * 陣列，相同索引代表一組對應。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 固定碼表 A=10 B=01 C=11 D=001 E=000。輸入一行 0/1 編碼。 */
#include <stdio.h>
#include <string.h>
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    char encoded_text[100000];
    if (scanf("%99999s", encoded_text) != 1)
        return 1;
    const char *code_words[] = {"10", "01", "11", "001", "000"};
    const char decoded_characters[] = "ABCDE";
    int text_length = (int)strlen(encoded_text), position = 0;
    while (position < text_length) {
        int matched_code = 0;
        for (int code_index = 0; code_index < 5; code_index++) {
            int code_length = (int)strlen(code_words[code_index]);
            if (position + code_length <= text_length &&
                strncmp(encoded_text + position, code_words[code_index], code_length) == 0) {
                putchar(decoded_characters[code_index]);
                position += code_length;
                matched_code = 1;
                break;
            }
        }
        if (!matched_code) {
            puts("\n編碼不合法");
            return 1;
        }
    }
    putchar('\n');
    return 0;
}

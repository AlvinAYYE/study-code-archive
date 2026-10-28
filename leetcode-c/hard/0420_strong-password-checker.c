/*
 * Title-CN: 強密碼檢查器
 * LeetCode 420. Strong Password Checker
 *
 * 題意翻譯：一個密碼符合下列條件才算強密碼：長度為 6 到 20；至少含一個
 * 小寫字母、一個大寫字母和一個數字；不能有三個以上相同字元連續出現。
 * 每次可以插入、刪除或替換一個字元。請回傳最少操作次數。
 *
 * 範例："a" 回傳 5（補足長度，並補上大寫字母和數字）；"aaa111" 回傳 2；
 * "1337C0d3" 回傳 0。
 *
 * 限制：密碼長度為 1 到 50；只含英文字母和數字。
 *
 * 解題思路：先數出缺少幾種字元類別，再找出連續相同字元的區段。長度不足 6
 * 時，插入字元可同時補長度和缺少類別，答案是兩者較大值。長度在 6 到 20 時，
 * 把每三個相同字元替換一個，再與缺少類別數取較大值。長度超過 20 時，必須先
 * 刪除多出的字元；優先刪除長度除以 3 餘 0 的區段（刪 1 個可少 1 次替換），
 * 再處理餘 1 的區段（刪 2 個可少 1 次替換），最後每刪 3 個可少 1 次替換。
 *
 * 複雜度：時間 O(n)，只掃描密碼常數次；額外空間 O(1)。
 * LeetCode 介面：保留 strongPasswordChecker；main() 僅供本機測試。
 */

#include <assert.h>
#include <string.h>

static int larger(int a, int b) {
    return a > b ? a : b;
}

int strongPasswordChecker(char *password) {
    int length = (int)strlen(password);
    int hasLower = 0;
    int hasUpper = 0;
    int hasDigit = 0;
    for (int i = 0; i < length; ++i) {
        if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
        if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
    }
    int missingTypes = 3 - hasLower - hasUpper - hasDigit;

    int replacements = 0;
    int groupsModuloZero = 0;
    int groupsModuloOne = 0;
    for (int start = 0; start < length;) {
        int end = start + 1;
        while (end < length && password[end] == password[start]) ++end;
        int runLength = end - start;
        if (runLength >= 3) {
            replacements += runLength / 3;
            if (runLength % 3 == 0) ++groupsModuloZero;
            if (runLength % 3 == 1) ++groupsModuloOne;
        }
        start = end;
    }

    if (length < 6) return larger(6 - length, missingTypes);
    if (length <= 20) return larger(missingTypes, replacements);

    int deletions = length - 20;
    int remainingDeletions = deletions;

    /* 對長度 3m 的重複區段，刪 1 個字元即可少一次替換。 */
    int use = groupsModuloZero < remainingDeletions ? groupsModuloZero : remainingDeletions;
    replacements -= use;
    remainingDeletions -= use;

    /* 對長度 3m+1 的區段，刪 2 個字元可少一次替換。 */
    use = groupsModuloOne < remainingDeletions / 2 ? groupsModuloOne : remainingDeletions / 2;
    replacements -= use;
    remainingDeletions -= 2 * use;

    /* 其餘刪除額度，每 3 個字元可少一次替換。 */
    replacements -= remainingDeletions / 3;
    if (replacements < 0) replacements = 0;
    return deletions + larger(missingTypes, replacements);
}

int main(void) {
    char shortPassword[] = "a";
    char missingAndRepeating[] = "aaa111";
    char alreadyStrong[] = "1337C0d3";
    char longRepeat[] = "aaaaaaaaaaaaaaaaaaaaa";
    assert(strongPasswordChecker(shortPassword) == 5);
    assert(strongPasswordChecker(missingAndRepeating) == 2);
    assert(strongPasswordChecker(alreadyStrong) == 0);
    assert(strongPasswordChecker(longRepeat) == 7);
    return 0;
}

/*
 * Title-CN: 不同的電子郵件地址
 * LeetCode 929. Unique Email Addresses
 *
 * 題意完整翻譯：
 *   電子郵件由 @ 分隔成本地名稱與網域名稱。寄信時，本地名稱中的句點 . 會被忽略；本地名稱中第一個加號 +
 *   以及其後所有字元也會被忽略。這兩條規則不適用於網域名稱。給定 emails，回傳實際會收到郵件的不同地址數量。
 *
 * 範例：
 *   1. emails = [test.email+alex@leetcode.com,
 *      test.e.mail+bob.cathy@leetcode.com, testemail+david@lee.tcode.com]，輸出
 *      2。前兩個都正規化為 testemail@leetcode.com，第三個網域不同。
 *   2. emails = [a@leetcode.com, b@leetcode.com, c@leetcode.com]，輸出 3。
 *
 * 限制：
 *   - 1 <= emails.length <= 100
 *   - 1 <= emails[i].length <= 100
 *   - 字串只含小寫英文字母、+、.、@，且恰有一個 @
 *   - 本地名稱與網域名稱皆非空，本地名稱不以 + 開頭
 *   - 網域以 .com 結尾，且 .com 前至少有一個字元
 *
 * 解題步驟：
 *   1. 逐一處理每個地址，在 @ 前掃描本地名稱。
 *   2. 遇到 + 就停止讀本地名稱；遇到 . 就略過；其餘字元加入正規化地址。
 *   3. 把 @ 與整個網域原樣接到正規化地址後方。
 *   4. 將正規化地址與之前處理過的地址比較，只將新的地址計數一次。
 *
 * 複雜度：
 *   時間：O(E^2 L)，E 是地址數、L 是地址長度；以線性比對去除重複。
 *   空間：O(E L)，保存正規化後的地址。
 *
 * LeetCode C API：
 *   int numUniqueEmails(char** emails, int emailsSize);
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numUniqueEmails(char** emails, int emailsSize) {
    char** normalized = (char**)malloc(sizeof(char*) * (size_t)emailsSize);
    int uniqueCount = 0;
    int emailIndex;

    for (emailIndex = 0; emailIndex < emailsSize; ++emailIndex) {
        char* address = emails[emailIndex];
        char* local = (char*)malloc(strlen(address) + 1);
        int localLength = 0;
        int i = 0;
        int isNew = 1;

        // 本地名稱遇到 + 就結束；句點則直接忽略。
        while (address[i] != '@' && address[i] != '+') {
            if (address[i] != '.') {
                local[localLength] = address[i];
                ++localLength;
            }
            ++i;
        }

        local[localLength] = '\0';

        // 網域部分不套用本地名稱規則，原樣複製。
        while (address[i] != '@') {
            ++i;
        }
        strcpy(local + localLength, address + i);

        for (i = 0; i < uniqueCount; ++i) {
            if (strcmp(normalized[i], local) == 0) {
                isNew = 0;
                break;
            }
        }

        if (isNew) {
            normalized[uniqueCount] = local;
            ++uniqueCount;
        } else {
            free(local);
        }
    }

    for (emailIndex = 0; emailIndex < uniqueCount; ++emailIndex) {
        free(normalized[emailIndex]);
    }
    free(normalized);
    return uniqueCount;
}

int main(void) {
    char email0[] = "test.email+alex@leetcode.com";
    char email1[] = "test.e.mail+bob.cathy@leetcode.com";
    char email2[] = "testemail+david@lee.tcode.com";
    char* first[] = {email0, email1, email2};
    char email3[] = "a@leetcode.com";
    char email4[] = "b@leetcode.com";
    char email5[] = "c@leetcode.com";
    char* second[] = {email3, email4, email5};

    assert(numUniqueEmails(first, 3) == 2);
    assert(numUniqueEmails(second, 3) == 3);
    puts("PASS 0929 numUniqueEmails");
    return 0;
}

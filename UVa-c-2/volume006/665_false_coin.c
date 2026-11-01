/*
 * ==========================================================================
 * UVa 665 - False coin
 * Title-CN: 尋找偽幣
 * Difficulty: Easy
 * Tags: Logic, Implementation
 * URL: https://onlinejudge.org/external/6/665.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given weighing results (<, =, >) of coin subsets on a balance scale, determine the unique false coin if possible.
 *
 * [中文] 題目描述:
 *     天平稱量若干枚硬幣，給出秤重結果（<, =, >），判斷能否唯一確定哪一枚是重量不同的假幣。
 *
 * [EN] Approach:
 *     Coins appearing in '=' weighings are definitely genuine. Suspect coins must participate in all unequal weighings. Count suspects.
 *
 * [中文] 解題思維:
 *     在 '=' 天平兩側的硬幣皆為真幣；在不平衡天平中未出現的硬幣亦為真幣。統計符合所有不平衡秤重的唯一偽幣候選。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int find_false_coin(int n, int k, int weigh_len[], int weigh_coins[][200], char results[]) {
    int genuine[105];
    memset(genuine, 0, sizeof(genuine));

    for (int w = 0; w < k; w++) {
        int m = weigh_len[w];
        if (results[w] == '=') {
            for (int i = 0; i < 2 * m; i++) genuine[weigh_coins[w][i]] = 1;
        } else {
            int in_weigh[105];
            memset(in_weigh, 0, sizeof(in_weigh));
            for (int i = 0; i < 2 * m; i++) in_weigh[weigh_coins[w][i]] = 1;
            for (int i = 1; i <= n; i++) {
                if (!in_weigh[i]) genuine[i] = 1; // cannot be the false coin
            }
        }
    }

    int false_id = 0, count = 0;
    for (int i = 1; i <= n; i++) {
        if (!genuine[i]) {
            false_id = i;
            count++;
        }
    }
    return count == 1 ? false_id : 0;
}

int main(void) {

    int w_len[] = {2};
    int w_coins[1][200] = {{1, 2, 3, 4}};
    char res[] = {'='};
    // 5 coins: 1,2,3,4 equal -> coin 5 is false
    int ans = find_false_coin(5, 1, w_len, w_coins, res);
    int ok = (ans == 5);
    printf("%s: UVa 665 - False coin\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

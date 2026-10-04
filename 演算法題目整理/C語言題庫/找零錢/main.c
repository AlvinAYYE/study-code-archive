/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】給定不同面額，使用最少枚硬幣湊出目標金額，並列出每種面額用了幾枚。
 * 【輸入】面額種類數 d、d 個正面額、目標金額
 * amt。【輸出】最少硬幣數及各面額數量；無法湊出時印出訊息。
 * 【閱讀順序】dp[x] 表示湊出 x
 * 元所需的最少硬幣數。dp[0]=0；對每個 x，嘗試每一種不超過 x
 * 的硬幣，從 dp[x-coin]+1 更新最小值。last[x]
 * 記下最後選的硬幣種類，最後沿 last 從 amt 倒扣，統計硬幣數。 【C 語法】malloc
 * 依金額大小動態配置陣列；指標 dp 指向配置好的整數陣列；free
 * 釋放記憶體。此解法允許同一面額硬幣重複使用。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入幣值種類數 d、d 個幣值、目標金額 amt；求最少硬幣數及各幣值張數。 */
#include <stdio.h>
#include <stdlib.h>
#define A 1000000
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int coin_count, coin_values[100], amount;
    if (scanf("%d", &coin_count) != 1 || coin_count < 1 || coin_count > 100)
        return 1;
    for (int index = 0; index < coin_count; index++)
        if (scanf("%d", &coin_values[index]) != 1 || coin_values[index] <= 0)
            return 1;
    if (scanf("%d", &amount) != 1 || amount < 0 || amount > A)
        return 1;
    int *minimum_coins = malloc((amount + 1) * sizeof(int)),
        *last_coin = malloc((amount + 1) * sizeof(int));
    if (!minimum_coins || !last_coin)
        return 1;
    for (int index = 0; index <= amount; index++)
        minimum_coins[index] = A, last_coin[index] = -1;
    minimum_coins[0] = 0;
    for (int current_amount = 1; current_amount <= amount; current_amount++)
        for (int coin_index = 0; coin_index < coin_count; coin_index++)
            if (coin_values[coin_index] <= current_amount &&
                minimum_coins[current_amount - coin_values[coin_index]] + 1 <
                    minimum_coins[current_amount])
                minimum_coins[current_amount] =
                    minimum_coins[current_amount - coin_values[coin_index]] + 1,
                last_coin[current_amount] = coin_index;
    if (minimum_coins[amount] >= A) {
        puts("無法湊出此金額");
        return 0;
    }
    printf("最少硬幣數：%d\n", minimum_coins[amount]);
    int coin_usage[100] = {0};
    for (int current_amount = amount; current_amount > 0;) {
        int coin_index = last_coin[current_amount];
        if (coin_index < 0)
            return 1;
        coin_usage[coin_index]++;
        current_amount -= coin_values[coin_index];
    }
    for (int coin_index = 0; coin_index < coin_count; coin_index++)
        printf("%d 元：%d 枚\n", coin_values[coin_index], coin_usage[coin_index]);
    free(minimum_coins);
    free(last_coin);
    return 0;
}

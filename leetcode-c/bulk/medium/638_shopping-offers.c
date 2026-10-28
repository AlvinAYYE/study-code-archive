/*
 * LeetCode 0638. Shopping Offers（購物優惠）
 * Difficulty: Medium
 * 題意：有 n 種商品，price[i] 是單買第 i 種商品的價格。每個優惠 special[i] 列出各商品數量和優惠總價。給定 needs，請計算剛好買到需求數量的最低花費；優惠可以不使用，也不能買超過需求。
 * 範例：
 *   1. 輸入：price = [2,5]，special = [[3,0,5],[1,2,10]]，needs = [3,2]；輸出：14。
 *   2. 輸入：price = [2,3,4]，special = [[1,1,0,4],[2,2,1,9]]，needs = [1,2,1]；輸出：11。
 * 限制：
 *   - 1 <= 商品種類數 n <= 6
 *   - 0 <= price[i], needs[i] <= 10
 *   - 1 <= special.length <= 100
 *   - 每個優惠列含 n 種商品數量及 1 個總價
 *   - 每個優惠至少包含一件商品
 * 解法：
 *   1. 把目前剩餘需求向量當作一個狀態；先假設剩下商品全部單買，得到一個可行花費上限。
 *   2. 逐一嘗試優惠。若優惠任一商品數量超過剩餘需求，就不能使用。
 *   3. 可使用時，將優惠數量從需求扣除，遞迴計算剩餘需求的最低花費，再加上優惠價格。
 *   4. 用需求向量的 base-11 編碼作為 memo 索引，記住每個狀態的最佳花費，避免重複計算。
 * 複雜度：最多 O(11^n * S * n)，S 為優惠數量；額外空間 O(11^n)。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
typedef struct {
    int itemCount;
    int *price;
    int **offers;
    int offerCount;
    int *memo;
} ShoppingContext;

static int minimumShoppingCost(ShoppingContext *context, const int *needs) {
    int state = 0;
    int multiplier = 1;
    int directCost = 0;
    for (int i = 0; i < context->itemCount; i++) {
        state += needs[i] * multiplier;
        multiplier *= 11;
        directCost += needs[i] * context->price[i];
    }
    if (context->memo[state] != -1) {
        return context->memo[state];
    }

    int bestCost = directCost;
    int nextNeeds[6];
    for (int offer = 0; offer < context->offerCount; offer++) {
        bool usable = true;
        for (int item = 0; item < context->itemCount; item++) {
            if (context->offers[offer][item] > needs[item]) {
                usable = false;
                break;
            }
            nextNeeds[item] = needs[item] - context->offers[offer][item];
        }
        if (!usable) {
            continue;
        }

        int cost = context->offers[offer][context->itemCount] +
                   minimumShoppingCost(context, nextNeeds);
        if (cost < bestCost) {
            bestCost = cost;
        }
    }
    context->memo[state] = bestCost;
    return bestCost;
}

int shoppingOffers(int* price, int priceSize, int** special, int specialSize,
                   int* specialColSize, int* needs, int needsSize) {
    (void)specialColSize;
    (void)needsSize;
    size_t stateCount = 1;
    for (int i = 0; i < priceSize; i++) {
        stateCount *= 11;
    }
    int *memo = (int *)malloc(sizeof(int) * stateCount);
    if (memo == NULL) {
        int directCost = 0;
        for (int i = 0; i < priceSize; i++) {
            directCost += price[i] * needs[i];
        }
        return directCost;
    }
    for (size_t i = 0; i < stateCount; i++) {
        memo[i] = -1;
    }

    ShoppingContext context = {priceSize, price, special, specialSize, memo};
    int answer = minimumShoppingCost(&context, needs);
    free(memo);
    return answer;
}

/* ---- generated tests ---- */
int main(void) {
    int priceOne[] = {2, 5};
    int offerOneA[] = {3, 0, 5};
    int offerOneB[] = {1, 2, 10};
    int *offersOne[] = {offerOneA, offerOneB};
    int offerColsOne[] = {3, 3};
    int needsOne[] = {3, 2};

    int priceTwo[] = {2, 3, 4};
    int offerTwoA[] = {1, 1, 0, 4};
    int offerTwoB[] = {2, 2, 1, 9};
    int *offersTwo[] = {offerTwoA, offerTwoB};
    int offerColsTwo[] = {4, 4};
    int needsTwo[] = {1, 2, 1};

    bool passed =
        shoppingOffers(priceOne, 2, offersOne, 2, offerColsOne, needsOne, 2) == 14 &&
        shoppingOffers(priceTwo, 3, offersTwo, 2, offerColsTwo, needsTwo, 3) == 11;
    printf("%s: 0638 shoppingOffers tests=2\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

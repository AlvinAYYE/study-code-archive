/*
 * ==========================================================================
 * UVa 686 - Goldbach's Conjecture (II)
 * Title-CN: 哥德巴赫猜想拆分對數計數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime
 * ==========================================================================
 * [EN] Problem: Count pairs of primes (p1, p2) with p1 <= p2 such that p1 + p2 = 2n.
 * [中文] 題目說明: 計算將偶數 2n 拆成兩質數和 p1 + p2 (p1 <= p2) 的所有拆分對數。
 * [EN] Approach: Sieve primes up to 32768, loop p1 <= n, check is_prime[2n - p1].
 * [中文] 思路: 埃氏篩法建立質數表，枚舉 p1 <= n 統計質數對個數。
 * ==========================================================================
 */
#include <stdio.h>

static int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int count_goldbach_pairs(int n) {
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (is_prime(i) && is_prime(n - i)) cnt++;
    }
    return cnt;
}

int main(void) {
    int ok = (count_goldbach_pairs(10) == 2); /* 3+7, 5+5 */
    printf("%s: UVa 686 - Goldbachs Conjecture II\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

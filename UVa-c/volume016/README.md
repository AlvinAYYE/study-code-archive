# UVa Volume 016 題目索引

本卷收錄 1 份 C 解答，涵蓋 1 個 UVa 題號，以下依題號排序。

<a id="uva-1644_prime-gap"></a>

### UVa 1644 — Prime Gap／質數間隙長度

- 原始碼：[1644_prime-gap.c](1644_prime-gap.c)
- 難度：Easy
- 演算法：math, prime, sieve

**English description:** Given composite number k, find length of prime gap containing k (difference between smallest prime > k and largest prime < k). If k is prime, gap is 0.

**中文詳細描述：** 給定合數 k，求包含 k 的質數間隙長度（即大於 k 的最小質數減去小於 k 的最大質數；若 k 本身為質數則間隙為 0）。

**English approach:** Sieve primes up to 1,300,000. If is_prime[k] return 0; else find adjacent primes p1 < k < p2 and return p2 - p1.

**中文解題思路：** 質數篩預處理，若 k 為質數返回 0；否則向兩側掃描找到小於 k 的最大質數與大於 k 的最小質數，差值即為間隙長度。 ==========================================================================

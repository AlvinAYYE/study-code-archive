<?php
/**
 * 題目 2
 * 題目
 * 假如有 n 階樓梯，每次只能向上走 1 階、2 階或 3 階，請問一共有多少種不同的走法呢？ (執
 * 行時間: 3 秒)
 * 測試資料第一行會有一個正整數 n (n <= 50)，請輸出走法的總數量。
 * 測試資料
 * 輸入 輸出
 * 1 1
 * 2 2
 * 3 4
 */
while (($line = readline()) !== false) {
    $dp = array_fill(0, $line + 1, 0);
    $dp[1] = 1;
    if ($line >= 2) {
        $dp[2] = 2;
    }
    if ($line >= 3) {
        $dp[3] = 4;
    }
    for ($i = 4; $i <= $line; $i++) {
        $dp[$i] = $dp[$i - 1] + $dp[$i - 2] + $dp[$i - 3];
    }
    echo $dp[$line] . PHP_EOL;
}
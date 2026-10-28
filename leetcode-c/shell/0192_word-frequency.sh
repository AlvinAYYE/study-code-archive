#!/bin/sh
# LeetCode 192. Word Frequency（單字出現頻率）
# 題目翻譯：讀取 words.txt，計算每個單字在檔案中出現幾次，依出現次數由大到小，
# 每行輸出「單字 次數」。題目保證不同單字的出現次數不會相同，因此不需處理並列順序。
#
# 輸入範例（words.txt）：
# the day is sunny the the
# the sunny is is
# 輸出範例：
# the 4
# is 3
# sunny 2
# day 1
#
# 限制：檔案只含小寫英文字母與空格；單字只含小寫英文字母；單字之間由一個或多個空白字元分隔。
# 解題步驟：1. tr 將連續空白壓成換行，讓每個單字各佔一行。2. grep 移除空行。
# 3. sort 將相同單字排在一起。4. uniq -c 統計次數。5. sort -nr 按次數由大到小排列。
# 6. awk 將「次數 單字」改成題目要求的「單字 次數」。
# 複雜度：令 N 為單字總數，排序需 O(N log N) 時間；排序及計數暫存約 O(N) 空間。
# 題目：https://leetcode.com/problems/word-frequency/

tr -s '[:space:]' '\n' < words.txt |
    grep -v '^$' |
    sort |
    uniq -c |
    sort -nr |
    awk '{ print $2, $1 }'

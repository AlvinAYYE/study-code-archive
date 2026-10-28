#!/bin/sh
# LeetCode 195. Tenth Line（第十行）
# 題目翻譯：只輸出 file.txt 的第 10 行，不要輸出其他行。
#
# 輸入範例（file.txt）：
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# 輸出範例：
# Line 10
#
# 限制：檔案可能少於 10 行；少於 10 行時應輸出空內容。
# 解題步驟：sed -n 關閉每行的預設輸出；10p 只列印第 10 行，因此不足 10 行時不會輸出。
# 複雜度：令 N 為檔案行數，時間 O(N)；sed 串流讀取，額外空間 O(1)。
# 題目：https://leetcode.com/problems/tenth-line/

sed -n '10p' file.txt

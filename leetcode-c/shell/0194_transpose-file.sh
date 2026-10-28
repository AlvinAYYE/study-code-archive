#!/bin/sh
# LeetCode 194. Transpose File（轉置文字檔）
# 題目翻譯：file.txt 是一個文字表格，請將列與欄互換後輸出。原本第 i 列第 j 欄的值，
# 會成為結果的第 j 列第 i 欄。
#
# 輸入範例（file.txt）：
# name age
# alice 21
# ryan 30
# 輸出範例：
# name alice ryan
# age 21 30
#
# 限制：每一列的欄位數相同；欄位以單一空格分隔。
# 解題步驟：awk 用 NF 取得每列欄位數，並以 $column 讀取指定欄位。第一列先填入轉置表格，
# 後續每列將欄位值接到相同欄號的字串後。讀完檔案後，依原欄位順序逐列印出轉置結果。
# 複雜度：原表有 R 列、C 欄，時間與暫存空間皆為 O(R*C)。
# 題目：https://leetcode.com/problems/transpose-file/

awk '{
    for (column = 1; column <= NF; column++) {
        if (NR == 1) {
            transposed[column] = $column
        } else {
            transposed[column] = transposed[column] " " $column
        }
    }
    columnCount = NF
}
END {
    for (column = 1; column <= columnCount; column++) {
        print transposed[column]
    }
}' file.txt

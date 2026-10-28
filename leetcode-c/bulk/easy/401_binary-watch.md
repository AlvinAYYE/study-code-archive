# 401 Binary Watch：二進位手錶

**難度：** Easy

## 題意完整翻譯

二進位手錶上方有 4 個 LED 表示小時（0 到 11），下方有 6 個 LED 表示分鐘（0 到 59）；亮起的 LED 代表二進位中的 1，最右邊是最低位。給定亮著的 LED 數量 turnedOn，回傳手錶可能顯示的所有時間，順序不限。小時不能有前導零；分鐘固定兩位，必要時在前面補 0。

## 範例

### 範例 1

- 輸入：turnedOn = 1
- 輸出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
- 說明：只有一個燈亮時，可能是分鐘的六個位元之一，或小時的四個位元之一。

### 範例 2

- 輸入：turnedOn = 9
- 輸出：[]
- 說明：手錶總共只有 10 個 LED，且小時和分鐘的有效範圍無法讓 9 個燈同時亮起。

## 限制

- 0 <= turnedOn <= 10

## 解題思路

1. 列舉所有合法小時 0 到 11，以及分鐘 0 到 59。
2. 分別計算小時與分鐘的二進位 1 數量；兩者相加等於 turnedOn 時，這個時間就是答案。
3. 用小時不補零、分鐘補成兩位數的格式建立時間字串。

## 複雜度

- 時間：O(12 × 60 × 6)，範圍固定；也可視為 O(1)。
- 空間：O(1) 額外空間；回傳的時間清單另需 O(k) 空間。

## C 函式簽名

~~~c
char** readBinaryWatch(int turnedOn, int* returnSize);
~~~

## 程式如何運作

~~~c
static int countOnBits(int value) {
    int count = 0;

    while (value > 0) {
        count += value & 1;
        value >>= 1;
    }

    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** times = (char**)malloc(sizeof(char*) * 720);
    int hour;
    int minute;

    *returnSize = 0;

    // 手錶只有 12 個合法小時與 60 個合法分鐘，逐一檢查即可。
    for (hour = 0; hour < 12; ++hour) {
        for (minute = 0; minute < 60; ++minute) {
            if (countOnBits(hour) + countOnBits(minute) == turnedOn) {
                char* time = (char*)malloc(6);
                sprintf(time, "%d:%02d", hour, minute);
                times[*returnSize] = time;
                ++(*returnSize);
            }
        }
    }

    return times;
}
~~~

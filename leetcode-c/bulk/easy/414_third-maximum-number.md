# 414 Third Maximum Number：第三大的不同數字

**難度：** Easy

## 題意完整翻譯

給定整數陣列 nums，回傳其中第三大的不同數字；若不同數字不足三個，則回傳最大值。相同數字只計算一次。

## 範例

### 範例 1

- 輸入：nums = [3,2,1]
- 輸出：1
- 說明：第一、第二、第三大的不同數字依序是 3、2、1。

### 範例 2

- 輸入：nums = [1,2]
- 輸出：2
- 說明：不同數字只有 2 和 1，因此回傳最大值 2。

### 範例 3

- 輸入：nums = [2,2,3,1]
- 輸出：1
- 說明：不同數字由大到小是 3、2、1，重複的 2 只算一次。

## 限制

- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1

## 解題思路

1. 用 first、second、third 保存目前前三大的不同數字，並用布林值標記各位置是否已有數字。
2. 逐一讀取陣列；若數字已在前三名中就跳過，避免重複計算。
3. 依大小插入前三名，並將原本較小名次往後移。
4. 最後若有第三名就回傳 third，否則回傳 first。

## 複雜度

- 時間：O(n)，只掃描陣列一次。
- 空間：O(1)，只保存前三個候選值與三個旗標。

## C 函式簽名

~~~c
int thirdMax(int* nums, int numsSize);
~~~

## 程式如何運作

~~~c
int thirdMax(int* nums, int numsSize) {
    long long first = 0;
    long long second = 0;
    long long third = 0;
    bool hasFirst = false;
    bool hasSecond = false;
    bool hasThird = false;
    int i;

    for (i = 0; i < numsSize; ++i) {
        long long value = nums[i];

        // 只取不同的數字。
        if ((hasFirst && value == first) ||
            (hasSecond && value == second) ||
            (hasThird && value == third)) {
            continue;
        }

        if (!hasFirst || value > first) {
            third = second;
            hasThird = hasSecond;
            second = first;
            hasSecond = hasFirst;
            first = value;
            hasFirst = true;
        } else if (!hasSecond || value > second) {
            third = second;
            hasThird = hasSecond;
            second = value;
            hasSecond = true;
        } else if (!hasThird || value > third) {
            third = value;
            hasThird = true;
        }
    }

    return (int)(hasThird ? third : first);
}
~~~

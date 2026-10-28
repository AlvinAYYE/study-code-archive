# 268 Missing Number：缺失的數字

**難度：** Easy

## 題意完整翻譯

給定包含 n 個相異整數的陣列 nums，陣列中的數字都在 0 到 n 之間。這個範圍共有 n + 1 個數字，陣列少了其中一個；請回傳缺少的數字。目標是以 O(n) 時間與 O(1) 額外空間完成。

## 範例

### 範例 1

- 輸入：nums = [3,0,1]
- 輸出：2
- 說明：n = 3，範圍是 [0,3]，只有 2 沒出現。

### 範例 2

- 輸入：nums = [0,1]
- 輸出：2
- 說明：n = 2，範圍是 [0,2]，只有 2 沒出現。

### 範例 3

- 輸入：nums = [9,6,4,2,3,5,7,0,1]
- 輸出：8
- 說明：n = 9，範圍是 [0,9]，只有 8 沒出現。

## 限制

- n == nums.length
- 1 <= n <= 10^4
- 0 <= nums[i] <= n
- nums 中所有數字皆相異

## 解題思路

1. 0 到 n 的完整總和是 n × (n + 1) / 2。
2. 把陣列中的每個數字從完整總和扣掉。
3. 最後剩下的數字就是缺失值。

## 複雜度

- 時間：O(n)，只需掃描陣列一次。
- 空間：O(1)，只使用一個累計變數。

## C 函式簽名

~~~c
int missingNumber(int* nums, int numsSize);
~~~

## 程式如何運作

~~~c
int missingNumber(int* nums, int numsSize) {
    int missing = numsSize * (numsSize + 1) / 2;
    int i;

    // 完整範圍總和減去已出現的數字。
    for (i = 0; i < numsSize; ++i) {
        missing -= nums[i];
    }

    return missing;
}
~~~

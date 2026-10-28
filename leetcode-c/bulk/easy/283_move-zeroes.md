# 283 Move Zeroes：移動零

**難度：** Easy

## 題意完整翻譯

給定整數陣列 nums，請把所有 0 移到陣列尾端，並保持非零數字原本的相對順序。必須直接修改原陣列，不可另外複製一份陣列。

## 範例

### 範例 1

- 輸入：nums = [0,1,0,3,12]
- 輸出：[1,3,12,0,0]
- 說明：非零數字依序保留為 1、3、12，再把兩個 0 放到尾端。

### 範例 2

- 輸入：nums = [0]
- 輸出：[0]
- 說明：陣列只有一個 0，移動後仍相同。

## 限制

- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1

## 解題思路

1. 用 writeIndex 記錄下一個非零值該放的位置。
2. 從左到右掃描，把每個非零值依序寫到 writeIndex，然後增加 writeIndex。
3. 掃描完後，從 writeIndex 到陣列尾端全部填 0。

## 複雜度

- 時間：O(n)，最多掃描並填寫陣列各一次。
- 空間：O(1)，直接修改原陣列。

## C 函式簽名

~~~c
void moveZeroes(int* nums, int numsSize);
~~~

## 程式如何運作

~~~c
void moveZeroes(int* nums, int numsSize) {
    int writeIndex = 0;
    int i;

    // 先依序把非零值集中到陣列前方。
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[writeIndex] = nums[i];
            ++writeIndex;
        }
    }

    // 剩餘位置全部補零。
    while (writeIndex < numsSize) {
        nums[writeIndex] = 0;
        ++writeIndex;
    }
}
~~~

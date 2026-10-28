# 349 Intersection of Two Arrays：兩個陣列的交集

**難度：** Easy

## 題意完整翻譯

給定整數陣列 nums1 與 nums2，回傳同時出現在兩個陣列中的數字。結果中的每個數字只能出現一次，回傳順序不限。

## 範例

### 範例 1

- 輸入：nums1 = [1,2,2,1], nums2 = [2,2]
- 輸出：[2]
- 說明：2 同時出現在兩個陣列中，但結果只保留一次。

### 範例 2

- 輸入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
- 輸出：[9,4]
- 說明：[4,9] 也符合，因為回傳順序不限。

## 限制

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## 解題思路

1. 用布林陣列記錄 nums1 出現過哪些值。
2. 再掃描 nums2；若某值也在 nums1 出現，而且還沒放入答案，就加入答案並標記。
3. 每個值最多加入一次，所以結果自然不會有重複數字。

## 複雜度

- 時間：O(n1 + n2)，另有固定大小 1001 的初始化。
- 空間：O(1) 額外空間（值域固定為 0 到 1000）；回傳陣列另需 O(min(n1,n2))。

## C 函式簽名

~~~c
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
~~~

## 程式如何運作

~~~c
int* intersection(int* nums1, int nums1Size,
                   int* nums2, int nums2Size, int* returnSize) {
    bool appearsInFirst[1001] = {false};
    bool alreadyAdded[1001] = {false};
    int capacity = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* answer = (int*)malloc(sizeof(int) * (size_t)capacity);
    int i;

    *returnSize = 0;

    for (i = 0; i < nums1Size; ++i) {
        appearsInFirst[nums1[i]] = true;
    }

    for (i = 0; i < nums2Size; ++i) {
        int value = nums2[i];

        if (appearsInFirst[value] && !alreadyAdded[value]) {
            answer[*returnSize] = value;
            ++(*returnSize);
            alreadyAdded[value] = true;
        }
    }

    return answer;
}
~~~

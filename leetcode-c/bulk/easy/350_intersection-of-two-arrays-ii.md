# 350 Intersection of Two Arrays II：兩個陣列的交集 II

**難度：** Easy

## 題意完整翻譯

給定整數陣列 nums1 與 nums2，回傳它們的交集。每個數字在結果中出現的次數，必須等於它在兩個陣列中較少的出現次數；結果順序不限。延伸思考：若陣列已排序、其中一個很小，或較大的陣列放在磁碟中而記憶體有限，可以如何調整作法？

## 範例

### 範例 1

- 輸入：nums1 = [1,2,2,1], nums2 = [2,2]
- 輸出：[2,2]
- 說明：2 在兩個陣列都出現兩次，因此結果有兩個 2。

### 範例 2

- 輸入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
- 輸出：[4,9]
- 說明：[9,4] 也符合；4 與 9 在兩邊共同出現的次數都只有一次。

## 限制

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## 解題思路

1. 用長度 1001 的陣列，先統計 nums1 中每個值出現幾次。
2. 逐一掃描 nums2；若目前值的剩餘次數大於 0，就把它加入答案，再將次數減 1。
3. 每次配對都消耗一個出現次數，因此答案次數就是兩邊出現次數的較小值。

## 複雜度

- 時間：O(n1 + n2)，另有固定大小 1001 的初始化。
- 空間：O(1) 額外空間（值域固定為 0 到 1000）；回傳陣列另需 O(min(n1,n2))。

## C 函式簽名

~~~c
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
~~~

## 程式如何運作

~~~c
int* intersect(int* nums1, int nums1Size,
                int* nums2, int nums2Size, int* returnSize) {
    int frequency[1001] = {0};
    int capacity = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* answer = (int*)malloc(sizeof(int) * (size_t)capacity);
    int i;

    *returnSize = 0;

    // 記錄第一個陣列中各數字的可配對次數。
    for (i = 0; i < nums1Size; ++i) {
        ++frequency[nums1[i]];
    }

    // 每成功配對一次，就消耗一次出現次數。
    for (i = 0; i < nums2Size; ++i) {
        int value = nums2[i];

        if (frequency[value] > 0) {
            answer[*returnSize] = value;
            ++(*returnSize);
            --frequency[value];
        }
    }

    return answer;
}
~~~

# LeetCode 0284. Peeking Iterator

Title-CN: 可偷看的迭代器

## 題目

在一般迭代器上增加 peek 操作：peek 回傳下一個元素，但不移動迭代位置；next 回傳下一個元素並移動位置；hasNext 判斷是否還有元素。

## 範例

1. 建立內容為 [1,2,3] 的迭代器；依序呼叫 next、peek、next、next、hasNext，結果為 1、2、2、3、false。

## 限制

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- 呼叫 next 和 peek 時保證還有下一個元素
- next、hasNext、peek 的呼叫總數不超過 1000

## 解題思路

1. PeekingIterator 保存原始 Iterator 指標、快取值和 hasPeeked 旗標。
2. 第一次 peek 時才從原始迭代器取出元素放進快取；之後的 peek 直接回傳快取，不再消耗原始迭代器。
3. next 若有快取就回傳快取並清除旗標；若沒有快取則直接呼叫原始迭代器的 next。
4. hasNext 在快取存在時一定為 true，否則詢問原始迭代器。

## 複雜度

每個操作時間 O(1)，額外空間 O(1)。

## C 函式簽名

struct PeekingIterator* Constructor(struct Iterator* iter); int peek(struct PeekingIterator* obj); int next(struct PeekingIterator* obj); bool hasNext(struct PeekingIterator* obj)

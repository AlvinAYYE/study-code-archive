# 0169. Majority Element《多數元素》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/majority-element/

## 題目翻譯

給定長度為 n 的整數陣列，找出出現次數嚴格大於 n/2 的元素。可以假設這個元素一定存在。

## 範例

~~~text
輸入：nums = [3,2,3]
輸出：3

輸入：nums = [2,2,1,1,1,2,2]
輸出：2
~~~

## 限制

- 1 <= n == nums.length <= 5 * 10^4
- -10^9 <= nums[i] <= 10^9
- 多數元素一定存在。

## 解題步驟

1. 維護一個候選值 candidate 和票數 votes。
2. 票數為 0 時，將目前元素設為新候選值。
3. 若目前元素等於候選值就加一票，否則扣一票。
4. 不同元素成對抵銷；多數元素數量超過其他元素總和，因此最後候選值必是答案。

## 複雜度

- 時間：O(n)，只掃描一次陣列。
- 空間：O(1)，只使用候選值和票數。

## C 函式簽名

~~~c
int majorityElement(int* nums, int numsSize);
~~~

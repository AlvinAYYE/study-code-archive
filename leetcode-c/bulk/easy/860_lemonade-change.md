# 0860. Lemonade Change《檸檬水找零》

- **Difficulty**: Easy
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/lemonade-change/
- **程式碼**: [`860_lemonade-change.c`](./860_lemonade-change.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每杯檸檬水售價 5 美元，客人依序各買一杯，且只會付 5、10 或 20 美元。起初沒有零錢，判斷能否為每位客人正確找零，使每人實付 5 美元。

**思路**：程式只追蹤手上的 5 與 10 元鈔票數量。收到 20 元時優先以 10+5 找零，否則用三張 5 元；一旦 5 元數量變負便回傳 false。

## Problem Statement (English)

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
```

## 限制 Constraints

1 <= bills.length <= 105
bills[i] is either 5, 10, or 20.

## 官方 C 函式簽名 Signature

```c
bool lemonadeChange(int* bills, int billsSize) {
    
}
```

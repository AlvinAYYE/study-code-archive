# 0468. Validate IP Address《驗證 IP 位址》

- **Difficulty**: Medium
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/validate-ip-address/
- **程式碼**: [`468_validate-ip-address.c`](./468_validate-ip-address.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 queryIP，合法 IPv4 回傳「IPv4」，合法 IPv6 回傳「IPv6」，否則回傳「Neither」。IPv4 要有 4 個介於 0 到 255 且無前導零的十進位欄位。IPv6 要有 8 個以冒號分隔、各含 1 到 4 個十六進位字元的欄位。

**思路**：程式依是否含句點選擇 IPv4 或 IPv6 驗證，並拆分欄位、計算群組與分隔符數。IPv4 檢查數字、前導零與範圍；IPv6 檢查十六進位字元與欄位長度。

## Problem Statement (English)

Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
```

## 限制 Constraints

queryIP consists only of English letters, digits and the characters '.' and ':'.

## 官方 C 函式簽名 Signature

```c
char* validIPAddress(char* queryIP) {
    
}
```

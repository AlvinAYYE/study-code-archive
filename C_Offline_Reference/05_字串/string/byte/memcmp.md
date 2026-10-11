# memcmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
int memcmp( const void* lhs, const void* rhs, size_t count );
```
|   |   |   |   |

|  |  |  |  |

Compares the first `count` bytes of the objects pointed to by `lhs` and `rhs`. The comparison is done lexicographically.
比較由 lhs 和 rhs 指向的物件的前 count 個位元組。比較按字典序進行。
The sign of the result is the sign of the difference between the values of the first pair of bytes (both interpreted as `unsigned char`) that differ in the objects being compared.
結果的符號是在被比較物件中第一對不同的位元組（均解釋為 unsigned char ）值之差的符號。
The behavior is undefined if access occurs beyond the end of either object pointed to by `lhs` and `rhs`. The behavior is undefined if either `lhs` or `rhs` is a null pointer.
如果訪問超出 lhs 和 rhs 指向的任一物件的末尾，則行為未定義。如果 lhs 或 rhs 為空指標，則行為未定義。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the objects to compare  |

| count  |   | -  |   | number of bytes to examine  |

### Return value

Negative value if `lhs` appears before `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之前，則傳回負值。
Zero if `lhs` and `rhs` compare equal, or if count is zero.
如果 lhs 和 rhs 相等，或 count 為零，則傳回零。
Positive value if `lhs` appears after `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之後，則傳回正值。

### Notes

This function reads object representations, not the object values, and is typically meaningful for byte arrays only: structs may have padding bytes whose values are indeterminate, the values of any bytes beyond the last stored member in a union are indeterminate, and a type may have two or more representations for the same value (different encodings for `+0` and `-0` or for `+0.0` and `–0.0`, indeterminate padding bits within the type).
此函式讀取物件表示，而不是物件值，通常僅對位元組陣列有意義： struct 可能有值不確定的填充位元組， union 中最後一個儲存成員之後的任何位元組的值不確定，且一個型別可能對同一值有兩個或更多表示（ + 0 和 -0 或 + 0.0 和 – 0.0 的不同編碼，型別內不確定的填充位）。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> void demo(const char* lhs, const char* rhs, size_t sz) {  for(size_t n = 0; n < sz; ++n)  putchar(lhs[n]);  int rc = memcmp(lhs, rhs, sz);  const char *rel = rc < 0 ? " precedes " : rc > 0 ? " follows " : " compares equal ";  fputs(rel, stdout);  for(size_t n = 0; n < sz; ++n)  putchar(rhs[n]);  puts(" in lexicographical order"); } int main(void) {  char a1[] = {'a','b','c'};  char a2[sizeof a1] = {'a','b','d'};  demo(a1, a2, sizeof a1);  demo(a2, a1, sizeof a1);  demo(a1, a1, sizeof a1); }
```

Output:

```c
abc precedes abd in lexicographical order abd follows abc in lexicographical order abc compares equal to abc in lexicographical order
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.4.1 The memcmp function (p: TBD)
7.24.4.1 memcmp 函式（頁碼：待定）
7.24.4.1 memcmp 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.4.1 The memcmp function (p: 266)
7.24.4.1 memcmp 函式（頁碼：266）
7.24.4.1 memcmp 函式（頁碼：266）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.4.1 The memcmp function (p: 365)
7.24.4.1 memcmp 函式（頁碼：365）
7.24.4.1 memcmp 函式（頁碼：365）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.4.1 The memcmp function (p: 328)
7.21.4.1 memcmp 函式（頁碼：328）
7.21.4.1 memcmp 函式（頁碼：328）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.4.1 The memcmp function
4.11.4.1 memcmp 函式
4.11.4.1 memcmp 函式

### See also

strcmp
|   | compares two strings
(function)   |

strncmp
|   | compares a certain amount of characters of two strings
(function)   |

C++ documentation for memcmp

---
來源頁路徑：`en.cppreference.com/c/string/byte/memcmp.html`

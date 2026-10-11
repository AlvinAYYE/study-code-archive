# strcspn

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
size_t strcspn( const char *dest, const char *src );
```
|   |   |   |   |

|  |  |  |  |

Returns the length of the maximum initial segment of the null-terminated byte string pointed to by `dest`, that consists of only the characters *not* found in the null-terminated byte string pointed to by `src`.
傳回 dest 指向的空終止位元組字串的最大初始段的長度，該段僅包含 src 指向的空終止位元組字串中未找到的字元。
The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string.
如果 dest 或 src 不是指向空終止位元組字串的指標，則行為未定義。

### Parameters

| dest  |   | -  |   | pointer to the null-terminated byte string to be analyzed  |

| src  |   | -  |   | pointer to the null-terminated byte string that contains the characters to search for  |

### Return value

The length of the maximum initial segment that contains only characters not found in the null-terminated byte string pointed to by `src`
僅包含 src 指向的空終止位元組字串中未找到的字元的最大初始段的長度

### Notes

The function name stands for "complementary span" because the function searches for characters not found in `src`, that is the complement of `src`.
該函式名稱代表 "complementary span"，因為該函式搜尋在 src 中未找到的字元，即 src 的補集。

### Example

Run this code

```c
#include <string.h> #include <stdio.h> int main(void) {  const char *string = "abcde312$#@";  const char *invalid = "*$#";  size_t valid_len = strcspn(string, invalid);  if(valid_len != strlen(string))  printf("'%s' contains invalid chars starting at position %zu\n",  string, valid_len); }
```

Output:

```c
'abcde312$#@' contains invalid chars starting at position 8
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.3 The strcspn function (p: 368)
7.24.5.3 strcspn 函式（頁碼：368）
7.24.5.3 strcspn 函式（頁碼：368）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.3 The strcspn function (p: 331)
7.21.5.3 strcspn 函式（頁碼：331）
7.21.5.3 strcspn 函式（頁碼：331）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.3 The strcspn function
4.11.5.3 strcspn 函式
4.11.5.3 strcspn 函式

### See also

strspn
|   | returns the length of the maximum initial segment that consists
of only the characters found in another byte string
(function)   |

wcscspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide chars *not* found in another wide string
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

C++ documentation for strcspn

---
來源頁路徑：`en.cppreference.com/c/string/byte/strcspn.html`

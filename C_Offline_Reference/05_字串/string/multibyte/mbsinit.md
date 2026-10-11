# mbsinit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int mbsinit( const mbstate_t* ps);
```
|   |   |   |  (since C95)  |

|  |  |  |  |

If `ps` is not a null pointer, the `mbsinit` function determines whether the pointed-to mbstate_t object describes the initial conversion state.
如果 ps 不是空指標，mbsinit 函式確定所指向的 mbstate_t 物件是否描述初始轉換狀態。

### Notes

Although a zero-initialized mbstate_t always represents the initial conversion state, there may be other values of mbstate_t that also represent the initial conversion state.
儘管零初始化的 mbstate_t 始終表示初始轉換狀態，但也可能存在其他同樣表示初始轉換狀態的 mbstate_t 值。

### Parameters

| ps  |   | -  |   | pointer to the mbstate_t object to examine  |

### Return value

`0` if `ps` is not a null pointer and does not represent the initial conversion state, nonzero value otherwise.
如果 ps 不是空指標且不表示初始轉換狀態，則傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <locale.h> #include <string.h> #include <stdio.h> #include <wchar.h> int main(void) {  // allow mbrlen() to work with UTF-8 multibyte encoding  setlocale(LC_ALL, "en_US.utf8");  // UTF-8 narrow multibyte encoding  const char* str = u8"水"; // or u8"\u6c34" or "\xe6\xb0\xb4"  static mbstate_t mb; // zero-initialize  (void)mbrlen(&str[0], 1, &mb);  if (!mbsinit(&mb)) {  printf("After processing the first 1 byte of %s,\n"  "the conversion state is not initial\n\n", str);  }  (void)mbrlen(&str[1], strlen(str), &mb);  if (mbsinit(&mb)) {  printf("After processing the remaining 2 bytes of %s,\n"  "the conversion state is initial conversion state\n", str);  } }
```

Output:

```c
After processing the first 1 byte of 水, the conversion state is not initial After processing the remaining 2 bytes of 水, the conversion state is initial conversion state
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.6.2.1 The mbsinit function (p: 322)
7.29.6.2.1 mbsinit 函式（p: 322）
7.29.6.2.1 mbsinit 函式（p: 322）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.2.1 The mbsinit function (p: 441-442)
7.29.6.2.1 mbsinit 函式（p: 441-442）
7.29.6.2.1 mbsinit 函式（p: 441-442）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.2.1 The mbsinit function (p: 387-388)
7.24.6.2.1 mbsinit 函式（p: 387-388）
7.24.6.2.1 mbsinit 函式（p: 387-388）

### See also

mbstate_t
(C95)
|   | conversion state information necessary to iterate multibyte character strings
(class)   |

C++ documentation for mbsinit

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbsinit.html`

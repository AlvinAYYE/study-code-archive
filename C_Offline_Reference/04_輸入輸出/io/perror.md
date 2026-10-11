# perror

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
void perror( const char *s );
```
|   |   |   |   |

|  |  |  |  |

Prints a textual description of the error code currently stored in the system variable errno to stderr.
將系統變數 errno 中目前儲存的錯誤程式碼的文字描述列印到 stderr。
The description is formed by concatenating the following components:
該描述透過連線以下各部分組成：

- the contents of the null-terminated byte string pointed to by `s`, followed by `": "` (unless `s` is a null pointer or the character pointed to by `s` is the null character)
s 指向的以空字元結尾的位元組字串的內容，後接 ": "（除非 s 是空指標或 s 指向的字元是空字元）

- implementation-defined error message string describing the error code stored in `errno`, followed by `'\n'`. The error message string is identical to the result of `strerror(errno)`.
描述 errno 中儲存的錯誤程式碼的實現定義錯誤訊息字串，後接 '\n'。該錯誤訊息字串與 strerror ( errno ) 的結果相同。

### Parameters

| s  |   | -  |   | pointer to a null-terminated string with explanatory message  |

### Return value

(none)

### Example

Run this code

```c
#include <stdio.h> int main(void) {  FILE *f = fopen("non_existent", "r");  if (f == NULL) {  perror("fopen() failed");  } else {  fclose(f);  } }
```

Possible output:
可能的輸出：

```c
fopen() failed: No such file or directory
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.10.4 The perror function (p: 339)
7.21.10.4 perror 函式（頁：339）
7.21.10.4 perror 函式（頁：339）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.10.4 The perror function (p: 305)
7.19.10.4 perror 函式（頁：305）
7.19.10.4 perror 函式（頁：305）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.10.4 The perror function
4.9.10.4 perror 函式
4.9.10.4 perror 函式

### See also

strerrorstrerror_sstrerrorlen_s
(C11)(C11)
|   | returns a text version of a given error code
(function)   |

C++ documentation for perror

---
來源頁路徑：`en.cppreference.com/c/io/perror.html`

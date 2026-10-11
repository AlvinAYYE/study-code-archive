# ptrdiff_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

```c
typedef /*implementation-defined*/ ptrdiff_t;
```
|   |   |   |   |

|  |  |  |  |

`ptrdiff_t` is the signed integer type of the result of subtracting two pointers.
ptrdiff_t 是兩個指標相減結果的有符號整數型別。

The bit width of `ptrdiff_t` is not less than 17.
在 C23 之前，`ptrdiff_t` 的位元寬度至少為 17 位元。
|   | (since C99)
(until C23) |

The bit width of `ptrdiff_t` is not less than 16.
從 C23 起，`ptrdiff_t` 的位元寬度至少為 16 位元。
|   | (since C23) |

### Notes

`ptrdiff_t` is used for pointer arithmetic and array indexing, if negative values are possible. Programs that use other types, such as `int`, may fail on, e.g. 64-bit systems when the index exceeds INT_MAX or if it relies on 32-bit modular arithmetic.
指標運算或陣列索引可能出現負值時，應使用 ptrdiff_t。若改用 int 等其他型別，程式可能會出錯；例如在 64 位元系統上，索引超過 INT_MAX，或程式依賴 32 位元模數運算時。
Only pointers to elements of the same array (including the pointer one past the end of the array) may be subtracted from each other.
只有指向同一陣列中元素的指標才能彼此相減，也包括指向陣列尾端之後一個位置的指標。
If an array is so large (greater than PTRDIFF_MAX elements, but equal to or less than SIZE_MAX bytes), that the difference between two pointers may not be representable as `ptrdiff_t`, the result of subtracting two such pointers is undefined.
如果陣列足夠大（元素數大於 PTRDIFF_MAX，但位元組數小於或等於 SIZE_MAX），以致兩個指標之差可能無法用 ptrdiff_t 表示，那麼這兩個指標相減的結果是未定義的。
For char arrays shorter than PTRDIFF_MAX, `ptrdiff_t` acts as the signed counterpart of size_t: it can store the size of the array of any type and is, on most platforms, synonymous with `intptr_t`).
對於長度小於 PTRDIFF_MAX 的 char 陣列，ptrdiff_t 充當 size_t 的有符號對應型別：它可以儲存任何型別陣列的大小，並且在大多數平臺上與 intptr_t 同義。

### Possible implementation
可能的實現

```c
typedef typeof((int*)nullptr - (int*)nullptr) ptrdiff_t; // valid since C23
```

### Example

Run this code

```c
#include <stddef.h> #include <stdint.h> #include <stdio.h> int main(void) {  const size_t N = 100;  int numbers[N];    printf("PTRDIFF_MAX = %ld\n", PTRDIFF_MAX);  int *p1 = &numbers[18], *p2 = &numbers[23];  ptrdiff_t diff = p2 - p1;  printf("p2-p1 = %td\n", diff); }
```

Possible output:
可能的輸出：

```c
PTRDIFF_MAX = 9223372036854775807 p2-p1 = 5
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.19 Common definitions <stddef.h> (p: TBD)
7.19 通用定義 <stddef.h>（頁碼：待定）
7.19 通用定義 <stddef.h>（頁碼：待定）

- 7.20.3 Limits of other integer types (p: TBD)
7.20.3 其他整數型別的極限（頁碼：待定）
7.20.3 其他整數型別的極限（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.19 Common definitions <stddef.h> (p: 211)
7.19 通用定義 <stddef.h>（頁碼：211）
7.19 通用定義 <stddef.h>（頁碼：211）

- 7.20.3 Limits of other integer types (p: 215)
7.20.3 其他整數型別的極限（頁碼：215）
7.20.3 其他整數型別的極限（頁碼：215）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.19 Common definitions <stddef.h> (p: 288)
7.19 通用定義 <stddef.h>（頁碼：288）
7.19 通用定義 <stddef.h>（頁碼：288）

- 7.20.3 Limits of other integer types (p: 293)
7.20.3 其他整數型別的極限（頁碼：293）
7.20.3 其他整數型別的極限（頁碼：293）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.17 Common definitions <stddef.h> (p: 253)
7.17 通用定義 <stddef.h>（頁碼：253）
7.17 通用定義 <stddef.h>（頁碼：253）

- 7.18.3 Limits of other integer types (p: 258)
7.18.3 其他整數型別的極限（頁碼：258）
7.18.3 其他整數型別的極限（頁碼：258）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.6 Common definitions <stddef.h>
4.1.6 通用定義 <stddef.h>
4.1.6 通用定義 <stddef.h>

### See also

size_t
|   | unsigned integer type returned by the sizeof operator
(typedef)   |

offsetof
|   | byte offset from the beginning of a struct type to specified member
(function macro)   |

C++ documentation for ptrdiff_t

---
來源頁路徑：`en.cppreference.com/c/types/ptrdiff_t.html`

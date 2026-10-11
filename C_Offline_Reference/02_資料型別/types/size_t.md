# size_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

Defined in header `<stdio.h>`
|   |  |   |  |

Defined in header `<stdlib.h>`
|   |  |   |  |

Defined in header `<string.h>`
|   |  |   |  |

Defined in header `<time.h>`
|   |  |   |  |

Defined in header `<uchar.h>`
|   |  |   |
(since C11)

Defined in header `<wchar.h>`
|   |  |   |
(since C95)

```c
typedef /*implementation-defined*/ size_t;
```
|   |   |   |   |

|  |  |  |  |

`size_t` is the unsigned integer type of the result of sizeof, offsetof and _Alignof(until C23)alignof(since C23), depending on the data model.
size_t 是 sizeof、offsetof 和 _Alignof（C23 之前）alignof（自 C23 起）運算結果的無符號整數型別，具體取決於資料模型。

The bit width of `size_t` is not less than 16.
`size_t` 的位元寬度至少為 16 位元。
|   | (since C99) |

### Notes

`size_t` can store the maximum size of a theoretically possible object of any type (including array).
`size_t` 足以表示任何型別物件（包括陣列）可能具有的最大大小。
`size_t` is commonly used for array indexing and loop counting. Programs that use other types, such as `unsigned int`, for array indexing may fail on, e.g. 64-bit systems when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic.
`size_t` 常用來表示陣列索引或迴圈計數。若改用 `unsigned int` 等較小的型別，在 64 位元系統上索引超過 `UINT_MAX` 時可能出錯；依賴 32 位元整數回繞的程式也可能出錯。

### Possible implementation
可能的實現

```c
typedef typeof(sizeof(0)) size_t; // valid since C23
```

### Example

Run this code

```c
#include <stddef.h> #include <stdint.h> #include <stdio.h>   int main(void) {  const size_t N = 101;  int numbers[N];  size_t sum = 0;  for (size_t ndx = 0; ndx < N; ++ndx)  sum += numbers[ndx] = ndx;  size_t size = sizeof numbers;  printf("sum = %zu\n", sum);  printf("size = %zu\n", size);  printf("SIZE_MAX = %zu\n", SIZE_MAX); }
```

Possible output:
可能的輸出：

```c
sum = 5050 size = 404 SIZE_MAX = 18446744073709551615
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

ptrdiff_t
|   | signed integer type returned when subtracting two pointers
(typedef)   |

offsetof
|   | byte offset from the beginning of a struct type to specified member
(function macro)   |

C++ documentation for size_t

---
來源頁路徑：`en.cppreference.com/c/types/size_t.html`

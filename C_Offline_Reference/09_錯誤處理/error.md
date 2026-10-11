# 錯誤處理

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Error numbers

Defined in header `<errno.h>`

errno
|   | 展開為 POSIX 相容的執行緒區域錯誤碼變數
(macro variable)   |

E2BIG, EACCES, ..., EXDEV
|   | 表示標準 POSIX 相容錯誤狀況的巨集
(macro constant)   |

### Assertions

Defined in header `<assert.h>`

assert
|   | 若指定條件不成立就中止程式；正式發布版本可透過 `NDEBUG` 關閉
(function macro)   |

static_assert
(C11)(removed in C23)
|   | 若常數運算式的值為假，就在編譯時發出診斷訊息
(keyword macro)  |

### Bounds checking

標準函式庫為部分既有函式提供有執行期邊界檢查的版本，例如 `gets_s`、`fopen_s`、`printf_s`、`strcpy_s`、`wcscpy_s`、`mbstowcs_s`、`qsort_s` 和 `getenv_s`。這項功能是選用的；只有實作定義了 `__STDC_LIB_EXT1__` 時才提供。以下巨集與函式支援這項功能。

|    |

Defined in header `<errno.h>`

Defined in header `<stdio.h>`

errno_t
(C11)
|   | `int` 的別名型別，用來標示函式會傳回 `errno` 錯誤碼
(typedef)  |

|    |

Defined in header `<stddef.h>`

Defined in header `<stdio.h>`

Defined in header `<stdlib.h>`

Defined in header `<string.h>`

Defined in header `<time.h>`

Defined in header `<wchar.h>`

rsize_t
(C11)
|   | 與 `size_t` 同型別的別名，用來標示函式會在執行期檢查參數範圍
(typedef)  |

|    |

Defined in header `<stdint.h>`

RSIZE_MAX
(C11)
|   | 邊界檢查函式可接受的最大大小；它可能展開為常數或變數，且執行期間可能改變（例如隨可用記憶體變化）
(macro variable)  |

|    |

Defined in header `<stdlib.h>`

set_constraint_handler_s
(C11)
|   | 設定邊界檢查函式發生限制違反時要呼叫的處理函式
(function)   |

abort_handler_s
(C11)
|   | 中止程式的邊界檢查錯誤處理函式
(function)   |

ignore_handler_s
(C11)
|   | 忽略錯誤的邊界檢查錯誤處理函式
(function)   |

Note: implementations of bounds-checked functions are available as open-source libraries Safe C and Slibc, and as part of Watcom C. There is also an incompatible set of bounds-checked functions available in Visual Studio.
|   | (since C11) |

### Notes

Since C23, static_assert is itself a keyword, which may also be a predefined macro, so `<assert.h>` no longer provides it.
自 C23 起，static_assert 本身是一個關鍵字，它也可能是一個預定義宏，因此 <assert.h> 不再提供它。

### References

| Extended content  |

- C23 standard (ISO/IEC 9899:2024):

- 7.2 Diagnostics <assert.h> (p: TBD)

- 7.5 Errors <errno.h> (p: TBD)

- 7.19 Common definitions <stddef.h> (p: TBD)

- 7.20 Integer types <stdint.h> (p: TBD)

- 7.21 Input/output <stdio.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- K.3.1.3 Use of errno (p: TBD)

- K.3.2/2 errno_t (p: TBD)

- K.3.3/2 rsize_t (p: TBD)

- K.3.4/2 RSIZE_MAX (p: TBD)

- 7.31.3 Errors <errno.h> (p: TBD)

- 7.31.10 Integer types <stdint.h> (p: TBD)

- 7.31.11 Input/output <stdio.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.2 Diagnostics <assert.h> (p: TBD)

- 7.5 Errors <errno.h> (p: TBD)

- 7.19 Common definitions <stddef.h> (p: TBD)

- 7.20 Integer types <stdint.h> (p: TBD)

- 7.21 Input/output <stdio.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- K.3.1.3 Use of errno (p: TBD)

- K.3.2/2 errno_t (p: TBD)

- K.3.3/2 rsize_t (p: TBD)

- K.3.4/2 RSIZE_MAX (p: TBD)

- 7.31.3 Errors <errno.h> (p: TBD)

- 7.31.10 Integer types <stdint.h> (p: TBD)

- 7.31.11 Input/output <stdio.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- C11 standard (ISO/IEC 9899:2011):

- 7.2 Diagnostics <assert.h> (p: 186-187)

- 7.5 Errors <errno.h> (p: 205)

- 7.19 Common definitions <stddef.h> (p: 288)

- 7.20 Integer types <stdint.h> (p: 289-295)

- 7.21 Input/output <stdio.h> (p: 296-339)

- 7.22 General utilities <stdlib.h> (p: 340-360)

- K.3.1.3 Use of errno (p: 584)

- K.3.2/2 errno_t (p: 585)

- K.3.3/2 rsize_t (p: 585)

- K.3.4/2 RSIZE_MAX (p: 585)

- 7.31.3 Errors <errno.h> (p: 455)

- 7.31.10 Integer types <stdint.h> (p: 456)

- 7.31.11 Input/output <stdio.h> (p: 456)

- 7.31.12 General utilities <stdlib.h> (p: 456)

- C99 standard (ISO/IEC 9899:1999):

- 7.2 Diagnostics <assert.h> (p: 169)

- 7.5 Errors <errno.h> (p: 186)

- 7.26.3 Errors <errno.h> (p: 401)

- 7.26.8 Integer types <stdint.h> (p: 401)

- 7.26.9 Input/output <stdio.h> (p: 402)

- 7.26.10 General utilities <stdlib.h> (p: 402)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.2 DIAGNOSTICS <assert.h>

- 4.1.3 Errors <errno.h>

- 4.13.1 Errors <errno.h>

- 4.13.6 Input/output <stdio.h>

- 4.13.7 General utilities <stdlib.h>

### See also

math_errhandlingMATH_ERRNOMATH_ERREXCEPT
(C99)(C99)(C99)
|   | defines the error handling mechanism used by the common mathematical functions
(macro constant)   |

C++ documentation for Error handling

---
來源頁路徑：`en.cppreference.com/c/error.html`

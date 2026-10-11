# C 標準函式庫標頭檔

> 來源：cppreference C 語言參考文件（離線轉換版）。

C 標準函式庫的介面由下列標頭檔提供。

| <assert.h>  |   | 依條件編譯的巨集，用來檢查引數是否為零  |

| <complex.h> (since C99)  |   | 複數運算  |

| <ctype.h>  |   | 判斷字元資料所含字元類別的函式  |

| <errno.h>  |   | 回報錯誤狀況的巨集  |

| <fenv.h> (since C99)  |   | 浮點環境  |

| <float.h>  |   | 浮點型別的範圍與精度限制  |

| <inttypes.h> (since C99)  |   | 整數型別的格式化輸入與輸出  |

| <iso646.h> (since C95)  |   | 運算子的替代拼法  |

| <limits.h>  |   | 整數型別的範圍限制  |

| <locale.h>  |   | 地區設定相關工具  |

| <math.h>  |   | 常用數學函式  |

| <setjmp.h>  |   | 非區域跳轉  |

| <signal.h>  |   | 訊號處理  |

| <stdalign.h> (since C11)(deprecated in C23)  |   | `alignas` 與 `alignof` 的便利巨集  |

| <stdarg.h>  |   | 可變引數處理  |

| <stdatomic.h> (since C11)  |   | 原子操作  |

| <stdbit.h> (since C23)  |   | 操作型別之位元組與位元表示的巨集  |

| <stdbool.h> (since C99)(deprecated in C23)  |   | 布林型別相關巨集  |

| <stdckdint.h> (since C23)  |   | 執行整數溢位檢查的巨集  |

| <stddef.h>  |   | 常用型別與巨集定義  |

| <stdint.h> (since C99)  |   | 固定寬度整數型別  |

| <stdio.h>  |   | 標準輸入與輸出  |

| <stdlib.h>  |   | 通用工具：記憶體管理、程式控制、字串轉換、亂數與搜尋排序  |

| <stdmchar.h> (since C29)  |   | 文字轉碼  |

| <stdnoreturn.h> (since C11)(deprecated in C23)  |   | `noreturn` 的便利巨集  |

| <string.h>  |   | 字串處理  |

| <tgmath.h> (since C99)  |   | 型別通用數學（包裝 `<math.h>` 與 `<complex.h>` 函式的巨集）  |

| <threads.h> (since C11)  |   | 執行緒函式庫  |

| <time.h>  |   | 日期與時間工具  |

| <uchar.h> (since C11)  |   | UTF-16 與 UTF-32 字元工具  |

| <wchar.h> (since C95)  |   | 多位元組字元與寬字元工具  |

| <wctype.h> (since C95)  |   | 判斷寬字元資料中字元類別的函式  |

### Feature test macros (since C23)
特性測試宏（自 C23 起）

Feature test macros are defined in corresponding headers respectively since C23. Note that not all headers contain such a macro.
自 C23 起，特性測試宏分別定義在相應的標頭檔中。請注意，並非所有標頭檔都包含這樣的宏。

| #  |   | Header  |   | Macro name  |   | Value  |

| 1  |   | <assert.h>  |   | `__STDC_VERSION_ASSERT_H__`  |   | `202311L`  |

| 2  |   | <complex.h>  |   | `__STDC_VERSION_COMPLEX_H__`  |   | `202311L`  |

| 3  |   | <ctype.h>  |   | N/A  |

| 4  |   | <errno.h>  |   | N/A  |

| 5  |   | <fenv.h>  |   | `__STDC_VERSION_FENV_H__`  |   | `202311L`  |

| 6  |   | <float.h>  |   | `__STDC_VERSION_FLOAT_H__`  |   | `202311L`  |

| 7  |   | <inttypes.h>  |   | `__STDC_VERSION_INTTYPES_H__`  |   | `202311L`  |

| 8  |   | <iso646.h>  |   | N/A  |

| 9  |   | <limits.h>  |   | `__STDC_VERSION_LIMITS_H__`  |   | `202311L`  |

| 10  |   | <locale.h>  |   | N/A  |

| 11  |   | <math.h>  |   | `__STDC_VERSION_MATH_H__`  |   | `202311L`  |

| 12  |   | <setjmp.h>  |   | `__STDC_VERSION_SETJMP_H__`  |   | `202311L`  |

| 13  |   | <signal.h>  |   | N/A  |

| 14  |   | <stdalign.h>  |   | N/A  |

| 15  |   | <stdarg.h>  |   | `__STDC_VERSION_STDARG_H__`  |   | `202311L`  |

| 16  |   | <stdatomic.h>  |   | `__STDC_VERSION_STDATOMIC_H__`  |   | `202311L`  |

| 17  |   | <stdbit.h>  |   | `__STDC_VERSION_STDBIT_H__`  |   | `202311L`  |

| 18  |   | <stdbool.h>  |   | N/A  |

| 19  |   | <stdckdint.h>  |   | `__STDC_VERSION_STDCKDINT_H__`  |   | `202311L`  |

| 20  |   | <stddef.h>  |   | `__STDC_VERSION_STDDEF_H__`  |   | `202311L`  |

| 21  |   | <stdint.h>  |   | `__STDC_VERSION_STDINT_H__`  |   | `202311L`  |

| 22  |   | <stdio.h>  |   | `__STDC_VERSION_STDIO_H__`  |   | `202311L`  |

| 23  |   | <stdlib.h>  |   | `__STDC_VERSION_STDLIB_H__`  |   | `202311L`  |

| 24  |   | <stdmchar.h>  |   | `__STDC_VERSION_STDMCHAR_H__`  |   | `2029??L`  |

| 25  |   | <stdnoreturn.h>  |   | N/A  |

| 26  |   | <string.h>  |   | `__STDC_VERSION_STRING_H__`  |   | `202311L`  |

| 27  |   | <tgmath.h>  |   | `__STDC_VERSION_TGMATH_H__`  |   | `202311L`  |

| 28  |   | <threads.h>  |   | N/A  |

| 29  |   | <time.h>  |   | `__STDC_VERSION_TIME_H__`  |   | `202311L`  |

| 30  |   | <uchar.h>  |   | `__STDC_VERSION_UCHAR_H__`  |   | `202311L`  |

| 31  |   | <wchar.h>  |   | `__STDC_VERSION_WCHAR_H__`  |   | `202311L`  |

| 32  |   | <wctype.h>  |   | N/A  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.1.2 Standard headers
7.1.2 標準標頭檔
7.1.2 標準標頭檔

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.1.2 Standard headers (p: 131-132)
7.1.2 標準標頭檔（頁：131-132）
7.1.2 標準標頭檔（頁：131-132）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.1.2 Standard headers (p: 181-182)
7.1.2 標準標頭檔（頁：181-182）
7.1.2 標準標頭檔（頁：181-182）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.1.2 Standard headers (p: 165)
7.1.2 標準標頭檔（頁：165）
7.1.2 標準標頭檔（頁：165）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.2 Standard headers
4.1.2 標準標頭檔
4.1.2 標準標頭檔

### See also

C++ documentation for C++ Standard Library headers

---
來源頁路徑：`en.cppreference.com/c/header.html`

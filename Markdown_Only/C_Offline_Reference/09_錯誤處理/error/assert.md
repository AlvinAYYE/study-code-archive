# assert

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<assert.h>`
|   |  |   |  |

```c
#ifdef NDEBUG #define assert(condition) ((void)0) #else #define assert(condition) /*implementation defined*/ #endif
```
|   |   |   | (until C23) |

```c
#ifdef NDEBUG #define assert(...) ((void)0) #else #define assert(...) /*implementation defined*/ #endif
```
|   |   |   | (since C23) |

|  |  |  |  |

The definition of the macro `assert` depends on another macro, `NDEBUG`, which is not defined by the standard library.
宏 assert 的定義依賴於另一個宏 NDEBUG ，後者不由標準函式庫定義。
If `NDEBUG` is defined as a macro name at the point in the source code where <assert.h> is included, then `assert` does nothing.
若在原始碼引入 <assert.h> 的位置已定義 NDEBUG，assert 就不會執行任何動作。
If `NDEBUG` is not defined, then `assert` checks if its argument(until C23)the expression synthesized from `__VA_ARGS__`(since C23) (which must have scalar type, otherwise, the behavior is undefined) compares equal to zero. If it does, `assert` outputs implementation-specific diagnostic information on the standard error output and calls `abort()`. The diagnostic information is required to include the text of `expression`, as well as the values of  the predefined variable `__func__` and of(since C99) the predefined macros `__FILE__` and `__LINE__`.
若未定義 NDEBUG，assert 會檢查參數（C23 以前）或由 __VA_ARGS__ 組成的運算式（自 C23 起）是否為 0；該運算式必須是純量型別，否則行為未定義。若結果為 0，assert 會將實作定義的診斷訊息輸出至標準錯誤，然後呼叫 abort()。訊息必須包含 expression 的文字、預先定義變數 __func__ 的值，以及自 C99 起的預先定義巨集 __FILE__ 和 __LINE__ 的值。

### Parameters

| condition  |   | -  |   | expression of scalar type  |

### Return value

(none)

### Notes

There is no standardized interface to add an additional message to `assert` errors. A portable way to include one is to use a comma operator, or use `&&` with a string literal:
沒有標準化的介面可以為 assert 錯誤附加額外訊息。一種可移植的做法是使用逗號運運算元，或對字串字面量使用 && ：

```c
assert(("There are five lights", 2 + 2 == 5)); assert(2 + 2 == 5 && "There are five lights");
```

The implementation of `assert` in Microsoft CRT does not conform to C99 and later revisions, because its underlying function (`_wassert`) takes neither `__func__` nor an equivalent replacement.
Microsoft CRT 中 assert 的實現不符合 C99 及其後續修訂版，因為其底層函式 ( _wassert ) 既不接受 __func__ ，也不接受等價的替代。
Even though the change of `assert` in C23 (N2829) is not a formal defect report, the C committee recommends implementations to backport the change to old modes.
儘管 C23 中 assert 的變更 ( N2829 ) 並非正式的缺陷報告，C 委員會仍建議各實現將該變更向後移植到舊的模式中。

### Example

Run this code

```c
#include <stdio.h> // uncomment to disable assert() // #define NDEBUG #include <assert.h> #include <math.h> #define TEST(...) __VA_ARGS__ int main(void) {  double x = -1.0;  assert(x >= 0.0);  printf("sqrt(x) = %f\n", sqrt(x));  assert(TEST(x >= 0.0));  return 0; }
```

Possible output:
可能的輸出：

```c
--- Output with NDEBUG not defined: --- a.out: main.cpp:10: main: Assertion `x >= 0.0' failed. --- Output with NDEBUG defined: --- sqrt(x) = -nan
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.2.2.1 The assert macro (p: 196)
7.2.2.1 assert 宏（頁：196）
7.2.2.1 assert 宏（頁：196）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.2.1.1 The assert macro (p: 135)
7.2.1.1 assert 宏（頁：135）
7.2.1.1 assert 宏（頁：135）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.2.1.1 The assert macro (p: 186-187)
7.2.1.1 assert 宏（頁：186-187）
7.2.1.1 assert 宏（頁：186-187）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.2.1.1 The assert macro (p: 169)
7.2.1.1 assert 宏（頁：169）
7.2.1.1 assert 宏（頁：169）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.2.1.1 The assert macro
4.2.1.1 assert 宏
4.2.1.1 assert 宏

### See also

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

C++ documentation for assert

---
來源頁路徑：`en.cppreference.com/c/error/assert.html`

# localeconv

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<locale.h>`
|   |  |   |  |

```c
struct lconv* localeconv(void);
```
|   |   |   |   |

|  |  |  |  |

The `localeconv` function obtains a pointer to a static object of type lconv, which represents numeric and monetary formatting rules of the current C locale.
localeconv 函式獲得一個指向 lconv 型別靜態物件的指標，該物件表示目前 C 區域設定的數值和貨幣格式化規則。

### Parameters

(none)

### Return value

pointer to the current lconv object.
指向目前 lconv 物件的指標。

### Notes

Modifying the object references through the returned pointer is undefined behavior.
透過傳回的指標修改所引用的物件屬於未定義行為。
`localeconv` modifies a static object, calling it from different threads without synchronization is undefined behavior.
localeconv 修改一個靜態物件，從不同執行緒在沒有同步的情況下呼叫它屬於未定義行為。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> int main(void) {  setlocale(LC_MONETARY, "en_IN.utf8");  struct lconv* lc = localeconv();  printf("Local Currency Symbol  : %s\n", lc->currency_symbol);  printf("International Currency Symbol: %s\n", lc->int_curr_symbol); }
```

Output:

```c
Local Currency Symbol  : ₹ International Currency Symbol: INR
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.11.2.1 The localeconv function (p: TBD)
7.11.2.1 localeconv 函式 (p: 待定)
7.11.2.1 localeconv 函式 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.11.2.1 The localeconv function (p: TBD)
7.11.2.1 localeconv 函式 (p: 待定)
7.11.2.1 localeconv 函式 (p: 待定)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.11.2.1 The localeconv function (p: 225-230)
7.11.2.1 localeconv 函式 (p: 225-230)
7.11.2.1 localeconv 函式 (p: 225-230)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.11.2.1 The localeconv function (p: 206-211)
7.11.2.1 localeconv 函式 (p: 206-211)
7.11.2.1 localeconv 函式 (p: 206-211)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.4.2.1 The localeconv function
4.4.2.1 localeconv 函式
4.4.2.1 localeconv 函式

### See also

setlocale
|   | gets and sets the current C locale
(function)   |

lconv
|   | formatting details, returned by localeconv
(struct)  |

C++ documentation for localeconv

---
來源頁路徑：`en.cppreference.com/c/locale/localeconv.html`

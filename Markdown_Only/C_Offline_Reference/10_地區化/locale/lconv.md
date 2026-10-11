# lconv

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<locale.h>`
|   |  |   |  |

```c
struct lconv;
```
|   |   |   |   |

|  |  |  |  |

The struct `lconv` contains numeric and monetary formatting rules as defined by a C locale. Objects of this struct may be obtained with localeconv. The members of `lconv` are values of type `char` and of type `char*`. Each `char*` member except `decimal_point` may be pointing at a null character (that is, at an empty C-string). The members of type `char` are all non-negative numbers, any of which may be CHAR_MAX if the corresponding value is not available in the current C locale.
struct lconv 包含由 C 區域設定定義的數值和貨幣格式化規則。該 struct 的物件可以透過 localeconv 獲得。lconv 的成員是 char 型別和 char * 型別的值。除 decimal_point 之外的每個 char * 成員都可能指向一個空字元（即指向一個空 C 字串）。char 型別的成員全都是非負數，如果對應的值在目前 C 區域設定中不可用，則其中任何一個都可能是 CHAR_MAX。

### Member objects

#### Non-monetary numeric formatting parameters

char* decimal_point
|   | the character used as the decimal point
(public member object)  |

char* thousands_sep
|   | the character used to separate groups of digits before the decimal point
(public member object)  |

char* grouping
|   | a string whose elements indicate the sizes of digit groups
(public member object)  |

#### Monetary numeric formatting parameters

char* mon_decimal_point
|   | the character used as the decimal point
(public member object)  |

char* mon_thousands_sep
|   | the character used to separate groups of digits before the decimal point
(public member object)  |

char* mon_grouping
|   | a string whose elements indicate the sizes of digit groups
(public member object)  |

char* positive_sign
|   | a string used to indicate non-negative monetary quantity
(public member object)  |

char* negative_sign
|   | a string used to indicate negative monetary quantity
(public member object)  |

#### Local monetary numeric formatting parameters

char* currency_symbol
|   | the symbol used for currency in the current C locale
(public member object)  |

char frac_digits
|   | the number of digits after the decimal point to display in a monetary quantity
(public member object)  |

char p_cs_precedes
|   | `1` if `currency_symbol` is placed before non-negative value, `0` if after
(public member object)  |

char n_cs_precedes
|   | `1` if `currency_symbol` is placed before negative value, `0` if after
(public member object)  |

char p_sep_by_space
|   | indicates the separation of `currency_symbol`, `positive_sign`, and the non-negative monetary value
(public member object)  |

char n_sep_by_space
|   | indicates the separation of `currency_symbol`, `negative_sign`, and the negative monetary value
(public member object)  |

char p_sign_posn
|   | indicates the position of `positive_sign` in a non-negative monetary value
(public member object)  |

char n_sign_posn
|   | indicates the position of `negative_sign` in a negative monetary value
(public member object)  |

#### International monetary numeric formatting parameters

char* int_curr_symbol
|   | the string used as international currency name in the current C locale
(public member object)  |

char int_frac_digits
|   | the number of digits after the decimal point to display in an international monetary quantity
(public member object)  |

char int_p_cs_precedes
(C99)
|   | `1` if `int_curr_symbol` is placed before non-negative international monetary value, `0` if after
(public member object)  |

char int_n_cs_precedes
(C99)
|   | `1` if `int_curr_symbol` is placed before negative international monetary value, `0` if after
(public member object)  |

char int_p_sep_by_space
(C99)
|   | indicates the separation of `int_curr_symbol`, `positive_sign`, and the non-negative international monetary value
(public member object)  |

char int_n_sep_by_space
(C99)
|   | indicates the separation of `int_curr_symbol`, `negative_sign`, and the negative international monetary value
(public member object)  |

char int_p_sign_posn
(C99)
|   | indicates the position of `positive_sign` in a non-negative international monetary value
(public member object)  |

char int_n_sign_posn
(C99)
|   | indicates the position of `negative_sign` in a negative international monetary value
(public member object)  |

The characters of the C-strings pointed to by `grouping` and `mon_grouping` are interpreted according to their numeric values. When the terminating `'\0'` is encountered, the last value seen is assumed to repeat for the remainder of digits. If CHAR_MAX is encountered, no further digits are grouped. The typical grouping of three digits at a time is `"\003"`.
grouping 和 mon_grouping 所指向的 C 字串中的字元根據其數值來解釋。當遇到終止的 '\0' 時，假定最後看到的值對剩餘的數字重複。如果遇到 CHAR_MAX，則不再對數字進行分組。典型的每三位一組的分組方式是 " \003 "。
The values of `p_sep_by_space`, `n_sep_by_space`, `int_p_sep_by_space`, `int_n_sep_by_space` are interpreted as follows:
p_sep_by_space、n_sep_by_space、int_p_sep_by_space、int_n_sep_by_space 的值解釋如下：

| `0`  |   | no space separates the currency symbol and the value  |

| `1`  |   | sign sticks to the currency symbol, value is separated by a space  |

| `2`  |   | sign sticks to the value. Currency symbol is separated by a space  |

The values of `p_sign_posn`, `n_sign_posn`, `int_p_sign_posn`, `int_n_sign_posn` are interpreted as follows:
p_sign_posn、n_sign_posn、int_p_sign_posn、int_n_sign_posn 的值解釋如下：

| `0`  |   | parentheses around the value and the currency symbol are used to represent the sign  |

| `1`  |   | sign before the value and the currency symbol  |

| `2`  |   | sign after the value and the currency symbol  |

| `3`  |   | sign before the currency symbol  |

| `4`  |   | sign after the currency symbol  |

### Example

Run this code

```c
#include <locale.h> #include <stdio.h>   int main(void) {  setlocale(LC_ALL, "ja_JP.UTF-8");  struct lconv* lc = localeconv();  printf("Japanese currency symbol: %s(%s)\n", lc->currency_symbol, lc->int_curr_symbol); }
```

Possible output:
可能的輸出：

```c
Japanese currency symbol: ￥(JPY )
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.11/2 Localization <locale.h> (p: TBD)
7.11/2 本地化 <locale.h> (p: 待定)
7.11/2 本地化 <locale.h> (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.11/2 Localization <locale.h> (p: TBD)
7.11/2 本地化 <locale.h> (p: 待定)
7.11/2 本地化 <locale.h> (p: 待定)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.11/2 Localization <locale.h> (p: 223)
7.11/2 本地化 <locale.h> (p: 223)
7.11/2 本地化 <locale.h> (p: 223)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.11/2 Localization <locale.h> (p: 204)
7.11/2 本地化 <locale.h> (p: 204)
7.11/2 本地化 <locale.h> (p: 204)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.4 LOCALIZATION <locale.h>
4.4 本地化 <locale.h>
4.4 本地化 <locale.h>

### See also

localeconv
|   | queries numeric and monetary formatting details of the current locale
(function)   |

C++ documentation for lconv

---
來源頁路徑：`en.cppreference.com/c/locale/lconv.html`

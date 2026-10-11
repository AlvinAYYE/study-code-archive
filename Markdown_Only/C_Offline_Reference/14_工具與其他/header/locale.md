# Standard library header <locale.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the localization library.
該標頭檔是本地化庫的一部分。

### Types

lconv
|   | formatting details, returned by localeconv
(struct)  |

### Constants

NULL
|   | implementation-defined null pointer constant
(macro constant)   |

LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME
|   | locale categories for setlocale
(macro constant)   |

### Functions

setlocale
|   | gets and sets the current C locale
(function)   |

localeconv
|   | queries numeric and monetary formatting details of the current locale
(function)   |

### Synopsis

```c
// In the "C" locale, the members shall have the values specified in the comments: struct lconv {  char* decimal_point; // "."  char* thousands_sep; // ""  char* grouping; // ""  char* mon_decimal_point; // ""  char* mon_thousands_sep; // ""  char* mon_grouping; // ""  char* positive_sign; // ""  char* negative_sign; // ""  char* currency_symbol; // ""  char frac_digits; // CHAR_MAX  char p_cs_precedes; // CHAR_MAX  char n_cs_precedes; // CHAR_MAX  char p_sep_by_space; // CHAR_MAX  char n_sep_by_space; // CHAR_MAX  char p_sign_posn; // CHAR_MAX  char n_sign_posn; // CHAR_MAX  char* int_curr_symbol; // ""  char int_frac_digits; // CHAR_MAX  char int_p_cs_precedes; // CHAR_MAX  char int_n_cs_precedes; // CHAR_MAX  char int_p_sep_by_space; // CHAR_MAX  char int_n_sep_by_space; // CHAR_MAX  char int_p_sign_posn; // CHAR_MAX  char int_n_sign_posn; // CHAR_MAX }; char* setlocale(int category, const char* locale); lconv* localeconv(); #define NULL /* see description */ #define LC_ALL /* see description */ #define LC_COLLATE /* see description */ #define LC_CTYPE /* see description */ #define LC_MONETARY /* see description */ #define LC_NUMERIC /* see description */ #define LC_TIME /* see description */
```

### Notes

- NULL is also defined in the following headers:
- <string.h>

- <time.h>

- <stddef.h>

- <stdio.h>

- <wchar.h>
NULL 也定義於下列標頭檔：<string.h>、<time.h>、<stddef.h>、<stdio.h>、<wchar.h>

---
來源頁路徑：`en.cppreference.com/c/header/locale.html`

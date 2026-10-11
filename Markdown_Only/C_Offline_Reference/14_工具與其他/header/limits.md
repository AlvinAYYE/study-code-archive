# Standard library header <limits.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the type support library, in particular it's part of the C numeric limits interface.
該標頭檔是型別支援庫的一部分，特別是它是 C 數值極限介面的一部分。

#####  Limits of core language integer types

BOOL_WIDTH
(C23)
|   | bit width of `bool`
(macro constant)   |

BOOL_MAX
(C29)
|   | maximum value of `_Bool`
(macro constant)  |

CHAR_BIT
|   | bit width of byte
(macro constant)   |

MB_LEN_MAX
|   | maximum number of bytes in a multibyte character
(macro constant)   |

CHAR_WIDTH
(C23)
|   | bit width of `char`
(macro constant)   |

CHAR_MIN
|   | minimum value of `char`
(macro constant)   |

CHAR_MAX
|   | maximum value of `char`
(macro constant)   |

SCHAR_WIDTHSHRT_WIDTHINT_WIDTHLONG_WIDTHLLONG_WIDTH
(C23)(C23)(C23)(C23)(C23)
|   | bit width of `signed char`, `short`, `int`, `long`, and `long long` respectively
(macro constant)   |

SCHAR_MINSHRT_MININT_MINLONG_MINLLONG_MIN
(C99)
|   | minimum value of `signed char`, `short`, `int`, `long` and `long long` respectively
(macro constant)   |

SCHAR_MAXSHRT_MAXINT_MAXLONG_MAXLLONG_MAX
(C99)
|   | maximum value of `signed char`, `short`, `int`, `long` and `long long` respectively
(macro constant)   |

UCHAR_WIDTHUSHRT_WIDTHUINT_WIDTHULONG_WIDTHULLONG_WIDTH
(C23)(C23)(C23)(C23)(C23)
|   | bit width of `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long`, and `unsigned long long` respectively
(macro constant)   |

UCHAR_MAXUSHRT_MAXUINT_MAXULONG_MAXULLONG_MAX
(C99)
|   | maximum value of `unsigned char`, `unsigned short`, `unsigned int`,
`unsigned long` and `unsigned long long` respectively
(macro constant)   |

BITINT_MAXWIDTH
(C23)
|   | maximum width `N` supported by the declaration of a bit-precise integer in the type specifier `_BitInt(N)`, greater than or equal to `ULLONG_WIDTH`
(macro constant)  |

### Synopsis

```c
#define __STDC_VERSION_LIMITS_H__ 202311L #define BITINT_MAXWIDTH /* see description */ #define BOOL_MAX /* see description */ #define BOOL_WIDTH /* see description */ #define CHAR_BIT /* see description */ #define CHAR_MAX /* see description */ #define CHAR_MIN /* see description */ #define CHAR_WIDTH /* see description */ #define INT_MAX /* see description */ #define INT_MIN /* see description */ #define INT_WIDTH /* see description */ #define LLONG_MAX /* see description */ #define LLONG_MIN /* see description */ #define LLONG_WIDTH /* see description */ #define LONG_MAX /* see description */ #define LONG_MIN /* see description */ #define LONG_WIDTH /* see description */ #define MB_LEN_MAX /* see description */ #define SCHAR_MAX /* see description */ #define SCHAR_MIN /* see description */ #define SCHAR_WIDTH /* see description */ #define SHRT_MAX /* see description */ #define SHRT_MIN /* see description */ #define SHRT_WIDTH /* see description */ #define UCHAR_MAX /* see description */ #define UCHAR_WIDTH /* see description */ #define UINT_MAX /* see description */ #define UINT_WIDTH /* see description */ #define ULLONG_MAX /* see description */ #define ULLONG_WIDTH /* see description */ #define ULONG_MAX /* see description */ #define ULONG_WIDTH /* see description */ #define USHRT_MAX /* see description */ #define USHRT_WIDTH /* see description */
```

---
來源頁路徑：`en.cppreference.com/c/header/limits.html`

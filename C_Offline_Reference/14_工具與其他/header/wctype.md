# Standard library header <wctype.h> (C95)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of wide character classification and mapping utilities library.
該標頭檔是寬字元分類和對映實用工具庫的一部分。

### Functions

#####  Character classification

iswalnum
(C95)
|   | checks if a wide character is alphanumeric
(function)   |

iswalpha
(C95)
|   | checks if a wide character is alphabetic
(function)   |

iswlower
(C95)
|   | checks if a wide character is an lowercase character
(function)   |

iswupper
(C95)
|   | checks if a wide character is an uppercase character
(function)   |

iswdigit
(C95)
|   | checks if a wide character is a digit
(function)   |

iswxdigit
(C95)
|   | checks if a wide character is a hexadecimal character
(function)   |

iswcntrl
(C95)
|   | checks if a wide character is a control character
(function)   |

iswgraph
(C95)
|   | checks if a wide character is a graphical character
(function)   |

iswspace
(C95)
|   | checks if a wide character is a space character
(function)   |

iswblank
(C99)
|   | checks if a wide character is a blank character
(function)   |

iswprint
(C95)
|   | checks if a wide character is a printing character
(function)   |

iswpunct
(C95)
|   | checks if a wide character is a punctuation character
(function)   |

iswctype
(C95)
|   | classifies a wide character according to the specified LC_CTYPE category
(function)   |

wctype
(C95)
|   | looks up a character classification category in the current C locale
(function)   |

#####  Character manipulation

towlower
(C95)
|   | converts a wide character to lowercase
(function)   |

towupper
(C95)
|   | converts a wide character to uppercase
(function)   |

towctrans
(C95)
|   | performs character mapping according to the specified LC_CTYPE mapping category
(function)   |

wctrans
(C95)
|   | looks up a character mapping category in the current C locale
(function)   |

### Types

wint_t
(C95)
|   | integer type that can hold any valid wide character and at least one more value
(typedef)  |

wctrans_t
(C95)
|   | scalar type that holds locale-specific character mapping
(typedef)  |

wctype_t
(C95)
|   | scalar type that holds locale-specific character classification
(typedef)  |

### Macros

WEOF
(C95)
|   | a non-character value of type wint_t used to indicate errors
(macro constant)  |

### Synopsis

```c
typedef /* see description */ wctrans_t; typedef /* see description */ wctype_t; typedef /* see description */ wint_t; #define WEOF /* see description */ int iswalnum(wint_t wc); int iswalpha(wint_t wc); int iswblank(wint_t wc); int iswcntrl(wint_t wc); int iswdigit(wint_t wc); int iswgraph(wint_t wc); int iswlower(wint_t wc); int iswprint(wint_t wc); int iswpunct(wint_t wc); int iswspace(wint_t wc); int iswupper(wint_t wc); int iswxdigit(wint_t wc); int iswctype(wint_t wc, wctype_t desc); wctype_t wctype(const char* property); wint_t towlower(wint_t wc); wint_t towupper(wint_t wc); wint_t towctrans(wint_t wc, wctrans_t desc); wctrans_t wctrans(const char* property);
```

---
來源頁路徑：`en.cppreference.com/c/header/wctype.html`

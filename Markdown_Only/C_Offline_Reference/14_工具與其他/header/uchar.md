# Standard library header <uchar.h> (C11)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of null-terminated multibyte strings library.
該標頭檔是以空字元結尾的多位元組字串庫的一部分。

### Functions

mbrtoc8
(C23)
|   | converts a narrow multibyte character to UTF-8 encoding
(function)   |

c8rtomb
(C23)
|   | converts UTF-8 string to narrow multibyte encoding
(function)   |

mbrtoc16
(C11)
|   | converts a narrow multibyte character to UTF-16 encoding
(function)   |

c16rtomb
(C11)
|   | converts a UTF-16 character to narrow multibyte encoding
(function)   |

mbrtoc32
(C11)
|   | converts a narrow multibyte character to UTF-32 encoding
(function)   |

c32rtomb
(C11)
|   | converts a UTF-32 character to narrow multibyte encoding
(function)   |

### Types

mbstate_t
(C95)
|   | conversion state information necessary to iterate multibyte character strings
(class)   |

char8_t
(C23)
|   | 8-bit character type
(typedef)   |

char16_t
(C11)
|   | 16-bit character type
(typedef)   |

char32_t
(C11)
|   | 32-bit character type
(typedef)   |

### Synopsis

```c
#define __STDC_VERSION_UCHAR_H__ 202311L typedef /* see description */ mbstate_t; typedef /* see description */ size_t; typedef /* see description */ char8_t; typedef /* see description */ char16_t; typedef /* see description */ char32_t; size_t mbrtoc8(char8_t* restrict pc8, const char* restrict s, size_t n,  mbstate_t* restrict ps); size_t c8rtomb(char* restrict s, char8_t c8, mbstate_t* restrict ps); size_t mbrtoc16(char16_t* restrict pc16, const char* restrict s, size_t n,  mbstate_t* restrict ps); size_t c16rtomb(char* restrict s, char16_t c16, mbstate_t* restrict ps); size_t mbrtoc32(char32_t* restrict pc32, const char* restrict s, size_t n,  mbstate_t* restrict ps); size_t c32rtomb(char* restrict s, char32_t c32, mbstate_t* restrict ps);
```

---
來源頁路徑：`en.cppreference.com/c/header/uchar.html`

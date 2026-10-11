# Standard library header <wchar.h> (C95)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of null-terminated wide strings library.
該標頭檔是以空字元結尾的寬字串庫的一部分。

### Functions

#####  Conversions to numeric formats

wcstolwcstoll
(C95)(C99)
|   | converts a wide string to an integer value
(function)   |

wcstoulwcstoull
(C95)(C99)
|   | converts a wide string to an unsigned integer value
(function)   |

wcstofwcstodwcstold
(C99)(C95)(C99)
|   | converts a wide string to a floating-point value
(function)   |

#####  String manipulation

wcscpywcscpy_s
(C95)(C11)
|   | copies one wide string to another
(function)   |

wcsncpywcsncpy_s
(C95)(C11)
|   | copies a certain amount of wide characters from one string to another
(function)   |

wcscatwcscat_s
(C95)(C11)
|   | appends a copy of one wide string to another
(function)   |

wcsncatwcsncat_s
(C95)(C11)
|   | appends a certain amount of wide characters from one wide string to another
(function)   |

wcsxfrm
(C95)
|   | transform a wide string so that wcscmp would produce the same result as wcscoll
(function)   |

#####  String examination

wcslenwcsnlen_s
(C95)(C11)
|   | returns the length of a wide string
(function)   |

wcscmp
(C95)
|   | compares two wide strings
(function)   |

wcsncmp
(C95)
|   | compares a certain amount of characters from two wide strings
(function)   |

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

wcschr
(C95)
|   | finds the first occurrence of a wide character in a wide string
(function)   |

wcsrchr
(C95)
|   | finds the last occurrence of a wide character in a wide string
(function)   |

wcsspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide characters found in another wide string
(function)   |

wcscspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide chars *not* found in another wide string
(function)   |

wcspbrk
(C95)
|   | finds the first location of any wide character in one wide string, in another wide string
(function)   |

wcsstr
(C95)
|   | finds the first occurrence of a wide string within another wide string
(function)   |

wcstokwcstok_s
(C95)(C11)
|   | finds the next token in a wide string
(function)   |

#####  Wide character array manipulation

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

wmemmovewmemmove_s
(C95)(C11)
|   | copies a certain amount of wide characters between two, possibly overlapping, arrays
(function)   |

wmemcmp
(C95)
|   | compares a certain amount of wide characters from two arrays
(function)   |

wmemchr
(C95)
|   | finds the first occurrence of a wide character in a wide character array
(function)   |

wmemset
(C95)
|   | copies the given wide character to every position in a wide character array
(function)   |

### Types

wchar_t
|   | integer type that can hold any valid wide character
(typedef)  |

wint_t
(C95)
|   | integer type that can hold any valid wide character and at least one more value
(typedef)  |

### Macros

WEOF
(C95)
|   | a non-character value of type wint_t used to indicate errors
(macro constant)  |

WCHAR_WIDTH
(C23)
|   | bit width of `wchar_t`
(macro constant)   |

WCHAR_MIN
|   | minimum value of `wchar_t`
(macro constant)   |

WCHAR_MAX
|   | maximum value of `wchar_t`
(macro constant)   |

### Synopsis

```c
#define __STDC_VERSION_WCHAR_H__ 202311L typedef /* see description */ wchar_t; typedef /* see description */ size_t; typedef /* see description */ mbstate_t; typedef /* see description */ wint_t; struct tm { /* see description */ }; #define MB_UTF16 /* see description */ #define MB_UTF32 /* see description */ #define MB_UTF8 /* see description */ #define NULL /* see description */ #define WCHAR_MAX /* see description */ #define WCHAR_MIN /* see description */ #define WCHAR_UTF16 /* see description */ #define WCHAR_UTF32 /* see description */ #define WCHAR_UTF8 /* see description */ #define WCHAR_WIDTH /* see description */ #define WEOF /* see description */ int fwprintf(FILE* restrict stream, const wchar_t* restrict format, ...); int fwscanf(FILE* restrict stream, const wchar_t* restrict format, ...); int swprintf(wchar_t* restrict s, size_t n, const wchar_t* restrict format, ...); int swscanf(const wchar_t* restrict s, const wchar_t* restrict format, ...); int vfwprintf(FILE* restrict stream, const wchar_t* restrict format, va_list arg); int vfwscanf(FILE* restrict stream, const wchar_t* restrict format, va_list arg); int vswprintf(wchar_t* restrict s, size_t n, const wchar_t* restrict format,  va_list arg); int vswscanf(const wchar_t* restrict s, const wchar_t* restrict format, va_list arg); int vwprintf(const wchar_t* restrict format, va_list arg); int vwscanf(const wchar_t* restrict format, va_list arg); int wprintf(const wchar_t* restrict format, ...); int wscanf(const wchar_t* restrict format, ...); wint_t fgetwc(FILE* stream); wchar_t* fgetws(wchar_t* restrict s, int n, FILE* restrict stream); wint_t fputwc(wchar_t c, FILE* stream); int fputws(const wchar_t* restrict s, FILE* restrict stream); int fwide(FILE* stream, int mode); wint_t getwc(FILE* stream); wint_t getwchar(void); wint_t putwc(wchar_t c, FILE* stream); wint_t putwchar(wchar_t c); wint_t ungetwc(wint_t c, FILE* stream); double wcstod(const wchar_t* restrict nptr, wchar_t** restrict endptr); float wcstof(const wchar_t* restrict nptr, wchar_t** restrict endptr); long double wcstold(const wchar_t* restrict nptr, wchar_t** restrict endptr); long int wcstol(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base); long long int wcstoll(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base); unsigned long int wcstoul(const wchar_t* restrict nptr, wchar_t** restrict endptr,  int base); unsigned long long int wcstoull(const wchar_t* restrict nptr, wchar_t** restrict endptr,  int base); wchar_t* wcscpy(wchar_t* restrict s1, const wchar_t* restrict s2); wchar_t* wcsncpy(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n); wchar_t* wmemcpy(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n); wchar_t* wmemmove(wchar_t* s1, const wchar_t* s2, size_t n); wchar_t* wcscat(wchar_t* restrict s1, const wchar_t* restrict s2); wchar_t* wcsncat(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n); int wcscmp(const wchar_t* s1, const wchar_t* s2); int wcscoll(const wchar_t* s1, const wchar_t* s2); int wcsncmp(const wchar_t* s1, const wchar_t* s2, size_t n); size_t wcsxfrm(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n); int wmemcmp(const wchar_t* s1, const wchar_t* s2, size_t n); /*QWchar_t*/* wcschr(/*QWchar_t*/* s, wchar_t c); size_t wcscspn(const wchar_t* s1, const wchar_t* s2); /*QWchar_t*/* wcspbrk(/*QWchar_t*/* s1, const wchar_t* s2); /*QWchar_t*/* wcsrchr(/*QWchar_t*/* s, wchar_t c); size_t wcsspn(const wchar_t* s1, const wchar_t* s2); /*QWchar_t*/* wcsstr(/*QWchar_t*/* s1, const wchar_t* s2); wchar_t* wcstok(wchar_t* restrict s1, const wchar_t* restrict s2,  wchar_t** restrict ptr); /*QWchar_t*/* wmemchr(/*QWchar_t*/* s, wchar_t c, size_t n); size_t wcslen(const wchar_t* s); size_t wcsnlen(const wchar_t* s, size_t n); wchar_t* wmemset(wchar_t* s, wchar_t c, size_t n); size_t wcsftime(wchar_t* restrict s, size_t maxsize, const wchar_t* restrict format,  const struct tm* restrict timeptr); wint_t btowc(int c); int wctob(wint_t c); int mbsinit(const mbstate_t* ps); size_t mbrlen(const char* restrict s, size_t n, mbstate_t* restrict ps); size_t mbrtowc(wchar_t* restrict pwc, const char* restrict s, size_t n,  mbstate_t* restrict ps); size_t wcrtomb(char* restrict s, wchar_t wc, mbstate_t* restrict ps); size_t mbsrtowcs(wchar_t* restrict dst, const char** restrict src, size_t len,  mbstate_t* restrict ps); size_t wcsrtombs(char* restrict dst, const wchar_t** restrict src, size_t len,  mbstate_t* restrict ps);
```

Only if the implementation defines `__STDC_IEC_60559_DFP__`:
僅當實現定義 __STDC_IEC_60559_DFP__ ：

```c
_Decimal32 wcstod32(const wchar_t* restrict nptr, wchar_t** restrict endptr); _Decimal64 wcstod64(const wchar_t* restrict nptr, wchar_t** restrict endptr); _Decimal128 wcstod128(const wchar_t* restrict nptr, wchar_t** restrict endptr);
```

Only if the implementation defines `__STDC_IEC_60559_TYPES__` and additionally the user code defines `__STDC_WANT_IEC_60559_TYPES_EXT__` before any inclusion of `<wchar.h>`:
僅當實現定義 __STDC_IEC_60559_TYPES__ ，且此外使用者程式碼 在包含 <wchar.h> 之前的任何位置定義 __STDC_WANT_IEC_60559_TYPES_EXT__ ：

```c
#ifdef __STDC_WANT_IEC_60559_TYPES_EXT__ /*_FloatN*/ /*wcstofN*/(const wchar_t* restrict nptr, wchar_t** restrict endptr); /*_FloatNx*/ /*wcstofNx*/(const wchar_t* restrict nptr, wchar_t** restrict endptr); /*_DecimalN*/ /*wcstodN*/(const wchar_t* restrict nptr, wchar_t** restrict endptr); /*_DecimalNx*/ /*wcstodNx*/(const wchar_t* restrict nptr, wchar_t** restrict endptr); void /*wcstoencfN*/(unsigned char encptr[restrict static N/8],  const wchar_t* restrict nptr, wchar_t** restrict endptr); void /*wcstoencdecdN*/(unsigned char encptr[restrict static N/8],  const wchar_t* restrict nptr, wchar_t** restrict endptr); void /*wcstoencbindN*/(unsigned char encptr[restrict static N/8],  const wchar_t* restrict nptr, wchar_t** restrict endptr); #endif
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<wchar.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者程式碼在包含 <wchar.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#ifdef __STDC_WANT_LIB_EXT1__ typedef /* see description */ errno_t; typedef /* see description */ rsize_t; int fwprintf_s(FILE* restrict stream, const wchar_t* restrict format, ...); int fwscanf_s(FILE* restrict stream, const wchar_t* restrict format, ...); int snwprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format, ...); int swprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format, ...); int swscanf_s(const wchar_t* restrict s, const wchar_t* restrict format, ...); int vfwprintf_s(FILE* restrict stream, const wchar_t* restrict format, va_list arg); int vfwscanf_s(FILE* restrict stream, const wchar_t* restrict format, va_list arg); int vsnwprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format,  va_list arg); int vswprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format,  va_list arg); int vswscanf_s(const wchar_t* restrict s, const wchar_t* restrict format, va_list arg); int vwprintf_s(const wchar_t* restrict format, va_list arg); int vwscanf_s(const wchar_t* restrict format, va_list arg); int wprintf_s(const wchar_t* restrict format, ...); int wscanf_s(const wchar_t* restrict format, ...); errno_t wcscpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2); errno_t wcsncpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,  rsize_t n); errno_t wmemcpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,  rsize_t n); errno_t wmemmove_s(wchar_t* s1, rsize_t s1max, const wchar_t* s2, rsize_t n); errno_t wcscat_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2); errno_t wcsncat_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,  rsize_t n); wchar_t* wcstok_s(wchar_t* restrict s1, rsize_t* restrict s1max,  const wchar_t* restrict s2, wchar_t** restrict ptr); size_t wcsnlen_s(const wchar_t* s, size_t maxsize); errno_t wcrtomb_s(size_t* restrict retval, char* restrict s, rsize_t smax, wchar_t wc,  mbstate_t* restrict ps); errno_t mbsrtowcs_s(size_t* restrict retval, wchar_t* restrict dst, rsize_t dstmax,  const char** restrict src, rsize_t len, mbstate_t* restrict ps); errno_t wcsrtombs_s(size_t* restrict retval, char* restrict dst, rsize_t dstmax,  const wchar_t** restrict src, rsize_t len, mbstate_t* restrict ps); #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/wchar.html`

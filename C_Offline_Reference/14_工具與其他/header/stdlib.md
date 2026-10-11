# Standard library header <stdlib.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is a part of program support utilities library, in particular, it provides functions for program termination, memory management, string conversions, random numbers generation. The header also provides some algorithms.
這個標頭檔屬於程式支援工具函式庫，提供程式終止、記憶體管理、字串轉換及亂數產生等函式，也提供部分演演演算法。

### Functions

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

exit
|   | causes normal program termination with cleaning up
(function)   |

quick_exit
(C11)
|   | causes normal program termination without completely cleaning up
(function)   |

_Exit
(C99)
|   | causes normal program termination without cleaning up
(function)   |

atexit
|   | registers a function to be called on exit() invocation
(function)   |

at_quick_exit
(C11)
|   | registers a function to be called on quick_exit invocation
(function)   |

EXIT_SUCCESSEXIT_FAILURE
|   | indicates program execution execution status
(macro constant)   |

|  | This section is incomplete
Reason: Add more from 7.24 General utilities <stdlib.h>  |

### Synopsis

|  | This section is incomplete
Reason: Add more from B.23 General utilities <stdlib.h>  |

```c
#define __STDC_VERSION_STDLIB_H__ 202311L // TODO: types and macros void call_once(once_flag* flag, void (*func)(void)); double atof(const char* nptr); int atoi(const char* nptr); long int atol(const char* nptr); long long int atoll(const char* nptr); int strfromd(char* restrict s, size_t n, const char* restrict format, double fp); int strfromf(char* restrict s, size_t n, const char* restrict format, float fp); int strfroml(char* restrict s, size_t n, const char* restrict format, long double fp); double strtod(const char* restrict nptr, char** restrict endptr); float strtof(const char* restrict nptr, char** restrict endptr); long double strtold(const char* restrict nptr, char** restrict endptr); long int strtol(const char* restrict nptr, char** restrict endptr, int base); long long int strtoll(const char* restrict nptr, char** restrict endptr, int base); unsigned long int strtoul(const char* restrict nptr, char** restrict endptr, int base); unsigned long long int strtoull(const char* restrict nptr,  char** restrict endptr, int base); int rand(void); void srand(unsigned int seed); void* aligned_alloc(size_t alignment, size_t size); void* calloc(size_t nmemb, size_t size); void free(void* ptr); void free_sized(void* ptr, size_t size); void free_aligned_sized(void* ptr, size_t alignment, size_t size); void* malloc(size_t size); void* realloc(void* ptr, size_t size); [[noreturn]] void abort(void); int atexit(void (*func)(void)); int at_quick_exit(void (*func)(void)); [[noreturn]] void exit(int status); [[noreturn]] void _Exit(int status); char* getenv(const char* name); [[noreturn]] void quick_exit(int status); int system(const char* string); QVoid* bsearch(const void* key, QVoid* base, size_t nmemb, size_t size,  int (*compar)(const void* , const void* )); void qsort(void* base, size_t nmemb, size_t size,  int (*compar)(const void* , const void* )); int abs(int j); long int labs(long int j); long long int llabs(long long int j); div_t div(int numer, int denom); ldiv_t ldiv(long int numer, long int denom); lldiv_t lldiv(long long int numer, long long int denom); int mblen(const char* s, size_t n); int mbtowc(wchar_t* restrict pwc, const char* restrict s, size_t n); int wctomb(char* s, wchar_t wc); size_t mbstowcs(wchar_t* restrict pwcs, const char* restrict s, size_t n); size_t wcstombs(char* restrict s, const wchar_t* restrict pwcs, size_t n); size_t memalignment(const void* p);
```

Only if the implementation defines `__STDC_IEC_60559_DFP__`:
僅當實現定義 __STDC_IEC_60559_DFP__ ：

```c
int strfromd32(char* restrict s, size_t n, const char* restrict format, _Decimal32 fp); int strfromd64(char* restrict s, size_t n, const char* restrict format, _Decimal64 fp); int strfromd128(char* restrict s, size_t n, const char* restrict format, _Decimal128 fp); _Decimal32 strtod32(const char* restrict nptr, char** restrict endptr); _Decimal64 strtod64(const char* restrict nptr, char** restrict endptr); _Decimal128 strtod128(const char* restrict nptr, char** restrict endptr);
```

Only if the implementation defines `__STDC_IEC_60559_TYPES__` and additionally the user code defines `__STDC_WANT_IEC_60559_TYPES_EXT__` before any inclusion of `<stdlib.h>`:
僅當實現定義 __STDC_IEC_60559_TYPES__ ，且此外使用者程式碼 在包含 <stdlib.h> 之前的任何位置定義 __STDC_WANT_IEC_60559_TYPES_EXT__ ：

```c
#ifdef __STDC_WANT_IEC_60559_TYPES_EXT__ int strfromfN(char* restrict s, size_t n, const char* restrict format, _FloatN fp); int strfromfNx(char* restrict s, size_t n, const char* restrict format, _FloatNx fp); int strfromdN(char* restrict s, size_t n, const char* restrict format, _DecimalN fp); int strfromdNx(char* restrict s, size_t n, const char* restrict format, _DecimalNx fp); _FloatN strtofN(const char* restrict nptr, char** restrict endptr); _FloatNx strtofNx(const char* restrict nptr, char** restrict endptr); _DecimalN strtodN(const char* restrict nptr, char** restrict endptr); _DecimalNx strtodNx(const char* restrict nptr, char** restrict endptr); int strfromencfN(char* restrict s, size_t n, const char* restrict format,  const unsigned char encptr[restrict static N/8]); int strfromencdecdN(char* restrict s, size_t n, const char* restrict format,  const unsigned char encptr[restrict static N/8]); int strfromencbindN(char* restrict s, size_t n, const char* restrict format,  const unsigned char encptr[restrict static N/8]); void strtoencfN(unsigned char encptr[restrict static N/8],  const char* restrict nptr, char** restrict endptr); void strtoencdecdN(unsigned char encptr[restrict static N/8],  const char* restrict nptr, char** restrict endptr); void strtoencbindN(unsigned char encptr[restrict static N/8],  const char* restrict nptr, char** restrict endptr); #endif
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<stdlib.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者 程式碼在包含 <stdlib.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#if defined(__STDC_WANT_LIB_EXT1__) constraint_handler_t set_constraint_handler_s(constraint_handler_t handler); void abort_handler_s(const char* restrict msg, void* restrict ptr, errno_t error); void ignore_handler_s(const char* restrict msg, void* restrict ptr, errno_t error); errno_t getenv_s(size_t* restrict len, char* restrict value, rsize_t maxsize,  const char* restrict name); QVoid* bsearch_s(const void* key, QVoid* base, rsize_t nmemb, rsize_t size,  int (*compar)(const void* k, const void* y, void* context),  void* context); errno_t qsort_s(void* base, rsize_t nmemb, rsize_t size,  int (*compar)(const void* x, const void* y, void* context),  void* context); errno_t wctomb_s(int* restrict status, char* restrict s, rsize_t smax,  wchar_t wc); errno_t mbstowcs_s(size_t* restrict retval, wchar_t* restrict dst, rsize_t dstmax,  const char* restrict src, rsize_t len); errno_t wcstombs_s(size_t* restrict retval, char* restrict dst, rsize_t dstmax,  const wchar_t* restrict src, rsize_t len); #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/stdlib.html`

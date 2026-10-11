# Standard library header <inttypes.h> (C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the type support library, in particular, it is a part of format conversion of integer types interface.
該標頭檔是型別支援庫的一部分，特別是它是整數型別格式轉換介面的一部分。

|  | This section is incomplete
Reason: Add macros from B.7. Format conversion of integer types <inttypes.h>  |

### Synopsis

```c
intmax_t imaxabs(intmax_t j); imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom); intmax_t strtoimax(const char* restrict nptr, char** restrict endptr, int base); uintmax_t strtoumax(const char* restrict nptr, char** restrict endptr, int base); intmax_t wcstoimax(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base); uintmax_t wcstoumax(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
```

---
來源頁路徑：`en.cppreference.com/c/header/inttypes.html`

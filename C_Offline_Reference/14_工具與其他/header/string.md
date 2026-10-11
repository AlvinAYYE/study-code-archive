# Standard library header <string.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header provides functions for handling null-terminated byte strings.
該標頭檔提供處理以空字元結尾的位元組字串的函式。

### Macros

NULL
|   | implementation-defined null pointer constant
(macro constant)   |

### Types

size_t
|   | unsigned integer type returned by the sizeof operator
(typedef)   |

### Functions

#####  String manipulation

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

strncpystrncpy_s
(C11)
|   | copies a certain amount of characters from one string to another
(function)   |

strcatstrcat_s
(C11)
|   | concatenates two strings
(function)   |

strncatstrncat_s
(C11)
|   | concatenates a certain amount of characters of two strings
(function)   |

strxfrm
|   | transform a string so that strcmp would produce the same result as strcoll
(function)   |

strdup
(C23)
|   | allocates a copy of a string
(function)   |

strndup
(C23)
|   | allocates a copy of a string of specified size
(function)   |

#####  String examination

strlenstrnlen_s
(C11)
|   | returns the length of a given string
(function)   |

strcmp
|   | compares two strings
(function)   |

strncmp
|   | compares a certain amount of characters of two strings
(function)   |

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

strchr
|   | finds the first occurrence of a character
(function)   |

strrchr
|   | finds the last occurrence of a character
(function)   |

strspn
|   | returns the length of the maximum initial segment that consists
of only the characters found in another byte string
(function)   |

strcspn
|   | returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

strstr
|   | finds the first occurrence of a substring of characters
(function)   |

strtokstrtok_s
(C11)
|   | finds the next token in a byte string
(function)   |

#####  Character array manipulation

memchr
|   | searches an array for the first occurrence of a character
(function)   |

memcmp
|   | compares two buffers
(function)   |

memsetmemset_explicitmemset_s
(C23)(C11)
|   | fills a buffer with a character
(function)   |

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

memmovememmove_s
(C11)
|   | moves one buffer to another
(function)   |

memccpy
(C23)
|   | copies one buffer to another, stopping after the specified delimiter
(function)   |

#####  Miscellaneous

strerrorstrerror_sstrerrorlen_s
(C11)(C11)
|   | returns a text version of a given error code
(function)   |

### Synopsis

```c
#define __STDC_VERSION_STRING_H__ 202311L #define NULL /* see description */ typedef /* see description */ size_t; void* memcpy(void* restrict s1, const void* restrict s2, size_t n); void* memccpy(void* restrict s1, const void* restrict s2, int c, size_t n); void* memmove(void* s1, const void* s2, size_t n); char* strcpy(char* restrict s1, const char* restrict s2); char* strncpy(char* restrict s1, const char* restrict s2, size_t n); char* strdup(const char* s); char* strndup(const char* s, size_t n); char* strcat(char* restrict s1, const char* restrict s2); char* strncat(char* restrict s1, const char* restrict s2, size_t n); int memcmp(const void* s1, const void* s2, size_t n); int strcmp(const char* s1, const char* s2); int strcoll(const char* s1, const char* s2); int strncmp(const char* s1, const char* s2, size_t n); size_t strxfrm(char* restrict s1, const char* restrict s2, size_t n); /*QVoid*/* memchr(/*QVoid*/* s, int c, size_t n); /*QChar*/* strchr(/*QChar*/* s, int c); size_t strcspn(const char* s1, const char* s2); /*QChar*/* strpbrk(/*QChar*/* s1, const char* s2); /*QChar*/* strrchr(/*QChar*/* s, int c); size_t strspn(const char* s1, const char* s2); /*QChar*/* strstr(/*QChar*/* s1, const char* s2); char* strtok(char* restrict s1, const char* restrict s2); void* memset(void* s, int c, size_t n); void* memset_explicit(void* s, int c, size_t n); char* strerror(int errnum); size_t strlen(const char* s); size_t strnlen(const char* s, size_t n);
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<string.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者程式碼在包含 <string.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#ifdef __STDC_WANT_LIB_EXT1__ tyepdef /* see description */ errno_t; tyepdef /* see description */ rsize_t; errno_t memcpy_s(void* restrict s1, rsize_t s1max, const void* restrict s2, rsize_t n); errno_t memmove_s(void* s1, rsize_t s1max, const void* s2, rsize_t n); errno_t strcpy_s(char* restrict s1, rsize_t s1max, const char* restrict s2); errno_t strncpy_s(char* restrict s1, rsize_t s1max, const char* restrict s2, rsize_t n); errno_t strcat_s(char* restrict s1, rsize_t s1max, const char* restrict s2); errno_t strncat_s(char* restrict s1, rsize_t s1max, const char* restrict s2, rsize_t n); char* strtok_s(char* restrict s1, rsize_t* restrict s1max,  const char* restrict s2, char** restrict ptr); errno_t memset_s(void* s, rsize_t smax, int c, rsize_t n) errno_t strerror_s(char* s, rsize_t maxsize, errno_t errnum); size_t strerrorlen_s(errno_t errnum); size_t strnlen_s(const char* s, size_t maxsize); #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/string.html`

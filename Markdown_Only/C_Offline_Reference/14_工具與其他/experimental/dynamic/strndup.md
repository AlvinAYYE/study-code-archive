# strndup

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char *strndup( const char *str, size_t size );
```
|   |   |   |  (dynamic memory TR)  |

|  |  |  |  |

Returns a pointer to a null-terminated byte string, which contains copies of at most `size` bytes from the string pointed to by `str`. If the null terminator is not encountered in the first `size` bytes, it is added to the duplicated string.
傳回指向以空字元結尾之位元組字串的指標；該字串最多複製 str 指向字串的 size 個位元組。若前 size 個位元組中沒有空字元，會在複製結果末尾加上空字元。
The returned pointer must be passed to free to avoid a memory leak.
傳回的指標必須傳遞給 free 以避免記憶體洩漏。
If an error occurs, a null pointer is returned and errno may be set.
如果發生錯誤，則傳回空指標，並可能設定 errno。
As all functions from Dynamic Memory TR, `strndup` is only guaranteed to be available if `__STDC_ALLOC_LIB__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT2__` to the integer constant `1` before including `string.h`.
與 Dynamic Memory TR 中的所有函式一樣，strndup 僅在實現定義了 __STDC_ALLOC_LIB__ 且使用者在包含 string.h 之前將 __STDC_WANT_LIB_EXT2__ 定義為整數常量 1 時才保證可用。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to duplicate  |

| size  |   | -  |   | max number of bytes to copy from `str`  |

### Return value

A pointer to the newly allocated string, or a null pointer if an error occurred.
指向新分配字串的指標，如果發生錯誤則為空指標。

### Notes

The function is identical to the POSIX strndup except that it is allowed, but not required to set errno on error.
該函式與 POSIX strndup 相同，不同之處在於允許但不要求在出錯時設定 errno。

### Example

Run this code

```c
#ifdef __STDC_ALLOC_LIB__ #define __STDC_WANT_LIB_EXT2__ 1 #else #define _POSIX_C_SOURCE 200809L #endif #include <string.h> #include <stdio.h> #include <stdlib.h> int main(void) {  const char *s1 = "String";  char *s2 = strndup(s1, 2);  printf("strndup(\"String\", 2) == %s\n", s2);  free(s2); }
```

Output:

```c
strndup("String", 2) == St
```

### See also

strdup
(dynamic memory TR)
|   | allocate a copy of a string
(function)   |

strncpystrncpy_s
(C11)
|   | copies a certain amount of characters from one string to another
(function)   |

malloc
|   | allocates memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/experimental/dynamic/strndup.html`

# strdup

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char * strdup( const char *str1 );
```
|   |   |   |  (dynamic memory TR)  |

|  |  |  |  |

Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by `str1`. The returned pointer must be passed to free to avoid a memory leak.
傳回一個指向空終止位元組字串的指標，該字串是 str1 所指向字串的 副本。傳回的指標必須傳遞給 free 以避免記憶體洩漏。
If an error occurs, a null pointer is returned and errno may be set.
如果發生錯誤，則傳回空指標，並可能設定 errno。
As all functions from Dynamic Memory TR, `strdup` is only guaranteed to be available if `__STDC_ALLOC_LIB__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT2__` to the integer constant `1` before including `string.h`.
和 Dynamic Memory TR 中的其他函式一樣，只有實作定義了 __STDC_ALLOC_LIB__，且使用者在引入 string.h 前將 __STDC_WANT_LIB_EXT2__ 定義為整數常數 1，才能保證 strdup 可用。

### Parameters

| str1  |   | -  |   | pointer to the null-terminated byte string to duplicate  |

### Return value

A pointer to the newly allocated string, or a null pointer if an error occurred.
指向新分配字串的指標，如果發生錯誤則為空指標。

### Notes

The function is identical to the POSIX strdup.
該函式與 POSIX strdup 相同。

### Example

Run this code

```c
#ifdef __STDC_ALLOC_LIB__ #define __STDC_WANT_LIB_EXT2__ 1 #else #define _POSIX_C_SOURCE 200809L #endif #include <string.h> #include <assert.h> #include <stdlib.h> int main(void) {  const char *s1 = "String";  char *s2 = strdup(s1);  assert(strcmp(s1, s2) == 0);  free(s2); }
```

### See also

strndup
(dynamic memory TR)
|   | allocate a copy of a string up to specified size
(function)   |

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

malloc
|   | allocates memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/experimental/dynamic/strdup.html`

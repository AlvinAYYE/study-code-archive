# strndup

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char *strndup( const char *src, size_t size );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Returns a pointer to a null-terminated byte string, which contains copies of at most `size` bytes from the string pointed to by `src`. The space for the new string is obtained as if malloc was called. If the null terminator is not encountered in the first `size` bytes, it is appended to the duplicated string.
傳回一個指向以空字元結尾的位元組串的指標，該位元組串包含 src 所指向字串中至多 size 個位元組的副本。新字串所需的儲存空間透過呼叫 malloc 獲得。如果前 size 個位元組中未遇到空字元結束符，則將其追加到複製出的字串。
The returned pointer must be passed to free to avoid a memory leak.
傳回的指標必須傳遞給 free 以避免記憶體洩漏。
If an error occurs, a null pointer is returned and errno might be set.
如果發生錯誤，則傳回空指標，且可能設定 errno 。

### Parameters

| src  |   | -  |   | pointer to the null-terminated byte string to duplicate  |

| size  |   | -  |   | max number of bytes to copy from `src`  |

### Return value

A pointer to the newly allocated string, or a null pointer if an error occurred.
指向新分配字串的指標，如果發生錯誤則為空指標。

### Notes

The function is identical to the POSIX strndup except that it is allowed, but not required to set errno on error.
該函式與 POSIX strndup 相同，不同之處在於允許但不要求在出錯時設定 errno。

### Example

Run this code

```c
#include <string.h> #include <stdio.h> #include <stdlib.h> int main(void) {  const size_t n = 3;    const char *src = "Replica";  char *dup = strndup(src, n);  printf("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);  free(dup);  src = "Hi";  dup = strndup(src, n);  printf("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);  free(dup);  const char arr[] = {'A','B','C','D'}; // NB: no trailing '\0'  dup = strndup(arr, n);  printf("strndup({'A','B','C','D'}, %lu) == \"%s\"\n", n, dup);  free(dup); }
```

Output:

```c
strndup("Replica", 3) == "Rep" strndup("Hi", 3) == "Hi" strndup({'A','B','C','D'}, 3) == "ABC"
```

### See also

strdup
(C23)
|   | allocates a copy of a string
(function)   |

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

malloc
|   | allocates memory
(function)   |

free
|   | deallocates previously allocated memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/string/byte/strndup.html`

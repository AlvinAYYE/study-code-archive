# strdup

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char *strdup( const char *src );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by `src`. The space for the new string is obtained as if the malloc was invoked. The returned pointer must be passed to free to avoid a memory leak.
傳回指向空終止位元組字串的指標，該字串是 src 指向的字串的副本。新字串的空間如同呼叫 malloc 一樣獲得。傳回的指標必須傳遞給 free 以避免記憶體洩漏。
If an error occurs, a null pointer is returned and errno might be set.
如果發生錯誤，則傳回空指標，且可能設定 errno 。

### Parameters

| src  |   | -  |   | pointer to the null-terminated byte string to duplicate  |

### Return value

A pointer to the newly allocated string, or a null pointer if an error occurred.
指向新分配字串的指標，如果發生錯誤則為空指標。

### Notes

The function is identical to the POSIX strdup.
該函式與 POSIX strdup 相同。

### Example

Run this code

```c
#include <string.h> #include <stdio.h> #include <stdlib.h> int main(void) {  const char *s1 = "Duplicate me!";  char *s2 = strdup(s1);  printf("s2 = \"%s\"\n", s2);  free(s2); }
```

Output:

```c
s2 = "Duplicate me!"
```

### See also

strndup
(C23)
|   | allocates a copy of a string of specified size
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
來源頁路徑：`en.cppreference.com/c/string/byte/strdup.html`

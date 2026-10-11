# NULL

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<locale.h>`
|   |  |   |  |

Defined in header `<stddef.h>`
|   |  |   |  |

Defined in header `<stdio.h>`
|   |  |   |  |

Defined in header `<stdlib.h>`
|   |  |   |  |

Defined in header `<string.h>`
|   |  |   |  |

Defined in header `<time.h>`
|   |  |   |  |

Defined in header `<wchar.h>`
|   |  |   |  |

```c
#define NULL /*implementation-defined*/
```
|   |   |   |   |

|  |  |  |  |

The macro `NULL` is an implementation-defined null pointer constant, which may be
宏 NULL 是一個實現定義的空指標常數，它可以是

- an integer constant expression with the value `0`
一個值為 0 的整數常量表示式

- an integer constant expression with the value `0` cast to the type `void*`
一個值為 0 並轉換為 void * 型別的整數常量表示式

- predefined constant nullptr
|   | (since C23) |

A null pointer constant may be converted to any pointer type; such conversion results in the null pointer value of that type.
空指標常量可以轉換為任何指標型別；這種轉換產生該型別的空指標值。

### Notes

POSIX requires `NULL` to be defined as an integer constant expression with the value `0` cast to `void*`.
POSIX 要求 NULL 被定義為值為 0 並轉換為 void * 的整數常量表示式。

### Possible implementation
可能的實現

```c
// C++ compatible: #define NULL 0 // C++ incompatible: #define NULL (10*2 - 20) #define NULL ((void*)0) // since C23 (compatible with C++11 and later) #define NULL nullptr
```

### Example

Run this code

```c
#include <inttypes.h> #include <stdint.h> #include <stdio.h> #include <stdlib.h> int main(void) {  // any kind of pointer can be set to NULL  int* p = NULL;  struct S *s = NULL;  void(*f)(int, double) = NULL;  printf("%p %p %p\n", (void*)p, (void*)s, (void*)(long)f);  // many pointer-returning functions use null pointers to indicate error  char *ptr = malloc(0xFULL);  if (ptr == NULL)  printf("Out of memory");  else  printf("ptr = %#" PRIxPTR"\n", (uintptr_t)ptr);  free(ptr); }
```

Possible output:
可能的輸出：

```c
(nil) (nil) (nil) ptr = 0xc001cafe
```

### See also

nullptr_t
(C23)
|   | the type of the predefined null pointer constant nullptr
(typedef)   |

C++ documentation for NULL

---
來源頁路徑：`en.cppreference.com/c/types/NULL.html`

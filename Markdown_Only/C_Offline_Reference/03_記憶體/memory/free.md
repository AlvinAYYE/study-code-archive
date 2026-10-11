# free

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void free( void *ptr );
```
|   |   |   |   |

|  |  |  |  |

Deallocates the space previously allocated by malloc(), calloc(), aligned_alloc(),(since C11) or realloc().
釋放先前由 malloc()、calloc()、aligned_alloc()（自 C11 起）或 realloc() 配置的空間。
If `ptr` is a null pointer, the function does nothing.
如果 ptr 是空指標，則該函式不做任何事。
The behavior is undefined if the value of `ptr` does not equal a value returned earlier by malloc(), calloc(), realloc(), or aligned_alloc()(since C11).
如果 ptr 的值不等於先前由 malloc() 、 calloc() 、 realloc() 或 aligned_alloc() (自 C11 起) 傳回的值，則行為是未定義的。
The behavior is undefined if the memory area referred to by `ptr` has already been deallocated, that is, `free()`, free_sized(), free_aligned_sized()(since C23), or realloc() has already been called with `ptr` as the argument and no calls to malloc(), calloc(), realloc(), or aligned_alloc()(since C11) resulted in a pointer equal to `ptr` afterwards.
如果 ptr 所引用的記憶體區域已被釋放，則行為是未定義的；也就是說，已經以 ptr 作為實參呼叫過 free() 、 free_sized() 、 free_aligned_sized() (自 C23 起) 或 realloc()，並且此後沒有任何對 malloc() 、 calloc() 、 realloc() 或 aligned_alloc() (自 C11 起) 的呼叫傳回過等於 ptr 的指標。
The behavior is undefined if after `free()` returns, an access is made through the pointer `ptr` (unless another allocation function happened to result in a pointer value equal to `ptr`).
如果在 free() 傳回後透過指標 ptr 進行了訪問，則行為是未定義的（除非另一個分配函式恰好傳回了等於 ptr 的指標值）。

`free` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`free` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
A call to `free` that deallocates a region of memory *synchronizes-with* a call to any subsequent allocation function that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by the allocation function. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
`free` 釋放某段記憶體後，若後續的配置函式重新配置同一段或其中一部分，兩次操作會建立同步關係：`free` 對該記憶體的存取先完成，配置函式才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
|   | (since C11) |

### Parameters

| ptr  |   | -  |   | pointer to the memory to deallocate  |

### Return value

(none)

### Notes

The function accepts (and does nothing with) the null pointer to reduce the amount of special-casing. Whether allocation succeeds or not, the pointer returned by an allocation function can be passed to `free()`.
該函式接受空指標（並且不做任何處理），以減少特殊情況的處理。無論分配是否成功，分配函式傳回的指標都可以傳遞給 free()。

### Example

Run this code

```c
#include <stdlib.h> int main(void) {  int *p1 = malloc(10*sizeof *p1);  free(p1); // every allocated pointer must be freed  int *p2 = calloc(10, sizeof *p2);  int *p3 = realloc(p2, 1000*sizeof *p3);  if(p3) // p3 not null means p2 was freed by realloc  free(p3);  else // p3 null means p2 was not freed  free(p2); }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.3.3 The free function (p: 365)
7.24.3.3 free 函式 (p: 365)
7.24.3.3 free 函式 (p: 365)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.3.3 The free function (p: 254)
7.22.3.3 free 函式 (p: 254)
7.22.3.3 free 函式 (p: 254)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.3.3 The free function (p: 348)
7.22.3.3 free 函式 (p: 348)
7.22.3.3 free 函式 (p: 348)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.3.2 The free function (p: 313)
7.20.3.2 free 函式 (p: 313)
7.20.3.2 free 函式 (p: 313)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.3.2 The free function
4.10.3.2 free 函式
4.10.3.2 free 函式

### See also

malloc
|   | allocates memory
(function)   |

free_sized
(C23)
|   | deallocates previously allocated sized memory
(function)   |

free_aligned_sized
(C23)
|   | deallocates previously allocated sized and aligned memory
(function)   |

C++ documentation for free

---
來源頁路徑：`en.cppreference.com/c/memory/free.html`

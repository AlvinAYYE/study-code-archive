# realloc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void *realloc( void *ptr, size_t new_size );
```
|   |   |   |   |

|  |  |  |  |

Reallocates the given area of memory. If `ptr` is not NULL, it must be previously allocated by malloc, calloc or `realloc` and not yet freed with a call to free or `realloc`. Otherwise, the results are undefined.
重新配置指定的記憶體區域。若 ptr 不是 NULL，它必須是先前由 malloc、calloc 或 realloc 配置，且尚未透過 free 或 realloc 釋放的指標；否則行為未定義。
The reallocation is done by either:
重新分配透過以下方式之一完成：

a) expanding or contracting the existing area pointed to by `ptr`, if possible. The contents of the area remain unchanged up to the lesser of the new and old sizes. If the area is expanded, the contents of the new part of the array are undefined.
可能的話，直接擴大或縮小 `ptr` 指向的原記憶體區塊。新舊大小範圍內較小的那一段內容會保留；若區塊變大，新增加部分的內容未定義。

b) allocating a new memory block of size `new_size` bytes, copying memory area with size equal the lesser of the new and the old sizes, and freeing the old block.
也可能另行配置 `new_size` 位元組的新區塊，複製新舊區塊中較小範圍的內容，再釋放舊區塊。

If there is not enough memory, the old memory block is not freed and null pointer is returned.
如果沒有足夠的記憶體，舊的記憶體塊不會被釋放，並傳回空指標。
If `ptr` is NULL, the behavior is the same as calling `malloc(new_size)`.
若 ptr 是 NULL，行為與呼叫 malloc(new_size) 相同。
Otherwise,

if `new_size` is zero, the behavior is implementation defined (null pointer may be returned (in which case the old memory block may or may not be freed), or some non-null pointer may be returned that may not be used to access storage). Such usage is deprecated (via C DR 400).(since C17)
|   | (until C23) |

if `new_size` is zero, the behavior is undefined.
|   | (since C23) |

`realloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`realloc` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
A previous call to free or `realloc` that deallocates a region of memory *synchronizes-with* a call to any allocation function, including `realloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `realloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
若先前的 `free` 或 `realloc` 釋放了某段記憶體，之後任何配置函式（包括 `realloc`）重新配置同一段或其中一部分，兩次操作會建立同步關係：釋放端對該記憶體的存取先完成，配置端才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
|   | (since C11) |

### Parameters

| ptr  |   | -  |   | pointer to the memory area to be reallocated  |

| new_size  |   | -  |   | new size of the array in bytes  |

### Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free or `realloc`. The original pointer `ptr` is invalidated and any access to it is undefined behavior (even if reallocation was in-place).
成功時，傳回指向新分配記憶體起始位置的指標。為避免記憶體洩漏，傳回的指標必須用 free 或 realloc 釋放。原始指標 ptr 會失效，對它的任何訪問都屬於未定義行為（即使重新分配是原地進行的）。
On failure, returns a null pointer. The original pointer `ptr` remains valid and may need to be deallocated with free or `realloc`.
失敗時，傳回空指標。原始指標 ptr 仍然有效，可能需要用 free 或 realloc 釋放。

### Notes

Originally (in C89), support for zero size was added to accommodate code such as
最初在 C89 中加入零大小配置的支援，是為了容許下列這類寫法：

```c
OBJ *p = calloc(0, sizeof(OBJ)); // "zero-length" placeholder /*...*/ while (1) {  p = realloc(p, c * sizeof(OBJ)); // reallocations until size settles  /* code that may change c or break out of loop */ }
```

### Example

Run this code

```c
#include <assert.h> #include <stdio.h> #include <stdlib.h> #include <string.h> void print_storage_info(const int* next, const int* prev, int ints) {  if (next)  printf("%s location: %p. Size: %d ints (%ld bytes).\n",  (next != prev ? "New" : "Old"), (void*)next, ints, ints * sizeof(int));  else  printf("Allocation failed.\n"); } int main(void) {  const int pattern[] = {1, 2, 3, 4, 5, 6, 7, 8};  const int pattern_size = sizeof pattern / sizeof(int);  int *next = NULL, *prev = NULL;  if ((next = (int*)malloc(pattern_size * sizeof *next))) // allocates an array  {  memcpy(next, pattern, sizeof pattern); // fills the array  print_storage_info(next, prev, pattern_size);  }  else  return EXIT_FAILURE;  // Reallocate in cycle using the following values as a new storage size.  const int realloc_size[] = {10, 12, 512, 32768, 65536, 32768};  for (int i = 0; i != sizeof realloc_size / sizeof(int); ++i)  {  if ((next = (int*)realloc(prev = next, realloc_size[i] * sizeof(int))))  {  print_storage_info(next, prev, realloc_size[i]);  assert(!memcmp(next, pattern, sizeof pattern)); // is pattern held  }  else // if realloc failed, the original pointer needs to be freed  {  free(prev);  return EXIT_FAILURE;  }  }  free(next); // finally, frees the storage  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
New location: 0x144c010. Size: 8 ints (32 bytes). Old location: 0x144c010. Size: 10 ints (40 bytes). New location: 0x144c450. Size: 12 ints (48 bytes). Old location: 0x144c450. Size: 512 ints (2048 bytes). Old location: 0x144c450. Size: 32768 ints (131072 bytes). New location: 0x7f490c5bd010. Size: 65536 ints (262144 bytes). Old location: 0x7f490c5bd010. Size: 32768 ints (131072 bytes).
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.3.5 The realloc function (p: TBD)
7.22.3.5 realloc 函式 (p: 待定)
7.22.3.5 realloc 函式 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.3.5 The realloc function (p: 254)
7.22.3.5 realloc 函式 (p: 254)
7.22.3.5 realloc 函式 (p: 254)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.3.5 The realloc function (p: 349)
7.22.3.5 realloc 函式 (p: 349)
7.22.3.5 realloc 函式 (p: 349)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.3.4 The realloc function (p: 314)
7.20.3.4 realloc 函式 (p: 314)
7.20.3.4 realloc 函式 (p: 314)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.3.4 The realloc function
4.10.3.4 realloc 函式
4.10.3.4 realloc 函式

### See also

C++ documentation for realloc

---
來源頁路徑：`en.cppreference.com/c/memory/realloc.html`

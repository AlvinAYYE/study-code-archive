# malloc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void *malloc( size_t size );
```
|   |   |   |   |

|  |  |  |  |

Allocates `size` bytes of uninitialized storage.
分配 size 個位元組的未初始化儲存空間。
If allocation succeeds, returns a pointer that is suitably aligned for any object type with fundamental alignment.
若配置成功，會傳回一個指標，其位址適當對齊，可用來存放任何具有基本對齊要求的物件型別。
If `size` is zero, the behavior of `malloc` is implementation-defined. For example, a null pointer may be returned. Alternatively, a non-null pointer may be returned; but such a pointer should not be dereferenced, and should be passed to free to avoid memory leaks.
若 size 為 0，malloc 的行為由實作定義。例如，它可能傳回空指標，也可能傳回非空指標。後者不可解參照，但仍應傳給 free，以免造成記憶體流失。

`malloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`malloc` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
A previous call to free, free_sized, and free_aligned_sized(since C23) or realloc that deallocates a region of memory *synchronizes-with* a call to `malloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `malloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
若先前的 `free`、`free_sized`、`free_aligned_sized`（C23 起）或 `realloc` 釋放了某段記憶體，之後 `malloc` 重新配置同一段或其中一部分，兩次操作會建立同步關係：釋放端對該記憶體的存取先完成，配置端才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
|   | (since C11) |

### Parameters

| size  |   | -  |   | number of bytes to allocate  |

### Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
成功時，會傳回指向新配置記憶體起始位置的指標。為避免記憶體流失，必須使用 free() 或 realloc() 釋放該記憶體。
On failure, returns a null pointer.
失敗時，傳回空指標。

### Example

Run this code

```c
#include <stdio.h>  #include <stdlib.h>  int main(void)  {  int *p1 = malloc(4*sizeof(int)); // allocates enough for an array of 4 int  int *p2 = malloc(sizeof(int[4])); // same, naming the type directly  int *p3 = malloc(4*sizeof *p3); // same, without repeating the type name  if(p1) {  for(int n=0; n<4; ++n) // populate the array  p1[n] = n*n;  for(int n=0; n<4; ++n) // print it back out  printf("p1[%d] == %d\n", n, p1[n]);  }  free(p1);  free(p2);  free(p3); }
```

Output:

```c
p1[0] == 0 p1[1] == 1 p1[2] == 4 p1[3] == 9
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.3.4 The malloc function (p: 254)
7.22.3.4 malloc 函式 (p: 254)
7.22.3.4 malloc 函式 (p: 254)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.3.4 The malloc function (p: 349)
7.22.3.4 malloc 函式 (p: 349)
7.22.3.4 malloc 函式 (p: 349)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.3.3 The malloc function (p: 314)
7.20.3.3 malloc 函式 (p: 314)
7.20.3.3 malloc 函式 (p: 314)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.3.3 The malloc function
4.10.3.3 malloc 函式
4.10.3.3 malloc 函式

### See also

free
|   | deallocates previously allocated memory
(function)   |

C++ documentation for malloc

---
來源頁路徑：`en.cppreference.com/c/memory/malloc.html`

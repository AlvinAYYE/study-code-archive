# aligned_alloc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void *aligned_alloc( size_t alignment, size_t size );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Allocate `size` bytes of uninitialized storage whose alignment is specified by `alignment`. The `size` parameter must be an integral multiple of `alignment`.
配置 size 個位元組的未初始化儲存空間，並依 alignment 指定的值對齊。size 必須是 alignment 的整數倍。
`aligned_alloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`aligned_alloc` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
aligned_alloc 是執行緒安全的：它的行為就好像只訪問透過其參數可見的記憶體位置，而不訪問任何靜態儲存。
A previous call to free, free_sized, and free_aligned_sized(since C23) or realloc that deallocates a region of memory *synchronizes-with* a call to `aligned_alloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `aligned_alloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
若先前的 `free`、`free_sized`、`free_aligned_sized`（C23 起）或 `realloc` 釋放了某段記憶體，之後 `aligned_alloc` 重新配置同一段或其中一部分，兩次操作會建立同步關係：釋放端對該記憶體的存取先完成，配置端才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
先前釋放某塊記憶體區域的 free、free_sized 和 free_aligned_sized (自 C23 起) 或 realloc 呼叫，與分配同一記憶體區域或其一部分的 aligned_alloc 呼叫同步。這種同步發生在釋放函式對該記憶體的任何訪問之後，並在 aligned_alloc 對該記憶體的任何訪問之前。對於每個特定的記憶體區域，所有分配和釋放函式之間存在單一的全序關係。

### Parameters

| alignment  |   | -  |   | specifies the alignment. Must be a valid alignment supported by the implementation.  |

| size  |   | -  |   | number of bytes to allocate. An integral multiple of `alignment`  |

### Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free or realloc.
成功時，傳回指向新分配記憶體起始位置的指標。為避免記憶體洩漏，傳回的指標必須用 free 或 realloc 釋放。
On failure, returns a null pointer.
失敗時，傳回空指標。

### Notes

Passing a `size` which is not an integral multiple of `alignment` or an `alignment` which is not valid or not supported by the implementation causes the function to fail and return a null pointer (C11, as published, specified undefined behavior in this case, this was corrected by DR460). Removal of size restrictions to make it possible to allocate small objects at restrictive alignment boundaries (similar to alignas) has been proposed by N2072.
傳入不是 alignment 整數倍的 size，或傳入無效的、或實現不支援的 alignment，會導致函式失敗並傳回空指標（C11 釋出版本在此情況下規定為未定義行為，這已由 DR460 修正）。N2072 提出了取消 size 限制的建議，以便能夠在嚴格的對齊邊界（類似 alignas）處分配小物件。
As an example of the "supported by the implementation" requirement, POSIX function `posix_memalign` accepts any `alignment` that is a power of two and a multiple of `sizeof(void *)`, and POSIX-based implementations of `aligned_alloc` inherit this requirements.
作為“由實現支援”這一要求的例子，POSIX 函式 posix_memalign 接受任何為 2 的冪且是 sizeof ( void * ) 倍數的對齊值，基於 POSIX 的 aligned_alloc 實現繼承了這一要求。
Fundamental alignments are always supported. If `alignment` is a power of two and not greater than `_Alignof(max_align_t)`, `aligned_alloc` may simply call malloc.
基本對齊總是受到支援。如果 alignment 是 2 的冪且不大於 _Alignof ( max_align_t )，aligned_alloc 可以簡單地呼叫 malloc。
Regular malloc aligns memory suitable for any object type with a fundamental alignment. The `aligned_alloc` is useful for over-aligned allocations, such as to SSE, cache line, or VM page boundary.
普通的 malloc 對齊到適合任何具有基本對齊的物件型別的記憶體。aligned_alloc 適用於過度對齊分配，例如對齊到 SSE、快取行或 VM 頁邊界。
This function is not supported in Microsoft C Runtime library because its implementation of std::free is unable to handle aligned allocations of any kind. Instead, MS CRT provides `_aligned_malloc` (to be freed with `_aligned_free`).
Microsoft C 執行時庫不支援此函式，因為其 std::free 的實現無法處理任何型別的對齊分配。MS CRT 改為提供 _aligned_malloc（需用 _aligned_free 釋放）。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int *p1 = malloc(10*sizeof *p1);  printf("default-aligned addr: %p\n", (void*)p1);  free(p1);  int *p2 = aligned_alloc(1024, 1024*sizeof *p2);  printf("1024-byte aligned addr: %p\n", (void*)p2);  free(p2); }
```

Possible output:
可能的輸出：

```c
default-aligned addr: 0x1e40c20 1024-byte aligned addr: 0x1e41000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.3.1 The aligned_alloc function (p: TBD)
7.22.3.1 aligned_alloc 函式 (p: 待定)
7.22.3.1 aligned_alloc 函式 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.3.1 The aligned_alloc function (p: 253)
7.22.3.1 aligned_alloc 函式 (p: 253)
7.22.3.1 aligned_alloc 函式 (p: 253)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.3.1 The aligned_alloc function (p: 347-348)
7.22.3.1 aligned_alloc 函式 (p: 347-348)
7.22.3.1 aligned_alloc 函式 (p: 347-348)

### See also

C++ documentation for aligned_alloc

---
來源頁路徑：`en.cppreference.com/c/memory/aligned_alloc.html`

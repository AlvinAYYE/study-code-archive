# free_aligned_sized

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void free_aligned_sized( void* ptr, size_t alignment, size_t size );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

If `ptr` is a null pointer or the result obtained from a call to aligned_alloc, where `alignment` is equal to the requested allocation alignment and `size` is equal to the requested allocation size, this function is equivalent to `free(ptr)`. Otherwise, the behavior is undefined.
如果 ptr 是空指標，或者是從 aligned_alloc 呼叫獲得的結果（其中 alignment 等於所請求的分配對齊，size 等於所請求的分配大小），則此函式等價於 free ( ptr )。否則，行為是未定義的。
The result of an malloc, calloc, or realloc call may not be passed to `free_aligned_sized`.
malloc、calloc 或 realloc 呼叫的結果不能傳遞給 free_aligned_sized。
`free_aligned_sized` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`free_aligned_sized` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
free_aligned_sized 是執行緒安全的：它的行為就好像只訪問透過其參數可見的記憶體位置，而不訪問任何靜態儲存。
A call to `free_aligned_sized` that deallocates a region of memory *synchronizes-with* a call to any subsequent allocation function that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by the allocation function. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
`free_aligned_sized` 釋放某段記憶體後，若後續的配置函式重新配置同一段或其中一部分，兩次操作會建立同步關係：`free_aligned_sized` 對該記憶體的存取先完成，配置函式才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
釋放某塊記憶體區域的 free_aligned_sized 呼叫，與隨後分配同一記憶體區域或其一部分的任何分配函式呼叫同步。這種同步發生在釋放函式對該記憶體的任何訪問之後，並在分配函式對該記憶體的任何訪問之前。對於每個特定的記憶體區域，所有分配和釋放函式之間存在單一的全序關係。

### Parameters

| ptr  |   | -  |   | pointer to the memory to deallocate  |

| alignment  |   | -  |   | alignment of memory to deallocate  |

| size  |   | -  |   | size of memory to deallocate  |

### Return value

(none)

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.3.5 The free_sized function (p: 366)
7.24.3.5 free_sized 函式 (p: 366)
7.24.3.5 free_sized 函式 (p: 366)

### See also

aligned_alloc
(C11)
|   | allocates aligned memory
(function)   |

free
|   | deallocates previously allocated memory
(function)   |

free_sized
(C23)
|   | deallocates previously allocated sized memory
(function)   |

malloc
|   | allocates memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/memory/free_aligned_sized.html`

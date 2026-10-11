# free_sized

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void free_sized( void* ptr, size_t size );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Deallocates the space previously allocated by malloc(), calloc(), or realloc() (but not aligned_alloc()).
釋放先前由 malloc()、calloc() 或 realloc() 配置的空間；不能用來釋放 aligned_alloc() 配置的空間。

|  | This section is incomplete
Reason: share wording among `free_*` family  |

`free_sized` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`free_sized` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
free_sized 是執行緒安全的：它的行為就好像只訪問透過其參數可見的記憶體位置，而不訪問任何靜態儲存。
A call to `free_sized` that deallocates a region of memory *synchronizes-with* a call to any subsequent allocation function that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by the allocation function. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
`free_sized` 釋放某段記憶體後，若後續的配置函式重新配置同一段或其中一部分，兩次操作會建立同步關係：`free_sized` 對該記憶體的存取先完成，配置函式才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
釋放某塊記憶體區域的 free_sized 呼叫，與隨後分配同一記憶體區域或其一部分的任何分配函式呼叫同步。這種同步發生在釋放函式對該記憶體的任何訪問之後，並在分配函式對該記憶體的任何訪問之前。對於每個特定的記憶體區域，所有分配和釋放函式之間存在單一的全序關係。

### Parameters

| ptr  |   | -  |   | pointer to the memory to deallocate  |

| size  |   | -  |   | size of memory previously passed to an allocation function  |

### Return value

(none)

### Notes

|  | This section is incomplete  |

### Possible implementation
可能的實現

```c
void free_sized(void* ptr, size_t /*size*/) {  free(ptr); }
```

### Example

Run this code

```c
#include <stddef.h> #include <stdio.h> #include <stdlib.h> typedef struct {  size_t size; // current number of elements  size_t capacity; // reserved number of elements  void** data; } PtrVector; PtrVector vector_create(size_t initial_capacity) {  PtrVector ret =  {  .capacity = initial_capacity,  .data = (void**) malloc(initial_capacity * sizeof(void*))  };  return ret; } void vector_delete(PtrVector* self) {  free_sized(self->data, self->capacity * sizeof(void*)); } void vector_push_back(PtrVector* self, void* value) {  if (self->size == self->capacity)  {  self->capacity *= 2;  self->data = (void**) realloc(self->data, self->capacity * sizeof(void*));  }  self->data[self->size++] = value; } int main() {  int data = 42;  float pi = 3.141592f;  PtrVector v = vector_create(8);  vector_push_back(&v, &data);  vector_push_back(&v, &pi);  printf("data[0] = %i\n", *(int*)v.data[0]);  printf("data[1] = %f\n", *(float*)v.data[1]);  vector_delete(&v); }
```

Output:

```c
data[0] = 42 data[1] = 3.141592
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.3.4 The free_sized function (p: 365-366)
7.24.3.4 free_sized 函式 (p: 365-366)
7.24.3.4 free_sized 函式 (p: 365-366)

### See also

free
|   | deallocates previously allocated memory
(function)   |

free_aligned_sized
(C23)
|   | deallocates previously allocated sized and aligned memory
(function)   |

malloc
|   | allocates memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/memory/free_sized.html`

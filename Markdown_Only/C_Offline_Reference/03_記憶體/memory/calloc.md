# calloc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void* calloc( size_t num, size_t size );
```
|   |   |   |   |

|  |  |  |  |

Allocates memory for an array of `num` objects of `size` and initializes all bytes in the allocated storage to zero.
配置足以容納 num 個物件的記憶體，每個物件大小為 size，並將配置區域中的所有位元組初始化為 0。
If allocation succeeds, returns a pointer to the lowest (first) byte in the allocated memory block that is suitably aligned for any object type with fundamental alignment.
配置成功時，會傳回指向配置區域最低位址（第一個位元組）的指標；此位址符合所有基本對齊需求的物件型別之對齊要求。
If `size` is zero, the behavior is implementation defined (null pointer may be returned, or some non-null pointer may be returned that may not be used to access storage).
如果 size 為零，則行為是實現定義的（可能傳回空指標，也可能傳回某個非空指標，該指標可能不能用於訪問儲存）。

`calloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage.
`calloc` 可在多執行緒環境中安全使用。它只會操作參數所涉及的記憶體位置，不會存取靜態儲存區。
A previous call to free, free_sized, and free_aligned_sized(since C23) or realloc that deallocates a region of memory *synchronizes-with* a call to `calloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `calloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.
若先前的 `free`、`free_sized`、`free_aligned_sized`（C23 起）或 `realloc` 釋放了某段記憶體，之後 `calloc` 重新配置同一段或其中一部分，兩次操作會建立同步關係：釋放端對該記憶體的存取先完成，配置端才會存取它。對同一段記憶體的配置與釋放操作，也有單一的先後順序。
|   | (since C11) |

### Parameters

| num  |   | -  |   | number of objects  |

| size  |   | -  |   | size of each object  |

### Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
成功時，傳回指向新分配記憶體起始位置的指標。為避免記憶體洩漏，必須使用 free() 或 realloc() 釋放傳回的指標。
On failure, returns a null pointer.
失敗時，傳回空指標。

### Notes

Due to the alignment requirements, the number of allocated bytes is not necessarily equal to `num * size`.
由於對齊要求，分配的位元組數不一定等於 num * size。
Initialization to all bits zero does not guarantee that a floating-point or a pointer would be initialized to `0.0` and the null pointer value, respectively (although that is true on all common platforms).
全部位初始化為零並不能保證浮點數或指標分別被初始化為 0.0 和空指標值（儘管在所有常見平臺上確實如此）。
Originally (in C89), support for zero size was added to accommodate code such as
最初（在 C89 中），新增對零大小的支援是為了適應諸如以下的程式碼

```c
OBJ* p = calloc(0, sizeof(OBJ)); // "zero-length" placeholder ... while(1) {  p = realloc(p, c * sizeof(OBJ)); // reallocations until size settles  ... // code that may change c or break out of loop }
```

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int* p1 = calloc(4, sizeof(int)); // allocate and zero out an array of 4 int  int* p2 = calloc(1, sizeof(int[4])); // same, naming the array type directly  int* p3 = calloc(4, sizeof *p3); // same, without repeating the type name  if (p2)  {  for (int n = 0; n < 4; ++n) // print the array  printf("p2[%d] == %d\n", n, p2[n]);  }  free(p3);  free(p2);  free(p1); }
```

Output:

```c
p2[0] == 0 p2[1] == 0 p2[2] == 0 p2[3] == 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.3.2 The calloc function (p: 365)
7.24.3.2 calloc 函式 (p: 365)
7.24.3.2 calloc 函式 (p: 365)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.3.2 The calloc function (p: 253)
7.22.3.2 calloc 函式 (p: 253)
7.22.3.2 calloc 函式 (p: 253)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.3.2 The calloc function (p: 348)
7.22.3.2 calloc 函式 (p: 348)
7.22.3.2 calloc 函式 (p: 348)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.3.1 The calloc function (p: 313)
7.20.3.1 calloc 函式 (p: 313)
7.20.3.1 calloc 函式 (p: 313)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.3.1 The calloc function
4.10.3.1 calloc 函式
4.10.3.1 calloc 函式

### See also

C++ documentation for calloc

---
來源頁路徑：`en.cppreference.com/c/memory/calloc.html`

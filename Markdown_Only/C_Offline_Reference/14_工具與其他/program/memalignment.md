# memalignment

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
size_t memalignment( const void *p );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Returns the maximum alignment satisfied by the provided address. The return value can be greater than any alignment value supported by the implementation. If `p` is a null pointer value, `0` is returned to indicate that the pointer cannot be used to access an object of any type.
傳回所提供的位址所滿足的最大對齊。傳回值可能大於實現支援的任何對齊值。如果 p 是空指標值，則傳回 0，表示該指標不能用於訪問任何型別的物件。
If the return value compares is greater than or equal to `alignof(T)`, the alignment requirement for the type `T` is satisfied by the pointer.
如果傳回值大於或等於 alignof ( T )，則該指標滿足型別 T 的對齊要求。
A freestanding implementation needs to provide `memalignment`.
獨立實現需要提供 memalignment。

### Parameters

| p  |   | -  |   | pointer to query alignment  |

### Return value

The alignment value of `p`, or `0` if `p` is a null pointer value.
p 的對齊值；如果 p 是空指標值，則為 0。

### Notes

On common platforms where
在滿足以下條件的常見平臺上

- null pointers are cast to integer `0`,
空指標被轉換為整數 0，

- pointer values are directly cast to the numeric values of virtual addresses, and
指標值被直接轉換為虛擬位址的數值，且

- size_t is same as uintptr_t,
size_t 與 uintptr_t 相同，

this function can be implemented as `return (size_t)p & -(size_t)p;`.
該函式可以實現為 return ( size_t ) p & - ( size_t ) p ;。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main() {  alignas(128) int i = 0;  printf("%zu\n%zu\n", memalignment(nullptr), memalignment(&i)); }
```

Possible output:
可能的輸出：

```c
0 128
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.9.1 The memalignment function (p: 374)
7.24.9.1 memalignment 函式 (p: 374)
7.24.9.1 memalignment 函式 (p: 374)

### See also

aligned_alloc
(C11)
|   | allocates aligned memory
(function)   |

free_aligned_sized
(C23)
|   | deallocates previously allocated sized and aligned memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/program/memalignment.html`

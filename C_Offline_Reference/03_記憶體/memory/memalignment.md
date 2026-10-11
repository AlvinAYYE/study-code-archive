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
傳回指定位址所符合的最大對齊值。傳回值可能大於實作支援的任何對齊值。若 p 是空指標，則傳回 0，表示該指標不能用來存取任何型別的物件。
若傳回值大於或等於 `alignof(T)`，代表該指標符合型別 `T` 的對齊要求。
A freestanding implementation needs to provide `memalignment`.
獨立實現需要提供 memalignment。

### Parameters

| p  |   | -  |   | pointer to query alignment  |

### Return value

The alignment value of `p`, or `0` if `p` is a null pointer value.
p 的對齊值；如果 p 是空指標值，則為 0。

### Notes

在常見平台上，如果同時符合以下條件：

- 空指標轉成整數時值為 `0`；

- 指標值可直接轉成虛擬位址的數值；而且

- `size_t` 與 `uintptr_t` 型別相同，

就可以用 `return (size_t)p & -(size_t)p;` 實作此函式。

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
來源頁路徑：`en.cppreference.com/c/memory/memalignment.html`

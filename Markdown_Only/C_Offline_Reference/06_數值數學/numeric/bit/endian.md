# __STDC_ENDIAN_LITTLE__, __STDC_ENDIAN_BIG__, __STDC_ENDIAN_NATIVE__

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdbit.h>`
|   |  |   |  |

```c
#define __STDC_ENDIAN_LITTLE__ /* implementation-defined */
```
|   |  (1)  |   |  (since C23)  |

```c
#define __STDC_ENDIAN_BIG__ /* implementation-defined */
```
|   |  (2)  |   |  (since C23)  |

```c
#define __STDC_ENDIAN_NATIVE__ /* implementation-defined */
```
|   |  (3)  |   |  (since C23)  |

|  |  |  |  |

Indicates the endianness of all scalar types:
指示所有標量型別的位元組序：

- If all scalar types are little-endian, `__STDC_ENDIAN_NATIVE__` equals `__STDC_ENDIAN_LITTLE__`.
如果所有標量型別都是小端序，__STDC_ENDIAN_NATIVE__ 等於 __STDC_ENDIAN_LITTLE__。

- If all scalar types are big-endian, `__STDC_ENDIAN_NATIVE__` equals `__STDC_ENDIAN_BIG__`.
如果所有標量型別都是大端序，__STDC_ENDIAN_NATIVE__ 等於 __STDC_ENDIAN_BIG__。

- If the platform uses neither little-endian nor big-endian, `__STDC_ENDIAN_NATIVE__` equals neither `__STDC_ENDIAN_BIG__` nor `__STDC_ENDIAN_LITTLE__`.
如果平臺既不使用小端序也不使用大端序，__STDC_ENDIAN_NATIVE__ 既不等於 __STDC_ENDIAN_BIG__ 也不等於 __STDC_ENDIAN_LITTLE__。

- The values of the integer constant expressions for `__STDC_ENDIAN_BIG__` and `__STDC_ENDIAN_LITTLE__` are not equal.
__STDC_ENDIAN_BIG__ 和 __STDC_ENDIAN_LITTLE__ 的整數常量表示式的值不相等。

### Example

Run this code

```c
#include <stdbit.h> #include <stdio.h> int main() {  switch(__STDC_ENDIAN_NATIVE__)  {  case __STDC_ENDIAN_LITTLE__:  printf("__STDC_ENDIAN_LITTLE__\n");  break;  case __STDC_ENDIAN_BIG__:  printf("__STDC_ENDIAN_BIG__\n");  break;  default:  printf("mixed-endian\n");  }  return __STDC_ENDIAN_NATIVE__; }
```

Possible output:
可能的輸出：

```c
mixed-endian
```

### See also

C++ documentation for endian

---
來源頁路徑：`en.cppreference.com/c/numeric/bit/endian.html`

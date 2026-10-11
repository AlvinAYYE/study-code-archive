# ckd_add

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdckdint.h>`
|   |  |   |  |

```c
#define ckd_add( result, a, b ) /* implementation-defined */ // exposed interface: bool ckd_add( type1* result, type2 a, type3 b );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Computes the addition `x + y` and stores the result into `*result`. The addition is performed as if both operands were represented in a signed integer type with infinite range, and the result was then converted from this integer type to `type1`. If the value assigned to `*result` correctly represents the mathematical result of the operation, it returns `false`. Otherwise, it returns `true`. In this case, the value assigned to `*result` is the mathematical result of the operation wrapped around to the width of `*result`.
計算加法 x + y 並將結果存入 * result 。該加法的執行方式如同兩個運算元都以無限範圍的有符號整數型別表示，然後再將結果從該整數型別轉換為 type1 。若賦給 * result 的值正確表示了該運算的數學結果，則傳回 false ；否則傳回 true 。此時，賦給 * result 的值是該運算的數學結果迴繞到 * result 的寬度後的值。

### Parameters

| a, b  |   | -  |   | integer values  |

| result  |   | -  |   | address of where result should be stored  |

### Return value

`false` if the value assigned to `*result` correctly represents the mathematical result of the addition, `true` otherwise.
若賦給 * result 的值正確表示了加法的數學結果，則傳回 false ，否則傳回 true 。

### Note

Both `type2` and `type3` shall be any integer type other than “plain” `char`, `bool`, a bit-precise integer type, or an enumerated type, and they can be the same. `*result` shall be a modifiable lvalue of any integer type other than “plain” `char`, `bool`, a bit-precise integer type, or an enumerated type.
type2 和 type3 必須是整數型別，但不能是純 char、bool、位元精確整數型別或列舉型別；兩者可以相同。*result 必須是可修改的左值，型別也必須是整數型別，但不能是純 char、bool、位元精確整數型別或列舉型別。
It is recommended to produce a diagnostic message if `type2` or `type3` are not suitable integer types, or if `*result` is not a modifiable lvalue of a suitable integer type.
若 type2 或 type3 不是合適的整數型別，或 *result 不是合適整數型別的可修改左值，建議實作發出診斷訊息。

### Example

Run this code

```c
#include <limits.h> #include <stdckdint.h> #include <stdint.h> #include <stdio.h> const char* text(bool overflow) { return overflow ? "Overflow" : "OK"; } int main() {  uint8_t x;  uint16_t y;  uint16_t result_uint16;  uint32_t result_uint32;  bool overflow;  x = 14;  y = 28;  overflow = ckd_add(&result_uint16, x, y);  printf("%u + %u => %u (%s)\n", x, y, result_uint16, text(overflow));  x = 14;  y = UINT16_MAX;  overflow = ckd_add(&result_uint16, x, y);  printf("%u + %u => %u (%s)\n", x, y, result_uint16, text(overflow));  x = 14;  y = UINT16_MAX;  overflow = ckd_add(&result_uint32, x, y);  printf("%u + %u => %u (%s)\n", x, y, result_uint32, text(overflow)); }
```

Output:

```c
14 + 28 => 42 (OK) 14 + 65535 => 13 (Overflow) 14 + 65535 => 65549 (OK)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.20.1 The ckd_ checked integer operation macros (p: 311)
7.20.1 ckd_ 整數檢查操作宏（頁：311）
7.20.1 ckd_ 整數檢查操作宏（頁：311）

### See also

ckd_sub
(C23)
|   | checked subtraction operation on two integers
(type-generic function macro)  |

ckd_mul
(C23)
|   | checked multiplication operation on two integers
(type-generic function macro)  |

C++ documentation for ckd_add

---
來源頁路徑：`en.cppreference.com/c/numeric/ckd_add.html`

# FLT_EVAL_METHOD

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<float.h>`
|   |  |   |  |

```c
#define FLT_EVAL_METHOD /* implementation-defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Specifies range and precision of floating-point values obtained from floating-point constants and from all operations (operators, implicit conversions of operands) except assignment, cast, and library function call.
指定從浮點常量以及除賦值、轉換和庫函式呼叫之外的所有操作（運運算元、運算元的隱式轉換）獲得的浮點值的範圍和精度。

| Value  |   | Explanation  |

| negative values except `-1`  |   | implementation-defined behavior  |

| `-1`  |   | the default precision is not known  |

| `0`  |   | all operations and constants evaluate in the range and precision of the type used. Additionally, `float_t` and `double_t` are equivalent to `float` and `double` respectively  |

| `1`  |   | all operations and constants evaluate in the range and precision of `double`. Additionally, both `float_t` and `double_t` are equivalent to `double`  |

| `2`  |   | all operations and constants evaluate in the range and precision of `long double`. Additionally, both `float_t` and `double_t` are equivalent to `long double`  |

### Notes

Regardless of the value of `FLT_EVAL_METHOD`, any floating-point expression may be *contracted*, that is, calculated as if all intermediate results have infinite range and precision (unless  #pragma `STDC FP_CONTRACT` is off).
無論 FLT_EVAL_METHOD 的值如何，任何浮點表示式都可能被收縮，即計算時如同所有中間結果都具有無限範圍和精度（除非 #pragma STDC FP_CONTRACT 為 off）。
Cast and assignment strip away any extraneous range and precision: this models the action of storing a value from an extended-precision FPU register into a standard-sized memory location.
轉換和賦值會去除任何多餘的範圍和精度：這模擬了將值從擴充套件精度 FPU 暫存器儲存到標準大小記憶體位置的操作。

### See also

float_t
(C99)
|   | most efficient floating-point type at least as wide as `float`
(typedef)   |

double_t
(C99)
|   | most efficient floating-point type at least as wide as `double`
(typedef)   |

C++ documentation for FLT_EVAL_METHOD

---
來源頁路徑：`en.cppreference.com/c/types/limits/FLT_EVAL_METHOD.html`

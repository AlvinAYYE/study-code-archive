# FLT_ROUNDS

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<float.h>`
|   |  |   |  |

```c
#define FLT_ROUNDS /* implementation defined */
```
|   |   |   |   |

|  |  |  |  |

Returns the current rounding direction of floating-point arithmetic operations.
傳回浮點運算的目前舍入方向。

| Value  |   | Explanation  |

| `-1`  |   | the default rounding direction is not known  |

| `0`  |   | toward zero; same meaning as FE_TOWARDZERO  |

| `1`  |   | to nearest, ties to even; same meaning as FE_TONEAREST  |

| `2`  |   | towards positive infinity; same meaning as FE_UPWARD  |

| `3`  |   | towards negative infinity; same meaning as FE_DOWNWARD  |

| `4` (since C23)  |   | to nearest, ties away from zero; same meaning as FE_TONEARESTFROMZERO  |

| other values  |   | implementation-defined behavior  |

### Notes

The rounding mode can be changed with fesetround and FLT_ROUNDS reflects that change.
舍入模式可以用 fesetround 更改，FLT_ROUNDS 反映該更改。

### See also

fegetroundfesetround
(C99)(C99)
|   | gets or sets rounding direction
(function)   |

FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD
(C99)
|   | floating-point rounding direction
(macro constant)   |

C++ documentation for FLT_ROUNDS

---
來源頁路徑：`en.cppreference.com/c/types/limits/FLT_ROUNDS.html`

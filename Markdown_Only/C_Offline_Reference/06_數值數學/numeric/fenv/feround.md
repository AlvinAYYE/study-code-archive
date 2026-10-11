# fegetround, fesetround

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int fesetround( int round );
```
|   |  (1)  |   |  (since C99)  |

```c
int fegetround();
```
|   |  (2)  |   |  (since C99)  |

|  |  |  |  |

1) Attempts to establish the floating-point rounding direction equal to the argument `round`, which is expected to be one of the floating-point rounding macros.
1) 嘗試將浮點捨入方向設為 round 指定的模式；round 必須是其中一個浮點捨入巨集。
2) Returns the value of the floating-point rounding macro that corresponds to the current rounding direction.
2) 回傳代表目前浮點捨入方向的巨集值。

### Parameters

| round  |   | -  |   | rounding direction, one of floating-point rounding macros  |

### Return value

1) `0` on success, non-zero otherwise.
1) 成功時回傳 0，否則回傳非零值。
2) the floating-point rounding macro describing the current rounding direction or a negative value if the direction cannot be determined.
2) 回傳代表目前捨入方向的浮點捨入巨集；若無法判定目前模式，則回傳負值。

### Notes

The current rounding mode, reflecting the effects of the most recent `fesetround`, can also be queried with FLT_ROUNDS.
目前的捨入模式反映最近一次 fesetround 的設定，也可透過 FLT_ROUNDS 查詢。

### Example

Run this code

```c
#include <fenv.h> #include <math.h> #include <stdio.h>   // #pragma STDC FENV_ACCESS ON void show_fe_current_rounding_direction(void) {  printf("current rounding direction: ");  switch (fegetround())  {  case FE_TONEAREST: printf ("FE_TONEAREST"); break;  case FE_DOWNWARD: printf ("FE_DOWNWARD"); break;  case FE_UPWARD: printf ("FE_UPWARD"); break;  case FE_TOWARDZERO: printf ("FE_TOWARDZERO"); break;  default: printf ("unknown");  };  printf("\n"); }   int main(void) {  /* Default rounding direction */  show_fe_current_rounding_direction();  printf("+11.5 -> %+4.1f\n", rint(+11.5)); /* midway between two integers */  printf("+12.5 -> %+4.1f\n", rint(+12.5)); /* midway between two integers */  /* Save current rounding direction. */  int curr_direction = fegetround();  /* Temporarily change current rounding direction. */  fesetround(FE_DOWNWARD);  show_fe_current_rounding_direction();  printf("+11.5 -> %+4.1f\n", rint(+11.5));  printf("+12.5 -> %+4.1f\n", rint(+12.5));  /* Restore default rounding direction. */  fesetround(curr_direction);  show_fe_current_rounding_direction();    return 0; }
```

Possible output:
可能的輸出：

```c
current rounding direction: FE_TONEAREST +11.5 -> +12.0 +12.5 -> +12.0 current rounding direction: FE_DOWNWARD +11.5 -> +11.0 +12.5 -> +12.0 current rounding direction: FE_TONEAREST
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.6.3.1 The fegetround function (p: TBD)
7.6.3.1 fegetround 函式 (p: TBD)
7.6.3.1 fegetround 函式 (p: TBD)

- 7.6.3.2 The fesetround function (p: TBD)
7.6.3.2 fesetround 函式 (p: TBD)
7.6.3.2 fesetround 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.6.3.1 The fegetround function (p: TBD)
7.6.3.1 fegetround 函式 (p: TBD)
7.6.3.1 fegetround 函式 (p: TBD)

- 7.6.3.2 The fesetround function (p: TBD)
7.6.3.2 fesetround 函式 (p: TBD)
7.6.3.2 fesetround 函式 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.3.1 The fegetround function (p: 212)
7.6.3.1 fegetround 函式 (p: 212)
7.6.3.1 fegetround 函式 (p: 212)

- 7.6.3.2 The fesetround function (p: 212-213)
7.6.3.2 fesetround 函式 (p: 212-213)
7.6.3.2 fesetround 函式 (p: 212-213)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.3.1 The fegetround function (p: 193)
7.6.3.1 fegetround 函式 (p: 193)
7.6.3.1 fegetround 函式 (p: 193)

- 7.6.3.2 The fesetround function (p: 193-194)
7.6.3.2 fesetround 函式 (p: 193-194)
7.6.3.2 fesetround 函式 (p: 193-194)

### See also

nearbyintnearbyintfnearbyintl
(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode
(function)   |

rintrintfrintllrintlrintflrintlllrintllrintfllrintl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode with
exception if the result differs
(function)   |

C++ documentation for fegetround, fesetround

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/feround.html`

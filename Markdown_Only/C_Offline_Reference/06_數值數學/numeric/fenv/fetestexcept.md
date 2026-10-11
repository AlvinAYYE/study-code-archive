# fetestexcept

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int fetestexcept( int excepts );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines which of the specified subset of the floating-point exceptions are currently set. The argument `excepts` is a bitwise OR of the floating-point exception macros.
檢查指定的浮點例外中，哪些目前已設置。excepts 是多個浮點例外巨集的位元 OR 結果。

### Parameters

| excepts  |   | -  |   | bitmask listing the exception flags to test  |

### Return value

Bitwise OR of the floating-point exception macros that are both included in `excepts` and correspond to floating-point exceptions currently set.
回傳值是 excepts 中目前已設置之浮點例外巨集的位元 OR 結果。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <fenv.h> #include <float.h>   #pragma STDC FENV_ACCESS ON   void show_fe_exceptions(void) {  printf("current exceptions raised: ");  if(fetestexcept(FE_DIVBYZERO)) printf(" FE_DIVBYZERO");  if(fetestexcept(FE_INEXACT)) printf(" FE_INEXACT");  if(fetestexcept(FE_INVALID)) printf(" FE_INVALID");  if(fetestexcept(FE_OVERFLOW)) printf(" FE_OVERFLOW");  if(fetestexcept(FE_UNDERFLOW)) printf(" FE_UNDERFLOW");  if(fetestexcept(FE_ALL_EXCEPT)==0) printf(" none");  printf("\n"); } int main(void) {  /* Show default set of exception flags. */  show_fe_exceptions();    /* Perform some computations which raise exceptions. */  printf("1.0/0.0 = %f\n", 1.0/0.0); /* FE_DIVBYZERO */  printf("1.0/10.0 = %f\n", 1.0/10.0); /* FE_INEXACT */  printf("sqrt(-1) = %f\n", sqrt(-1)); /* FE_INVALID */  printf("DBL_MAX*2.0 = %f\n", DBL_MAX*2.0); /* FE_INEXACT FE_OVERFLOW */  printf("nextafter(DBL_MIN/pow(2.0,52),0.0) = %.1f\n",  nextafter(DBL_MIN/pow(2.0,52),0.0)); /* FE_INEXACT FE_UNDERFLOW */  show_fe_exceptions();  return 0; }
```

Output:

```c
current exceptions raised: none 1.0/0.0 = inf 1.0/10.0 = 0.100000 sqrt(-1) = -nan DBL_MAX*2.0 = inf nextafter(DBL_MIN/pow(2.0,52),0.0) = 0.0 current exceptions raised: FE_DIVBYZERO FE_INEXACT FE_INVALID FE_OVERFLOW FE_UNDERFLOW
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.2.5 The fetestexcept function (p: 211-212)
7.6.2.5 fetestexcept 函式 (p: 211-212)
7.6.2.5 fetestexcept 函式 (p: 211-212)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.2.5 The fetestexcept function (p: 192-193)
7.6.2.5 fetestexcept 函式 (p: 192-193)
7.6.2.5 fetestexcept 函式 (p: 192-193)

### See also

feclearexcept
(C99)
|   | clears the specified floating-point status flags
(function)   |

C++ documentation for fetestexcept

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/fetestexcept.html`

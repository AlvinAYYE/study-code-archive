# FE_DFL_ENV

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
#define FE_DFL_ENV /*implementation defined*/
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The macro constant FE_DFL_ENV expands to an expression of type `const fenv_t*`, which points to a full copy of the default floating-point environment, that is, the environment as loaded at program startup.
FE_DFL_ENV 會展開成 const fenv_t * 型別的運算式，指向預設浮點環境的完整副本，也就是程式啟動時載入的環境。
Additional macros that begin with `FE_` followed by uppercase letters, and have the type `const fenv_t*`, may be supported by an implementation.
實作可以支援其他巨集；其名稱以 FE_ 開頭並接大寫字母，型別為 const fenv_t *。

### Example

Run this code

```c
#include <stdio.h> #include <fenv.h>   #pragma STDC FENV_ACCESS ON   void show_fe_exceptions(void) {  printf("current exceptions raised: ");  if(fetestexcept(FE_DIVBYZERO)) printf(" FE_DIVBYZERO");  if(fetestexcept(FE_INEXACT)) printf(" FE_INEXACT");  if(fetestexcept(FE_INVALID)) printf(" FE_INVALID");  if(fetestexcept(FE_OVERFLOW)) printf(" FE_OVERFLOW");  if(fetestexcept(FE_UNDERFLOW)) printf(" FE_UNDERFLOW");  if(fetestexcept(FE_ALL_EXCEPT)==0) printf(" none");  printf("\n"); } void show_fe_rounding_method(void) {  printf("current rounding method: ");  switch (fegetround()) {  case FE_TONEAREST: printf ("FE_TONEAREST"); break;  case FE_DOWNWARD: printf ("FE_DOWNWARD"); break;  case FE_UPWARD: printf ("FE_UPWARD"); break;  case FE_TOWARDZERO: printf ("FE_TOWARDZERO"); break;  default: printf ("unknown");  };  printf("\n"); }   void show_fe_environment(void) {  show_fe_exceptions();  show_fe_rounding_method(); }  int main() {  printf("On startup:\n");  show_fe_environment();    // Change environment  fesetround(FE_DOWNWARD); // change rounding mode  feraiseexcept(FE_INVALID); // raise exception  printf("\nBefore restoration:\n");  show_fe_environment();    fesetenv(FE_DFL_ENV); // restore  printf("\nAfter restoring default environment:\n");  show_fe_environment(); }
```

Output:

```c
On startup: current exceptions raised: none current rounding method: FE_TONEAREST Before restoration: current exceptions raised: FE_INVALID current rounding method: FE_DOWNWARD After restoring default environment: current exceptions raised: none current rounding method: FE_TONEAREST
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6/9 Floating-point environment <fenv.h> (p: 208)
7.6/9 浮點環境 <fenv.h> (p: 208)
7.6/9 浮點環境 <fenv.h> (p: 208)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6/8 Floating-point environment <fenv.h> (p: 188-189)
7.6/8 浮點環境 <fenv.h> (p: 188-189)
7.6/8 浮點環境 <fenv.h> (p: 188-189)

### See also

fegetenvfesetenv
(C99)
|   | saves or restores the current floating-point environment
(function)   |

feupdateenv
(C99)
|   | restores the floating-point environment and raises the previously raise exceptions
(function)   |

C++ documentation for FE_DFL_ENV

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/FE_DFL_ENV.html`

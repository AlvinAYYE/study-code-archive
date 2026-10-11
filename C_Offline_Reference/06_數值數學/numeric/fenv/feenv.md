# fegetenv, fesetenv

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int fegetenv( fenv_t* envp );
```
|   |  (1)  |   |  (since C99)  |

```c
int fesetenv( const fenv_t* envp );
```
|   |  (2)  |   |  (since C99)  |

|  |  |  |  |

1) Attempts to store the status of the floating-point environment in the object pointed to by `envp`.
1) 嘗試將目前的浮點環境狀態儲存到 envp 指向的物件。
2) Attempts to establish the floating-point environment from the object pointed to by `envp`. The value of that object must be previously obtained by a call to feholdexcept or `fegetenv` or be a floating-point macro constant. If any of the floating-point status flags are set in `envp`, they become set in the environment (and are then testable with fetestexcept), but the corresponding floating-point exceptions are not raised (execution continues uninterrupted)
2) 嘗試依據 envp 指向的物件建立浮點環境。該物件必須先前由 feholdexcept 或 fegetenv 取得，或是浮點環境巨集常數。若其中有已設置的浮點狀態旗標，這些旗標也會在新環境中設置（之後可用 fetestexcept 檢查），但不會引發對應的浮點例外，程式會繼續執行。

### Parameters

| envp  |   | -  |   | pointer to the object of type `fenv_t` which holds the status of the floating-point environment  |

### Return value

`0` on success, non-zero otherwise.
成功傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <fenv.h>   #pragma STDC FENV_ACCESS ON   void show_fe_exceptions(void) {  printf("current exceptions raised: ");  if(fetestexcept(FE_DIVBYZERO)) printf(" FE_DIVBYZERO");  if(fetestexcept(FE_INEXACT)) printf(" FE_INEXACT");  if(fetestexcept(FE_INVALID)) printf(" FE_INVALID");  if(fetestexcept(FE_OVERFLOW)) printf(" FE_OVERFLOW");  if(fetestexcept(FE_UNDERFLOW)) printf(" FE_UNDERFLOW");  if(fetestexcept(FE_ALL_EXCEPT)==0) printf(" none");  printf("\n"); } void show_fe_rounding_method(void) {  printf("current rounding method: ");  switch (fegetround()) {  case FE_TONEAREST: printf ("FE_TONEAREST"); break;  case FE_DOWNWARD: printf ("FE_DOWNWARD"); break;  case FE_UPWARD: printf ("FE_UPWARD"); break;  case FE_TOWARDZERO: printf ("FE_TOWARDZERO"); break;  default: printf ("unknown");  };  printf("\n"); } void show_fe_environment(void) {  show_fe_exceptions();  show_fe_rounding_method(); }    int main(void) {  fenv_t curr_env;  int rtn;    /* Show default environment. */  show_fe_environment();  printf("\n");    /* Perform some computation under default environment. */  printf("+11.5 -> %+4.1f\n", rint(+11.5)); /* midway between two integers */  printf("+12.5 -> %+4.1f\n", rint(+12.5)); /* midway between two integers */  show_fe_environment();  printf("\n");    /* Save current environment. */  rtn = fegetenv(&curr_env);    /* Perform some computation with new rounding method. */  feclearexcept(FE_ALL_EXCEPT);  fesetround(FE_DOWNWARD);  printf("1.0/0.0 = %f\n", 1.0/0.0);  printf("+11.5 -> %+4.1f\n", rint(+11.5));  printf("+12.5 -> %+4.1f\n", rint(+12.5));  show_fe_environment();  printf("\n");    /* Restore previous environment. */  rtn = fesetenv(&curr_env);  show_fe_environment();    return 0; }
```

Output:

```c
current exceptions raised: none current rounding method: FE_TONEAREST +11.5 -> +12.0 +12.5 -> +12.0 current exceptions raised: FE_INEXACT current rounding method: FE_TONEAREST 1.0/0.0 = inf +11.5 -> +11.0 +12.5 -> +12.0 current exceptions raised: FE_DIVBYZERO FE_INEXACT current rounding method: FE_DOWNWARD current exceptions raised: FE_INEXACT current rounding method: FE_TONEAREST
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.4.1 The fegetenv function (p: 213)
7.6.4.1 fegetenv 函式 (p: 213)
7.6.4.1 fegetenv 函式 (p: 213)

- 7.6.4.3 The fesetenv function (p: 214)
7.6.4.3 fesetenv 函式 (p: 214)
7.6.4.3 fesetenv 函式 (p: 214)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.4.1 The fegetenv function (p: 194)
7.6.4.1 fegetenv 函式 (p: 194)
7.6.4.1 fegetenv 函式 (p: 194)

- 7.6.4.3 The fesetenv function (p: 195)
7.6.4.3 fesetenv 函式 (p: 195)
7.6.4.3 fesetenv 函式 (p: 195)

### See also

feholdexcept
(C99)
|   | saves the environment, clears all status flags and ignores all future errors
(function)   |

feupdateenv
(C99)
|   | restores the floating-point environment and raises the previously raise exceptions
(function)   |

FE_DFL_ENV
(C99)
|   | default floating-point environment
(macro constant)   |

C++ documentation for fegetenv, fesetenv

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/feenv.html`

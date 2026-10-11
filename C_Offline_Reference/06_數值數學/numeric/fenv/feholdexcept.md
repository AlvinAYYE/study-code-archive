# feholdexcept

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int feholdexcept( fenv_t* envp );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

First, saves the current floating-point environment to the object pointed to by `envp` (similar to fegetenv), then clears all floating-point status flags, and then installs the non-stop mode: future floating-point exceptions will not interrupt execution (will not trap), until the floating-point environment is restored by feupdateenv or fesetenv.
先將目前的浮點環境儲存到 envp 指向的物件（類似 fegetenv），再清除所有浮點狀態旗標，並啟用非停止模式。在 feupdateenv 或 fesetenv 還原浮點環境之前，之後發生的浮點例外都不會中斷程式執行或觸發陷阱。
This function may be used in the beginning of a subroutine that must hide the floating-point exceptions it may raise from the caller. If only some exceptions must be suppressed, while others must be reported, the non-stop mode is usually ended with a call to feupdateenv after clearing the unwanted exceptions.
若子程式可能引發浮點例外，但不應讓呼叫端察覺，可在子程式開頭使用此函式。若只想暫時忽略部分例外、仍須回報其他例外，通常會先清除不需回報的例外，再呼叫 feupdateenv 結束非停止模式。

### Parameters

| envp  |   | -  |   | pointer to the object of type `fenv_t` where the floating-point environment will be stored  |

### Return value

`0` on success, non-zero otherwise.
成功傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <stdio.h> #include <fenv.h> #include <float.h>   #pragma STDC FENV_ACCESS ON   void show_fe_exceptions(void) {  printf("current exceptions raised: ");  if(fetestexcept(FE_DIVBYZERO)) printf(" FE_DIVBYZERO");  if(fetestexcept(FE_INEXACT)) printf(" FE_INEXACT");  if(fetestexcept(FE_INVALID)) printf(" FE_INVALID");  if(fetestexcept(FE_OVERFLOW)) printf(" FE_OVERFLOW");  if(fetestexcept(FE_UNDERFLOW)) printf(" FE_UNDERFLOW");  if(fetestexcept(FE_ALL_EXCEPT)==0) printf(" none");  printf("\n"); } double x2 (double x) /* times two */ {  fenv_t curr_excepts;    /* Save and clear current f-p environment. */  feholdexcept(&curr_excepts);    /* Raise inexact and overflow exceptions. */  printf("In x2(): x = %f\n", x=x*2.0);  show_fe_exceptions();  feclearexcept(FE_INEXACT); /* hide inexact exception from caller */  /* Merge caller's exceptions (FE_INVALID) */  /* with remaining x2's exceptions (FE_OVERFLOW). */  feupdateenv(&curr_excepts);  return x; } int main(void) {   feclearexcept(FE_ALL_EXCEPT);  feraiseexcept(FE_INVALID); /* some computation with invalid argument */  show_fe_exceptions();  printf("x2(DBL_MAX) = %f\n", x2(DBL_MAX));  show_fe_exceptions();    return 0; }
```

Output:

```c
current exceptions raised: FE_INVALID In x2(): x = inf current exceptions raised: FE_INEXACT FE_OVERFLOW x2(DBL_MAX) = inf current exceptions raised: FE_INVALID FE_OVERFLOW
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.4.2 The feholdexcept function (p: 213-214)
7.6.4.2 feholdexcept 函式 (p: 213-214)
7.6.4.2 feholdexcept 函式 (p: 213-214)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.4.2 The feholdexcept function (p: 194-195)
7.6.4.2 feholdexcept 函式 (p: 194-195)
7.6.4.2 feholdexcept 函式 (p: 194-195)

### See also

feupdateenv
(C99)
|   | restores the floating-point environment and raises the previously raise exceptions
(function)   |

fegetenvfesetenv
(C99)
|   | saves or restores the current floating-point environment
(function)   |

FE_DFL_ENV
(C99)
|   | default floating-point environment
(macro constant)   |

C++ documentation for feholdexcept

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/feholdexcept.html`

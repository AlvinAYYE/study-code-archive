# fegetexceptflag, fesetexceptflag

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int fegetexceptflag( fexcept_t* flagp, int excepts );
```
|   |  (1)  |   |  (since C99)  |

```c
int fesetexceptflag( const fexcept_t* flagp, int excepts );
```
|   |  (2)  |   |  (since C99)  |

|  |  |  |  |

1) Attempts to obtain the full contents of the floating-point exception flags that are listed in the bitmask argument `excepts`, which is a bitwise OR of the floating-point exception macros.
1) 嘗試取得 excepts 所指定之浮點例外旗標的完整內容。excepts 是多個浮點例外巨集的位元 OR 結果。
2) Attempts to copy the full contents of the floating-point exception flags that are listed in `excepts` from `flagp` into the floating-point environment. Does not raise any exceptions, only modifies the flags.
2) 嘗試將 flagp 中 excepts 指定之浮點例外旗標的完整內容複製到浮點環境。此操作只會修改旗標，不會引發例外。
The full contents of a floating-point exception flag is not necessarily a boolean value indicating whether the exception is raised or cleared. For example, it may be a struct which includes the boolean status and the address of the code that triggered the exception. These functions obtain all such content and obtain/store it in `flagp` in implementation-defined format.
浮點例外旗標不一定只是表示例外是否發生的布林值；例如，它可能是包含布林狀態和觸發例外之程式碼位置的結構。這些函式會取得所有相關資訊，並以實作定義的格式存取 flagp。

### Parameters

| flagp  |   | -  |   | pointer to an `fexcept_t` object where the flags will be stored or read from  |

| excepts  |   | -  |   | bitmask listing the exception flags to get/set  |

### Return value

`0` on success, non-zero otherwise.
成功傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <stdio.h> #include <fenv.h>   #pragma STDC FENV_ACCESS ON   void show_fe_exceptions(void) {  printf("current exceptions raised: ");  if(fetestexcept(FE_DIVBYZERO)) printf(" FE_DIVBYZERO");  if(fetestexcept(FE_INEXACT)) printf(" FE_INEXACT");  if(fetestexcept(FE_INVALID)) printf(" FE_INVALID");  if(fetestexcept(FE_OVERFLOW)) printf(" FE_OVERFLOW");  if(fetestexcept(FE_UNDERFLOW)) printf(" FE_UNDERFLOW");  if(fetestexcept(FE_ALL_EXCEPT)==0) printf(" none");  printf("\n"); } int main(void) {  fexcept_t excepts;    /* Setup a "current" set of exception flags. */  feraiseexcept(FE_INVALID);  show_fe_exceptions();    /* Save current exception flags. */  fegetexceptflag(&excepts,FE_ALL_EXCEPT);    /* Temporarily raise two other exceptions. */  feclearexcept(FE_ALL_EXCEPT);  feraiseexcept(FE_OVERFLOW | FE_INEXACT);  show_fe_exceptions();    /* Restore previous exception flags. */  fesetexceptflag(&excepts,FE_ALL_EXCEPT);  show_fe_exceptions();  return 0; }
```

Output:

```c
current exceptions raised: FE_INVALID current exceptions raised: FE_INEXACT FE_OVERFLOW current exceptions raised: FE_INVALID
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.2.2 The fegetexceptflag function (p: 210)
7.6.2.2 fegetexceptflag 函式 (p: 210)
7.6.2.2 fegetexceptflag 函式 (p: 210)

- 7.6.2.4 The fesetexceptflag function (p: 211)
7.6.2.4 fesetexceptflag 函式 (p: 211)
7.6.2.4 fesetexceptflag 函式 (p: 211)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.2.2 The fegetexceptflag function (p: 191)
7.6.2.2 fegetexceptflag 函式 (p: 191)
7.6.2.2 fegetexceptflag 函式 (p: 191)

- 7.6.2.4 The fesetexceptflag function (p: 192)
7.6.2.4 fesetexceptflag 函式 (p: 192)
7.6.2.4 fesetexceptflag 函式 (p: 192)

### See also

C++ documentation for fegetexceptflag, fesetexceptflag

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/feexceptflag.html`

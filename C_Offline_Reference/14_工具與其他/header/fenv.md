# Standard library header <fenv.h> (C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the floating-point environment library.
該標頭檔是浮點環境庫的一部分。

### Types

Defined in header ``<fenv.h>``

| `fenv_t`  |   | The type representing the entire floating-point environment  |

| `fexcept_t`  |   | The type representing all floating-point status flags collectively  |

### Functions

feclearexcept
(C99)
|   | clears the specified floating-point status flags
(function)   |

fetestexcept
(C99)
|   | determines which of the specified floating-point status flags are set
(function)   |

feraiseexcept
(C99)
|   | raises the specified floating-point exceptions
(function)   |

fegetexceptflagfesetexceptflag
(C99)(C99)
|   | copies the state of the specified floating-point status flags from or to the floating-point environment
(function)   |

fegetroundfesetround
(C99)(C99)
|   | gets or sets rounding direction
(function)   |

fegetenvfesetenv
(C99)
|   | saves or restores the current floating-point environment
(function)   |

feholdexcept
(C99)
|   | saves the environment, clears all status flags and ignores all future errors
(function)   |

feupdateenv
(C99)
|   | restores the floating-point environment and raises the previously raise exceptions
(function)   |

### Macros

FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW
(C99)
|   | floating-point exceptions
(macro constant)   |

FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD
(C99)
|   | floating-point rounding direction
(macro constant)   |

FE_DFL_ENV
(C99)
|   | default floating-point environment
(macro constant)   |

### Synopsis

```c
#define __STDC_VERSION_FENV_H__ 202311L #define FE_ALL_EXCEPT /* see description */ #define FE_DIVBYZERO /* see description */ #define FE_INEXACT /* see description */ #define FE_INVALID /* see description */ #define FE_OVERFLOW /* see description */ #define FE_UNDERFLOW /* see description */ #define FE_DOWNWARD /* see description */ #define FE_TONEARESTFROMZERO /* see description */ #define FE_TONEAREST /* see description */ #define FE_TOWARDZERO /* see description */ #define FE_UPWARD /* see description */ #define FE_DFL_ENV /* see description */ #define FE_DFL_MODE /* see description */ #define fenv_t /* see description */ #define fexcept_t /* see description */ #define femode_t /* see description */ #pragma STDC FENV_ACCESS /*on-off-switch*/ #pragma STDC FENV_ROUND direction #pragma STDC FENV_ROUND FE_DYNAMIC // functions int feclearexcept(int excepts); int fegetexceptflag(fexcept_t* flagp, int excepts); int feraiseexcept(int excepts); int fesetexcept(int excepts); int fesetexceptflag(const fexcept_t* flagp, int excepts); int fetestexceptflag(const fexcept_t* flagp, int excepts); int fetestexcept(int excepts); int fegetmode(femode_t* modep); int fegetround(void); int fesetmode(const femode_t* modep); int fesetround(int rnd); int fegetenv(fenv_t* envp); int feholdexcept(fenv_t* envp); int fesetenv(const fenv_t* envp); int feupdateenv(const fenv_t* envp); // Only if the implementation defines __STDC_IEC_60559_DFP__: #define FE_DEC_DOWNWARD /* implementation-defined */ #define FE_DEC_TONEARESTFROMZERO /* implementation-defined */ #define FE_DEC_TONEAREST /* implementation-defined */ #define FE_DEC_TOWARDZERO /* implementation-defined */ #define FE_DEC_UPWARD /* implementation-defined */ #pragma STDC FENV_DEC_ROUND /*dec-direction*/ int fe_dec_getround(void); int fe_dec_setround(int rnd); // Only if the implementation follows the recommended practice from F.2.2: #define FE_SNANS_ALWAYS_SIGNAL /* implementation-defined */
```

---
來源頁路徑：`en.cppreference.com/c/header/fenv.html`

# Floating-point environment

> 來源：cppreference C 語言參考文件（離線轉換版）。

The floating-point environment is the set of floating-point status flags and control modes supported by the implementation. It is thread-local, each thread inherits the initial state of its floating-point environment from the parent thread. Floating-point operations modify the floating-point status flags to indicate abnormal results or auxiliary information. The state of floating-point control modes affects the outcomes of some floating-point operations.
浮點環境包含實作支援的浮點狀態旗標與控制模式。它屬於執行緒區域；每個執行緒建立時，會從父執行緒繼承初始的浮點環境。浮點運算會更新狀態旗標，指出異常結果或其他資訊；控制模式則會影響部分浮點運算的結果。
The floating-point environment access and modification is only meaningful when  #pragma STDC FENV_ACCESS is set to `ON`. Otherwise the implementation is free to assume that floating-point control modes are always the default ones and that floating-point status flags are never tested or modified. In practice, few current compilers, such as HP aCC, Oracle Studio, and IBM XL, support the `#pragma` explicitly, but most compilers allow meaningful access to the floating-point environment anyway.
只有將 #pragma STDC FENV_ACCESS 設為 ON，存取或修改浮點環境才有作用。否則，實作可以假設浮點控制模式始終是預設值，而且程式不會測試或修改浮點狀態旗標。目前只有少數編譯器（例如 HP aCC、Oracle Studio 和 IBM XL）明確支援這項 #pragma；多數編譯器仍允許程式實際存取浮點環境。

### Types

Defined in header `<fenv.h>`

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

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.6 Floating-point environment <fenv.h> (p: TBD)
7.6 浮點環境 <fenv.h> （頁碼：待定）
7.6 浮點環境 <fenv.h> （頁碼：待定）

- 7.31.4 Floating-point environment <fenv.h> (p: TBD)
7.31.4 浮點環境 <fenv.h> （頁碼：待定）
7.31.4 浮點環境 <fenv.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.6 Floating-point environment <fenv.h> (p: 150-156)
7.6 浮點環境 <fenv.h> （頁碼：150-156）
7.6 浮點環境 <fenv.h> （頁碼：150-156）

- 7.31.4 Floating-point environment <fenv.h> (p: 332)
7.31.4 浮點環境 <fenv.h> （頁碼：332）
7.31.4 浮點環境 <fenv.h> （頁碼：332）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6 Floating-point environment <fenv.h> (p: 206-215)
7.6 浮點環境 <fenv.h> （頁碼：206-215）
7.6 浮點環境 <fenv.h> （頁碼：206-215）

- 7.31.4 Floating-point environment <fenv.h> (p: 455)
7.31.4 浮點環境 <fenv.h> （頁碼：455）
7.31.4 浮點環境 <fenv.h> （頁碼：455）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6 Floating-point environment <fenv.h> (p: 187-196)
7.6 浮點環境 <fenv.h> （頁碼：187-196）
7.6 浮點環境 <fenv.h> （頁碼：187-196）

### See also

C++ documentation for Floating-point environment

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv.html`

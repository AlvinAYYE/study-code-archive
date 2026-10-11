# Standard library header <stdarg.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header provides support for varying arguments.
該標頭檔提供對變長參數的支援。

#####  Types

va_list
|   | holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)   |

#####  Macros

va_start
|   | enables access to variadic function arguments
(function macro)   |

va_arg
|   | accesses the next variadic function argument
(function macro)   |

va_copy
(C99)
|   | makes a copy of the variadic function arguments
(function macro)   |

va_end
|   | ends traversal of the variadic function arguments
(function macro)   |

### Synopsis

```c
#define __STDC_VERSION_STDARG_H__ 202311L typedef /*unspecified*/ va_list; /*type*/ va_arg(va_list ap, /*type*/); void va_copy(va_list dest, va_list src); void va_end(va_list ap); void va_start(va_list ap, ...);
```

---
來源頁路徑：`en.cppreference.com/c/header/stdarg.html`

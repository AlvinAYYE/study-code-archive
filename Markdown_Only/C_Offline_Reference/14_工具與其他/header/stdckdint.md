# Standard library header <stdckdint.h> (C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of numeric library, in particular, it provides type-generic macros for checked integer arithmetic.
這個標頭檔屬於數值函式庫，提供可執行檢查式整數運算的泛型巨集。

### Functions

ckd_add
(C23)
|   | checked addition operation on two integers
(type-generic function macro)  |

ckd_sub
(C23)
|   | checked subtraction operation on two integers
(type-generic function macro)  |

ckd_mul
(C23)
|   | checked multiplication operation on two integers
(type-generic function macro)  |

### Synopsis

```c
#define __STDC_VERSION_STDCKDINT_H__ 202311L bool ckd_add(/*type1*/* result, /*type2*/ a, /*type3*/ b); bool ckd_sub(/*type1*/* result, /*type2*/ a, /*type3*/ b); bool ckd_mul(/*type1*/* result, /*type2*/ a, /*type3*/ b);
```

---
來源頁路徑：`en.cppreference.com/c/header/stdckdint.html`

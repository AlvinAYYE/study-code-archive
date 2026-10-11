# Real and complex

> 來源：cppreference C 語言參考文件（離線轉換版）。

When a value of real type is converted to a complex type, the real part of the complex result value is determined by the rules of conversion to the corresponding real type (see  Real floating types) and the imaginary part of the complex result value is a positive zero or an unsigned zero.
當實數型別的值轉換為複數型別時，複數 結果值的實部由到相應實數型別的轉換規則確定（見 Real floating types），複數結果值的虛部是正零或無符號零。
When a value of complex type is converted to a real type, the imaginary part of the complex value is discarded and the value of the real part is converted according to the conversion rules for the corresponding real type (see  Real floating types).
當複數型別的值轉換為實數型別時，複數 值的虛部被丟棄，實部的值根據相應實數型別的轉換 規則進行轉換（見 Real floating types）。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  /* a real type to a complex type */  double d = 1.0;  double _Complex zd;  zd = d;  printf("%.1f%+.1fi\n", creal(zd), cimag(zd));  /* a complex type to a real type */  zd = 3.0 + 4.0*I;  d = zd;  printf("%.1f\n", d);  return 0; }
```

Possible output:
可能的輸出：

```c
1.0+0.0i 3.0
```

---
來源頁路徑：`en.cppreference.com/c/language/real_and_complex.html`

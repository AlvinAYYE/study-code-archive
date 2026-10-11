# CMPLXF, CMPLX, CMPLXL

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex CMPLXF( float real, float imag );
```
|   |   |   |  (since C11)  |

```c
double complex CMPLX( double real, double imag );
```
|   |   |   |  (since C11)  |

```c
long double complex CMPLXL( long double real, long double imag );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Each of these macros expands to an expression that evaluates to the value of the specified complex type, with the real part having the value of `real` (converted to the specified argument type) and the imaginary part having the value of `imag` (converted to the specified argument type)
每個巨集都會展開成運算式，求值後得到指定複數型別的值；實部是 real 轉換成指定型別後的值，虛部則是 imag 轉換後的值。
The expressions are suitable for use as initializers for objects with static or thread storage duration, as long as the expressions `real` and `imag` are also suitable.
只要 real 和 imag 適合作為常數運算式，這些運算式就能用來初始化靜態或執行緒儲存期的物件。

### Parameters

| real  |   | -  |   | the real part of the complex number to return  |

| imag  |   | -  |   | the imaginary part of the complex number to return  |

### Return value

A complex number composed of `real` and `imag` as the real and imaginary parts.
以 real 為實部、imag 為虛部所構成的複數。

### Notes

These macros are implemented as if the imaginary types are supported (even if they are otherwise not supported and _Imaginary_I is actually undefined) and as if defined as follows:
這些巨集的行為就像實作支援虛數型別一樣（即使實際上不支援，且未定義 _Imaginary_I），等同於以下列方式定義：

```c
#define CMPLX(x, y) ((double complex)((double)(x) + _Imaginary_I * (double)(y))) #define CMPLXF(x, y) ((float complex)((float)(x) + _Imaginary_I * (float)(y))) #define CMPLXL(x, y) ((long double complex)((long double)(x) + \  _Imaginary_I * (long double)(y)))
```

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = CMPLX(0.0, -0.0);  printf("z = %.1f%+.1fi\n", creal(z), cimag(z)); }
```

Output:

```c
z = 0.0-0.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.9.3 The CMPLX macros (p: 197)
7.3.9.3 CMPLX 宏 (p: 197)
7.3.9.3 CMPLX 宏 (p: 197)

### See also

_Imaginary_I
(C99)
|   | the imaginary unit constant i
(macro constant)   |

C++ documentation for complex

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/CMPLX.html`

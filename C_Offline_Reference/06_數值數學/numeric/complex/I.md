# I

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
#define I /* unspecified */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `I` macro expands to either _Complex_I or _Imaginary_I. If the implementation does not support imaginary types, then the macro always expands to _Complex_I.
I 會展開成 _Complex_I 或 _Imaginary_I。若實作不支援虛數型別，I 一律展開成 _Complex_I。
A program may undefine and perhaps then redefine the macro `I`.
程式可以取消定義 I 巨集，之後也可以重新定義。

### Notes

The macro is not named `i`, which is the name of the imaginary unit in mathematics, because the name `i` was already used in many C programs, e.g. as a loop counter variable.
這個巨集沒有命名為 i（數學上虛數單位的符號），因為許多 C 程式已用 i 作為變數名稱，例如迴圈計數器。
The macro `I` is often used to form complex numbers, with expressions such as `x + y*I`. If `I` is defined as _Complex_I, then such expression may create a value with imaginary component `+0.0` even when `y` is `-0.0`, which is significant for complex number functions with branch cuts. The macro CMPLX provides a way to construct a complex number precisely.
宏 I 常用於構造複數，例如表示式 x + y * I 。 若 I 被定義為 _Complex_I，則即使 y 為 -0.0，此類表示式也可能建立出虛部分量為 +0.0 的值，這對於帶分支切割的複數函式而言很重要。宏 CMPLX 提供了一種精確構造複數的方式。
GCC provides a non-portable extension that allows imaginary constants to be specified with the suffix `i` on integer literals: `1.0fi`, `1.0i`, and `1.0li` are imaginary units in GNU C. A similar approach is part of standard C++ as of C++14 (`1.0if`, `1.0i`, and `1.0il` are the imaginary units in C++)
GCC 提供不可攜的擴充語法，可在數值常值後加上 i 來表示虛數常數。在 GNU C 中，1.0fi、1.0i 和 1.0li 代表虛數單位。類似語法自 C++14 起納入標準 C++（寫作 1.0if、1.0i 和 1.0il）。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  printf("I = %.1f%+.1fi\n", creal(I), cimag(I));  double complex z1 = I * I; // imaginary unit squared  printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));  double complex z = 1.0 + 2.0*I; // usual way to form a complex number pre-C11  printf("z = %.1f%+.1fi\n", creal(z), cimag(z)); }
```

Output:

```c
I = 0.0+1.0i I * I = -1.0+0.0i z = 1.0+2.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.1/6 I (p: 188)
7.3.1/6 I (p: 188)
7.3.1/6 I (p: 188)

- G.6/1 I (p: 537)
G.6/1 I (p: 537)
G.6/1 I (p: 537)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.1/4 I (p: 170)
7.3.1/4 I (p: 170)
7.3.1/4 I (p: 170)

- G.6/1 I (p: 472)
G.6/1 I (p: 472)
G.6/1 I (p: 472)

### See also

_Imaginary_I
(C99)
|   | the imaginary unit constant i
(macro constant)   |

_Complex_I
(C99)
|   | the complex unit constant i
(macro constant)   |

CMPLXCMPLXFCMPLXL
(C11)(C11)(C11)
|   | constructs a complex number from real and imaginary parts
(function macro)   |

C++ documentation for operator""i

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/I.html`

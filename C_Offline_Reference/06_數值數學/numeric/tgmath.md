# Type-generic math (since C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

The header <tgmath.h> includes the headers <math.h> and <complex.h> and defines several type-generic macros that determine which real or, when applicable, complex function to call based on the types of the arguments.
標頭檔 <tgmath.h> 會一併包含 <math.h> 和 <complex.h>，並定義多個型別通用巨集。這些巨集會依照參數的型別，決定要呼叫哪個實數函式；適用時也可能呼叫複數函式。
For each macro, the parameters whose corresponding real type in the unsuffixed <math.h> function is `double` are known as *generic parameters* (for example, both parameters of pow are generic parameters, but only the first parameter of scalbn is a generic parameter).
對每個巨集而言，在 <math.h> 中對應到無字尾函式之 double 實數版本的參數，稱為通用參數。例如，pow 的兩個參數都是通用參數，scalbn 則只有第一個參數是通用參數。
When a <tgmath.h>'s macro is used the types of the arguments passed to the generic parameters determine which function is selected by the macro as described below. If the types of the arguments are not compatible with the parameter types of the selected function, the behavior is undefined (e.g. if a complex argument is passed into a real-only <tgmath.h>'s macro: `float complex fc; ceil(fc);` or `double complex dc; double d; fmax(dc, d);` are examples of undefined behavior).
使用 <tgmath.h> 的巨集時，傳給通用參數的參數型別會決定巨集選用哪個函式，規則如下。若參數型別與所選函式的參數型別不相容，行為未定義。例如，把複數參數傳給只接受實數的 <tgmath.h> 巨集就會造成未定義行為：float complex fc; ceil(fc); 以及 double complex dc; double d; fmax(dc, d); 都是這種情況。
Note: type-generic macros were implemented in implementation-defined manner in C99, but C11 keyword _Generic makes it possible to implement these macros in portable manner.
注意：C99 並未規定型別通用巨集的實作方式；C11 加入關鍵字 _Generic 後，才得以可攜地實作這些巨集。

### Complex/real type-generic macros
複數/實數型別泛型宏

For all functions that have both real and complex counterparts, a type-generic macro `XXX` exists, which calls either of:
對於所有同時具有實數和複數對應版本的函式，都存在一個型別泛型宏 XXX ，它會呼叫以下之一：

- real function:

- `float` variant `XXXf`
float 變體 XXXf

- `double` variant `XXX`
double 變體 XXX

- `long double` variant `XXXl`
long double 變體 XXXl
float 變體 XXXf double 變體 XXX long double 變體 XXXl

- complex function:
複數函式：

- `float` variant `cXXXf`
float 變體 cXXXf

- `double` variant `cXXX`
double 變體 cXXX

- `long double` variant `cXXXl`
long double 變體 cXXXl
float 變體 cXXXf double 變體 cXXX long double 變體 cXXXl

An exception to the above rule is the `fabs` macro (see the table below).
上述規則的一個例外是 fabs 宏（見下表）。
The function to call is determined as follows:
要呼叫的函式按如下方式確定：

- If any of the arguments for the generic parameters is imaginary, the behavior is specified on each function reference page individually (in particular, `sin`, `cos`, `tag`, `cosh`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` call *real* functions, the return types of `sin`, `tan`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` are imaginary, and the return types of `cos` and `cosh` are real).
若泛型參數的任一實參為虛數，則其行為在各函式參考頁中分別規定（特別是， sin 、 cos 、 tag 、 cosh 、 sinh 、 tanh 、 asin 、 atan 、 asinh 和 atanh 呼叫實數函式； sin 、 tan 、 sinh 、 tanh 、 asin 、 atan 、 asinh 和 atanh 的傳回型別為虛數，而 cos 和 cosh 的傳回型別為實數）。

- If any of the arguments for the generic parameters is complex, then the complex function is called, otherwise the real function is called.
若泛型參數的任一實參為複數，則呼叫複數函式，否則呼叫實數函式。

- If any of the arguments for the generic parameters is `long double`, then the `long double` variant is called. Otherwise, if any of the parameters is `double` or integer, then the `double` variant is called. Otherwise, `float` variant is called.
若泛型參數的任一實參為 long double ，則呼叫 long double 變體。否則，若任一參數為 double 或整數，則呼叫 double 變體。否則呼叫 float 變體。

The type-generic macros are as follows:
型別泛型宏如下：

| Type-generic
macro  |   | Real function
variants  |   | Complex function
variants  |

|    |   | `float`  |   | `double`  |   | `long double`  |   | `float`  |   | `double`  |   | `long double`  |

| fabs  |   | fabsf  |   | fabs  |   | fabsl  |   | cabsf  |   | cabs  |   | cabsl  |

| exp  |   | expf  |   | exp  |   | expl  |   | cexpf  |   | cexp  |   | cexpl  |

| log  |   | logf  |   | log  |   | logl  |   | clogf  |   | clog  |   | clogl  |

| pow  |   | powf  |   | pow  |   | powl  |   | cpowf  |   | cpow  |   | cpowl  |

| sqrt  |   | sqrtf  |   | sqrt  |   | sqrtl  |   | csqrtf  |   | csqrt  |   | csqrtl  |

| sin  |   | sinf  |   | sin  |   | sinl  |   | csinf  |   | csin  |   | csinl  |

| cos  |   | cosf  |   | cos  |   | cosl  |   | ccosf  |   | ccos  |   | ccosl  |

| tan  |   | tanf  |   | tan  |   | tanl  |   | ctanf  |   | ctan  |   | ctanl  |

| asin  |   | asinf  |   | asin  |   | asinl  |   | casinf  |   | casin  |   | casinl  |

| acos  |   | acosf  |   | acos  |   | acosl  |   | cacosf  |   | cacos  |   | cacosl  |

| atan  |   | atanf  |   | atan  |   | atanl  |   | catanf  |   | catan  |   | catanl  |

| sinh  |   | sinhf  |   | sinh  |   | sinhl  |   | csinhf  |   | csinh  |   | csinhl  |

| cosh  |   | coshf  |   | cosh  |   | coshl  |   | ccoshf  |   | ccosh  |   | ccoshl  |

| tanh  |   | tanhf  |   | tanh  |   | tanhl  |   | ctanhf  |   | ctanh  |   | ctanhl  |

| asinh  |   | asinhf  |   | asinh  |   | asinhl  |   | casinhf  |   | casinh  |   | casinhl  |

| acosh  |   | acoshf  |   | acosh  |   | acoshl  |   | cacoshf  |   | cacosh  |   | cacoshl  |

| atanh  |   | atanhf  |   | atanh  |   | atanhl  |   | catanhf  |   | catanh  |   | catanhl  |

### Real-only functions
僅實數函式

For all functions that do not have complex counterparts, with the exception of `modf`, a type-generic macro `XXX` exists, which calls either of the variants of a real function:
對於所有沒有複數對應版本的函式（ modf 除外），都存在一個型別泛型宏 XXX ，它會呼叫實數函式的某個變體：

- `float` variant `XXXf`
float 變體 XXXf

- `double` variant `XXX`
double 變體 XXX

- `long double` variant `XXXl`
long double 變體 XXXl

The function to call is determined as follows:
要呼叫的函式按如下方式確定：

- If any of the arguments for the generic parameters is `long double`, then the `long double` variant is called. Otherwise, if any of the arguments for the generic parameters is `double`, then the `double` variant is called. Otherwise, `float` variant is called.
若泛型參數的任一實參為 long double ，則呼叫 long double 變體。否則，若泛型參數的任一實參為 double ，則呼叫 double 變體。否則呼叫 float 變體。

| Type-generic
macro  |   | Real function
variants  |

|    |   | `float`  |   | `double`  |   | `long double`  |

| atan2  |   | atan2f  |   | atan2  |   | atan2l  |

| cbrt  |   | cbrtf  |   | cbrt  |   | cbrtl  |

| ceil  |   | ceilf  |   | ceil  |   | ceill  |

| copysign  |   | copysignf  |   | copysign  |   | copysignl  |

| erf  |   | erff  |   | erf  |   | erfl  |

| erfc  |   | erfcf  |   | erfc  |   | erfcl  |

| exp2  |   | exp2f  |   | exp2  |   | exp2l  |

| expm1  |   | expm1f  |   | expm1  |   | expm1l  |

| fdim  |   | fdimf  |   | fdim  |   | fdiml  |

| floor  |   | floorf  |   | floor  |   | floorl  |

| fma  |   | fmaf  |   | fma  |   | fmal  |

| fmax  |   | fmaxf  |   | fmax  |   | fmaxl  |

| fmin  |   | fminf  |   | fmin  |   | fminl  |

| fmod  |   | fmodf  |   | fmod  |   | fmodl  |

| frexp  |   | frexpf  |   | frexp  |   | frexpl  |

| hypot  |   | hypotf  |   | hypot  |   | hypotl  |

| ilogb  |   | ilogbf  |   | ilogb  |   | ilogbl  |

| ldexp  |   | ldexpf  |   | ldexp  |   | ldexpl  |

| lgamma  |   | lgammaf  |   | lgamma  |   | lgammal  |

| llrint  |   | llrintf  |   | llrint  |   | llrintl  |

| llround  |   | llroundf  |   | llround  |   | llroundl  |

| log10  |   | log10f  |   | log10  |   | log10l  |

| log1p  |   | log1pf  |   | log1p  |   | log1pl  |

| log2  |   | log2f  |   | log2  |   | log2l  |

| logb  |   | logbf  |   | logb  |   | logbl  |

| lrint  |   | lrintf  |   | lrint  |   | lrintl  |

| lround  |   | lroundf  |   | lround  |   | lroundl  |

| nearbyint  |   | nearbyintf  |   | nearbyint  |   | nearbyintl  |

| nextafter  |   | nextafterf  |   | nextafter  |   | nextafterl  |

| nexttoward  |   | nexttowardf  |   | nexttoward  |   | nexttowardl  |

| remainder  |   | remainderf  |   | remainder  |   | remainderl  |

| remquo  |   | remquof  |   | remquo  |   | remquol  |

| rint  |   | rintf  |   | rint  |   | rintl  |

| round  |   | roundf  |   | round  |   | roundl  |

| scalbln  |   | scalblnf  |   | scalbln  |   | scalblnl  |

| scalbn  |   | scalbnf  |   | scalbn  |   | scalbnl  |

| tgamma  |   | tgammaf  |   | tgamma  |   | tgammal  |

| trunc  |   | truncf  |   | trunc  |   | truncl  |

### Complex-only functions
僅複數函式

For all complex number functions that do not have real counterparts, a type-generic macro `cXXX` exists, which calls either of the variants of a complex function:
對於所有沒有實數對應版本的複數函式，都存在一個型別泛型宏 cXXX ，它會呼叫複數函式的某個變體：

- `float complex` variant `cXXXf`
float 複數變體 cXXXf

- `double complex` variant `cXXX`
double 複數變體 cXXX

- `long double complex` variant `cXXXl`
long double 複數變體 cXXXl

The function to call is determined as follows:
要呼叫的函式按如下方式確定：

- If any of the arguments for the generic parameters is real, complex, or imaginary, then the appropriate complex function is called.
若泛型參數的任一實參為實數、複數或虛數，則呼叫相應的複數函式。

| Type-generic
macro  |   | Complex function
variants  |

|    |   | `float`  |   | `double`  |   | `long double`  |

| carg  |   | cargf  |   | carg  |   | cargl  |

| conj  |   | conjf  |   | conj  |   | conjl  |

| creal  |   | crealf  |   | creal  |   | creall  |

| cimag  |   | cimagf  |   | cimag  |   | cimagl  |

| cproj  |   | cprojf  |   | cproj  |   | cprojl  |

### Example

Run this code

```c
#include <stdio.h> #include <tgmath.h> int main(void) {  int i = 2;  printf("sqrt(2) = %f\n", sqrt(i)); // argument type is int, calls sqrt  float f = 0.5;  printf("sin(0.5f) = %f\n", sin(f)); // argument type is float, calls sinf  float complex dc = 1 + 0.5*I;  float complex z = sqrt(dc); // argument type is float complex, calls csqrtf  printf("sqrt(1 + 0.5i) = %f+%fi\n",  creal(z), // argument type is float complex, calls crealf  cimag(z)); // argument type is float complex, calls cimagf }
```

Output:

```c
sqrt(2) = 1.414214 sin(0.5f) = 0.479426 sqrt(1 + 0.5i) = 1.029086+0.242934i
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

---
來源頁路徑：`en.cppreference.com/c/numeric/tgmath.html`

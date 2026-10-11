# Arithmetic types

> 來源：cppreference C 語言參考文件（離線轉換版）。

(See also type for type system overview and the list of type-related utilities that are provided by the C library.)
（另見 type 以瞭解型別系統概述以及 C 庫提供的與型別相關的工具列表。）

### Boolean type

- `_Bool` (also accessible as the macro bool)(until C23)`bool`(since C23) — type, capable of holding one of the two values: `1` and `0` (also accessible as the macros true and false)(until C23)`true` and `false`(since C23).

Note that conversion to _Bool(until C23)bool(since C23) does not work the same as conversion to other integer types: `(bool)0.5` evaluates to `true`, whereas `(int)0.5` evaluates to `0`.
|   | (since C99) |

### Character types
字元型別

- `signed char` — type for signed character representation.
signed char —— 用於有符號字元表示的型別。

- `unsigned char` — type for unsigned character representation. Also used to inspect object representations (raw memory).
unsigned char —— 用於無符號字元表示的型別。也用於檢查物件表示（原始記憶體）。

- `char` — type for character representation. Equivalent to either `signed char` or `unsigned char` (which one is implementation-defined and may be controlled by a compiler commandline switch), but `char` is a distinct type, different from both `signed char` and `unsigned char`.
char：用來表示字元的型別。它的實際表示方式等同於 signed char 或 unsigned char 其中之一，由實作決定，也可能受編譯器選項影響；不過 char 本身是獨立型別，與這兩種型別都不同。
signed char —— 用於有符號字元表示的型別。unsigned char —— 用於無符號字元表示的型別。也用於檢查物件表示（原始記憶體）。char —— 用於字元表示的型別。等價於 signed char 或 unsigned char 之一（哪一個是實現定義的，可以由編譯器命令列開關控制），但 char 是一個不同的型別，與 signed char 和 unsigned char 都不同。

Note that the standard library also defines typedef names wchar_t, char16_t and char32_t(since C11) to represent wide characters and char8_t for UTF-8 characters(since C23).
注意：標準函式庫也定義了 wchar_t、char16_t 和 char32_t（C11 起）等 typedef 名稱來表示寬字元，並在 C23 起提供 char8_t 表示 UTF-8 字元。

### Integer types

- `short int` (also accessible as `short`, may use the keyword `signed`)
short int（也可用 short 訪問，可以使用關鍵字 signed）

- `unsigned short int` (also accessible as `unsigned short`)
unsigned short int（也可用 unsigned short 訪問）

- `int` (also accessible as `signed int`)
int（也可用 signed int 訪問）

This is the most optimal integer type for the platform, and is guaranteed to be at least 16 bits. Most current systems use 32 bits (see Data models below).
這是該平臺最優的整數型別，保證至少 16 位。大多數目前系統使用 32 位（見下文 Data models）。

- `unsigned int` (also accessible as `unsigned`), the unsigned counterpart of `int`, implementing modulo arithmetic. Suitable for bit manipulations.
unsigned int（也可用 unsigned 訪問），是 int 的無符號對應型別，實現模算術。適用於位操作。

- `long int` (also accessible as `long`)
long int（也可用 long 訪問）

- `unsigned long int` (also accessible as `unsigned long`)
unsigned long int（也可用 unsigned long 訪問）
short int（也可用 short 訪問，可以使用關鍵字 signed）unsigned short int（也可用 unsigned short 訪問）int（也可用 signed int 訪問）這是該平臺最優的整數型別，保證至少 16 位。大多數目前系統使用 32 位（見下文 Data models）。unsigned int（也可用 unsigned 訪問），是 int 的無符號對應型別，實現模算術。適用於位操作。long int（也可用 long 訪問）unsigned long int（也可用 unsigned long 訪問）

- `long long int` (also accessible as `long long`)

- `unsigned long long int` (also accessible as `unsigned long long`)
|   | (since C99) |

- `_BitInt(n)` (also accessible as `signed _BitInt(n)`), the bit-precise signed integer types (where `n` is replaced by an integer constant expression denoting the precise width (including the sign bit), that cannot be larger than BITINT_MAXWIDTH from <limits.h>)

- `unsigned _BitInt(n)`, the bit-precise unsigned integer types (where `n` is replaced by an integer constant expression denoting the precise width, that cannot be larger than BITINT_MAXWIDTH from <limits.h>)
|   | (since C23) |

Note: as with all type specifiers, any order is permitted: `unsigned long long int` and `long int unsigned long` name the same type.
注意：與所有型別說明符一樣，任何順序都是允許的：unsigned long long int 和 long int unsigned long 命名同一型別。
The following table summarizes all available integer types and their properties:
下表彙總了所有可用的整數型別及其屬性：

| Type specifier  |   | Equivalent type  |   | Width in bits by data model  |

| C standard  |   | LP32  |   | ILP32  |   | LLP64  |   | LP64  |

`char`
|   | `char`  |   | at least
**8**  |   | **8**  |   | **8**  |   | **8**  |   | **8**  |

`signed char`
|   | `signed char`  |

`unsigned char`
|   | `unsigned char`  |

`short`
|   | `short int`  |   | at least
**16**  |   | **16**  |   | **16**  |   | **16**  |   | **16**  |

`short int`

`signed short`

`signed short int`

`unsigned short`
|   | `unsigned short int`  |

`unsigned short int`

`int`
|   | `int`  |   | at least
**16**  |   | **16**  |   | **32**  |   | **32**  |   | **32**  |

`signed`

`signed int`

`unsigned`
|   | `unsigned int`  |

`unsigned int`

`long`
|   | `long int`  |   | at least
**32**  |   | **32**  |   | **32**  |   | **32**  |   | **64**  |

`long int`

`signed long`

`signed long int`

`unsigned long`
|   | `unsigned long int`  |

`unsigned long int`

`long long`
|   | `long long int`
(C99)  |   | at least
**64**  |   | **64**  |   | **64**  |   | **64**  |   | **64**  |

`long long int`

`signed long long`

`signed long long int`

`unsigned long long`
|   | `unsigned long long int`
(C99)  |

`unsigned long long int`

Besides the minimal bit counts, the C Standard guarantees that
除了最小位數之外，C 標準還保證

`1` == `sizeof(char)` `≤` `sizeof(short)` `≤` `sizeof(int)` `≤` `sizeof(long)` `≤` `sizeof(long long)`.
1 == sizeof ( char ) ≤ sizeof ( short ) ≤ sizeof ( int ) ≤ sizeof ( long ) ≤ sizeof ( long long )。

Note: this allows the extreme case in which byte are sized 64 bits, all types (including `char`) are 64 bits wide, and `sizeof` returns `1` for every type.
注意：這允許極端情況，即位元組大小為 64 位，所有型別（包括 char）都是 64 位寬，且 sizeof 對每個型別都傳回 1。
Note: integer arithmetic is defined differently for the signed and unsigned integer types. See arithmetic operators, in particular integer overflows.
注意：整數算術對有符號和無符號整數型別的定義不同。參見算術運運算元，特別是整數溢位。

#### Data models

The choices made by each implementation about the sizes of the fundamental types are collectively known as *data model*. Four data models found wide acceptance:
每個實現關於基本型別大小的選擇統稱為 data model。有四種 data model 被廣泛接受：
32 bit systems:
32 位系統：

- **LP32** or **2/4/4** (`int` is 16-bit, `long` and pointer are 32-bit)
LP32 或 2/4/4（int 為 16 位，long 和 pointer 為 32 位）

- Win16 API

- **ILP32** or **4/4/4** (`int`, `long`, and pointer are 32-bit);
ILP32 或 4/4/4（int、long 和 pointer 為 32 位）；

- Win32 API

- Unix and Unix-like systems (Linux, Mac OS X)
Unix 和類 Unix 系統（Linux、Mac OS X）
Win32 API Unix 和類 Unix 系統（Linux、Mac OS X）
LP32 或 2/4/4（int 為 16 位，long 和 pointer 為 32 位）Win16 API ILP32 或 4/4/4（int、long 和 pointer 為 32 位）；Win32 API Unix 和類 Unix 系統（Linux、Mac OS X）

64 bit systems:
64 位系統：

- **LLP64** or **4/4/8** (`int` and `long` are 32-bit, pointer is 64-bit)
LLP64 或 4/4/8（int 和 long 為 32 位，pointer 為 64 位）

- Win64 API

- **LP64** or **4/8/8** (`int` is 32-bit, `long` and pointer are 64-bit)
LP64 或 4/8/8（int 為 32 位，long 和 pointer 為 64 位）

- Unix and Unix-like systems (Linux, Mac OS X)
Unix 和類 Unix 系統（Linux、Mac OS X）
Unix 和類 Unix 系統（Linux、Mac OS X）
LLP64 或 4/4/8（int 和 long 為 32 位，pointer 為 64 位）Win64 API LP64 或 4/8/8（int 為 32 位，long 和 pointer 為 64 位）Unix 和類 Unix 系統（Linux、Mac OS X）

Other models are very rare. For example, **ILP64** (**8/8/8**: `int`, `long`, and pointer are 64-bit) only appeared in some early 64-bit Unix systems (e.g. Unicos on Cray).
其他模型非常罕見。例如，ILP64（8/8/8：int、long 和 pointer 為 64 位）僅出現在一些早期的 64 位 Unix 系統中（例如 Cray 上的 Unicos）。
Note that exact-width integer types are available in <stdint.h> since C99.
注意精確寬度整數型別自 C99 起在 <stdint.h> 中可用。

### Real floating types
實浮點型別

C has three or six(since C23) types for representing real floating-point values:
C 有三種或六種（C23 起）用於表示實浮點值的型別：

- `float` — single precision floating-point type. Matches IEEE-754 binary32 format if supported.
float —— 單精度浮點型別。如果支援，則匹配 IEEE-754 binary32 格式。

- `double` — double precision floating-point type. Matches IEEE-754 `binary64` format if supported.
double —— 雙精度浮點型別。如果支援，則匹配 IEEE-754 binary64 格式。

- `long double` — extended precision floating-point type. Matches IEEE-754 `binary128` format if supported, otherwise matches IEEE-754 `binary64`-extended format if supported, otherwise matches some non-IEEE-754 extended floating-point format as long as its precision is better than `binary64` and range is at least as good as `binary64`, otherwise matches IEEE-754 `binary64` format.
- `binary128` format is used by some HP-UX, SPARC, MIPS, ARM64, and z/OS implementations.
binary128 格式被一些 HP-UX、SPARC、MIPS、ARM64 和 z/OS 實現使用。

- The most well known IEEE-754 `binary64`-extended format is 80-bit x87 extended precision format. It is used by many x86 and x86-64 implementations (a notable exception is MSVC, which implements `long double` in the same format as `double`, i.e. `binary64`).
最著名的 IEEE-754 binary64-extended 格式是 80 位 x87 擴充套件精度格式。它被許多 x86 和 x86-64 實現使用（一個顯著的例外是 MSVC，它以與 double 相同的格式即 binary64 實現 long double）。
long double —— 擴充套件精度浮點型別。如果支援，則匹配 IEEE-754 binary128 格式；否則，如果支援，則匹配 IEEE-754 binary64-extended 格式；否則匹配某種非 IEEE-754 擴充套件浮點格式，只要其精度優於 binary64 且範圍至少與 binary64 一樣好；否則匹配 IEEE-754 binary64 格式。binary128 格式被一些 HP-UX、SPARC、MIPS、ARM64 和 z/OS 實現使用。最著名的 IEEE-754 binary64-extended 格式是 80 位 x87 擴充套件精度格式。它被許多 x86 和 x86-64 實現使用（一個顯著的例外是 MSVC，它以與 double 相同的格式即 binary64 實現 long double）。
float —— 單精度浮點型別。如果支援，則匹配 IEEE-754 binary32 格式。double —— 雙精度浮點型別。如果支援，則匹配 IEEE-754 binary64 格式。long double —— 擴充套件精度浮點型別。如果支援，則匹配 IEEE-754 binary128 格式；否則，如果支援，則匹配 IEEE-754 binary64-extended 格式；否則匹配某種非 IEEE-754 擴充套件浮點格式，只要其精度優於 binary64 且範圍至少與 binary64 一樣好；否則匹配 IEEE-754 binary64 格式。binary128 格式被一些 HP-UX、SPARC、MIPS、ARM64 和 z/OS 實現使用。最著名的 IEEE-754 binary64-extended 格式是 80 位 x87 擴充套件精度格式。它被許多 x86 和 x86-64 實現使用（一個顯著的例外是 MSVC，它以與 double 相同的格式即 binary64 實現 long double）。

If the implementation predefines the macro constant `__STDC_IEC_60559_DFP__`, the following decimal floating-point types are also supported.
- `_Decimal32` — Represents IEEE-754 decimal32 format.

- `_Decimal64` — Represents IEEE-754 decimal64 format.

- `_Decimal128` — Represents IEEE-754 decimal128 format.
Otherwise, these decimal floating-point types are not supported.
|   | (since C23) |

Floating-point types may support special values:
浮點型別可能支援特殊值：

- *infinity* (positive and negative), see INFINITY
無窮大（正和負），參見 INFINITY

- the *negative zero*, `-0.0`. It compares equal to the positive zero, but is meaningful in some arithmetic operations, e.g. `1.0 / 0.0 == INFINITY`, but `1.0 / -0.0 == -INFINITY`)
負零 -0.0。它與正零比較相等，但在某些算術運算中有意義，例如 1.0 / 0.0 == INFINITY，但 1.0 / -0.0 == -INFINITY）

- *not-a-number* (NaN), which does not compare equal with anything (including itself). Multiple bit patterns represent NaNs, see nan, NAN. Note that C takes no special notice of signaling NaNs (specified by IEEE-754), and treats all NaNs as quiet.
非數（NaN），它與任何值（包括它自身）比較都不相等。多個位模式表示 NaN，參見 nan、NAN。注意 C 對 signaling NaN（由 IEEE-754 指定）沒有特別注意，並將所有 NaN 視為 quiet。

Real floating-point numbers may be used with arithmetic operators `**+**` `**-**` `**/**` `*****` and various mathematical functions from <math.h>. Both built-in operators and library functions may raise floating-point exceptions and set errno as described in math_errhandling.
實浮點數可用於算術運運算元 + - / * 以及 <math.h> 中的各種數學函式。內建運運算元和庫函式都可能引發浮點異常並設定 errno，如 math_errhandling 中所述。
Floating-point expressions may have greater range and precision than indicated by their types, see FLT_EVAL_METHOD. Assignment, return, and cast force the range and precision to the one associated with the declared type.
浮點表示式可能具有比其型別所指示的更大範圍和精度，參見 FLT_EVAL_METHOD。賦值、傳回和強制型別轉換將範圍和精度強制為與宣告型別相關聯的值。
Floating-point expressions may also be *contracted*, that is, calculated as if all intermediate values have infinite range and precision, see  #pragma STDC FP_CONTRACT.
浮點表示式也可以被收縮，即計算時彷彿所有中間值都有無限的範圍和精度，參見 #pragma STDC FP_CONTRACT。
Some operations on floating-point numbers are affected by and modify the state of the floating-point environment (most notably, the rounding direction).
某些對浮點數的操作會受影響於並修改浮點環境的狀態（最顯著的是舍入方向）。
Implicit conversions are defined between real floating types and integer, complex, and imaginary types.
實浮點型別與整數、複數和虛數型別之間定義了隱式轉換。
See Limits of floating-point types and the <math.h> library for additional details, limits, and properties of the floating-point types.
浮點型別的詳細資訊、限制與屬性，請參閱 Limits of floating-point types 和 <math.h> 函式庫。

### Complex floating types

Complex floating types model the mathematical complex number, that is the numbers that can be written as a sum of a real number and a real number multiplied by the imaginary unit: a + bi
The three complex types are

- `float _Complex` (also available as `float complex` if <complex.h> is included)

- `double _Complex` (also available as `double complex` if <complex.h> is included)

- `long double _Complex` (also available as `long double complex` if <complex.h> is included)

Note: as with all type specifiers, any order is permitted: `long double complex`, `complex long double`, and even `double complex long` name the same type.

Run this code

```c
#include <complex.h> #include <stdio.h> int main(void) { double complex z = 1 + 2*I; z = 1 / z; printf("1/(1.0+2.0i) = %.1f%+.1fi\n", creal(z), cimag(z)); }
```

Output:

```c
1/(1.0+2.0i) = 0.2-0.4i
```

If the macro constant `__STDC_NO_COMPLEX__` is defined by the implementation, the complex types (as well as the library header <complex.h>) are not provided.
|   | (since C11) |

Each complex type has the same object representation and alignment requirements as an array of two elements of the corresponding real type (`float` for `float complex`, `double` for `double complex`, `long double` for `long double complex`). The first element of the array holds the real part, and the second element of the array holds the imaginary component.

```c
float a[4] = {1, 2, 3, 4}; float complex z1, z2; memcpy(&z1, a, sizeof z1); // z1 becomes 1.0 + 2.0i memcpy(&z2, a+2, sizeof z2); // z2 becomes 3.0 + 4.0i
```

Complex numbers may be used with arithmetic operators `**+**` `**-**` `*****` and `**/**`, possibly mixed with imaginary and real numbers. There are many mathematical functions defined for complex numbers in <complex.h>. Both built-in operators and library functions may raise floating-point exceptions and set errno as described in math_errhandling.
Increment and decrement are not defined for complex types.
Relational operators are not defined for complex types (there is no notion of "less than").

|  | This section is incomplete
Reason: review other ops, link library  |

Implicit conversions are defined between complex types and other arithmetic types.
In order to support the one-infinity model of complex number arithmetic, C regards any complex value with at least one infinite part as an infinity even if its other part is a NaN, guarantees that all operators and functions honor basic properties of infinities and provides cproj to map all infinities to the canonical one (see arithmetic operators for the exact rules).

Run this code

```c
#include <complex.h> #include <math.h> #include <stdio.h> int main(void) { double complex z = (1 + 0*I) * (INFINITY + I*INFINITY); // textbook formula would give // (1+i0)(∞+i∞) ⇒ (1×∞ – 0×∞) + i(0×∞+1×∞) ⇒ NaN + I*NaN // but C gives a complex infinity printf("%f%+f*i\n", creal(z), cimag(z)); // textbook formula would give // cexp(∞+iNaN) ⇒ exp(∞)×(cis(NaN)) ⇒ NaN + I*NaN // but C gives ±∞+i*nan double complex y = cexp(INFINITY + I*NAN); printf("%f%+f*i\n", creal(y), cimag(y)); }
```

Possible output:

```c
inf+inf*i inf+nan*i
```

C also treats multiple infinities so as to preserve directional information where possible, despite the inherent limitations of the Cartesian representation:
multiplying the imaginary unit by real infinity gives the correctly-signed imaginary infinity: i × ∞ = i∞. Also, i × (∞ – i∞) = ∞ + i∞ indicates the reasonable quadrant.

|  | This section is incomplete
Reason: wording  |

### Imaginary floating types

Imaginary floating types model the mathematical imaginary numbers, that is numbers that can be written as a real number multiplied by the imaginary unit: bi The three imaginary types are

- `float _Imaginary` (also available as `float imaginary` if <complex.h> is included)

- `double _Imaginary` (also available as `double imaginary` if <complex.h> is included)

- `long double _Imaginary` (also available as `long double imaginary` if <complex.h> is included)

Note: as with all type specifiers, any order is permitted: `long double imaginary`, `imaginary long double`, and even `double imaginary long` name the same type.

Run this code

```c
#include <complex.h> #include <stdio.h> int main(void) { double imaginary z = 3*I; z = 1 / z; printf("1/(3.0i) = %+.1fi\n", cimag(z)); }
```

Output:

```c
1/(3.0i) = -0.3i
```

An implementation that defines `__STDC_IEC_559_COMPLEX__` is recommended, but not required to support imaginary numbers. POSIX recommends checking if the macro _Imaginary_I is defined to identify imaginary number support.
|   | (until C11) |

Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__`(until C23)`__STDC_IEC_60559_COMPLEX__`(since C23) is defined.
|   | (since C11) |

Each of the three imaginary types has the same object representation and alignment requirement as its *corresponding real type* (`float` for `float imaginary`, `double` for `double imaginary`, `long double` for `long double imaginary`).
Note: despite that, imaginary types are distinct and not compatible with their corresponding real types, which prohibits aliasing.
Imaginary numbers may be used with arithmetic operators `**+**` `**-**` `*****` and `**/**`, possibly mixed with complex and real numbers. There are many mathematical functions defined for imaginary numbers in <complex.h>. Both built-in operators and library functions may raise floating-point exceptions and set errno as described in math_errhandling.
Increment and decrement are not defined for imaginary types.

|  | This section is incomplete
Reason: review other ops, link library  |

Implicit conversions are defined between imaginary types and other arithmetic types.
The imaginary numbers make it possible to express all complex numbers using the natural notation `x + I*y` (where I is defined as _Imaginary_I). Without imaginary types, certain special complex values cannot be created naturally. For example, if I is defined as _Complex_I, then writing `0.0 + I*INFINITY` gives NaN as the real part, and `CMPLX(0.0, INFINITY)` must be used instead. Same goes for the numbers with the negative zero imaginary component, which are meaningful when working with the library functions with branch cuts, such as csqrt: `1.0 - 0.0*I` results in the positive zero imaginary component if I is defined as _Complex_I and the negative zero imaginary part requires the use of CMPLX or conj.
Imaginary types also simplify implementations; multiplication of an imaginary by a complex can be implemented straightforwardly with two multiplications if the imaginary types are supported, instead of four multiplications and two additions.
|   | (since C99) |

### Keywords

- bool, true, false, char, int, short, long, signed, unsigned, float, double.
bool、true、false、char、int、short、long、signed、unsigned、float、double。

- _Bool, _BitInt, _Complex, _Imaginary, _Decimal32, _Decimal64, _Decimal128.
_Bool、_BitInt、_Complex、_Imaginary、_Decimal32、_Decimal64、_Decimal128。

### Range of values
值的範圍

The following table provides a reference for the limits of common numeric representations.
下表提供了常見數值表示的限制參考。
Prior to C23, the C Standard allowed any signed integer representation, and the minimum guaranteed range of N-bit signed integers was from −(2N−1−1)−(2N−1−1)-(2N-1
-1) to +2N−1−1+2N−1−1+2N-1
-1 (e.g. **-127** to **127** for a signed 8-bit type), which corresponds to the limits of one's complement or sign-and-magnitude.
在 C23 之前，C 標準允許任何有符號整數表示，N 位有符號整數的最小保證範圍是從 − ( 2 N − 1 − 1 ) − ( 2 N − 1 − 1 ) -(2 N-1 -1) 到 + 2 N − 1 − 1 + 2 N − 1 − 1 +2 N-1 -1（例如有符號 8 位型別為 -127 到 127），這對應於反碼或原碼錶示的限制。
However, all popular data models (including all of ILP32, LP32, LP64, LLP64) and almost all C compilers use two's complement representation (the only known exceptions are some compilers for UNISYS), and as of C23, it is the only representation allowed by the standard, with the guaranteed range from −2N−1−2N−1-2N-1
to +2N−1−1+2N−1−1+2N-1
-1 (e.g. **-128** to **127** for a signed 8-bit type).
然而，所有流行的資料模型（包括 ILP32、LP32、LP64、LLP64）和幾乎所有 C 編譯器都使用補碼錶示（唯一已知的例外是一些用於 UNISYS 的編譯器），並且從 C23 起，它是標準允許的唯一表示，保證範圍從 − 2 N − 1 − 2 N − 1 -2 N-1 到 + 2 N − 1 − 1 + 2 N − 1 − 1 +2 N-1 -1（例如有符號 8 位型別為 -128 到 127）。

| Type  |   | Size in bits  |   | Format  |   | Value range  |

| Approximate  |   | Exact  |

| character  |   | 8  |   | signed  |   |   |   | **−128** to **127**  |

| unsigned  |   |   |   | **0** to **255**  |

| 16  |   | UTF-16  |   |   |   | **0** to **65535**  |

| 32  |   | UTF-32  |   |   |   | **0** to **1114111** (**0x10ffff**)  |

| integer  |   | 16  |   | signed  |   | **± 3.27 · 10**  |   | **−32768** to **32767**  |

| unsigned  |   | **0** to **6.55 · 10**  |   | **0** to **65535**  |

| 32  |   | signed  |   | **± 2.14 · 10**  |   | **−2,147,483,648** to **2,147,483,647**  |

| unsigned  |   | **0** to **4.29 · 10**  |   | **0** to **4,294,967,295**  |

| 64  |   | signed  |   | **± 9.22 · 10**  |   | **−9,223,372,036,854,775,808** to **9,223,372,036,854,775,807**  |

| unsigned  |   | **0** to **1.84 · 10**  |   | **0** to **18,446,744,073,709,551,615**  |

| binary
floating-
point  |   | 32  |   | IEEE-754  |   |

- min subnormal:
**± 1.401,298,4 · 10**

- min normal:
**± 1.175,494,3 · 10**

- max:
**± 3.402,823,4 · 10**

|   |

- min subnormal:
**±0x1p−149**

- min normal:
**±0x1p−126**

- max:
**±0x1.fffffep+127**

| 64  |   | IEEE-754  |   |

- min subnormal:
**± 4.940,656,458,412 · 10**

- min normal:
**± 2.225,073,858,507,201,4 · 10**

- max:
**± 1.797,693,134,862,315,7 · 10**

|   |

- min subnormal:
**±0x1p−1074**

- min normal:
**±0x1p−1022**

- max:
**±0x1.fffffffffffffp+1023**

| 80  |   | x86  |   |

- min subnormal:
**± 3.645,199,531,882,474,602,528
 · 10**

- min normal:
**± 3.362,103,143,112,093,506,263
 · 10**

- max:
**± 1.189,731,495,357,231,765,021
 · 10**

|   |

- min subnormal:
**±0x1p−16445**

- min normal:
**±0x1p−16382**

- max:
**±0x1.fffffffffffffffep+16383**

| 128  |   | IEEE-754  |   |

- min subnormal:
**± 6.475,175,119,438,025,110,924,
438,958,227,646,552,5 · 10**

- min normal:
**± 3.362,103,143,112,093,506,262,
677,817,321,752,602,6 · 10**

- max:
**± 1.189,731,495,357,231,765,085,
759,326,628,007,016,2 · 10**

|   |

- min subnormal:
**±0x1p−16494**

- min normal:
**±0x1p−16382**

- max:
**±0x1.ffffffffffffffffffffffffffff
p+16383**

| decimal
floating-
point  |   | 32  |   | IEEE-754  |   |   |   |

- min subnormal:
**± 1 · 10**

- min normal:
**± 1 · 10**

- max:
**± 9.999'999 · 10**

| 64  |   | IEEE-754  |   |   |   |

- min subnormal:
**± 1 · 10**

- min normal:
**± 1 · 10**

- max:
**± 9.999'999'999'999'999 · 10**

| 128  |   | IEEE-754  |   |   |   |

- min subnormal:
**± 1 · 10**

- min normal:
**± 1 · 10**

- max:
**± 9.999'999'999'999'999'999'
999'999'999'999'999 · 10**

- ↑ The object representation usually occupies 96/128 bits on 32/64-bit platforms respectively.
↑ 物件表示通常分別在 32/64 位平臺上佔用 96/128 位。

Note: actual (as opposed to guaranteed minimal) ranges are available in the library headers <limits.h> and <float.h>.
注意：實際（相對於保證的最小）範圍可在庫標頭檔 <limits.h> 和 <float.h> 中找到。

### See also

C++ documentation for Fundamental types

---
來源頁路徑：`en.cppreference.com/c/language/arithmetic_types.html`

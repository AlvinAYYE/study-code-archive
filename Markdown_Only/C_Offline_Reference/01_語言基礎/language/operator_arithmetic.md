# Arithmetic operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Arithmetic operators apply standard mathematical operations to their operands.
算術運運算元對其運算元應用標準數學運算。

|  | This section is incomplete
Reason: consider a more general-purpose ToC for this and other tables that cover multiple topics  |

| Operator  |   | Operator name  |   | Example  |   | Result  |

| `+`  |   | unary plus  |   | `+a`  |   | the value of **a** after promotions  |

| `-`  |   | unary minus  |   | `-a`  |   | the negative of **a**  |

| `+`  |   | addition  |   | `a + b`  |   | the addition of **a** and **b**  |

| `-`  |   | subtraction  |   | `a - b`  |   | the subtraction of **b** from **a**  |

| `*`  |   | product  |   | `a * b`  |   | the product of **a** and **b**  |

| `/`  |   | division  |   | `a / b`  |   | the division of **a** by **b**  |

| `%`  |   | remainder  |   | `a % b`  |   | the remainder of **a** divided by **b**  |

| `~`  |   | bitwise NOT  |   | `~a`  |   | the bitwise NOT of **a**  |

| `&`  |   | bitwise AND  |   | `a & b`  |   | the bitwise AND of **a** and **b**  |

| `|`  |   | bitwise OR  |   | `a | b`  |   | the bitwise OR of **a** and **b**  |

| `^`  |   | bitwise XOR  |   | `a ^ b`  |   | the bitwise XOR of **a** and **b**  |

| `<<`  |   | bitwise left shift  |   | `a << b`  |   | **a** left shifted by **b**  |

| `>>`  |   | bitwise right shift  |   | `a >> b`  |   | **a** right shifted by **b**  |

### Overflows

Unsigned integer arithmetic is always performed modulo 2n
where n is the number of bits in that particular integer. E.g. for `unsigned int`, adding one to UINT_MAX gives `0`, and subtracting one from `0` gives UINT_MAX.
無符號整數算術總是按 2 n 取模進行，其中 n 是該特定整數的位數。例如對於 unsigned int ，給 UINT_MAX 加 1 得到 0 ，從 0 減 1 得到 UINT_MAX 。
When signed integer arithmetic operation overflows (the result does not fit in the result type), the behavior is undefined: it may wrap around according to the rules of the representation (typically 2's complement), it may trap on some platforms or due to compiler options (e.g. `-ftrapv` in GCC and Clang), or may be completely optimized out by the compiler.
當有符號整數算術運算溢位（結果不適合結果型別）時，行為是未定義的：它可能按照表示規則（通常是補碼）迴繞，可能在某些平臺上或由於編譯器選項（例如 GCC 和 Clang 中的 -ftrapv ）觸發陷阱，也可能被編譯器完全最佳化掉。

#### Floating-point environment

If  #pragma STDC FENV_ACCESS is set to `ON`, all floating-point arithmetic operators obey the current floating-point rounding direction and report floating-point arithmetic errors as specified in math_errhandling unless part of a static initializer (in which case floating-point exceptions are not raised and the rounding mode is to nearest)
如果 #pragma STDC FENV_ACCESS 設定為 ON ，所有浮點算術運運算元都遵守目前的浮點舍入方向，並按照 math_errhandling 中的規定報告浮點算術錯誤，除非是靜態初始化器的一部分（在這種情況下不引發浮點異常，舍入模式為向最近舍入）

#### Floating-point contraction

Unless  #pragma STDC FP_CONTRACT is set to `OFF`, all floating-point arithmetic may be performed as if the intermediate results have infinite range and precision, that is optimizations that omit rounding errors and floating-point exceptions that would be observed if the expression was evaluated exactly as written. For example, allows the implementation of `(x*y) + z` with a single fused multiply-add CPU instruction or optimization of `a = x*x*x*x;` as `tmp = x*x; a = tmp*tmp`.
除非 #pragma STDC FP_CONTRACT 設定為 OFF ，否則所有浮點算術都可以執行，好像中間結果具有無限的範圍和精度，即省略舍入誤差和如果表示式嚴格按照書寫形式求值時會觀察到的浮點異常的最佳化。例如，允許用單條融合乘加 CPU 指令實現 ( x * y ) + z ，或將 a = x * x * x * x ; 最佳化為 tmp = x * x ; a = tmp * tmp 。
Unrelated to contracting, intermediate results of floating-point arithmetic may have range and precision that is different from the one indicated by its type, see FLT_EVAL_METHOD
與收縮無關，浮點算術的中間結果可能具有與其型別所指示不同的範圍和精度，參見 FLT_EVAL_METHOD

### Unary arithmetic
一元算術

The unary arithmetic operator expressions have the form
一元算術運運算元表示式具有以下形式

|   |

| `**+**` expression  |   | (1)  |   |   |

|   |

| `**-**` expression  |   | (2)  |   |   |

|   |

1) unary plus (promotion)

2) unary minus (negation)

| expression  |   | -  |   | expression of any arithmetic type  |

Both unary plus and unary minus first apply integral promotions to their operand, and then
一元正號和一元負號都首先對其運算元應用整數提升，然後

- unary plus returns the value after promotion
一元正號傳回提升後的值

- unary minus returns the negative of the value after promotion (except that the negative of a NaN is another NaN)
一元負號傳回提升後值的負值（但 NaN 的負值是另一個 NaN）

The type of the expression is the type after promotion, and the value category is non-lvalue.
表示式的型別是提升後的型別，值類別是非左值。

#### Notes

The unary minus invokes undefined behavior due to signed integer overflow when applied to INT_MIN, LONG_MIN, or LLONG_MIN, on typical (2's complement) platforms.
在典型的（補碼）平臺上，一元負號應用於 INT_MIN 、 LONG_MIN 或 LLONG_MIN 時會因有符號整數溢位而引發未定義行為。
In C++, unary operator `**+**` can also be used with other built-in types such as arrays and functions, not so in C.
在 C++ 中，一元運運算元 + 也可用於其他內建型別（如陣列和函式），但在 C 中不行。

Run this code

```c
#include <stdio.h> #include <complex.h> #include <limits.h> int main(void) {  char c = 'a';  printf("sizeof char: %zu sizeof int: %zu\n", sizeof c, sizeof +c);  printf("-1, where 1 is signed: %d\n", -1);  // Defined behavior since arithmetic is performed for unsigned integer.  // Hence, the calculation is (-1) modulo (2 raised to n) = UINT_MAX, where n is  // the number of bits of unsigned int. If unsigned int is 32-bit long, then this  // gives (-1) modulo (2 raised to 32) = 4294967295  printf("-1, where 1 is unsigned: %u\n", -1u);   // Undefined behavior because the mathematical value of -INT_MIN = INT_MAX + 1  // (i.e. 1 more than the maximum possible value for signed int)  //  // printf("%d\n", -INT_MIN);  // Undefined behavior because the mathematical value of -LONG_MIN = LONG_MAX + 1  // (i.e. 1 more than the maximum possible value for signed long)  //  // printf("%ld\n", -LONG_MIN);  // Undefined behavior because the mathematical value of -LLONG_MIN = LLONG_MAX + 1  // (i.e. 1 more than the maximum possible value for signed long long)  //  // printf("%lld\n", -LLONG_MIN);  double complex z = 1 + 2*I;  printf("-(1+2i) = %.1f%+.1f\n", creal(-z), cimag(-z)); }
```

Possible output:
可能的輸出：

```c
sizeof char: 1 sizeof int: 4 -1, where 1 is signed: -1 -1, where 1 is unsigned: 4294967295 -(1+2i) = -1.0-2.0
```

### Additive operators
加法運運算元

The binary additive arithmetic operator expressions have the form
二元加法算術運運算元表示式具有以下形式

|   |

| lhs `**+**` rhs  |   | (1)  |   |   |

|   |

| lhs `**-**` rhs  |   | (2)  |   |   |

|   |

1) addition: lhs and rhs must be one of the following
- both have arithmetic types, including complex and imaginary
兩者都有算術型別（包括複數和虛數）

- one is a pointer to complete object type, the other has integer type
一個是指向完整物件型別的指標，另一個具有整數型別
兩者都有算術型別（包括複數和虛數）；一個是指向完整物件型別的指標，另一個具有整數型別

2) subtraction: lhs and rhs must be one of the following
- both have arithmetic types, including complex and imaginary
兩者都有算術型別（包括複數和虛數）

- lhs has pointer to complete object type, rhs has integer type
lhs 是指向完整物件型別的指標，rhs 具有整數型別

- both are pointers to complete objects of compatible types, ignoring qualifiers
兩者都是指向相容型別的完整物件的指標（忽略限定符）
兩者都有算術型別（包括複數和虛數）；lhs 是指向完整物件型別的指標，rhs 具有整數型別；兩者都是指向相容型別的完整物件的指標（忽略限定符）

#### Arithmetic addition and subtraction

If both operands have arithmetic types, then
如果兩個運算元都有算術型別，則

- first, usual arithmetic conversions are performed
首先，執行通常算術轉換

- then, the values of the operands after conversions are added or subtracted following the usual rules of mathematics (for subtraction, rhs is subtracted from lhs), except that
然後，按照數學的通常規則將轉換後的運算元值相加或相減（對於減法，從 lhs 中減去 rhs ），除了

- if one operand is NaN, the result is NaN
如果一個運算元是 NaN，結果為 NaN

- infinity minus infinity is NaN and FE_INVALID is raised
無窮大減無窮大為 NaN 並引發 FE_INVALID

- infinity plus the negative infinity is NaN and FE_INVALID is raised
無窮大加負無窮大為 NaN 並引發 FE_INVALID
如果一個運算元是 NaN，結果為 NaN；無窮大減無窮大為 NaN 並引發 FE_INVALID；無窮大加負無窮大為 NaN 並引發 FE_INVALID

Complex and imaginary addition and subtraction are defined as follows (note the result type is imaginary if both operands are imaginary and complex if one operand is real and the other imaginary, as specified by the usual arithmetic conversions):
複數和虛數的加法和減法定義如下（注意，如果兩個運算元都是虛數，則結果型別為虛數；如果一個運算元是實數而另一個是虛數，則為複數，如通常算術轉換所規定）：

| + or -  |   | u  |   | iv  |   | u + iv  |

| x  |   | x ± u  |   | x ± iv  |   | (x ± u) ± iv  |

| iy  |   | ±u + iy  |   | i(y ± v)  |   | ±u + i(y ± v)  |

| x + iy  |   | (x ± u) + iy  |   | x + i(y ± v)  |   | (x ± u) + i(y ± v)  |

Run this code

```c
// work in progress // note: take part of the c/language/conversion example
```

#### Pointer arithmetic

- If the pointer `P` points at an element of an array with index `I`, then
如果指標 P 指向索引為 I 的陣列元素，則

- `P+N` and `N+P` are pointers that point at an element of the same array with index `I+N`
P + N 和 N + P 是指向同一陣列中索引為 I+N 的元素的指標

- `P-N` is a pointer that points at an element of the same array with index `I-N`
P - N 是指向同一陣列中索引為 I-N 的元素的指標
P + N 和 N + P 是指向同一陣列中索引為 I+N 的元素的指標；P - N 是指向同一陣列中索引為 I-N 的元素的指標

The behavior is defined only if both the original pointer and the result pointer are pointing at elements of the same array or one past the end of that array. Note that executing p-1 when p points at the first element of an array is undefined behavior and may fail on some platforms.
只有當原始指標和結果指標都指向同一陣列的元素或指向該陣列末尾之後一個位置時，行為才有定義。注意，當 p 指向陣列的第一個元素時執行 p-1 是未定義行為，在某些平臺上可能會失敗。

- If the pointer `P1` points at an element of an array with index `I` (or one past the end) and `P2` points at an element of the same array with index `J` (or one past the end), then
如果指標 P1 指向索引為 I 的陣列元素（或末尾之後一個位置），P2 指向同一陣列中索引為 J 的元素（或末尾之後一個位置），則

- `P1-P2` has the value equal to `I-J` and the type ptrdiff_t (which is a signed integer type, typically half as large as the size of the largest object that can be declared)
P1 - P2 的值等於 I - J ，型別為 ptrdiff_t （這是一個帶符號整數型別，通常大小為可宣告的最大物件大小的一半）
P1 - P2 的值等於 I - J ，型別為 ptrdiff_t （這是一個帶符號整數型別，通常大小為可宣告的最大物件大小的一半）

The behavior is defined only if the result fits in ptrdiff_t.
只有當結果適合 ptrdiff_t 時，行為才有定義。
For the purpose of pointer arithmetic, a pointer to an object that is not an element of any array is treated as a pointer to the first element of an array of size 1.
就指標運算而言，指向不是任何陣列元素的物件的指標被視為指向大小為 1 的陣列的第一個元素的指標。

Run this code

```c
// work in progress int n = 4, m = 3; int a[n][m]; // VLA of 4 VLAs of 3 ints each int (*p)[m] = a; // p == &a[0]  p = p + 1; // p == &a[1] (pointer arithmetic works with VLAs just the same) (*p)[2] = 99; // changes a[1][2]
```

### Multiplicative operators
乘法運運算元

The binary multiplicative arithmetic operator expressions have the form
二元乘法算術運運算元表示式具有以下形式

|   |

| lhs `*****` rhs  |   | (1)  |   |   |

|   |

| lhs `**/**` rhs  |   | (2)  |   |   |

|   |

| lhs `**%**` rhs  |   | (3)  |   |   |

|   |

1) multiplication. lhs and rhs must have arithmetic types

2) division. lhs and rhs must have arithmetic types

3) remainder. lhs and rhs must have integer types

- first, usual arithmetic conversions are performed. Then...
首先，執行通常算術轉換。然後……

#### Multiplication

The binary operator * performs multiplication of its operands (after usual arithmetic conversions) following the usual arithmetic definitions, except that
二元運運算元 * 按照通常算術定義對其運算元執行乘法（通常算術轉換之後），除了

- if one operand is a NaN, the result is a NaN
如果一個運算元是 NaN，結果為 NaN

- multiplication of infinity by zero gives NaN and FE_INVALID is raised
無窮大乘以零得到 NaN 並引發 FE_INVALID

- multiplication of infinity by a nonzero gives infinity (even for complex arguments)
無窮大乘以非零值得到無窮大（即使對於複數參數）

Because in C, any complex value with at least one infinite part is an infinity even if its other part is a NaN, the usual arithmetic rules do not apply to complex-complex multiplication. Other combinations of floating operands follow the following table:
因為在 C 中，任何至少有一個無窮部分的複數值都是無窮大，即使另一部分是 NaN，通常算術規則不適用於複數與複數的乘法。浮點運算元的其他組合遵循下表：

| *  |   | u  |   | iv  |   | u + iv  |

| x  |   | xu  |   | i(xv)  |   | (xu) + i(xv)  |

| iy  |   | i(yu)  |   | −yv  |   | (−yv) + i(yu)  |

| x + iy  |   | (xu) + i(yu)  |   | (−yv) + i(xv)  |   | *special rules*  |

Besides infinity handling, complex multiplication is not allowed to overflow intermediate results, except when  #pragma STDC CX_LIMITED_RANGE is set to `ON`, in which case the value may be calculated as if by (x+iy)×(u+iv) = (xu-yv)+i(yu+xv), as the programmer assumes the responsibility of limiting the range of the operands and dealing with the infinities.
除了無窮大處理外，複數乘法不允許中間結果溢位，除非 #pragma STDC CX_LIMITED_RANGE 設定為 ON ，此時可以按 (x+iy)×(u+iv) = (xu-yv)+i(yu+xv) 的方式計算值，因為程式設計師承擔限制運算元範圍和處理無窮大的責任。
Despite disallowing undue overflow, complex multiplication may raise spurious floating-point exceptions (otherwise it is prohibitively difficult to implement non-overflowing versions)
儘管不允許過度溢位，複數乘法仍可能引發虛假的浮點異常（否則實現不溢位的版本將極其困難）

Run this code

```c
#include <stdio.h> #include <stdio.h> #include <complex.h> #include <math.h> int main(void) { // TODO simpler cases, take some from C++  double complex z = (1 + 0*I) * (INFINITY + I*INFINITY); // textbook formula would give // (1+i0)(∞+i∞) ⇒ (1×∞ – 0×∞) + i(0×∞+1×∞) ⇒ NaN + I*NaN // but C gives a complex infinity  printf("%f + i*%f\n", creal(z), cimag(z)); // textbook formula would give // cexp(∞+iNaN) ⇒ exp(∞)×(cis(NaN)) ⇒ NaN + I*NaN // but C gives ±∞+i*nan  double complex y = cexp(INFINITY + I*NAN);  printf("%f + i*%f\n", creal(y), cimag(y)); }
```

Possible output:
可能的輸出：

```c
inf + i*inf inf + i*nan
```

#### Division

The binary operator `**/**` divides the first operand by the second (after usual arithmetic conversions) following the usual arithmetic definitions, except that
二元運運算元 / 按照通常算術定義將第一個運算元除以第二個運算元（通常算術轉換之後），除了

- when the type after usual arithmetic conversions is an integer type, the result is the algebraic quotient (not a fraction), rounded in implementation-defined direction(until C99)truncated towards zero(since C99)
當通常算術轉換後的型別為整數型別時，結果為代數商（不是分數），按實現定義的方向舍入（C99 之前），向零截斷（C99 起）

- if one operand is a NaN, the result is a NaN
如果一個運算元是 NaN，結果為 NaN

- if the first operand is a complex infinity and the second operand is finite, then the result of the `**/**` operator is a complex infinity
如果第一個運算元是複數無窮大而第二個運算元是有限的，則 / 運運算元的結果是複數無窮大

- if the first operand is finite and the second operand is a complex infinity, then the result of the `**/**` operator is a zero.
如果第一個運算元是有限的而第二個運算元是複數無窮大，則 / 運運算元的結果是零。

Because in C, any complex value with at least one infinite part as an infinity even if its other part is a NaN, the usual arithmetic rules do not apply to complex-complex division. Other combinations of floating operands follow the following table:
因為在 C 中，任何至少有一個無窮部分的複數值都是無窮大，即使另一部分是 NaN，通常算術規則不適用於複數與複數的除法。浮點運算元的其他組合遵循下表：

| /  |   | u  |   | iv  |

| x  |   | x/u  |   | i(−x/v)  |

| iy  |   | i(y/u)  |   | y/v  |

| x + iy  |   | (x/u) + i(y/u)  |   | (y/v) + i(−x/v)  |

Besides infinity handling, complex division is not allowed to overflow intermediate results, except when  #pragma STDC CX_LIMITED_RANGE is set to `ON`, in which case the value may be calculated as if by (x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u2
+v2
), as the programmer assumes the responsibility of limiting the range of the operands and dealing with the infinities.
除了無窮大處理外，複數除法不允許中間結果溢位，除非 #pragma STDC CX_LIMITED_RANGE 設定為 ON ，此時可以按 (x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u 2 +v 2 ) 的方式計算值，因為程式設計師承擔限制運算元範圍和處理無窮大的責任。
Despite disallowing undue overflow, complex division may raise spurious floating-point exceptions (otherwise it is prohibitively difficult to implement non-overflowing versions)
儘管不允許過度溢位，複數除法仍可能引發虛假的浮點異常（否則實現不溢位的版本將極其困難）
If the second operand is zero, the behavior is undefined, except that if the IEEE floating-point arithmetic is supported, and the floating-point division is taking place, then
如果第二個運算元為零，行為是未定義的，除非支援 IEEE 浮點算術且正在進行浮點除法，此時

- Dividing a non-zero number by ±0.0 gives the correctly-signed infinity and FE_DIVBYZERO is raised
非零數除以 ±0.0 得到符號正確的無窮大並引發 FE_DIVBYZERO

- Dividing 0.0 by 0.0 gives NaN and FE_INVALID is raised
0.0 除以 0.0 得到 NaN 並引發 FE_INVALID

#### Remainder

The binary operator % yields the remainder of the division of the first operand by the second (after usual arithmetic conversions).
二元運運算元 % 產生第一個運算元除以第二個運算元（通常算術轉換之後）的餘數。
The sign of the remainder is defined in such a way that if the quotient `a/b` is representable in the result type, then `(a/b)*b + a%b == a`.
餘數的符號定義方式使得如果商 a/b 可在結果型別中表示，則 ( a / b ) * b + a % b == a 。
If the second operand is zero, the behavior is undefined.
如果第二個運算元為零，行為是未定義的。
If the quotient `a/b` is not representable in the result type, the behavior of both `a/b` and `a%b` is undefined (that means `INT_MIN%-1` is undefined on 2's complement systems)
如果商 a/b 不能在結果型別中表示，則 a/b 和 a%b 的行為都是未定義的（這意味著 INT_MIN % -1 在補碼系統上是未定義的）
Note: the remainder operator does not work on floating-point types, the library function fmod provides that functionality.
注意：餘數運運算元不適用於浮點型別，庫函式 fmod 提供該功能。

### Bitwise logic

The bitwise arithmetic operator expressions have the form
位算術運運算元表示式具有以下形式

|   |

| `**~**` rhs  |   | (1)  |   |   |

|   |

| lhs `**&**` rhs  |   | (2)  |   |   |

|   |

| lhs `**|**` rhs  |   | (3)  |   |   |

|   |

| lhs `**^**` rhs  |   | (4)  |   |   |

|   |

1) bitwise NOT

2) bitwise AND

3) bitwise OR

4) bitwise XOR
where

| lhs, rhs  |   | -  |   | expressions of integer type  |

First, operators `&`, `^`, and `|` perform usual arithmetic conversions on both operands and the operator `~` performs integer promotions on its only operand.
首先，運運算元 & 、 ^ 和 | 對兩個運算元執行通常算術轉換，運運算元 ~ 對其唯一運算元執行整數提升。
Then, the corresponding binary logic operators are applied bitwise; that is, each bit of the result is set or cleared according to the logic operation (NOT, AND, OR, or XOR), applied to the corresponding bits of the operands.
然後，相應的二元邏輯運運算元按位應用；即，結果的每一位根據應用於運算元對應位的邏輯運算（NOT、AND、OR 或 XOR）置位或清零。
Note: bitwise operators are commonly used to manipulate bit sets and bit masks.
注意：位運運算元通常用於操作位集合和位掩碼。
Note: for unsigned types (after promotion), the expression `~E` is equivalent to the maximum value representable by the result type minus the original value of `E`.
注意：對於無符號型別（提升之後），表示式 ~ E 等價於結果型別可表示的最大值減去 E 的原始值。

Run this code

```c
#include <stdio.h> #include <stdint.h> int main(void) {  uint32_t a = 0x12345678;  uint16_t mask = 0x00f0;  printf("Promoted mask:\t%#010x\n"  "Value:\t\t%#x\n"  "Setting bits:\t%#x\n"  "Clearing bits:\t%#x\n"  "Selecting bits:\t%#010x\n"  , mask  , a  , a | mask  , a & ~mask  , a & mask  ); }
```

Possible output:
可能的輸出：

```c
Promoted mask: 0x000000f0 Value: 0x12345678 Setting bits: 0x123456f8 Clearing bits: 0x12345608 Selecting bits: 0x00000070
```

### Shift operators
移位運運算元

The bitwise shift operator expressions have the form
位移運運算元表示式具有以下形式

|   |

| lhs `**<<**` rhs  |   | (1)  |   |   |

|   |

| lhs `**>>**` rhs  |   | (2)  |   |   |

|   |

1) left shift of lhs by rhs bits

2) right shift of lhs by rhs bits
where

| lhs, rhs  |   | -  |   | expressions of integer type  |

First, integer promotions are performed, individually, on each operand (Note: this is unlike other binary arithmetic operators, which all perform usual arithmetic conversions). The type of the result is the type of lhs after promotion.
首先，對每個運算元分別執行整數提升（注意：這與其他二元算術運運算元不同，其他二元算術運運算元都執行通常算術轉換）。結果的型別是 lhs 提升後的型別。
The behavior is undefined if rhs is negative or is greater or equal the number of bits in the promoted lhs.
如果 rhs 為負數或大於等於提升後的 lhs 的位數，則行為是未定義的。
For unsigned lhs, the value of `LHS << RHS` is the value of LHS * 2RHS
, reduced modulo maximum value of the return type plus 1 (that is, bitwise left shift is performed and the bits that get shifted out of the destination type are discarded). For signed lhs with nonnegative values, the value of `LHS << RHS` is LHS * 2RHS
if it is representable in the promoted type of lhs, otherwise the behavior is undefined.
對於無符號 lhs ， LHS << RHS 的值是 LHS * 2 RHS 的值，按傳回型別最大值加 1 取模（即執行按位左移，移出目標型別的位被丟棄）。對於帶非負值的有符號 lhs ，如果 LHS << RHS 的值可在 lhs 提升後的型別中表示，則其值為 LHS * 2 RHS ，否則行為是未定義的。
For unsigned lhs and for signed lhs with nonnegative values, the value of `LHS >> RHS` is the integer part of LHS / 2RHS
. For negative `LHS`, the value of `LHS >> RHS` is implementation-defined where in most implementations, this performs arithmetic right shift (so that the result remains negative). Thus in most implementations, right shifting a signed `LHS` fills the new higher-order bits with the original sign bit (i.e. with 0 if it was non-negative and 1 if it was negative).
對於無符號 lhs 和帶非負值的有符號 lhs ， LHS >> RHS 的值是 LHS / 2 RHS 的整數部分。對於負的 LHS ， LHS >> RHS 的值是實現定義的，在大多數實現中，這執行算術右移（使結果保持為負）。因此在大多數實現中，對有符號 LHS 右移時，新的高位用原始符號位填充（即如果為非負則用 0 填充，如果為負則用 1 填充）。

Run this code

```c
#include <stdio.h> enum {ONE=1, TWO=2}; int main(void) {  char c = 0x10;  unsigned long long ulong_num = 0x123;  printf("0x123 << 1 = %#llx\n"  "0x123 << 63 = %#llx\n" // overflow truncates high bits for unsigned numbers  "0x10 << 10 = %#x\n", // char is promoted to int  ulong_num << 1, ulong_num << 63, c << 10);  long long long_num = -1000;  printf("-1000 >> 1 = %lld\n", long_num >> ONE); // implementation defined }
```

Possible output:
可能的輸出：

```c
0x123 << 1 = 0x246 0x123 << 63 = 0x8000000000000000 0x10 << 10 = 0x4000 -1000 >> 1 = -500
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.3.3 Unary arithmetic operators (p: 64)
6.5.3.3 一元算術運運算元 (p: 64)
6.5.3.3 一元算術運運算元 (p: 64)

- 6.5.5 Multiplicative operators (p: 66)
6.5.5 乘法運運算元 (p: 66)
6.5.5 乘法運運算元 (p: 66)

- 6.5.6 Additive operators (p: 66-68)
6.5.6 加法運運算元 (p: 66-68)
6.5.6 加法運運算元 (p: 66-68)

- 6.5.7 Bitwise shift operators (p: 68)
6.5.7 位移運運算元 (p: 68)
6.5.7 位移運運算元 (p: 68)

- 6.5.10 Bitwise AND operator (p: 70)
6.5.10 按位 AND 運運算元 (p: 70)
6.5.10 按位 AND 運運算元 (p: 70)

- 6.5.11 Bitwise exclusive OR operator (p: 70)
6.5.11 按位異或運運算元 (p: 70)
6.5.11 按位異或運運算元 (p: 70)

- 6.5.12 Bitwise inclusive OR operator (p: 70-71)
6.5.12 按位或運運算元 (p: 70-71)
6.5.12 按位或運運算元 (p: 70-71)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.3.3 Unary arithmetic operators (p: 89)
6.5.3.3 一元算術運運算元 (p: 89)
6.5.3.3 一元算術運運算元 (p: 89)

- 6.5.5 Multiplicative operators (p: 92)
6.5.5 乘法運運算元 (p: 92)
6.5.5 乘法運運算元 (p: 92)

- 6.5.6 Additive operators (p: 92-94)
6.5.6 加法運運算元 (p: 92-94)
6.5.6 加法運運算元 (p: 92-94)

- 6.5.7 Bitwise shift operators (p: 94-95)
6.5.7 位移運運算元 (p: 94-95)
6.5.7 位移運運算元 (p: 94-95)

- 6.5.10 Bitwise AND operator (p: 97)
6.5.10 按位 AND 運運算元 (p: 97)
6.5.10 按位 AND 運運算元 (p: 97)

- 6.5.11 Bitwise exclusive OR operator (p: 98)
6.5.11 按位異或運運算元 (p: 98)
6.5.11 按位異或運運算元 (p: 98)

- 6.5.12 Bitwise inclusive OR operator (p: 98)
6.5.12 按位或運運算元 (p: 98)
6.5.12 按位或運運算元 (p: 98)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.3.3 Unary arithmetic operators (p: 79)
6.5.3.3 一元算術運運算元 (p: 79)
6.5.3.3 一元算術運運算元 (p: 79)

- 6.5.5 Multiplicative operators (p: 82)
6.5.5 乘法運運算元 (p: 82)
6.5.5 乘法運運算元 (p: 82)

- 6.5.6 Additive operators (p: 82-84)
6.5.6 加法運運算元 (p: 82-84)
6.5.6 加法運運算元 (p: 82-84)

- 6.5.7 Bitwise shift operators (p: 84-85)
6.5.7 位移運運算元 (p: 84-85)
6.5.7 位移運運算元 (p: 84-85)

- 6.5.10 Bitwise AND operator (p: 87)
6.5.10 按位 AND 運運算元 (p: 87)
6.5.10 按位 AND 運運算元 (p: 87)

- 6.5.11 Bitwise exclusive OR operator (p: 88)
6.5.11 按位異或運運算元 (p: 88)
6.5.11 按位異或運運算元 (p: 88)

- 6.5.12 Bitwise inclusive OR operator (p: 88)
6.5.12 按位或運運算元 (p: 88)
6.5.12 按位或運運算元 (p: 88)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.3.3 Unary arithmetic operators
3.3.3.3 一元算術運運算元
3.3.3.3 一元算術運運算元

- 3.3.5 Multiplicative operators
3.3.5 乘法運運算元
3.3.5 乘法運運算元

- 3.3.6 Additive operators
3.3.6 加法運運算元
3.3.6 加法運運算元

- 3.3.7 Bitwise shift operators
3.3.7 位移運運算元
3.3.7 位移運運算元

- 3.3.10 Bitwise AND operator
3.3.10 按位 AND 運運算元
3.3.10 按位 AND 運運算元

- 3.3.11 Bitwise exclusive OR operator
3.3.11 按位異或運運算元
3.3.11 按位異或運運算元

- 3.3.12 Bitwise inclusive OR operator
3.3.12 按位或運運算元
3.3.12 按位或運運算元

### See also

Operator precedence
運運算元優先順序

| Common operators  |

| Assignment  |   | Increment,
decrement  |   | Arithmetic  |   | Logical  |   | Comparison  |   | Member
access  |   | Other  |

```c
a = b a += b a -= b a *= b a /= b a %= b a &= b a |= b a ^= b a <<= b a >>= b
```
|   |
```c
++a --a a++ a--
```
|   |
```c
+a -a a + b a - b a * b a / b a % b ~a a & b a | b a ^ b a << b a >> b
```
|   |
```c
!a a && b a || b
```
|   |
```c
a == b a != b a < b a > b a <= b a >= b
```
|   |
```c
a[b] *a &a a->b a.b
```
|   |
```c
a(...) a, b (type) a a ? b : c sizeof
```

`_Alignof`
(since C11)
(until C23)
`alignof`
(since C23)

C++ documentation for Arithmetic operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_arithmetic.html`

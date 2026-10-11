# Implicit conversions

> 來源：cppreference C 語言參考文件（離線轉換版）。

When an expression is used in the context where a value of a different type is expected, *conversion* may occur:
當表示式在期望使用不同型別值的上下文中使用時，可能發生轉換：

```c
int n = 1L; // expression 1L has type long, int is expected n = 2.1; // expression 2.1 has type double, int is expected char* p = malloc(10); // expression malloc(10) has type void*, char* is expected
```

Conversions take place in the following situations:
轉換在以下情況下發生：

### Conversion as if by assignment
如同賦值的轉換

- In the assignment operator, the value of the right-hand operand is converted to the unqualified type of the left-hand operand.
在賦值運運算元中，右運算元的值被轉換為左運算元的無限定型別。

- In scalar initialization, the value of the initializer expression is converted to the unqualified type of the object being initialized.
在標量初始化中，初始化表示式的值被轉換為被初始化物件的無限定型別。

- In a function-call expression, to a function that has a prototype, the value of each argument expression is converted to the type of the unqualified declared types of the corresponding parameter.
在函式呼叫表示式中，對於具有原型的函式，每個實參表示式的值被轉換為對應形參宣告型別的無限定型別。

- In a return statement, the value of the operand of `return` is converted to an object having the return type of the function.
在 return 陳述式中， return 的運算元值被轉換為具有該函式傳回型別的物件。

Note that actual assignment, in addition to the conversion, also removes extra range and precision from floating-point types and prohibits overlaps; those characteristics do not apply to conversion as if by assignment.
請注意，實際的賦值除了轉換之外，還會削減浮點型別多餘的取值範圍和精度，並禁止重疊；這些特性並不適用於如同賦值的轉換。

### Default argument promotions
預設參數提升

In a function call expression when the call is made to
在函式呼叫表示式中，當呼叫的是

1) a function without a prototype (until C23),

2) a variadic function, where the argument expression is one of the trailing arguments that are matched against the ellipsis parameter.

Each argument of integer type undergoes integer promotion, and each argument of type `float` is implicitly converted to the type `double`.
每個整數型別的實參都要經過整數提升，每個 float 型別的實參被隱式轉換為 double 型別。

```c
int add_nums(int count, ...); int sum = add_nums(2, 'c', true); // add_nums is called with three ints: (2, 99, 1)
```

Note that `float complex` and `float imaginary` are not promoted to `double complex` and `double imaginary` in this context.
|   | (since C99) |

### Usual arithmetic conversions
通常算術轉換

The arguments of the following arithmetic operators undergo implicit conversions for the purpose of obtaining the *common real type ﻿*, which is the type in which the calculation is performed:
以下算術運運算元的運算元會進行隱式轉換，以獲得共同實型別，也就是進行計算所使用的型別：

- binary arithmetic `*`, `/`, `%`, `+`, `-`,
二元算術 * 、 / 、 % 、 + 、 - 、

- relational operators `<`, `>`, `<=`, `>=`, `==`, `!=`,
關係運運算元 < 、 > 、 <= 、 >= 、 == 、 != 、

- binary bitwise arithmetic `&`, `^`, `|`,
二元位算術 & 、 ^ 、 | 、

- the conditional operator `?:`.
條件運運算元 ?: 。

1) If one operand has decimal floating type, the other operand shall not have standard floating,
complex, or imaginary type.

- First, if the type of either operand is `_Decimal128`, the other operand is converted to `_Decimal128`.

- Otherwise, if the type of either operand is `_Decimal64`, the other operand is converted to `_Decimal64`.

- Otherwise, if the type of either operand is `_Decimal32`, the other operand is converted to `_Decimal32`.
|   | (since C23) |

2) Otherwise, if one operand is `long double`, `long double complex`, or `long double imaginary`(since C99), the other operand is implicitly converted as follows:
- integer or real floating type to `long double`
整數或實浮點型別到 long double
整數或實浮點型別到 long double

- complex type to `long double complex`

- imaginary type to `long double imaginary`
|   | (since C99) |

3) Otherwise, if one operand is `double`, `double complex`, or `double imaginary`(since C99), the other operand is implicitly converted as follows:
- integer or real floating type to `double`
整數或實浮點型別到 double
整數或實浮點型別到 double

- complex type to `double complex`

- imaginary type to `double imaginary`
|   | (since C99) |

4) Otherwise, if one operand is `float`, `float complex`, or `float imaginary`(since C99), the other operand is implicitly converted as follows:
- integer type to `float` (the only real type possible is float, which remains as-is)
整數型別到 float（唯一可能的實型別是 float，它保持不變）
整數型別到 float（唯一可能的實型別是 float，它保持不變）

- complex type remains `float complex`

- imaginary type remains `float imaginary`
|   | (since C99) |

5) Otherwise, both operands are integers. Both operands undergo integer promotions; then, after integer promotion, one of the following cases applies:
- If the types are the same, that type is the common type.
如果型別相同，該型別即為共同型別。

- Else, the types are different:
- If the types have the same signedness (both signed or both unsigned), the operand whose type has the lesser *conversion rank ﻿* is implicitly converted to the other type.
如果兩個型別具有相同的有符號性（都帶符號或都不帶符號），則型別轉換排名 [ 1 ] 較低的運算元被隱式轉換 [ 2 ] 為另一個型別。

- Else, the operands have different signedness:
- If the unsigned type has *conversion rank* greater than or equal to the rank of the signed type, then the operand with the signed type is implicitly converted to the unsigned type.
如果無符號型別的轉換排名大於或等於帶符號型別的排名，則帶符號型別的運算元被隱式轉換為無符號型別。

- Else, the unsigned type has *conversion rank* less than the signed type:
- If the signed type can represent all values of the unsigned type, then the operand with the unsigned type is implicitly converted to the signed type.
如果帶符號型別能夠表示無符號型別的所有值，則無符號型別的運算元被隱式轉換為帶符號型別。

- Else, both operands undergo implicit conversion to the unsigned type counterpart of the signed operand's type.
否則，兩個運算元都隱式轉換為帶符號運算元型別所對應的無符號型別。
否則，無符號型別的轉換排名小於帶符號型別：如果帶符號型別能夠表示無符號型別的所有值，則無符號型別的運算元被隱式轉換為帶符號型別。否則，兩個運算元都隱式轉換為帶符號運算元型別所對應的無符號型別。
否則，運算元的有符號性不同：如果無符號型別的轉換排名大於或等於帶符號型別的排名，則帶符號型別的運算元被隱式轉換為無符號型別。否則，無符號型別的轉換排名小於帶符號型別：如果帶符號型別能夠表示無符號型別的所有值，則無符號型別的運算元被隱式轉換為帶符號型別。否則，兩個運算元都隱式轉換為帶符號運算元型別所對應的無符號型別。
否則，型別不同：如果兩個型別具有相同的有符號性（都帶符號或都不帶符號），則型別轉換排名 [ 1 ] 較低的運算元被隱式轉換 [ 2 ] 為另一個型別。否則，運算元的有符號性不同：如果無符號型別的轉換排名大於或等於帶符號型別的排名，則帶符號型別的運算元被隱式轉換為無符號型別。否則，無符號型別的轉換排名小於帶符號型別：如果帶符號型別能夠表示無符號型別的所有值，則無符號型別的運算元被隱式轉換為帶符號型別。否則，兩個運算元都隱式轉換為帶符號運算元型別所對應的無符號型別。
如果型別相同，該型別即為共同型別。否則，型別不同：如果兩個型別具有相同的有符號性（都帶符號或都不帶符號），則型別轉換排名 [ 1 ] 較低的運算元被隱式轉換 [ 2 ] 為另一個型別。否則，運算元的有符號性不同：如果無符號型別的轉換排名大於或等於帶符號型別的排名，則帶符號型別的運算元被隱式轉換為無符號型別。否則，無符號型別的轉換排名小於帶符號型別：如果帶符號型別能夠表示無符號型別的所有值，則無符號型別的運算元被隱式轉換為帶符號型別。否則，兩個運算元都隱式轉換為帶符號運算元型別所對應的無符號型別。

- ↑ Refer to integer promotions below for the rules on ranking.
↑ 排名規則參見下文的整數提升。

- ↑ Refer to “integer conversions” under implicit conversion semantics below.
↑ 參見下文隱式轉換語意中的“整數轉換”。

```c
1.f + 20000001; // int is converted to float, giving 20000000.00  // addition and then rounding to float gives 20000000.00 (char)'a' + 1L; // first, char 'a', which is 97, is promoted to int  // different types: int and long  // same signedness: both signed  // different rank: long is of greater rank than int  // therefore, int 97 is converted to long 97  // the result is 97 + 1 = 98 of type signed long 2u - 10; // different types: unsigned int and signed int  // different signedness  // same rank  // therefore, signed int 10 is converted to unsigned int 10  // since the arithmetic operation is performed for unsigned integers  // (see “Arithmetic operators” topic), the calculation performed is (2 - 10)  // modulo (2 raised to n), where n is the number of value bits of unsigned int  // if unsigned int is 32-bit long and there is no padding bits in its object  // representation, then the result is (-8) modulo (2 raised to 32) = 4294967288  // of type unsigned int 5UL - 2ULL; // different types: unsigned long and unsigned long long  // same signedness  // different rank: rank of unsigned long long is greater  // therefore, unsigned long 5 is converted to unsigned long long 5  // since the arithmetic operation is performed for unsigned integers  // (see “Arithmetic operators” topic),  // if unsigned long long is 64-bit long, then  // the result is (5 - 2) modulo (2 raised to 64) = 3 of type  // unsigned long long 0UL - 1LL; // different types: unsigned long and signed long long  // different signedness  // different rank: rank of signed long long is greater.  // if ULONG_MAX > LLONG_MAX, then signed long long cannot represent all  // unsigned long therefore, this is the last case: both operands are converted  // to unsigned long long unsigned long 0 is converted to unsigned long long 0  // long long 1 is converted to unsigned long long 1 since the arithmetic  // operation is performed for unsigned integers  // (see “Arithmetic operators” topic),  // if unsigned long long is 64-bit long, then  // the calculation is (0 - 1) modulo (2 raised to 64)  // thus, the result is 18446744073709551615 (ULLONG_MAX) of type  // unsigned long long
```

The result type is determined as follows:

- if both operands are complex, the result type is complex;

- if both operands are imaginary, the result type is imaginary;

- if both operands are real, the result type is real;

- if the two floating-point operands have different type domains (complex vs. real, complex vs imaginary, or imaginary vs. real), the result type is complex.

```c
double complex z = 1 + 2*I; double f = 3.0; z + f; // z remains as-is, f is converted to double, the result is double complex
```
|   | (since C99) |

As always, the result of a floating-point operator may have greater range and precision than is indicated by its type (see `FLT_EVAL_METHOD`).
與往常一樣，浮點運運算元的結果可能具有比其型別所指示的更大的範圍和精度（參見 FLT_EVAL_METHOD ）。

Note: real and imaginary operands are not implicitly converted to complex because doing so would require extra computation, while producing undesirable results in certain cases involving infinities, NaNs and signed zeros. For example, if reals were converted to complex, 2.0×(3.0+i∞) would evaluate as (2.0+i0.0)×(3.0+i∞) ⇒ (2.0×3.0–0.0×∞) + i(2.0×∞+0.0×3.0) ⇒ NaN+i∞ rather than the correct 6.0+i∞. If imaginaries were converted to complex, i2.0×(∞+i3.0) would evaluate as (0.0+i2.0) × (∞+i3.0) ⇒ (0.0×∞ – 2.0×3.0) + i(0.0×3.0 + 2.0×∞) ⇒ NaN + i∞ instead of –6.0 + i∞.
|   | (since C99) |

Note: regardless of usual arithmetic conversions, the calculation may always be performed in a narrower type than specified by these rules under the as-if rule.
注意：無論通常算術轉換如何，在 as-if 規則下，計算始終可以使用比這些規則規定更窄的型別來進行。

### Value transformations
值變換

#### Lvalue conversion

Any lvalue expression of any non-array type, when used in any context other than
任何非陣列型別的左值表示式，當用於以下情形之外的任何上下文中時

- as the operand of the address-of operator (if allowed),
作為取位址運運算元的運算元（如果允許），

- as the operand of the pre/post increment and decrement operators,
作為前置/後置遞增和遞減運運算元的運算元，

- as the left-hand operand of the member access (dot) operator,
作為成員訪問（點）運運算元的左運算元，

- as the left-hand operand of the assignment and compound assignment operators,
作為賦值和複合賦值運運算元的左運算元，

- as the operand of sizeof,
作為 sizeof 的運算元，

undergoes *lvalue conversion ﻿*: the type remains the same, but loses const/volatile/restrict-qualifiers and atomic properties, if any. The value remains the same, but loses its lvalue properties (the address may no longer be taken).
會進行左值轉換：型別不變，但會移除 const、volatile、restrict 限定符及原子屬性（若有）。值也不變，但不再具有左值性，因此不能再對它取址。
If the lvalue has incomplete type, the behavior is undefined.
如果該左值具有不完整型別，則行為是未定義行為。
If the lvalue designates an object of automatic storage duration whose address was never taken and if that object was uninitialized (not declared with an initializer and no assignment to it has been performed prior to use), the behavior is undefined.
若左值指定具有自動儲存期的物件，而該物件從未被取址、也未初始化（未以初始化器宣告，且使用前未曾被指派），則行為未定義。
This conversion models the memory load of the value of the object from its location.
該轉換模擬了從物件所在位置載入其值的記憶體讀取過程。

```c
volatile int n = 1; int x = n; // lvalue conversion on n reads the value of n volatile int* p = &n; // no lvalue conversion: does not read the value of n
```

#### Array to pointer conversion

Any lvalue expression(until C99)expression(since C99) of array type, when used in any context other than
任何陣列型別的左值表示式（直到 C99）表示式（自 C99 起），當用於以下情形之外的任何上下文中時

- as the operand of the address-of operator,
作為取位址運運算元的運算元，

- as the operand of sizeof,
作為 sizeof 的運算元，

- as the operand of typeof and typeof_unqual (since C23),
作為 typeof 和 typeof_unqual （自 C23 起）的運算元，

- as the string literal used for array initialization,
作為用於陣列初始化的字串字面量，

undergoes a conversion to the non-lvalue pointer to its first element.
會轉換為指向其第一個元素的非左值指標。
If the array was declared register, the behavior is undefined.
如果該陣列被宣告為 register ，則行為是未定義行為。
A non-lvalue array, or any of its elements, is not accessible(until C99), has temporary lifetime(since C99).
非左值陣列，或其任何元素，不可訪問（直到 C99），具有臨時生存期（自 C99 起）。

Run this code

```c
int a[3], b[3][4]; int* p = a; /* conversion to &a[0] */ int (*q)[4] = b; /* conversion to &b[0] */ struct S {  int a[1]; }; struct S f(void) {  struct S result = {{0}}; /* {0} since C99 */  return result; } void g(void) {  int* p = f().a; /* error until C99; OK since C99 */  int n = f().a[0]; /* error until C99; OK since C99 */  f().a[0] = 13; /* error until C99; UB since C99 */  (void)p, (void)n; } int main(void) { return 0; }
```

#### Function to pointer conversion

Any function designator expression, when used in any context other than
任何函式指示表示式，當用於以下情形之外的任何上下文中時

- as the operand of the address-of operator,
作為取位址運運算元的運算元，

- as the operand of sizeof,
作為 sizeof 的運算元，

- as the operand of typeof and typeof_unqual (since C23),
作為 typeof 和 typeof_unqual （自 C23 起）的運算元，

undergoes a conversion to the non-lvalue pointer to the function designated by the expression.
會轉換為指向該表示式所指示函式的非左值指標。

```c
int f(int); int (*p)(int) = f; // conversion to &f (***p)(1); // repeated dereference to f and conversion back to &f
```

### Implicit conversion semantics
隱式轉換語意

Implicit conversion, whether *as if by assignment ﻿* or a *usual arithmetic conversion ﻿*, consists of two stages:
隱式轉換，無論是如同賦值還是通常算術轉換，都包含兩個階段：

1) value transformation (if applicable),

2) one of the conversions listed below (if it can produce the target type).

#### Compatible types

Conversion of a value of any type to any compatible type is always a no-op and does not change the representation.
將任何型別的值轉換為任何相容型別始終是一個空操作，不會改變其表示形式。

```c
uint8_t (*a)[10]; // if uint8_t is a typedef to unsigned char unsigned char (*b)[] = a; // then these pointer types are compatible
```

#### Integer promotions

Integer promotion is the implicit conversion of a value of any integer type with *rank* less or equal to *rank* of int or of a bit-field of type _Bool(until C23)bool(since C23), `int`, `signed int`, `unsigned int`, to the value of type `int` or `unsigned int`.
整數提升會將整數轉換成 int 或 unsigned int。轉換對象包括整數轉換排名小於或等於 int 的型別，以及型別為 _Bool（C23 前）、bool（C23 起）、int、signed int 或 unsigned int 的位元欄位。
If `int` can represent the entire range of values of the original type (or the range of values of the original bit-field), the value is converted to type `int`. Otherwise the value is converted to `unsigned int`.
如果 int 能夠表示原始型別的整個值範圍（或原始位域的值範圍），則該值被轉換為 int 型別。否則該值被轉換為 unsigned int 。

The value from a bit-field of a bit-precise integer type is converted to the corresponding bit-precise integer type. Otherwise, bit-precise integer types are exempt from the integer promotion rules.
|   | (since C23) |

Integer promotions preserve the value, including the sign:
整數提升保留值，包括符號：

```c
int main(void) {  void f(); // old-style function declaration  // since C23, void f(...) has the same behavior wrt promotions  char x = 'a'; // integer conversion from int to char  f(x); // integer promotion from char back to int } void f(x) int x; {} // the function expects int
```

*rank* above is a property of every integer type and is defined as follows:
上文的排名是每個整數型別的一個屬性，定義如下：

1) the ranks of all signed integer types are different and increase with their precision: rank of `signed char` < rank of `short` < rank of `int` < rank of `long int` < rank of `long long int`

2) the ranks of all signed integer types equal the ranks of the corresponding unsigned integer types

3) the rank of any standard integer type is greater than the rank of any extended integer type or bit-precise integer type(since C23) of the same size (that is, rank of `__int64` < rank of `long long int`, but rank of `long long` < rank of `__int128` due to the rule (1))

4) rank of `char` equals rank of `signed char` and rank of `unsigned char`

5) the rank of _Bool(until C23)bool(since C23) is less than the rank of any other standard integer type

6) the rank of any enumerated type equals the rank of its compatible integer type

7) ranking is transitive: if rank of T1 < rank of T2 and rank of T2 < rank of T3 then rank of T1 < rank of T3.

8) the rank of a bit-precise signed integer type shall be greater than the rank of any standard integer type with less width or any bit-precise integer type with less width.

9) the rank of any bit-precise integer type relative to an extended integer type of the same width is implementation-defined.
|   | (since C23) |

10) any aspects of relative ranking of extended integer types not covered above are implementation defined.

Note: integer promotions are applied only
注意：整數提升僅應用於

- as part of *usual arithmetic conversions* (see above),
作為通常算術轉換的一部分（見上文），

- as part of *default argument promotions* (see above),
作為預設參數提升的一部分（見上文），

- to the operand of the unary arithmetic operators `+` and `-`,
一元算術運運算元 + 和 - 的運算元，

- to the operand of the unary bitwise operator `~`,
一元位運運算元 ~ 的運算元，

- to both operands of the shift operators `<<` and `>>`.
移位運運算元 << 和 >> 的兩個運算元。

#### Boolean conversion

A value of any scalar type can be implicitly converted to `_Bool`(until C23)`bool`(since C23). The values that compare equal to an integer constant expression of value zero(until C23)are a zero (for arithmetic types), null (for pointer types) or have a type of nullptr_t(since C23) are converted to `0`(until C23)`false`(since C23), all other values are converted to `1`(until C23)`true`(since C23).

```c
bool b1 = 0.5; // b1 == 1 (0.5 converted to int would be zero) bool b2 = 2.0*_Imaginary_I; // b2 == 1 (but converted to int would be zero) bool b3 = 0.0 + 3.0*I; // b3 == 1 (but converted to int would be zero) bool b4 = 0.0 / 0.0; // b4 == 1 (NaN does not compare equal to zero) bool b5 = nullptr; // b5 == 0 (since C23: nullptr is converted to false)
```
|   | (since C99) |

#### Integer conversions

A value of any integer type can be implicitly converted to any other integer type. Except where covered by promotions and boolean conversions above, the rules are:
任何整數型別的值都可以隱式轉換為任何其他整數型別。除了上文提升和布林轉換所涵蓋的情況外，規則如下：

- if the target type can represent the value, the value is unchanged,
如果目標型別能夠表示該值，則該值保持不變，

- otherwise, if the target type is unsigned, the value 2b
, where b is the number of value bits in the target type, is repeatedly subtracted or added to the source value until the result fits in the target type. In other words, unsigned integers implement modulo arithmetic.
否則，如果目標型別是無符號的，則將值 2 b （其中 b 是目標型別中數值位的數目）從源值中反覆減去或加上，直到結果能放入目標型別。換句話說，無符號整數實現模運算。

- otherwise, if the target type is signed, the behavior is implementation-defined (which may include raising a signal).
否則，如果目標型別是有符號的，則行為是實現定義的（可能包括引發訊號）。

```c
char x = 'a'; // int -> char, result unchanged unsigned char n = -123456; // target is unsigned, result is 192 (that is, -123456+483*256) signed char m = 123456; // target is signed, result is implementation-defined assert(sizeof(int) > -1); // assert fails:  // operator > requests conversion of -1 to size_t,  // target is unsigned, result is SIZE_MAX
```

#### Real floating-integer conversions

A finite value of any real floating type can be implicitly converted to any integer type. Except where covered by boolean conversion above, the rules are:
任何實浮點型別的有限值都可以隱式轉換為任何整數型別。除了上文布林轉換所涵蓋的情況外，規則如下：

- The fractional part is discarded (truncated towards zero).
小數部分被丟棄（向零截斷）。

- If the resulting value can be represented by the target type, that value is used
如果結果值能被目標型別表示，則使用該值

- otherwise, the behavior is undefined.
否則，行為是未定義行為。
如果結果值能被目標型別表示，則使用該值，否則行為是未定義行為。

```c
int n = 3.14; // n == 3 int x = 1e10; // undefined behavior for 32-bit int
```

A value of any integer type can be implicitly converted to any real floating type.
任何整數型別的值都可以隱式轉換為任何實浮點型別。

- if the value can be represented exactly by the target type, it is unchanged.
如果該值能被目標型別精確表示，則它保持不變。

- if the value can be represented, but cannot be represented exactly, the result is an implementation-defined choice of either the nearest higher or nearest lower value, although if IEEE arithmetic is supported, rounding is to nearest. It is unspecified whether `FE_INEXACT` is raised in this case.
如果該值可以被表示，但不能被精確表示，則結果是在最近較高值或最近較低值之間做實現定義的選擇，儘管如果支援 IEEE 算術，則舍入為向最近值舍入。在這種情況下是否引發 FE_INEXACT 是未指定的。

- if the value cannot be represented, the behavior is undefined, although if IEEE arithmetic is supported, `FE_INVALID` is raised and the result value is unspecified.
如果該值無法被表示，則行為是未定義行為，儘管如果支援 IEEE 算術，則會引發 FE_INVALID，且結果值未指定。

The result of this conversion may have greater range and precision than its target type indicates (see `FLT_EVAL_METHOD`).
該轉換的結果可能具有比其目標型別所指示的更大範圍和精度（參見 FLT_EVAL_METHOD）。
If control over `FE_INEXACT` is needed in floating-to-integer conversions, rint and nearbyint may be used.
如果在浮點到整數轉換中需要控制 FE_INEXACT，則可以使用 rint 和 nearbyint。

```c
double d = 10; // d = 10.00 float f = 20000001; // f = 20000000.00 (FE_INEXACT) float x = 1 + (long long)FLT_MAX; // undefined behavior
```

#### Real floating-point conversions

A value of any real floating type can be implicitly converted to any other real floating type.
任何實浮點型別的值都可以隱式轉換為任何其他實浮點型別。

- If the value can be represented by the target type exactly, it is unchanged.
如果該值可以被目標型別精確表示，則保持不變。

- if the value can be represented, but cannot be represented exactly, the result is the nearest higher or the nearest lower value (in other words, rounding direction is implementation-defined), although if IEEE arithmetic is supported, rounding is to nearest.
如果該值可以被表示，但不能被精確表示，則結果為最近較高值或最近較低值（換句話說，舍入方向是實現定義的），儘管如果支援 IEEE 算術，則舍入為向最近值舍入。

- if the value cannot be represented, the behavior is undefined
|  | This section is incomplete
Reason: check IEEE if appropriately-signed infinity is required  |
.
如果該值無法被表示，則行為是未定義行為 本節不完整 原因：檢查 IEEE 是否需要適當符號的無窮大。

The result of this conversion may have greater range and precision than its target type indicates (see `FLT_EVAL_METHOD`).
該轉換的結果可能具有比其目標型別所指示的更大範圍和精度（參見 FLT_EVAL_METHOD）。

```c
double d = 0.1; // d = 0.1000000000000000055511151231257827021181583404541015625 float f = d; // f = 0.100000001490116119384765625 float x = 2 * (double)FLT_MAX; // undefined
```

#### Complex type conversions

A value of any complex type can be implicitly converted to any other complex type. The real part and the imaginary part individually follow the conversion rules for the real floating types.

```c
double complex d = 0.1 + 0.1*I; float complex f = d; // f is (0.100000001490116119384765625, 0.100000001490116119384765625)
```

#### Imaginary type conversions

A value of any imaginary type can be implicitly converted to any other imaginary type. The imaginary part follows the conversion rules for the real floating types.

```c
double imaginary d = 0.1*_Imaginary_I; float imaginary f = d; // f is 0.100000001490116119384765625*I
```

#### Real-complex conversions

A value of any real floating type can be implicitly converted to any complex type.

- The real part of the result is determined by the conversion rules for the real floating types.

- The imaginary part of the result is positive zero (or unsigned zero on non-IEEE systems).

A value of any complex type can be implicitly converted to any real floating type.

- The real part is converted following the rules for the real floating types.

- The imaginary part is discarded.

Note: in complex-to-real conversion, a NaN in the imaginary part will not propagate to the real result.

```c
double complex z = 0.5 + 3*I; float f = z; // the imaginary part is discarded, f is set to 0.5 z = f; // sets z to 0.5 + 0*I
```

#### Real-imaginary conversions

A value of any imaginary type can be implicitly converted to any real type (integer or floating-point). The result is always a positive (or unsigned) zero, except when the target type is _Bool(until C23)bool(since C23), in which case boolean conversion rules apply.
A value of any real type can be implicitly converted to any imaginary type. The result is always a positive imaginary zero.

```c
double imaginary z = 3*I; bool b = z; // Boolean conversion: sets b to true float f = z; // Real-imaginary conversion: sets f to 0.0 z = 3.14; // Imaginary-real conversion: sets z to 0*_Imaginary_I
```

#### Complex-imaginary conversions

A value of any imaginary type can be implicitly converted to any complex type.

- The real part of the result is the positive zero.

- The imaginary part of the result follows the conversion rules for the corresponding real types.

A value of any complex type can be implicitly converted to any imaginary type.

- The real part is discarded.

- The imaginary part of the result follows the conversion rules for the corresponding real types.

```c
double imaginary z = I * (3*I); // the complex result -3.0+0i loses real part // sets z to 0*_Imaginary_I
```
|   | (since C99) |

#### Pointer conversions

A pointer to `void` can be implicitly converted to and from any pointer to object type with the following semantics:
指向 void 的指標可以按照以下語意隱式轉換為任何指向物件型別的指標，以及從任何指向物件型別的指標隱式轉換而來：

- If a pointer to object is converted to a pointer to void and back, its value compares equal to the original pointer.
如果指向物件的指標被轉換為指向 void 的指標再轉回來，則其值與原始指標比較相等。

- No other guarantees are offered.
不提供其他保證。

```c
int* p = malloc(10 * sizeof(int)); // malloc returns void*
```

A pointer to an unqualified type may be implicitly converted to the pointer to qualified version of that type (in other words, const, volatile, and restrict qualifiers can be added). The original pointer and the result compare equal.
指向非限定型別的指標可以隱式轉換為指向該型別限定版本的指標（換句話說，可以新增 const、volatile 和 restrict 限定符）。原始指標與結果比較相等。

```c
int n; const int* p = &n; // &n has type int*
```

Any integer constant expression with value `0` as well as integer pointer expression with value zero cast to the type `void*` can be implicitly converted to any pointer type (both pointer to object and pointer to function). The result is the null pointer value of its type, guaranteed to compare unequal to any non-null pointer value of that type. This integer or `void*` expression is known as *null pointer constant* and the standard library provides one definition of this constant as the macro NULL.
值為 0 的整數常數運算式，以及轉換成 void* 的零值整數指標運算式，都可隱式轉換成任何指標型別，包括物件指標與函式指標。結果是該型別的空指標值，必定不等於任何非空指標。這類整數或 void* 運算式稱為空指標常數；標準函式庫以巨集 NULL 定義此常數。

```c
int* p = 0; double* q = NULL;
```

### Notes

Although signed integer overflow in any arithmetic operator is undefined behavior, overflowing a signed integer type in an integer conversion is merely unspecified behavior.
儘管任何算術運運算元中的有符號整數溢位是未定義行為，但在整數轉換中使有符號整數型別溢位只是未指定行為。
On the other hand, although unsigned integer overflow in any arithmetic operator (and in integer conversion) is a well-defined operation and follows the rules of modulo arithmetic, overflowing an unsigned integer in a floating-to-integer conversion is undefined behavior: the values of real floating type that can be converted to unsigned integer are the values from the open interval `(`-1`, `*Unnn_MAX* + 1`)`.
無符號整數在算術運算或整數轉換中溢位，仍有明確定義，並遵循模數運算規則。但浮點數轉成整數時若造成無符號整數溢位，行為未定義。可轉換成無符號整數的實數浮點值必須落在開區間 ( -1 , Unnn_MAX + 1 ) 內。

```c
unsigned int n = -1.0; // undefined behavior
```

Conversions between pointers and integers (except from pointer to _Bool(until C23)bool(since C23) and(since C99)from integer constant expression with the value zero to pointer), between pointers to objects (except where either to or from is a pointer to void) and conversions between pointers to functions (except when the functions have compatible types) are never implicit and require a cast operator.
指標與整數之間的轉換（除了從指標到 _Bool（C23 之前）bool（C23 起）以及（C99 起）從值為零的整數常量表示式到指標的轉換）、指向物件的指標之間的轉換（除了其中一方是指向 void 的指標的情況）以及指向函式的指標之間的轉換（除非函式具有相容型別）都不是隱式的，需要 cast 運運算元。
There are no conversions (implicit or explicit) between pointers to functions and pointers to objects (including `void*`) or integers.
指向函式的指標與指向物件的指標（包括 void*）或整數之間不存在轉換（隱式或顯式）。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.3 Conversions (p: 44-50)
6.3 轉換 (p: 44-50)
6.3 轉換 (p: 44-50)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.3 Conversions (p: 37-41)
6.3 轉換 (p: 37-41)
6.3 轉換 (p: 37-41)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.3 Conversions (p: 50-56)
6.3 轉換 (p: 50-56)
6.3 轉換 (p: 50-56)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.3 Conversions (p: 42-48)
6.3 轉換 (p: 42-48)
6.3 轉換 (p: 42-48)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.2 Conversions
3.2 轉換
3.2 轉換

### See also

C++ documentation for Implicit conversions

---
來源頁路徑：`en.cppreference.com/c/language/conversion.html`

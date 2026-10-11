# Integer constant

> 來源：cppreference C 語言參考文件（離線轉換版）。

Allows values of integer type to be used in expressions directly.
允許直接在表示式中使用整數型別的值。

### Syntax

An integer constant is a non-lvalue expression of the form
整數常量是以下形式的非左值表示式

|   |

| decimal-constant integer-suffix ﻿(optional)  |   | (1)  |   |   |

|   |

| octal-constant integer-suffix ﻿(optional)  |   | (2)  |   |   |

|   |

| hex-constant integer-suffix ﻿(optional)  |   | (3)  |   |   |

|   |

| binary-constant integer-suffix ﻿(optional)  |   | (4)  |   | (since C23)  |

|   |

where

- decimal-constant is a non-zero decimal digit (`1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`), followed by zero or more decimal digits (`0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`)
decimal-constant 是一個非零十進位制數字（1、2、3、4、5、6、7、8、9），後跟零個或多個十進位制數字（0、1、2、3、4、5、6、7、8、9）

- octal-constant is the digit zero (`0`) followed by zero or more octal digits (`0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`)
octal-constant 是數字零（0）後跟零個或多個八進位制數字（0、1、2、3、4、5、6、7）

- hex-constant is the character sequence `0x` or the character sequence `0X` followed by one or more hexadecimal digits (`0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `a`, `A`, `b`, `B`, `c`, `C`, `d`, `D`, `e`, `E`, `f`, `F`)
hex-constant 是字元序列 0x 或字元序列 0X 後跟一個或多個十六進位制數字（0、1、2、3、4、5、6、7、8、9、a、A、b、B、c、C、d、D、e、E、f、F）

- binary-constant is the character sequence `0b` or the character sequence `0B` followed by one or more binary digits (`0`, `1`)
binary-constant 是字元序列 0b 或字元序列 0B 後跟一個或多個二進位制數字（0、1）

- integer-suffix, if provided, may contain one of the following (except the unsigned prefix can be combined with one of the others; if two suffixes are used they can appear in any order):
integer-suffix（如果提供）可以包含以下之一（但 unsigned 字首可以與其他之一組合；如果使用兩個字尾，它們可以以任何順序出現）：

- unsigned-suffix (the character `u` or the character `U`)
unsigned-suffix（字元 u 或字元 U）

- long-suffix (the character `l` or the character `L`) or the long-long-suffix (the character sequence `ll` or the character sequence `LL`)(since C99)
long-suffix（字元 l 或字元 L）或 long-long-suffix（字元序列 ll 或字元序列 LL）（C99 起）

- bit-precise-int-suffix (the character sequence `wb` or the character sequence `WB`) (since C23)
bit-precise-int-suffix（字元序列 wb 或字元序列 WB）（C23 起）
unsigned-suffix（字元 u 或字元 U）long-suffix（字元 l 或字元 L）或 long-long-suffix（字元序列 ll 或字元序列 LL）（C99 起）bit-precise-int-suffix（字元序列 wb 或字元序列 WB）（C23 起）

Optional single quotes (`'`) may be inserted between the digits as a separator. They are ignored by the compiler.
|   | (since C23) |

### Explanation

1) Decimal integer constant (base 10, the first digit is the most significant).

2) Octal integer constant (base 8, the first digit is the most significant).

3) Hexadecimal integer constant (base 16, the first digit is the most significant, the letters `a` through `f` represent the decimal values 10 through 15).

4) Binary integer constant (base 2, the first digit is the most significant).

The following variables are initialized to the same value:
以下變數初始化為相同的值：

```c
int d = 42; int o = 052; int x = 0x2a; int X = 0X2A; int b = 0b101010; // C23
```

The following variables are also initialized to the same value:
以下變數也初始化為相同的值：

```c
unsigned long long l1 = 18446744073709550592ull; // C99 unsigned long long l2 = 18'446'744'073'709'550'592llu; // C23 unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C23 unsigned long long l4 = 184467'440737'0'95505'92LLU; // C23
```

### The type of the integer constant
整數常量的型別

The type of the integer constant is the first type in which the value can fit, from the list of types which depends on which numeric base and which integer-suffix was used.
整數常量的型別是第一個能容納該值的型別，取自取決於所用數制和 integer-suffix 的型別列表。

Types allowed for integer constants
| suffix  |   | decimal bases  |   | other bases  |

| no suffix  |   | `int`
`long int`
`unsigned long int` (until C99)
`long long int` (since C99)
|   | `int`
`unsigned int`
`long int`
`unsigned long int`
`long long int`(since C99)
`unsigned long long int`(since C99)

| `u` or `U`  |   | `unsigned int`
`unsigned long int`
`unsigned long long int`(since C99)
|   | `unsigned int`
`unsigned long int`
`unsigned long long int`(since C99)

| `l` or `L`  |   | `long int`
`unsigned long int`(until C99)
`long long int`(since C99)
|   | `long int`
`unsigned long int`
`long long int`(since C99)
`unsigned long long int`(since C99)

| both `l`/`L` and `u`/`U`  |   | `unsigned long int`
`unsigned long long int`(since C99)
|   | `unsigned long int`
`unsigned long long int`(since C99)

| `ll` or `LL`  |   | `long long int`(since C99)  |   | `long long int`(since C99)
`unsigned long long int`(since C99)

| both `ll`/`LL` and `u`/`U`  |   | `unsigned long long int`(since C99)  |   | `unsigned long long int`(since C99)  |

| `wb` or `WB`  |   | `_BitInt(N)` where the width N is the smallest N greater than 1 which can accommodate the value and the sign bit(since C23)  |   | `_BitInt(N)` where the width N is the smallest N greater than 1 which can accommodate the value and the sign bit(since C23)  |

| both `wb`/`WB` and `u`/`U`  |   | `unsigned _BitInt(N)` where the width N is the smallest N greater than 0 which can accommodate the value(since C23)  |   | `unsigned _BitInt(N)` where the width N is the smallest N greater than 0 which can accommodate the value(since C23)  |

If the value of the integer constant is too big to fit in any of the types allowed by suffix/base combination, it does not have suffixes `wb`, `WB`, `uwb`, or `UWB`(since C23) and the compiler supports extended integer types (such as `__int128`), the constant may be given the extended integer type; otherwise, the program is ill-formed.
如果整數常量的值太大，無法放入字尾/數制組合所允許的任何型別中，它不具有字尾 wb、WB、uwb 或 UWB（C23 起），且編譯器支援擴充套件整數型別（如 __int128），則該常量可以被賦予擴充套件整數型別；否則程式是 ill-formed。

### Notes

Letters in the integer constants are case-insensitive: `0xDeAdBaBeU` and `0XdeadBABEu` represent the same number (one exception is the long-long-suffix, which is either `ll` or `LL`, never `lL` or `Ll`)(since C99).
整數常量中的字母不區分大小寫：0xDeAdBaBeU 和 0XdeadBABEu 表示相同的數字（一個例外是 long-long-suffix，它只能是 ll 或 LL，絕不會是 lL 或 Li）（C99 起）。
There are no negative integer constants. Expressions such as `-1` apply the unary minus operator to the value represented by the constant.
不存在負整數常量。像 -1 這樣的表示式對常量所表示的值應用一元負號運運算元。

When used in a controlling expression of  #if or  #elif, all signed integer constants act as if they have type intmax_t and all unsigned integer constants act as if they have type uintmax_t.
|   | (since C99) |

Integer constants may be used in integer constant expressions.
整數常量可以在整數常量表示式中使用。
Due to maximal munch, hexadecimal integer constants ending in `e` and `E`, when followed by the operators `+` or `-`, must be separated from the operator with whitespace or parentheses in the source:
由於 maximal munch，以 e 和 E 結尾的十六進位制整數常量，當後面跟著運運算元 + 或 - 時，在原始碼中必須用空白或括號與運運算元分隔：

```c
int x = 0xE+2; // error int y = 0xa+2; // OK int z = 0xE +2; // OK int q = (0xE)+2; // OK
```

Otherwise, a single invalid preprocessing number token is formed, which causes further analysis to fail.
否則，會形成一個無效的預處理數字令牌，導致進一步分析失敗。

### Example

Run this code

```c
#include <inttypes.h> #include <stdio.h> int main(void) {  printf("123 = %d\n", 123);  printf("0123 = %d\n", 0123);  printf("0x123 = %d\n", 0x123);  printf("12345678901234567890ull = %llu\n", 12345678901234567890ull);  // the type is a 64-bit type (unsigned long long or possibly unsigned long)  // even without a long suffix  printf("12345678901234567890u = %"PRIu64"\n", 12345678901234567890u );    // printf("%lld\n", -9223372036854775808); // Error:  // the value 9223372036854775808 cannot fit in signed long long, which  // is the biggest type allowed for unsuffixed decimal integer constant    printf("%llu\n", -9223372036854775808ull );  // unary minus applied to unsigned value subtracts it from 2^64,  // this gives unsigned 9223372036854775808    printf("%lld\n", -9223372036854775807ll - 1);  // correct way to form signed value -9223372036854775808 }
```

Output:

```c
123 = 123 0123 = 83 0x123 = 291 12345678901234567890ull = 12345678901234567890 12345678901234567890u = 12345678901234567890 9223372036854775808 -9223372036854775808
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.4.1 Integer constants (p: 57-60)
6.4.4.1 整數常量 (p: 57-60)
6.4.4.1 整數常量 (p: 57-60)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.4.1 Integer constants (p: 45-46)
6.4.4.1 整數常量 (p: 45-46)
6.4.4.1 整數常量 (p: 45-46)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.4.1 Integer constants (p: 62-64)
6.4.4.1 整數常量 (p: 62-64)
6.4.4.1 整數常量 (p: 62-64)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.4.1 Integer constants (p: 54-56)
6.4.4.1 整數常量 (p: 54-56)
6.4.4.1 整數常量 (p: 54-56)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.3.2 Integer constants
3.1.3.2 整數常量
3.1.3.2 整數常量

### See also

C++ documentation for Integer literal

---
來源頁路徑：`en.cppreference.com/c/language/integer_constant.html`

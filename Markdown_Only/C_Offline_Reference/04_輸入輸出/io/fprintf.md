# printf, fprintf, sprintf, snprintf, printf_s, fprintf_s, sprintf_s, snprintf_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int printf( const char* format, ... );
```
|   |  (1) |   | (until C99) |

```c
int printf( const char* restrict format, ... );
```
|   |   |   | (since C99) |

```c
int fprintf( FILE* stream, const char* format, ... );
```
|   |  (2) |   | (until C99) |

```c
int fprintf( FILE* restrict stream, const char* restrict format, ... );
```
|   |   |   | (since C99) |

```c
int sprintf( char* buffer, const char* format, ... );
```
|   |  (3) |   | (until C99) |

```c
int sprintf( char* restrict buffer, const char* restrict format, ... );
```
|   |   |   | (since C99) |

```c
int snprintf( char* restrict buffer, size_t bufsz,  const char* restrict format, ... );
```
|   |  (4)  |   |  (since C99)  |

```c
int printf_s( const char* restrict format, ... );
```
|   |  (5)  |   |  (since C11)  |

```c
int fprintf_s( FILE* restrict stream, const char* restrict format, ... );
```
|   |  (6)  |   |  (since C11)  |

```c
int sprintf_s( char* restrict buffer, rsize_t bufsz,  const char* restrict format, ... );
```
|   |  (7)  |   |  (since C11)  |

```c
int snprintf_s( char* restrict buffer, rsize_t bufsz,  const char* restrict format, ... );
```
|   |  (8)  |   |  (since C11)  |

|  |  |  |  |

Loads the data from the given locations, converts them to character string equivalents and writes the results to a variety of sinks/streams:
根據格式字串，將引數轉換成文字後寫入輸出串流或指定的字元陣列：

1) Writes the results to the output stream stdout.

2) Writes the results to the output stream `stream`.

3) Writes the results to a character string `buffer`. The behavior is undefined if the string to be written (plus the terminating null character) exceeds the size of the array pointed to by `buffer`.

4) Writes the results to a character string `buffer`. At most `bufsz - 1` characters are written. The resulting character string will be terminated with a null character, unless `bufsz` is zero. If `bufsz` is zero, nothing is written and `buffer` may be a null pointer, however the return value (number of bytes that would be written not including the null terminator) is still calculated and returned.

5-8) Same as (1-4), except that the following errors are detected at runtime and call the currently installed constraint handler function:
- the conversion specifier `%n` is present in `format`
格式中存在轉換說明符 %n

- any of the arguments corresponding to `%s` is a null pointer
對應於 %s 的任何參數是空指標

- `stream` or `format` or `buffer` is a null pointer
stream 或 format 或 buffer 是空指標

- `bufsz` is zero or greater than RSIZE_MAX
bufsz 為零或大於 RSIZE_MAX

- encoding errors occur in any of string and character conversion specifiers
在任何字串或字元轉換說明符中發生編碼錯誤

- (for `sprintf_s` only), the string to be stored in `buffer` (including the trailing null) would exceed `bufsz`.
（僅針對 sprintf_s ），要儲存到 buffer 中的字串（包括結尾的 null）會超過 bufsz 。
As with all bounds-checked functions, `printf_s`, `fprintf_s`, `sprintf_s`, and `snprintf_s` are only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>.

### Parameters

| stream  |   | -  |   | output file stream to write to  |

| buffer  |   | -  |   | pointer to a character string to write to  |

| bufsz  |   | -  |   | up to `bufsz - 1` characters may be written, plus the null terminator  |

| format  |   | -  |   | pointer to a null-terminated byte string specifying how to interpret the data  |

| ...  |   | -  |   | arguments specifying data to print. If any argument after default argument promotions is not the type expected by the corresponding conversion specification (the expected type is the promoted type or a compatible type of the promoted type), or if there are fewer arguments than required by `format`, the behavior is undefined. If there are more arguments than required by `format`, the extraneous arguments are evaluated and ignored.  |

The **format** string consists of ordinary byte characters (except `**%**`), which are copied unchanged into the output stream, and conversion specifications. Each conversion specification has the following format:
格式字串由一般位元組字元（除了 %）和轉換規格組成。一般字元會原樣寫入輸出串流；每個轉換規格的格式如下：

- introductory `**%**` character.
引導的 % 字元。
引導的 % 字元。

- (optional) flags that modify the behavior of the conversion:
（可選）修改轉換行為的標誌：

- `**-**`: the result of the conversion is left-justified within the field (by default it is right-justified).
- ：轉換結果在欄位內左對齊（預設右對齊）。

- `**0**`: applicable to floating-point and integer conversions only. Leading zeros are used to pad the field instead of *space* characters. This flag is ignored if `-` flag is present. For integer conversions, this flag is ignored if the precision is explicitly specified. For floating-point conversions, this flag is ignored if the value is NaN or infinity. Other conversions using this flag have undefined behavior.
0 ：僅適用於浮點數和整數轉換。使用前導零而不是空格字元填充欄位。如果存在 - 標誌，則忽略此標誌。對於整數轉換，如果顯式指定了精度，則忽略此標誌。對於浮點數轉換，如果值為 NaN 或無窮大，則忽略此標誌。其他使用此標誌的轉換具有未定義行為。

- `**+**`: applicable to floating-point and signed integer conversions only. Non-negative numbers are prefixed with a plus character. This flag is ignored by other conversions.
+ ：僅適用於浮點數和有符號整數轉換。非負數字首加號字元。其他轉換忽略此標誌。

- *space*: applicable to floating-point and signed integer conversions only. Non-negative numbers are prefixed with a space character. This flag is ignored if `+` flag is present. This flag is ignored by other conversions.
space ：僅適用於浮點數和有符號整數轉換。非負數字首空格字元。如果存在 + 標誌，則忽略此標誌。其他轉換忽略此標誌。

- `**#**`: applicable to floating-point and non-decimal integer conversions only. The *alternative form* of the conversion is performed. See below for the exact semantics. Other conversions using this flag have undefined behavior.
# ：僅適用於浮點數和非十進位制整數轉換。執行轉換的替代形式。確切語意見下文。其他使用此標誌的轉換具有未定義行為。
（可選）修改轉換行為的標誌：- ：轉換結果在欄位內左對齊（預設右對齊）。0 ：僅適用於浮點數和整數轉換。使用前導零而不是空格字元填充欄位。如果存在 - 標誌，則忽略此標誌。對於整數轉換，如果顯式指定了精度，則忽略此標誌。對於浮點數轉換，如果值為 NaN 或無窮大，則忽略此標誌。其他使用此標誌的轉換具有未定義行為。+ ：僅適用於浮點數和有符號整數轉換。非負數字首加號字元。其他轉換忽略此標誌。space ：僅適用於浮點數和有符號整數轉換。非負數字首空格字元。如果存在 + 標誌，則忽略此標誌。其他轉換忽略此標誌。# ：僅適用於浮點數和非十進位制整數轉換。執行轉換的替代形式。確切語意見下文。其他使用此標誌的轉換具有未定義行為。
（可選）修改轉換行為的標誌：- ：轉換結果在欄位內左對齊（預設右對齊）。0 ：僅適用於浮點數和整數轉換。使用前導零而不是空格字元填充欄位。如果存在 - 標誌，則忽略此標誌。對於整數轉換，如果顯式指定了精度，則忽略此標誌。對於浮點數轉換，如果值為 NaN 或無窮大，則忽略此標誌。其他使用此標誌的轉換具有未定義行為。+ ：僅適用於浮點數和有符號整數轉換。非負數字首加號字元。其他轉換忽略此標誌。space ：僅適用於浮點數和有符號整數轉換。非負數字首空格字元。如果存在 + 標誌，則忽略此標誌。其他轉換忽略此標誌。# ：僅適用於浮點數和非十進位制整數轉換。執行轉換的替代形式。確切語意見下文。其他使用此標誌的轉換具有未定義行為。

- (optional) integer value or `*****`: specifies *minimum field width*. The result is padded with *space* characters (by default), if required, on the left when right-justified, or on the right if left-justified. In the case when `*` is used, the width is specified by an additional argument of type `int`, which appears before the argument to be converted and the argument supplying precision if one is supplied. If the value of the argument is negative, then the `-` flag is implied and the absolute value used for minimum field width.
（可選）整數值或 * ：指定最小欄位寬度。如有需要，結果用空格字元填充（預設）：右對齊時在左側填充，左對齊時在右側填充。當使用 * 時，寬度由一個額外的 int 型別參數指定，該參數出現在待轉換參數之前，以及（如果提供）提供精度的參數之前。如果該參數的值為負，則隱含 - 標誌，並使用絕對值作為最小欄位寬度。
（可選）整數值或 * ：指定最小欄位寬度。如有需要，結果用空格字元填充（預設）：右對齊時在左側填充，左對齊時在右側填充。當使用 * 時，寬度由一個額外的 int 型別參數指定，該參數出現在待轉換參數之前，以及（如果提供）提供精度的參數之前。如果該參數的值為負，則隱含 - 標誌，並使用絕對值作為最小欄位寬度。

- (optional) `**.**` followed by non-negative integer number or `*****`: specifies the *precision* of the conversion. In the case when `*` is used, the *precision* is specified by an additional argument of type `int`, which appears before the argument to be converted, but after the argument supplying minimum field width if one is supplied. If the value of this argument is negative, it is ignored. If neither a number nor `*` is used, the precision is taken as zero. See below for the exact semantics.
（可選）. 後跟非負整數或 * ：指定轉換的精度。當使用 * 時，精度由一個額外的 int 型別參數指定，該參數出現在待轉換參數之前，但如果提供了最小欄位寬度參數，則出現在該參數之後。如果該參數的值為負，則忽略。如果既未使用數字也未使用 * ，則精度取零。確切語意見下文。
（可選）. 後跟非負整數或 * ：指定轉換的精度。當使用 * 時，精度由一個額外的 int 型別參數指定，該參數出現在待轉換參數之前，但如果提供了最小欄位寬度參數，則出現在該參數之後。如果該參數的值為負，則忽略。如果既未使用數字也未使用 * ，則精度取零。確切語意見下文。

- (optional) *length modifier* that specifies the size of the argument (in combination with the conversion format specifier, it specifies the type of the corresponding argument).
（可選）長度修飾符，指定參數的大小（與轉換格式說明符結合，指定相應參數的型別）。
（可選）長度修飾符，指定參數的大小（與轉換格式說明符結合，指定相應參數的型別）。

- conversion format specifier.
轉換格式說明符。
轉換格式說明符。

If a conversion specification is invalid, the behavior is undefined.
如果轉換說明無效，則行為未定義。

#### Non-numeric

- `**%**`: Writes `%` character. Has no argument. No modifiers supported, full conversion specification must be `%%`.
% ：寫入 % 字元。無參數。不支援修飾符，完整的轉換說明必須為 %% 。

- `**p**`: Writes a pointer. Argument is a `void*`, `char*`, `signed char*`, or `unsigned char*`(since C23). Output format is implementation defined.
p ：寫入一個指標。參數為 void * 、char * 、signed char * 或 unsigned char *（C23 起）。輸出格式由實現定義。

- `**c**`: Writes a character. Argument type depends on the length modifier:
c ：寫入一個字元。參數型別取決於長度修飾符：

- (none): Argument is an `int`, which is converted to `unsigned char` and copied to the output stream.
（無）：參數為 int ，轉換為 unsigned char 並複製到輸出流。

- `**l**`: Argument is a `wint_t`, which is converted to a `wchar_t`, put into a null terminated array, and printed with the semantics of `%ls`.
l ：參數為 wint_t ，轉換為 wchar_t ，放入空終止陣列，並按 %ls 的語意列印。
（無）：參數為 int ，轉換為 unsigned char 並複製到輸出流。l ：參數為 wint_t ，轉換為 wchar_t ，放入空終止陣列，並按 %ls 的語意列印。

- `**s**`: Write a string. Argument is a pointer to the initial element of an array of characters. Argument type depends on the length modifier:
s ：寫入一個字串。參數是指向字元陣列首元素的指標。參數型別取決於長度修飾符：

- (none): Argument is a `char*`, `signed char*`, `unsigned char*`. Characters are copied to the output stream.
（無）：參數為 char * 、signed char * 、unsigned char * 。字元被複制到輸出流。

- `**l**`: Argument is a `wchar_t*`. String is converted to a narrow string via `wcrtomb` (with zero-initialized conversion state), and resulting characters copied to the output stream. For the precision modifier and `%n` specifier, the number of characters refers to the narrow string, not the converted-from wide string.
l ：參數為 wchar_t * 。字串透過 wcrtomb（使用零初始化的轉換狀態）轉換為窄字串，結果字元複製到輸出流。對於精度修飾符和 %n 說明符，字元數指窄字串，而非轉換前的寬字串。
（無）：參數為 char * 、signed char * 、unsigned char * 。字元被複制到輸出流。l ：參數為 wchar_t * 。字串透過 wcrtomb（使用零初始化的轉換狀態）轉換為窄字串，結果字元複製到輸出流。對於精度修飾符和 %n 說明符，字元數指窄字串，而非轉換前的寬字串。
The precision specifies the maximum number of characters to write. Characters are copied until the maximum is reached or a null terminator is found. The null terminator does not contribute to the number of characters reported by `%n`.
精度指定要寫入的最大字元數。字元被複制，直到達到最大值或遇到空終止符。空終止符不計入 %n 報告的字元數。

Even though `%c` expects `int` argument, it is safe to pass a `char` because of the integer promotion that takes place when a variadic function is called.
儘管 %c 期望 int 參數，但由於呼叫可變參數函式時會發生整數提升，傳遞 char 是安全的。

#### Integer

Let `SInt` and `UInt` be respective types determined by the length specifier:
令 SInt 和 UInt 為由長度說明符確定的相應型別：

- `**hh**`: `signed char` and `unsigned char`
|   | (since C99) |

- `**h**`: `short` and `unsigned short`
h ：short 和 unsigned short

- `**(none)**`: `int` and `unsigned`
（無）：int 和 unsigned

- `**l**`: `long` and `unsigned long`
l ：long 和 unsigned long

- `**ll**`: `long long` and `unsigned long long`

- `**j**`: `intmax_t` and `uintmax_t`

- `**z**`: signed version of `size_t` and `size_t`

- `**t**`: `ptrdiff_t` and unsigned version of `ptrdiff_t`
|   | (since C99) |

- `**w*N***`: Any signed integer type with bit-width `*N*` and any unsigned integer type with bit-width `*N*`

- `**wf*N***`: `int_fast*N*_t` and `uint_fast*N*_t`
|   | (since C23) |

Then:

- `**d/i**`: Writes a signed integer in decimal representation. Argument is an `SInt`.
d/i ：以十進位製表示寫入一個有符號整數。參數為 SInt 。

- `**u**`: Writes an unsigned integer in decimal representation. Argument is an `UInt`.
u ：以十進位製表示寫入一個無符號整數。參數為 UInt 。

- `**x/X**`: Writes an unsigned integer in hexadecimal representation. Argument is an `UInt`. The alternative form prefixes `0x` if the argument is non-zero. If the format specifier is uppercase, the corresponding output will also be uppercase.
x/X ：以十六進位製表示寫入一個無符號整數。參數為 UInt 。替代形式在參數非零時新增 0x 字首。如果格式說明符為大寫，則相應輸出也為大寫。

- `**b**`: Writes an unsigned integer in binary representation. Argument is an `UInt`. The alternative form prefixes `0b` if the argument is non-zero.
|   | (since C23) |

- `**o**`: Writes an unsigned integer in octal representation. Argument is an `UInt`. The alternative form increases the precision as much as is needed for the first digit written to be zero.
o ：以八進位製表示寫入一個無符號整數。參數為 UInt 。替代形式會儘可能增加精度，使得寫入的第一個數字為零。

- `**n**`: Returns the number of characters written so far by this call to the function, including minimum field width padding. Argument is an `SInt*` to write the result to. Only supported modifier is length modifier.
n ：傳回本次函式呼叫到目前為止寫入的字元數，包括最小欄位寬度填充。參數為用於寫入結果的 SInt * 。唯一支援的修飾符是長度修飾符。

The precision specifies the minimum number of digits to write, leading zeros will be written if necessary. If unspecified, a precision of 1 is used. If precision is 0 and the argument is 0, no digits will be written (the plus or space character is still written if the `**+**` or *space* flag is specified).
精度指定要寫入的最小位數，必要時將寫入前導零。如果未指定，則使用精度 1。如果精度為 0 且參數為 0，則不寫入任何數字（如果指定了 + 或空格標誌，仍會寫入加號或空格字元）。
The correct conversion specifications for the fixed-width character types (int8_t, etc) are defined in the header <inttypes.h> (although PRIdMAX, PRIuMAX, etc is synonymous with `%jd`, `%ju`, etc).
定寬字元型別（int8_t 等）的正確轉換說明定義在標頭檔 <inttypes.h> 中（儘管 PRIdMAX 、PRIuMAX 等與 %jd 、%ju 等等價）。
The memory-writing conversion specifier `%n` is a common target of security exploits where format strings depend on user input and is not supported by the bounds-checked `printf_s` family of functions.
記憶體寫入轉換說明符 %n 是格式字串依賴使用者輸入時安全漏洞的常見攻擊目標，且不受邊界檢查的 printf_s 函式族支援。
There is a sequence point after the action of each conversion specifier; this permits storing multiple `%n` results in the same variable or, as an edge case, printing a string modified by an earlier `%n` within the same call.
每個轉換說明符的動作之後有一個順序點；這允許將多個 %n 的結果存入同一變數，或者作為邊界情況，在同一呼叫中列印被較早 %n 修改過的字串。

#### Floating-point

The argument type is determined by the length specifier:
參數型別由長度說明符確定：

- `**(none)**`: `double`
（無）：double

- `**l**`: `double`
|   | (since C99) |

- `**L**`: `long double`
L ：long double

- `**H**`: `_Decimal32`

- `**D**`: `_Decimal64`

- `**DD**`: `_Decimal128`
|   | (since C23) |

Then:

- If the argument is infinity, then `inf` or `infinity` is written. Which one is used is implementation defined.
如果參數為無窮大，則寫入 inf 或 infinity。使用哪一個由實現定義。

- If the argument is not-a-number, then `nan` or `nan(*char_sequence*)` is written. Which one is used is implementation defined.
如果參數為非數，則寫入 nan 或 nan( char_sequence )。使用哪一個由實現定義。

Otherwise:

- `**f/F**`: Writes a floating-point in decimal notation *[-]ddd.ddd*. The precision specifies the number of decimal places, trailing zeros will be written if necessary. If unspecified, a precision of 6 is used.
f/F ：以十進位制記法 [-]ddd.ddd 寫入浮點數。精度指定小數位數，必要時將寫入尾隨零。如果未指定，則使用精度 6。

- `**e/E**`: Writes a floating-point in decimal exponent notation *[-]d.ddd*`**e**`*±dd*. If the exponent is less than 10, it is written with a leading zero. The precision specifies the number of decimal places, trailing zeros will be written if necessary. If unspecified, a precision of 6 is used.
e/E ：以十進位制指數記法 [-]d.ddd e ±dd 寫入浮點數。如果指數小於 10，則以零開頭寫入。精度指定小數位數，必要時將寫入尾隨零。如果未指定，則使用精度 6。

- `**g/G**`: Writes a floating-point in decimal or decimal exponent notation, depending on the argument and precision.
g/G ：根據參數和精度，以十進位制或十進位制指數記法寫入浮點數。

Let *P = max(0, precision - 1)*, or 5 if precision is unspecified.
令 P = max(0, precision - 1) ，若未指定精度則為 5。
Let *EXP* be the exponent written if `%e` were the specification.
- If *-4 ≤ EXP ≤ P*, then the argument is written as if the `f/F` format specifier was used with precision *P - EXP*.
如果 -4 ≤ EXP ≤ P ，則參數按使用精度 P - EXP 的 f/F 格式說明符寫入。

- Otherwise, the argument is written as if the `e/E` format specifier was used with precision *P*.
否則，參數按使用精度 P 的 e/E 格式說明符寫入。
令 EXP 為若規格為 %e 時所寫入的指數。如果 -4 ≤ EXP ≤ P ，則參數按使用精度 P - EXP 的 f/F 格式說明符寫入。否則，參數按使用精度 P 的 e/E 格式說明符寫入。

- `**a/A**`: Writes a floating-point in hexadecimal exponent notation *[-]*`**0x**`*h.hhh*`**p**`*±d*. The precision specifies the number of digits following the decimal point, trailing zeros will be written if necessary.

- If the argument type is `double` or `long double`:

- If the precision is unspecified:

- If `FLT_RADIX` is a power of 2, the exact value is printed.

- Otherwise, enough digits are printed to distinguish the number from any other value of the argument type, except that trailing zeros may be omitted.

- Otherwise, for decimal type arguments:

Let *qmin,qmax* be:
- -101, 90 if argument type is `_Decimal32`

- -398, 369 if argument type is `_Decimal64`

- -6176, 6111 if argument type is `_Decimal128`
Let the argument be expressed with integers *s,c,q* as *s × c × 10* where:
- *c ≥ 0*,

- *s* is -1 or 1,

- *qmin ≤ q ≤ qmax*.
Let *n* be the number of significant digits in *c*.
Let *P* be the precision.
- If *P* is specified and *0 < P < n*, then the argument is rounded to *P* decimal digits, with unbounded exponent range, such that *c* is a *P*-digit integer

- If *0 ≤ -q ≤ n + 5*, then the argument is written with the style of the `f/F` format specifier used with precision *-q*.

- Otherwise, the argument is written with the style of the `e/E` format specifier used with precision *n - 1*, except that:

- If *c = 0*, then *q* is written for the exponent.

- No leading zero is written for the exponent.
|   | (since C23) |

There is exactly one digit before the decimal place, but it is unspecified how this digit is chosen. For example, `0x1.fp+6` and `0xf.6p+3` are both valid outputs for an argument of `123.0` with precision 1.
|   | (since C99) |

The alternative form writes a decimal point even if precision is 0. If the format specifier is uppercase, the corresponding output will also be uppercase.
替代形式即使精度為 0 也會寫入小數點。如果格式說明符為大寫，則相應輸出也為大寫。

### Return value

1,2) number of characters transmitted to the output stream or negative value if an output error or an encoding error (for string and character conversion specifiers) occurred.

3) number of characters written to `buffer` (not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred.

4) number of characters (not including the terminating null character) which would have been written to `buffer` if `bufsz` was ignored, or a negative value if an encoding error (for string and character conversion specifiers) occurred.

5,6) number of characters transmitted to the output stream or negative value if an output error, a runtime constraints violation error, or an encoding error occurred.

7) number of characters written to `buffer`, not counting the null character (which is always written as long as `buffer` is not a null pointer and `bufsz` is not zero and not greater than RSIZE_MAX), or zero on runtime constraint violations, and negative value on encoding errors.

8) number of characters not including the terminating null character (which is always written as long as `buffer` is not a null pointer and `bufsz` is not zero and not greater than RSIZE_MAX), which would have been written to `buffer` if `bufsz` was ignored, or a negative value if a runtime constraints violation or an encoding error occurred.

### Notes

The C standard and POSIX specify that the behavior of `sprintf` and its variants is undefined when an argument overlaps with the destination buffer. Example:
C 標準和 POSIX 規定，當某個參數與目標緩衝區重疊時， sprintf 及其變體的行為是未定義行為。示例：

```c
sprintf(dst, "%s and %s", dst, t); // <- broken: undefined behavior
```

POSIX specifies that errno is set on error. It also specifies additional conversion specifications, most notably support for argument reordering (`n$` immediately after `%` indicates `n` argument).
POSIX 規定出錯時設定 errno 。它還規定了額外的轉換說明符，其中最著名的是對參數重排序的支援（緊跟在 % 之後的 n$ 表示第 n 個參數）。
Calling `snprintf` with zero `bufsz` and null pointer for `buffer` is useful to determine the necessary buffer size to contain the output:
以 bufsz 為零且 buffer 為空指標呼叫 snprintf ，有助於確定容納輸出所需的緩衝區大小：

```c
const char fmt[] = "sqrt(2) = %f"; int sz = snprintf(NULL, 0, fmt, sqrt(2)); char buf[sz + 1]; // note +1 for terminating null byte snprintf(buf, sizeof buf, fmt, sqrt(2));
```

`snprintf_s`, just like `snprintf`, but unlike `sprintf_s`, will truncate the output to fit in `bufsz - 1`.
snprintf_s 與 snprintf 類似，但與 sprintf_s 不同，它會將輸出截斷以適應 bufsz - 1 。

### Example

Run this code

```c
#include <inttypes.h> #include <stdint.h> #include <stdio.h> int main(void) { const char* s = "Hello"; printf("Strings:\n"); // same as puts("Strings"); printf(" padding:\n"); printf("\t[%10s]\n", s); printf("\t[%-10s]\n", s); printf("\t[%*s]\n", 10, s); printf(" truncating:\n"); printf("\t%.4s\n", s); printf("\t%.*s\n", 3, s); printf("Characters:\t%c %%\n", 'A'); printf("Integers:\n"); printf("\tDecimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4,-4); printf("\tHexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6); printf("\tOctal:\t\t%o %#o %#o\n", 10, 10, 4); printf("Floating-point:\n"); printf("\tRounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3); printf("\tPadding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5); printf("\tScientific:\t%E %e\n", 1.5, 1.5); printf("\tHexadecimal:\t%a %A\n", 1.5, 1.5); printf("\tSpecial values:\t0/0=%g 1/0=%g\n", 0.0 / 0.0, 1.0 / 0.0); printf("Fixed-width types:\n"); printf("\tLargest 32-bit value is %" PRIu32 " or %#" PRIx32 "\n", UINT32_MAX, UINT32_MAX ); }
```

Possible output:
可能的輸出：

```c
Strings: padding: [ Hello] [Hello ] [ Hello] truncating: Hell Hel Characters: A % Integers: Decimal: 1 2 000003 0 +4 -4 Hexadecimal: 5 a A 0x6 Octal: 12 012 04 Floating-point: Rounding: 1.500000 2 1.30000000000000004440892098500626 Padding: 01.50 1.50 1.50 Scientific: 1.500000E+00 1.500000e+00 Hexadecimal: 0x1.8p+0 0X1.8P+0 Special values: 0/0=-nan 1/0=inf Fixed-width types: Largest 32-bit value is 4294967295 or 0xffffffff
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.6.1 The fprintf function (p: TBD)
7.21.6.1 fprintf 函式（p: TBD）
7.21.6.1 fprintf 函式（p: TBD）

- 7.21.6.3 The printf function (p: TBD)
7.21.6.3 printf 函式（p: TBD）
7.21.6.3 printf 函式（p: TBD）

- 7.21.6.5 The snprintf function (p: TBD)
7.21.6.5 snprintf 函式（p: TBD）
7.21.6.5 snprintf 函式（p: TBD）

- 7.21.6.6 The sprintf function (p: TBD)
7.21.6.6 sprintf 函式（p: TBD）
7.21.6.6 sprintf 函式（p: TBD）

- K.3.5.3.1 The fprintf_s function (p: TBD)
K.3.5.3.1 fprintf_s 函式（p: TBD）
K.3.5.3.1 fprintf_s 函式（p: TBD）

- K.3.5.3.3 The printf_s function (p: TBD)
K.3.5.3.3 printf_s 函式（p: TBD）
K.3.5.3.3 printf_s 函式（p: TBD）

- K.3.5.3.5 The snprintf_s function (p: TBD)
K.3.5.3.5 snprintf_s 函式（p: TBD）
K.3.5.3.5 snprintf_s 函式（p: TBD）

- K.3.5.3.6 The sprintf_s function (p: TBD)
K.3.5.3.6 sprintf_s 函式（p: TBD）
K.3.5.3.6 sprintf_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.6.1 The fprintf function (p: 225-230)
7.21.6.1 fprintf 函式（p: 225-230）
7.21.6.1 fprintf 函式（p: 225-230）

- 7.21.6.3 The printf function (p: 236)
7.21.6.3 printf 函式（p: 236）
7.21.6.3 printf 函式（p: 236）

- 7.21.6.5 The snprintf function (p: 237)
7.21.6.5 snprintf 函式（p: 237）
7.21.6.5 snprintf 函式（p: 237）

- 7.21.6.6 The sprintf function (p: 237)
7.21.6.6 sprintf 函式（p: 237）
7.21.6.6 sprintf 函式（p: 237）

- K.3.5.3.1 The fprintf_s function (p: 430)
K.3.5.3.1 fprintf_s 函式（p: 430）
K.3.5.3.1 fprintf_s 函式（p: 430）

- K.3.5.3.3 The printf_s function (p: 432)
K.3.5.3.3 printf_s 函式（p: 432）
K.3.5.3.3 printf_s 函式（p: 432）

- K.3.5.3.5 The snprintf_s function (p: 432-433)
K.3.5.3.5 snprintf_s 函式（p: 432-433）
K.3.5.3.5 snprintf_s 函式（p: 432-433）

- K.3.5.3.6 The sprintf_s function (p: 433)
K.3.5.3.6 sprintf_s 函式（p: 433）
K.3.5.3.6 sprintf_s 函式（p: 433）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.6.1 The fprintf function (p: 309-316)
7.21.6.1 fprintf 函式（p: 309-316）
7.21.6.1 fprintf 函式（p: 309-316）

- 7.21.6.3 The printf function (p: 324)
7.21.6.3 printf 函式（p: 324）
7.21.6.3 printf 函式（p: 324）

- 7.21.6.5 The snprintf function (p: 325)
7.21.6.5 snprintf 函式（p: 325）
7.21.6.5 snprintf 函式（p: 325）

- 7.21.6.6 The sprintf function (p: 325-326)
7.21.6.6 sprintf 函式（p: 325-326）
7.21.6.6 sprintf 函式（p: 325-326）

- K.3.5.3.1 The fprintf_s function (p: 591)
K.3.5.3.1 fprintf_s 函式（p: 591）
K.3.5.3.1 fprintf_s 函式（p: 591）

- K.3.5.3.3 The printf_s function (p: 593-594)
K.3.5.3.3 printf_s 函式（p: 593-594）
K.3.5.3.3 printf_s 函式（p: 593-594）

- K.3.5.3.5 The snprintf_s function (p: 594-595)
K.3.5.3.5 snprintf_s 函式（p: 594-595）
K.3.5.3.5 snprintf_s 函式（p: 594-595）

- K.3.5.3.6 The sprintf_s function (p: 595-596)
K.3.5.3.6 sprintf_s 函式（p: 595-596）
K.3.5.3.6 sprintf_s 函式（p: 595-596）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.6.1 The fprintf function (p: 274-282)
7.19.6.1 fprintf 函式（p: 274-282）
7.19.6.1 fprintf 函式（p: 274-282）

- 7.19.6.3 The printf function (p: 290)
7.19.6.3 printf 函式（p: 290）
7.19.6.3 printf 函式（p: 290）

- 7.19.6.5 The snprintf function (p: 290-291)
7.19.6.5 snprintf 函式（p: 290-291）
7.19.6.5 snprintf 函式（p: 290-291）

- 7.19.6.6 The sprintf function (p: 291)
7.19.6.6 sprintf 函式（p: 291）
7.19.6.6 sprintf 函式（p: 291）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.6.1 The fprintf function
4.9.6.1 fprintf 函式
4.9.6.1 fprintf 函式

- 4.9.6.3 The printf function
4.9.6.3 printf 函式
4.9.6.3 printf 函式

- 4.9.6.5 The sprintf function
4.9.6.5 sprintf 函式
4.9.6.5 sprintf 函式

### See also

wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s
(C95)(C95)(C95)(C11)(C11)(C11)(C11)
|   | prints formatted wide character output to stdout, a file stream or a buffer
(function)   |

vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | prints formatted output to stdout, a file stream or a buffer
using variable argument list
(function)   |

fputs
|   | writes a character string to a file stream
(function)   |

scanffscanfsscanfscanf_sfscanf_ssscanf_s
(C11)(C11)(C11)
|   | reads formatted input from stdin, a file stream or a buffer
(function)   |

C++ documentation for printf, fprintf, sprintf, snprintf

---
來源頁路徑：`en.cppreference.com/c/io/fprintf.html`

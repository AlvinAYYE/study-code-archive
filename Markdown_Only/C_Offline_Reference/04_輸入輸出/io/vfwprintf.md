# vwprintf, vfwprintf, vswprintf, vwprintf_s, vfwprintf_s, vswprintf_s, vsnwprintf_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int vwprintf( const wchar_t* format, va_list vlist );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
int vwprintf( const wchar_t* restrict format, va_list vlist );
```
|   |   |   | (since C99) |

```c
int vfwprintf( FILE* stream, const wchar_t* format, va_list vlist );
```
|   |  (2) |   | (since C95)
(until C99) |

```c
int vfwprintf( FILE* restrict stream,  const wchar_t* restrict format, va_list vlist );
```
|   |   |   | (since C99) |

```c
int vswprintf( wchar_t* buffer, size_t bufsz,  const wchar_t* format, va_list vlist );
```
|   |  (3) |   | (since C95)
(until C99) |

```c
int vswprintf( wchar_t* restrict buffer, size_t bufsz,  const wchar_t* restrict format, va_list vlist );
```
|   |   |   | (since C99) |

```c
int vwprintf_s( const wchar_t* restrict format, va_list vlist);
```
|   |  (4)  |   |  (since C11)  |

```c
int vfwprintf_s( FILE* restrict stream,  const wchar_t* restrict format, va_list vlist);
```
|   |  (5)  |   |  (since C11)  |

```c
int vswprintf_s( wchar_t* restrict buffer, rsize_t bufsz,  const wchar_t* restrict format, va_list vlist);
```
|   |  (6)  |   |  (since C11)  |

```c
int vsnwprintf_s( wchar_t* restrict buffer, rsize_t bufsz,  const wchar_t* restrict format, va_list vlist);
```
|   |  (7)  |   |  (since C11)  |

|  |  |  |  |

Loads the data from locations, defined by `vlist`, converts them to wide string equivalents and writes the results to a variety of sinks.
從 vlist 定義的位置載入資料，將其轉換為等效的寬字串，並將結果寫入各種輸出目標。

1) Writes the results to stdout.

2) Writes the results to a file stream `stream`.

3) Writes the results to a wide string `buffer`. At most `bufsz - 1` wide characters are written followed by null wide character. The resulting wide character string will be terminated with a null wide character, unless `bufsz` is zero.

4-6) Same as (1-3), except that the following errors are detected at runtime and call the currently installed constraint handler function:
- the conversion specifier `%n` is present in `format`
格式中存在轉換說明符 %n

- any of the arguments corresponding to `%s` is a null pointer
對應於 %s 的任何參數是空指標

- `format` or `buffer` is a null pointer
format 或 buffer 是空指標

- `bufsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
bufsz 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- encoding errors occur in any of string and character conversion specifiers
在任何字串或字元轉換說明符中發生編碼錯誤

- (for `vswprintf_s` only), the string to be stored in `buffer` (including the trailing wide null) would be exceed `bufsz`.
（僅針對 vswprintf_s），要儲存在 buffer 中的字串（包括末尾的寬空字元）將超出 bufsz。

7) Same as (6), except it will truncate the result to fit within the array pointed to by `buffer`.

As with all bounds-checked functions, `vwprintf_s`, `vfwprintf_s`, `vswprintf_s`, and `vsnwprintf_s` are only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>.

### Parameters

| stream  |   | -  |   | output wide stream to write to  |

| buffer  |   | -  |   | pointer to a wide string to write to  |

| bufsz  |   | -  |   | maximum number of wide characters to write  |

| format  |   | -  |   | pointer to a null-terminated wide string specifying how to interpret the data  |

| vlist  |   | -  |   | variable argument list containing the data to print.  |

The **format** string consists of ordinary wide characters (except `**%**`), which are copied unchanged into the output stream, and conversion specifications. Each conversion specification has the following format:
格式字串由普通寬字元（除 % 外）組成，這些字元原樣複製到輸出流中，以及轉換說明。每個轉換說明具有以下格式：

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

- (none): Argument is an `int`, which is converted to wide character via `btowc` and copied to the output stream.
（無）：參數為 int ，透過 btowc 轉換為寬字元並複製到輸出流。

- `**l**`: Argument is a `wint_t`, which is converted to a `wchar_t` and copied to the output stream.
l ：參數為 wint_t ，轉換為 wchar_t 並複製到輸出流。
（無）：參數為 int ，透過 btowc 轉換為寬字元並複製到輸出流。l ：參數為 wint_t ，轉換為 wchar_t 並複製到輸出流。

- `**s**`: Write a string. Argument is a pointer to the initial element of an array of characters. Argument type depends on the length modifier:
s ：寫入一個字串。參數是指向字元陣列首元素的指標。參數型別取決於長度修飾符：

- (none): Argument is a `char*`, `signed char*`, `unsigned char*`. String is converted to a wide string via `mbrtowc` (with zero-initialized conversion state), and resulting characters copied to the output stream. For the precision modifier and `%n` specifier, the number of characters refers to the wide string, not the converted-from narrow string.
（無）：參數為 char * 、signed char * 、unsigned char * 。字串透過 mbrtowc（使用零初始化的轉換狀態）轉換為寬字串，結果字元複製到輸出流。對於精度修飾符和 %n 說明符，字元數指寬字串，而非轉換前的窄字串。

- `**l**`: Argument is a `wchar_t*`. Characters are copied to the output stream.
l ：參數為 wchar_t * 。字元被複制到輸出流。
（無）：參數為 char * 、signed char * 、unsigned char * 。字串透過 mbrtowc（使用零初始化的轉換狀態）轉換為寬字串，結果字元複製到輸出流。對於精度修飾符和 %n 說明符，字元數指寬字串，而非轉換前的窄字串。l ：參數為 wchar_t * 。字元被複制到輸出流。
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

1,4) The number of wide characters written if successful or negative value if an error occurred.

3) The number of wide characters written if successful or negative value if an error occurred. If the resulting string gets truncated due to `bufsz` limit, function returns the total number of characters (not including the terminating null wide character) which would have been written, if the limit were not imposed.

2,5) number of wide characters transmitted to the output stream or negative value if an output error, a runtime constraints violation error, or an encoding error occurred.

6) number of wide characters written to `buffer`, not counting the null wide character (which is always written as long as `buffer` is not a null pointer and `bufsz` is not zero and not greater than `RSIZE_MAX/sizeof(wchar_t)`), or zero on runtime constraint violations, and negative value on encoding errors.

7) number of wide characters not including the terminating null character (which is always written as long as `buffer` is not a null pointer and `bufsz` is not zero and not greater than `RSIZE_MAX/sizeof(wchar_t)`), which would have been written to `buffer` if `bufsz` was ignored, or a negative value if a runtime constraints violation or an encoding error occurred.

### Notes

All these functions invoke va_arg at least once, the value of `arg` is indeterminate after the return. These functions to not invoke va_end, and it must be done by the caller.
所有這些函式至少呼叫一次 va_arg，傳回後 arg 的值是不確定的。這些函式不呼叫 va_end，必須由呼叫者完成。
While narrow strings provide vsnprintf, which makes it possible to determine the required output buffer size, there is no equivalent for wide strings (until C11's vsnwprintf_s), and in order to determine the buffer size, the program may need to call `vswprintf`, check the result value, and reallocate a larger buffer, trying again until successful.
雖然窄字串提供了 vsnprintf，可以確定所需的輸出緩衝區大小，但寬字串沒有等效函式（直到 C11 的 vsnwprintf_s），為了確定緩衝區大小，程式可能需要呼叫 vswprintf、檢查結果值，並重新分配更大的緩衝區，反覆嘗試直至成功。
`vsnwprintf_s`, unlike `vswprintf_s`, will truncate the result to fit within the array pointed to by `buffer`, even though truncation is treated as an error by most bounds-checked functions.
vsnwprintf_s 與 vswprintf_s 不同，會截斷結果以適應 buffer 指向的陣列，即使截斷被大多數邊界檢查函式視為錯誤。

### Example

Run this code

```c
#include <locale.h> #include <stdarg.h> #include <stddef.h> #include <stdio.h> #include <time.h> #include <wchar.h> void debug_wlog(const wchar_t* fmt, ...) {  struct timespec ts;  timespec_get(&ts, TIME_UTC);  char time_buf[100];  size_t rc = strftime(time_buf, sizeof time_buf, "%D %T", gmtime(&ts.tv_sec));  snprintf(time_buf + rc, sizeof time_buf - rc, ".%06ld UTC", ts.tv_nsec / 1000);  va_list args;  va_start(args, fmt);  wchar_t buf[1024];  int rc2 = vswprintf(buf, sizeof buf / sizeof *buf, fmt, args);  va_end(args);  if (rc2 > 0)  wprintf(L"%s [debug]: %ls\n", time_buf, buf);  else  wprintf(L"%s [debug]: (string too long)\n", time_buf); } int main(void) {  setlocale(LC_ALL, "");  debug_wlog(L"Logging, %d, %d, %d", 1, 2, 3); }
```

Possible output:
可能的輸出：

```c
02/20/15 22:12:38.476575 UTC [debug]: Logging, 1, 2, 3
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.2.5 The vfwprintf function (p: TBD)
7.29.2.5 vfwprintf 函式（頁：TBD）
7.29.2.5 vfwprintf 函式（頁：TBD）

- 7.29.2.7 The vswprintf function (p: TBD)
7.29.2.7 vswprintf 函式（頁：TBD）
7.29.2.7 vswprintf 函式（頁：TBD）

- 7.29.2.9 The vwprintf function (p: TBD)
7.29.2.9 vwprintf 函式（頁：TBD）
7.29.2.9 vwprintf 函式（頁：TBD）

- K.3.9.1.6 The vfwprintf_s function (p: TBD)
K.3.9.1.6 vfwprintf_s 函式（頁：TBD）
K.3.9.1.6 vfwprintf_s 函式（頁：TBD）

- K.3.9.1.8 The vsnwprintf_s function (p: TBD)
K.3.9.1.8 vsnwprintf_s 函式（頁：TBD）
K.3.9.1.8 vsnwprintf_s 函式（頁：TBD）

- K.3.9.1.9 The vswprintf_s function (p: TBD)
K.3.9.1.9 vswprintf_s 函式（頁：TBD）
K.3.9.1.9 vswprintf_s 函式（頁：TBD）

- K.3.9.1.11 The vwprintf_s function (p: TBD)
K.3.9.1.11 vwprintf_s 函式（頁：TBD）
K.3.9.1.11 vwprintf_s 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.2.5 The vfwprintf function (p: TBD)
7.29.2.5 vfwprintf 函式（頁：TBD）
7.29.2.5 vfwprintf 函式（頁：TBD）

- 7.29.2.7 The vswprintf function (p: TBD)
7.29.2.7 vswprintf 函式（頁：TBD）
7.29.2.7 vswprintf 函式（頁：TBD）

- 7.29.2.9 The vwprintf function (p: TBD)
7.29.2.9 vwprintf 函式（頁：TBD）
7.29.2.9 vwprintf 函式（頁：TBD）

- K.3.9.1.6 The vfwprintf_s function (p: TBD)
K.3.9.1.6 vfwprintf_s 函式（頁：TBD）
K.3.9.1.6 vfwprintf_s 函式（頁：TBD）

- K.3.9.1.8 The vsnwprintf_s function (p: TBD)
K.3.9.1.8 vsnwprintf_s 函式（頁：TBD）
K.3.9.1.8 vsnwprintf_s 函式（頁：TBD）

- K.3.9.1.9 The vswprintf_s function (p: TBD)
K.3.9.1.9 vswprintf_s 函式（頁：TBD）
K.3.9.1.9 vswprintf_s 函式（頁：TBD）

- K.3.9.1.11 The vwprintf_s function (p: TBD)
K.3.9.1.11 vwprintf_s 函式（頁：TBD）
K.3.9.1.11 vwprintf_s 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.2.5 The vfwprintf function (p: 417-418)
7.29.2.5 vfwprintf 函式（頁：417-418）
7.29.2.5 vfwprintf 函式（頁：417-418）

- 7.29.2.7 The vswprintf function (p: 419)
7.29.2.7 vswprintf 函式（頁：419）
7.29.2.7 vswprintf 函式（頁：419）

- 7.29.2.9 The vwprintf function (p: 420)
7.29.2.9 vwprintf 函式（頁：420）
7.29.2.9 vwprintf 函式（頁：420）

- K.3.9.1.6 The vfwprintf_s function (p: 632)
K.3.9.1.6 vfwprintf_s 函式（頁：632）
K.3.9.1.6 vfwprintf_s 函式（頁：632）

- K.3.9.1.8 The vsnwprintf_s function (p: 633-634)
K.3.9.1.8 vsnwprintf_s 函式（頁：633-634）
K.3.9.1.8 vsnwprintf_s 函式（頁：633-634）

- K.3.9.1.9 The vswprintf_s function (p: 634-635)
K.3.9.1.9 vswprintf_s 函式（頁：634-635）
K.3.9.1.9 vswprintf_s 函式（頁：634-635）

- K.3.9.1.11 The vwprintf_s function (p: 636)
K.3.9.1.11 vwprintf_s 函式（頁：636）
K.3.9.1.11 vwprintf_s 函式（頁：636）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.2.5 The vfwprintf function (p: 363)
7.24.2.5 vfwprintf 函式（頁：363）
7.24.2.5 vfwprintf 函式（頁：363）

- 7.24.2.7 The vswprintf function (p: 364)
7.24.2.7 vswprintf 函式（頁：364）
7.24.2.7 vswprintf 函式（頁：364）

- 7.24.2.9 The vwprintf function (p: 365)
7.24.2.9 vwprintf 函式（頁：365）
7.24.2.9 vwprintf 函式（頁：365）

### See also

vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | prints formatted output to stdout, a file stream or a buffer
using variable argument list
(function)   |

wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s
(C95)(C95)(C95)(C11)(C11)(C11)(C11)
|   | prints formatted wide character output to stdout, a file stream or a buffer
(function)   |

C++ documentation for vwprintf, vfwprintf, vswprintf

---
來源頁路徑：`en.cppreference.com/c/io/vfwprintf.html`

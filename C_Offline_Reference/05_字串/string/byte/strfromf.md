# strfromf, strfromd, strfroml

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int strfromf( char* restrict s, size_t n, const char* restrict format, float fp );
```
|   |   |   |  (since C23)  |

```c
int strfromd( char* restrict s, size_t n, const char* restrict format, double fp );
```
|   |   |   |  (since C23)  |

```c
int strfroml( char* restrict s, size_t n, const char* restrict format, long double fp );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Converts a floating-point value to a byte string.
將浮點值轉換為位元組字串。
The functions are equivalent to `snprintf(s, n, format, fp)`, except that the format string shall only contain the character `%`, an optional precision that does not contain an asterisk `*`, and one of the conversion specifiers `a`, `A`, `e`, `E`, `f`, `F`, `g`, or `G`, which applies to the type `double`, `float`, or `long double`) indicated by the function suffix (rather than by a length modifier). Use of these functions with any other format string results in undefined behavior.
這些函式等價於 snprintf ( s , n , format , fp ) ，但格式字串只能包含字元 % 、一個不包含星號 * 的可選精度，以及一個適用於由函式字尾（而非長度修飾符）指示的 double 、 float 或 long double 型別的轉換說明符 a 、 A 、 e 、 E 、 f 、 F 、 g 或 G 。將這些函式與任何其他格式字串一起使用會導致未定義行為。

### Parameters

| s  |   | -  |   | pointer to a character string to write to  |

| n  |   | -  |   | up to n - 1 characters may be written, plus the null terminator  |

| format  |   | -  |   | pointer to a null-terminated byte string specifying how to interpret the data  |

| fp  |   | -  |   | floating-point value to convert  |

### Return value

The number of characters that would have been written had `n` been sufficiently large, not counting the terminating null character. Thus, the null-terminated output has been completely written if and only if the returned value is both nonnegative and less than `n`.
如果 n 足夠大，本應寫入的字元數，不包括終止空字元。因此，當且僅當傳回值非負且小於 n 時，空終止輸出已被完整寫入。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main() {  char buffer[32];  int written;  const char* format[] = {"%a", "%A", "%e", "%E", "%f", "%F", "%g", "%G"};  for (size_t fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)  {  written = strfromf(buffer, sizeof buffer, format[fmt], 3.1415f);  printf("strfromf(... %s ...) = %2i, buffer: \"%s\"\n",  format[fmt], written, buffer);  }  puts("");  for (size_t fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)  {  written = strfromd(buffer, sizeof buffer, format[fmt], 3.1415);  printf("strfromd(... %s ...) = %2i, buffer: \"%s\"\n",  format[fmt], written, buffer);  }  puts("");  for (size_t fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)  {  written = strfroml(buffer, sizeof buffer, format[fmt], 3.1415);  printf("strfroml(... %s ...) = %2i, buffer: \"%s\"\n",  format[fmt], written, buffer);  } }
```

Output:

```c
strfromf(... %a ...) = 13, buffer: "0x1.921cacp+1" strfromf(... %A ...) = 13, buffer: "0X1.921CACP+1" strfromf(... %e ...) = 12, buffer: "3.141500e+00" strfromf(... %E ...) = 12, buffer: "3.141500E+00" strfromf(... %f ...) = 8, buffer: "3.141500" strfromf(... %F ...) = 8, buffer: "3.141500" strfromf(... %g ...) = 6, buffer: "3.1415" strfromf(... %G ...) = 6, buffer: "3.1415" strfromd(... %a ...) = 20, buffer: "0x1.921cac083126fp+1" strfromd(... %A ...) = 20, buffer: "0X1.921CAC083126FP+1" strfromd(... %e ...) = 12, buffer: "3.141500e+00" strfromd(... %E ...) = 12, buffer: "3.141500E+00" strfromd(... %f ...) = 8, buffer: "3.141500" strfromd(... %F ...) = 8, buffer: "3.141500" strfromd(... %g ...) = 6, buffer: "3.1415" strfromd(... %G ...) = 6, buffer: "3.1415" strfroml(... %a ...) = 20, buffer: "0xc.90e5604189378p-2" strfroml(... %A ...) = 20, buffer: "0XC.90E5604189378P-2" strfroml(... %e ...) = 12, buffer: "3.141500e+00" strfroml(... %E ...) = 12, buffer: "3.141500E+00" strfroml(... %f ...) = 8, buffer: "3.141500" strfroml(... %F ...) = 8, buffer: "3.141500" strfroml(... %g ...) = 6, buffer: "3.1415" strfroml(... %G ...) = 6, buffer: "3.1415"
```

### Reference

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.1.3 The strfromd, strfromf, and strfroml functions
7.24.1.3 strfromd 、 strfromf 和 strfroml 函式
7.24.1.3 strfromd 、 strfromf 和 strfroml 函式

### See also

printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | prints formatted output to stdout, a file stream or a buffer
(function)   |

strtofstrtodstrtold
(C99)(C99)
|   | converts a byte string to a floating-point value
(function)   |

---
來源頁路徑：`en.cppreference.com/c/string/byte/strfromf.html`

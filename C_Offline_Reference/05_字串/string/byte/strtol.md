# strtol, strtoll

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
long strtol( const char* str, char** str_end, int base );
```
|   |  (1) |   | (until C99) |

```c
long strtol( const char* restrict str, char** restrict str_end, int base );
```
|   |   |   | (since C99) |

```c
long long strtoll( const char* restrict str, char** restrict str_end, int base );
```
|   |  (2)  |   |  (since C99)  |

|  |  |  |  |

Interprets an integer value in a byte string pointed to by `str`.
解釋由 str 指向的位元組字串中的整數值。
Discards any whitespace characters (as identified by calling isspace) until the first non-whitespace character is found, then takes as many characters as possible to form a valid *base-n* (where n=`base`) integer number representation and converts them to an integer value. The valid integer value consists of the following parts:
丟棄任何空白字元（透過呼叫 isspace 識別），直到找到第一個非空白字元，然後取儘可能多的字元以構成有效的 base-n（其中 n= base ）整數表示，並將其轉換為整數值。有效的整數值由以下部分組成：

- (optional) plus or minus sign
（可選）正號或負號

- (optional) prefix (`**0**`) indicating octal base (applies only when the base is `8` or `0`)
（可選）指示八進位制基數的字首 ( 0 ) （僅當基數為 8 或 0 時適用）

- (optional) prefix (`**0x**` or `**0X**`) indicating hexadecimal base (applies only when the base is `16` or `0`)
（可選）指示十六進位制基數的字首 ( 0x 或 0X ) （僅當基數為 16 或 0 時適用）

- a sequence of digits
數字序列

The set of valid values for base is `{0, 2, 3, ..., 36}`. The set of valid digits for base-`2` integers is `{0, 1}`, for base-`3` integers is `{0, 1, 2}`, and so on. For bases larger than `10`, valid digits include alphabetic characters, starting from `Aa` for base-`11` integer, to `Zz` for base-`36` integer. The case of the characters is ignored.
base 的有效值集合為 {0, 2, 3, ..., 36} 。對於 base- 2 整數，有效數字集合為 {0, 1} ；對於 base- 3 整數，為 {0, 1, 2} ，依此類推。對於大於 10 的基數，有效數字包括字母字元，從 base- 11 整數的 Aa 到 base- 36 整數的 Zz 。字元的大小寫被忽略。
Additional numeric formats may be accepted by the currently installed C locale.
目前安裝的 C 本地化環境可能接受額外的數值格式。
If the value of `base` is `0`, the numeric base is auto-detected: if the prefix is `**0**`, the base is octal, if the prefix is `**0x**` or `**0X**`, the base is hexadecimal, otherwise the base is decimal.
如果 base 的值為 0 ，則數值基數自動檢測：如果字首為 0 ，則基數為八進位制；如果字首為 0x 或 0X ，則基數為十六進位制；否則基數為十進位制。
If the minus sign was part of the input sequence, the numeric value calculated from the sequence of digits is negated as if by unary minus in the result type.
如果負號是輸入序列的一部分，則根據數字序列計算的數值在結果型別中按一元負號取反。
The functions set the pointer pointed to by `str_end` to point to the character past the last numeric character interpreted. If `str_end` is a null pointer, it is ignored.
這些函式將 str_end 指向的指標設定為指向最後一個被解釋的數字字元之後的字元。如果 str_end 為空指標，則忽略它。
If the `str` is empty or does not have the expected form, no conversion is performed, and (if `str_end` is not a null pointer) the value of `str` is stored in the object pointed to by `str_end`.
如果 str 為空或不具有預期的形式，則不執行轉換，並且（如果 str_end 不是空指標） str 的值儲存在 str_end 指向的物件中。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be interpreted  |

| str_end  |   | -  |   | pointer to a pointer to character  |

| base  |   | -  |   | *base* of the interpreted integer value  |

### Return value

- If successful, an integer value corresponding to the contents of `str` is returned.
如果成功，則傳回與 str 內容對應的整數值。

- If the converted value falls out of range of corresponding return type, a range error occurs (setting errno to ERANGE) and LONG_MAX, LONG_MIN, LLONG_MAX or LLONG_MIN is returned (according to sign of the value and the return type).
如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤（將 errno 設定為 ERANGE ）並根據值的符號和傳回型別傳回 LONG_MAX 、 LONG_MIN 、 LLONG_MAX 或 LLONG_MIN 。

- If no conversion can be performed, `0` is returned.
如果無法執行轉換，則傳回 0 。

### Example

Run this code

```c
#include <errno.h> #include <limits.h> #include <stdbool.h> #include <stdio.h> #include <stdlib.h>   int main(void) {  // parsing with error handling  const char* p = "10 200000000000000000000000000000 30 -40 junk";  printf("Parsing '%s':\n", p);  for (;;)  {  // errno can be set to any non-zero value by a library function call  // regardless of whether there was an error, so it needs to be cleared  // in order to check the error set by strtol  errno = 0;  char* end;  const long i = strtol(p, &end, 10);  if (p == end)  break;    const bool range_error = errno == ERANGE;  printf("Extracted '%.*s', strtol returned %ld.", (int)(end-p), p, i);  p = end;    if (range_error)  printf("\n --> Range error occurred.");    putchar('\n');  }    printf("Unextracted leftover: '%s'\n\n", p);    // parsing without error handling  printf("\"1010\" in binary --> %ld\n", strtol("1010", NULL, 2));  printf("\"12\" in octal --> %ld\n", strtol("12", NULL, 8));  printf("\"A\" in hex --> %ld\n", strtol("A", NULL, 16));  printf("\"junk\" in base-36 --> %ld\n", strtol("junk", NULL, 36));  printf("\"012\" in auto-detected base --> %ld\n", strtol("012", NULL, 0));  printf("\"0xA\" in auto-detected base --> %ld\n", strtol("0xA", NULL, 0));  printf("\"junk\" in auto-detected base --> %ld\n", strtol("junk", NULL, 0)); }
```

Possible output:
可能的輸出：

```c
Parsing '10 200000000000000000000000000000 30 -40 junk': Extracted '10', strtol returned 10. Extracted ' 200000000000000000000000000000', strtol returned 9223372036854775807. --> Range error occurred. Extracted ' 30', strtol returned 30. Extracted ' -40', strtol returned -40. Unextracted leftover: ' junk' "1010" in binary --> 10 "12" in octal --> 10 "A" in hex --> 10 "junk" in base-36 --> 926192 "012" in auto-detected base --> 10 "0xA" in auto-detected base --> 10 "junk" in auto-detected base --> 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.1.7 The strtol, strtoll, strtoul, and strtoull functions (p: 362-363)
7.24.1.7 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：362-363）
7.24.1.7 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：362-363）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 251-252)
7.22.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：251-252）
7.22.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：251-252）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 344-345)
7.22.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：344-345）
7.22.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：344-345）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 310-311)
7.20.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：310-311）
7.20.1.4 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：310-311）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.1.5 The strtol function
4.10.1.5 strtol 函式
4.10.1.5 strtol 函式

### See also

atoiatolatoll
(C99)
|   | converts a byte string to an integer value
(function)   |

strtoul strtoull
(C99)
|   | converts a byte string to an unsigned integer value
(function)   |

wcstolwcstoll
(C95)(C99)
|   | converts a wide string to an integer value
(function)   |

wcstoulwcstoull
(C95)(C99)
|   | converts a wide string to an unsigned integer value
(function)   |

C++ documentation for strtol, strtoll

---
來源頁路徑：`en.cppreference.com/c/string/byte/strtol.html`

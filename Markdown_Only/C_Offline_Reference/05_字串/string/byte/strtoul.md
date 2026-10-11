# strtoul, strtoull

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
unsigned long strtoul( const char* str, char** str_end,  int base );
```
|   |   |   | (until C99) |

```c
unsigned long strtoul( const char* restrict str, char** restrict str_end,  int base );
```
|   |   |   | (since C99) |

```c
unsigned long long strtoull( const char* restrict str, char** restrict str_end,  int base );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Interprets an unsigned integer value in a byte string pointed to by `str`.
解釋由 str 指向的位元組字串中的無符號整數值。
Discards any whitespace characters (as identified by calling isspace) until the first non-whitespace character is found, then takes as many characters as possible to form a valid *base-n* (where n=`base`) unsigned integer number representation and converts them to an integer value. The valid unsigned integer value consists of the following parts:
丟棄任何空白字元（透過呼叫 isspace 識別），直到找到第一個非空白字元，然後取儘可能多的字元以構成有效的 base-n（其中 n= base ）無符號整數表示，並將其轉換為整數值。有效的無符號整數值由以下部分組成：

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
If the minus sign was part of the input sequence, the numeric value calculated from the sequence of digits is negated as if by unary minus in the result type, which applies unsigned integer wraparound rules.
如果負號是輸入序列的一部分，則根據數字序列計算的數值在結果型別中按一元負號取反，應用無符號整數迴繞規則。
The functions sets the pointer pointed to by `str_end` to point to the character past the last character interpreted. If `str_end` is a null pointer, it is ignored.
這些函式將 str_end 指向的指標設定為指向最後一個被解釋字元之後的字元。如果 str_end 為空指標，則忽略它。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be interpreted  |

| str_end  |   | -  |   | pointer to a pointer to character, might be set to a position past the last character interpreted  |

| base  |   | -  |   | *base* of the interpreted integer value  |

### Return value

Integer value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, range error occurs (errno is set to `ERANGE`) and ULONG_MAX or ULLONG_MAX is returned. If no conversion can be performed, `0` is returned.
成功時傳回與 str 內容對應的整數值。如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤（ errno 被設定為 ERANGE ）並傳回 ULONG_MAX 或 ULLONG_MAX 。如果無法執行轉換，則傳回 0 。

### Example

Run this code

```c
#include <errno.h> #include <stdio.h> #include <stdlib.h> int main(void) {  const char* p = "10 200000000000000000000000000000 30 -40 - 42";  printf("Parsing '%s':\n", p);  char* end = NULL;  for (unsigned long i = strtoul(p, &end, 10);  p != end;  i = strtoul(p, &end, 10))  {  printf("'%.*s' -> ", (int)(end - p), p);  p = end;  if (errno == ERANGE)  {  errno = 0;  printf("range error, got ");  }  printf("%lu\n", i);  }  printf("After the loop p points to '%s'\n", p); }
```

Output:

```c
Parsing '10 200000000000000000000000000000 30 -40 - 42': '10' -> 10 ' 200000000000000000000000000000' -> range error, got 18446744073709551615 ' 30' -> 30 ' -40' -> 18446744073709551576 After the loop p points to ' - 42'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.1.7 The strtol, strtoll, strtoul, and strtoull functions (p: TBD)
7.24.1.7 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：待定）
7.24.1.7 strtol 、 strtoll 、 strtoul 和 strtoull 函式（頁碼：待定）

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

- 4.10.1.6 The strtoul function
4.10.1.6 strtoul 函式
4.10.1.6 strtoul 函式

### See also

wcstoulwcstoull
(C95)(C99)
|   | converts a wide string to an unsigned integer value
(function)   |

atoiatolatoll
(C99)
|   | converts a byte string to an integer value
(function)   |

strtolstrtoll
(C99)
|   | converts a byte string to an integer value
(function)   |

C++ documentation for strtoul

---
來源頁路徑：`en.cppreference.com/c/string/byte/strtoul.html`

# wcstol, wcstoll

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
long wcstol( const wchar_t * str, wchar_t ** str_end, int base );
```
|   |   |   | (since C95)
(until C99) |

```c
long wcstol( const wchar_t * restrict str, wchar_t ** restrict str_end,  int base );
```
|   |   |   | (since C99) |

```c
long long wcstoll( const wchar_t * restrict str, wchar_t ** restrict str_end,  int base );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Interprets an integer value in a wide string pointed to by `str`.
解釋由 str 指向的寬字串中的整數值。
Discards any whitespace characters (as identified by calling iswspace) until the first non-whitespace character is found, then takes as many characters as possible to form a valid *base-n* (where n=`base`) integer number representation and converts them to an integer value. The valid integer value consists of the following parts:
丟棄任何空白字元（透過呼叫 iswspace 識別），直到找到第一個非空白字元，然後取儘可能多的字元以構成有效的 base-n（其中 n= base ）整數表示，並將其轉換為整數值。有效的整數值由以下部分組成：

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
The functions sets the pointer pointed to by `str_end` to point to the wide character past the last character interpreted. If `str_end` is a null pointer, it is ignored.
這些函式將 str_end 指向的指標設定為指向最後一個被解釋字元之後的寬字元。如果 str_end 為空指標，則忽略它。

### Parameters

| str  |   | -  |   | pointer to the null-terminated wide string to be interpreted  |

| str_end  |   | -  |   | pointer to a pointer to wide character  |

| base  |   | -  |   | *base* of the interpreted integer value  |

### Return value

Integer value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, range error occurs and LONG_MAX, LONG_MIN, LLONG_MAX or LLONG_MIN is returned. If no conversion can be performed, `0` is returned.
成功時傳回與 str 內容對應的整數值。如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤並傳回 LONG_MAX 、 LONG_MIN 、 LLONG_MAX 或 LLONG_MIN 。如果無法執行轉換，則傳回 0 。

### Example

Run this code

```c
#include <stdio.h> #include <errno.h> #include <wchar.h> int main(void) {  const wchar_t *p = L"10 200000000000000000000000000000 30 -40";  printf("Parsing L'%ls':\n", p);  wchar_t *end;  for (long i = wcstol(p, &end, 10);  p != end;  i = wcstol(p, &end, 10))  {  printf("'%.*ls' -> ", (int)(end-p), p);  p = end;  if (errno == ERANGE){  printf("range error, got ");  errno = 0;  }  printf("%ld\n", i);  } }
```

Output:

```c
Parsing L'10 200000000000000000000000000000 30 -40': '10' -> 10 ' 200000000000000000000000000000' -> range error, got 9223372036854775807 ' 30' -> 30 ' -40' -> -40
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.1.2 The wcstol, wcstoll, wcstoul, and wcstoull functions (p: 429-430)
7.29.4.1.2 wcstol 、 wcstoll 、 wcstoul 和 wcstoull 函式（頁碼：429-430）
7.29.4.1.2 wcstol 、 wcstoll 、 wcstoul 和 wcstoull 函式（頁碼：429-430）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.1.2 The wcstol, wcstoll, wcstoul, and wcstoull functions (p: 375-376)
7.24.4.1.2 wcstol 、 wcstoll 、 wcstoul 和 wcstoull 函式（頁碼：375-376）
7.24.4.1.2 wcstol 、 wcstoll 、 wcstoul 和 wcstoull 函式（頁碼：375-376）

### See also

strtolstrtoll
(C99)
|   | converts a byte string to an integer value
(function)   |

wcstoulwcstoull
(C95)(C99)
|   | converts a wide string to an unsigned integer value
(function)   |

C++ documentation for wcstol, wcstoll

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcstol.html`

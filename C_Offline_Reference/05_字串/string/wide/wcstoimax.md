# wcstoimax, wcstoumax

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<inttypes.h>`
|   |  |   |  |

```c
intmax_t wcstoimax( const wchar_t *restrict nptr,   wchar_t **restrict endptr, int base );
```
|   |   |   |  (since C99)  |

```c
uintmax_t wcstoumax( const wchar_t *restrict nptr,  wchar_t **restrict endptr, int base );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Interprets an unsigned integer value in a wide string pointed to by `nptr`.
解釋由 nptr 指向的寬字串中的無符號整數值。
Discards any whitespace characters (as identified by calling iswspace) until the first non-whitespace character is found, then takes as many characters as possible to form a valid *base-n* (where n=`base`) unsigned integer number representation and converts them to an integer value. The valid unsigned integer value consists of the following parts:
丟棄任何空白字元（透過呼叫 iswspace 識別），直到找到第一個非空白字元，然後取儘可能多的字元以構成有效的 base-n（其中 n= base ）無符號整數表示，並將其轉換為整數值。有效的無符號整數值由以下部分組成：

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
The functions sets the pointer pointed to by `endptr` to point to the wide character past the last character interpreted. If `endptr` is a null pointer, it is ignored.
這些函式將 endptr 指向的指標設定為指向最後一個被解釋字元之後的寬字元。如果 endptr 為空指標，則忽略它。

### Parameters

| nptr  |   | -  |   | pointer to the null-terminated wide string to be interpreted  |

| endptr  |   | -  |   | pointer to a pointer to a wide character.  |

| base  |   | -  |   | *base* of the interpreted integer value  |

### Return value

Integer value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, range error occurs and INTMAX_MAX, INTMAX_MIN, UINTMAX_MAX, or `0` is returned, as appropriate. If no conversion can be performed, `0` is returned.
成功時傳回與 str 內容對應的整數值。如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤並根據情況傳回 INTMAX_MAX 、 INTMAX_MIN 、 UINTMAX_MAX 或 0 。如果無法執行轉換，則傳回 0 。

### Example

Run this code

```c
#include <errno.h> #include <inttypes.h> #include <stdio.h> #include <string.h> #include <wchar.h> int main(void) {  wchar_t* endptr;  wprintf(L"%ld\n", wcstoimax(L" -123junk", &endptr, 10)); /* base 10 */  wprintf(L"%ld\n", wcstoimax(L"11111111", &endptr, 2)); /* base 2 */  wprintf(L"%ld\n", wcstoimax(L"XyZ", &endptr, 36)); /* base 36 */  wprintf(L"%ld\n", wcstoimax(L"010", &endptr, 0)); /* octal auto-detection */  wprintf(L"%ld\n", wcstoimax(L"10", &endptr, 0)); /* decimal auto-detection */  wprintf(L"%ld\n", wcstoimax(L"0x10", &endptr, 0)); /* hexadecimal auto-detection */  /* range error */  /* LONG_MAX+1 --> LONG_MAX */  errno = 0;  wprintf(L"%ld\n", wcstoimax(L"9223372036854775808", &endptr, 10));  wprintf(L"%s\n", strerror(errno)); }
```

Output:

```c
-123 255 44027 8 10 16 9223372036854775807 Numerical result out of range
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.8.2.4 The wcstoimax and wcstoumax functions (p: 220)
7.8.2.4 wcstoimax 和 wcstoumax 函式（頁碼：220）
7.8.2.4 wcstoimax 和 wcstoumax 函式（頁碼：220）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.8.2.4 The wcstoimax and wcstoumax functions (p: 201)
7.8.2.4 wcstoimax 和 wcstoumax 函式（頁碼：201）
7.8.2.4 wcstoimax 和 wcstoumax 函式（頁碼：201）

### See also

strtoimaxstrtoumax
(C99)(C99)
|   | converts a byte string to intmax_t or uintmax_t
(function)   |

wcstolwcstoll
(C95)(C99)
|   | converts a wide string to an integer value
(function)   |

wcstoulwcstoull
(C95)(C99)
|   | converts a wide string to an unsigned integer value
(function)   |

C++ documentation for wcstoimax, wcstoumax

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcstoimax.html`

# atoi, atol, atoll

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int atoi ( const char* str );
```
|   |  (1)  |   |   |

```c
long atol ( const char* str );
```
|   |  (2)  |   |   |

```c
long long atoll( const char* str );
```
|   |  (3)  |   |  (since C99)  |

|  |  |  |  |

Interprets an integer value in a byte string pointed to by `str`. The implied radix is always 10.
解釋由 str 指向的位元組字串中的整數值。隱含的基數為 10 。
Discards any whitespace characters until the first non-whitespace character is found, then takes as many characters as possible to form a valid integer number representation and converts them to an integer value. The valid integer value consists of the following parts:
丟棄任何空白字元，直到找到第一個非空白字元，然後取儘可能多的字元以構成有效的整數表示，並將其轉換為整數值。有效的整數值由以下部分組成：

- (optional) plus or minus sign
（可選）正號或負號

- numeric digits

If the value of the result cannot be represented, i.e. the converted value falls out of range of the corresponding return type, the behavior is undefined.
如果結果的值無法表示，即轉換後的值超出相應傳回型別的範圍，則行為未定義。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be interpreted  |

### Return value

Integer value corresponding to the contents of `str` on success.
成功時傳回與 str 內容對應的整數值。
If no conversion can be performed, `0` is returned.
如果無法執行轉換，則傳回 0 。

### Notes

The name stands for “ASCII to integer”.
該名稱代表 "ASCII to integer"。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  printf("%i\n", atoi(" -123junk"));  printf("%i\n", atoi(" +321dust"));  printf("%i\n", atoi("0"));  printf("%i\n", atoi("0042")); // treated as a decimal number with leading zeros  printf("%i\n", atoi("0x2A")); // only leading zero is converted discarding "x2A"  printf("%i\n", atoi("junk")); // no conversion can be performed  printf("%i\n", atoi("2147483648")); // UB: out of range of int }
```

Possible output:
可能的輸出：

```c
-123 321 0 42 0 0 -2147483648
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.1.2 The atoi, atol, and atoll functions (p: TBD)
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：待定）
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.1.2 The atoi, atol, and atoll functions (p: 249)
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：249）
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：249）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.1.2 The atoi, atol, and atoll functions (p: 341)
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：341）
7.22.1.2 atoi 、 atol 和 atoll 函式（頁碼：341）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.1.2 The atoi, atol, and atoll functions (p: 307)
7.20.1.2 atoi 、 atol 和 atoll 函式（頁碼：307）
7.20.1.2 atoi 、 atol 和 atoll 函式（頁碼：307）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.1.2 The atoi function
4.10.1.2 atoi 函式
4.10.1.2 atoi 函式

- 4.10.1.3 The atol function
4.10.1.3 atol 函式
4.10.1.3 atol 函式

### See also

strtolstrtoll
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

C++ documentation for atoi, atol, atoll

---
來源頁路徑：`en.cppreference.com/c/string/byte/atoi.html`

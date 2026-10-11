# strxfrm

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
size_t strxfrm( char *dest, const char *src, size_t count );
```
|   |   |   |  (until C99)  |

```c
size_t strxfrm( char *restrict dest, const char *restrict src, size_t count );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Transforms the null-terminated byte string pointed to by `src` into the implementation-defined form such that comparing two transformed strings with strcmp gives the same result as comparing the original strings with strcoll, in the current C locale.
將 src 指向的空終止位元組字串轉換為實現定義的形式，使得在目前 C 本地化環境中，用 strcmp 比較兩個轉換後的字串與用 strcoll 比較原始字串得到相同的結果。
The first `count` characters of the transformed string are written to destination, including the terminating null character, and the length of the full transformed string is returned, excluding the terminating null character.
轉換後的字串的前 count 個字元（包括終止空字元）被寫入 destination，並傳回完整轉換後字串的長度（不包括終止空字元）。
The behavior is undefined if the `dest` array is not large enough. The behavior is undefined if `dest` and `src` overlap.
如果 dest 陣列不夠大，則行為未定義。如果 dest 和 src 重疊，則行為未定義。
If `count` is `0`, then `dest` is allowed to be a null pointer.
如果 count 為 0 ，則 dest 允許為空指標。

### Notes

The correct length of the buffer that can receive the entire transformed string is `1+strxfrm(NULL, src, 0)`
可以接收整個轉換後字串的緩衝區的正確長度為 1 + strxfrm ( NULL , src , 0 )
This function is used when making multiple locale-dependent comparisons using the same string or set of strings, because it is more efficient to use `strxfrm` to transform all the strings just once, and subsequently compare the transformed strings with strcmp.
當使用相同的字串或字串集合進行多次依賴本地化環境的比較時，會使用此函式，因為使用 strxfrm 僅轉換一次所有字串，然後使用 strcmp 比較轉換後的字串，效率更高。

### Parameters

| dest  |   | -  |   | pointer to the first element of the array where the transformed string will be written  |

| src  |   | -  |   | pointer to the first character of a null-terminated byte string to transform  |

| count  |   | -  |   | maximum number of characters to be written  |

### Return value

The length of the transformed string, not including the terminating null-character.
轉換後字串的長度，不包括終止空字元。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> #include <locale.h> int main(void) {  setlocale(LC_COLLATE, "cs_CZ.iso88592");  const char *in1 = "hrnec";  char out1[1+strxfrm(NULL, in1, 0)];  strxfrm(out1, in1, sizeof out1);  const char *in2 = "chrt";  char out2[1+strxfrm(NULL, in2, 0)];  strxfrm(out2, in2, sizeof out2);  printf("In the Czech locale: ");  if(strcmp(out1, out2) < 0)  printf("%s before %s\n",in1, in2);  else  printf("%s before %s\n",in2, in1);  printf("In lexicographical comparison: ");  if(strcmp(in1, in2)<0)  printf("%s before %s\n",in1, in2);  else  printf("%s before %s\n",in2, in1); }
```

Possible output:
可能的輸出：

```c
In the Czech locale: hrnec before chrt In lexicographical comparison: chrt before hrnec
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.4.5 The strxfrm function (p: 267)
7.24.4.5 strxfrm 函式（頁碼：267）
7.24.4.5 strxfrm 函式（頁碼：267）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.4.5 The strxfrm function (p: 366-367)
7.24.4.5 strxfrm 函式（頁碼：366-367）
7.24.4.5 strxfrm 函式（頁碼：366-367）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.4.5 The strxfrm function (p: 329-330)
7.21.4.5 strxfrm 函式（頁碼：329-330）
7.21.4.5 strxfrm 函式（頁碼：329-330）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.4.5 The strxfrm function
4.11.4.5 strxfrm 函式
4.11.4.5 strxfrm 函式

### See also

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

strcmp
|   | compares two strings
(function)   |

wcsxfrm
(C95)
|   | transform a wide string so that wcscmp would produce the same result as wcscoll
(function)   |

C++ documentation for strxfrm

---
來源頁路徑：`en.cppreference.com/c/string/byte/strxfrm.html`

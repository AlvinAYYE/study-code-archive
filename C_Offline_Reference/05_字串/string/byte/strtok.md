# strtok, strtok_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strtok( char* str, const char* delim );
```
|   |  (1) |   | (until C99) |

```c
char* strtok( char* restrict str, const char* restrict delim );
```
|   |   |   | (since C99) |

```c
char* strtok_s( char* restrict str, rsize_t* restrict strmax,  const char* restrict delim, char** restrict ptr );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

Tokenizes a null-terminated byte string.
將以空字元結尾的位元組字串切分成多個詞元。

1) A sequence of calls to `strtok` breaks the string pointed to by `str` into a sequence of tokens, each of which is delimited by a character from the string pointed to by `delim`. Each call in the sequence has a *search target ﻿*:
- If `str` is non-null, the call is the *first call* in the sequence. The search target is null-terminated byte string pointed to by `str`.
若 str 不為空指標，表示這是本次切分序列的第一次呼叫。str 指向的以空字元結尾位元組字串會作為搜尋目標。

- If `str` is null, the call is one of the *subsequent calls* in the sequence. The search target is determined by the previous call in the sequence.
若 str 為空指標，表示這是同一切分序列的後續呼叫；搜尋目標由前一次呼叫決定。

Each call in the sequence searches the search target for the first character that is **not** contained in the *separator string* pointed to by `delim`, the separator string can be different from call to call.
- If no such character is found, then there are no tokens in the search target. The search target for the next call in the sequence is unchanged.
如果未找到這樣的字元，則搜尋目標中不存在標記。序列中下一次呼叫的搜尋目標保持不變。[ 1 ]

- If such a character is found, it is the start of the current token. `strtok` then searches from there for the first character that is contained in the separator string.
- If no such character is found, the current token extends to the end of search target. The search target for the next call in the sequence is an empty string.
如果未找到這樣的字元，則目前標記延伸到搜尋目標的末尾。序列中下一次呼叫的搜尋目標為空字串。[ 2 ]

- If such a character is found, it is overwritten by a null character, which terminates the current token. The search target for the next call in the sequence starts from the following character.
如果找到這樣的字元，它會被空字元覆蓋，從而終止目前標記。序列中下一次呼叫的搜尋目標從下一個字元開始。
如果找到這樣的字元，它就是目前標記的起點。strtok 隨後從該處搜尋第一個包含在分隔符字串中的字元。如果未找到這樣的字元，則目前標記延伸到搜尋目標的末尾，序列中下一次呼叫的搜尋目標為空字串。[ 2 ] 如果找到這樣的字元，它會被空字元覆蓋，從而終止目前標記，序列中下一次呼叫的搜尋目標從下一個字元開始。

If `str` or `delim` is not a pointer to a null-terminated byte string, the behavior is undefined.

2) Same as (1), except for the following differences:
- In each call, writes the number of characters left to see in `str` into `*strmax` and writes the tokenizer's internal state into `*ptr`.
在每次呼叫中，將 str 中剩餘待檢視的字元數寫入 * strmax，並將分詞器的內部狀態寫入 * ptr 。

- Subsequent calls in the sequence must pass `strmax` and `ptr` with the values stored by the previous call.
序列中的後續呼叫必須將 strmax 和 ptr 作為前一次呼叫所儲存的值傳入。

- The following errors are detected at runtime and call the currently installed constraint handler function, without storing anything in the object pointed to by `ptr`:
- `strmax`, `delim`, or `ptr` is a null pointer.
strmax 、delim 或 ptr 是空指標。

- `*ptr` is a null pointer for a subsequent call in the sequence.
* ptr 對於序列中的後續呼叫是空指標。

- `*strmax` is greater than `RSIZE_MAX`.
* strmax 大於 RSIZE_MAX。

- The end of the token found does not occur within the first `*s1max` characters of the search target.
找到的標記的結尾未出現在搜尋目標的前 * s1max 個字元內。
以下錯誤在執行時被檢測到，並呼叫目前安裝的約束處理函式，而不會向 ptr 指向的物件儲存任何內容：strmax 、delim 或 ptr 是空指標。* ptr 對於序列中的後續呼叫是空指標。* strmax 大於 RSIZE_MAX。找到的標記的結尾未出現在搜尋目標的前 * s1max 個字元內。

If both `str` points to a character array which lacks the null character and `strmax` points to a value which is greater than the size of that character array, the behavior is undefined.

As with all bounds-checked functions, `strtok_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.

- ↑ A token may still be formed in a subsequent call with a different separator string.
↑ 使用不同的分隔符字串時，後續呼叫仍可能形成標記。

- ↑ No more tokens can be formed in subsequent calls.
↑ 後續呼叫無法再形成更多標記。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to tokenize  |

| delim  |   | -  |   | pointer to the null-terminated byte string identifying delimiters  |

| strmax  |   | -  |   | pointer to an object which initially holds the size of `str`: `strtok_s` stores the number of characters that remain to be examined  |

| ptr  |   | -  |   | pointer to an object of type `char*`, which is used by `strtok_s` to store its internal state  |

### Return value

1) Returns a pointer to the first character of the next token, or a null pointer if there is no token.

2) Returns a pointer to the first character of the next token, or a null pointer if there is no token or there is a runtime-constraint violation.

### Note

This function is destructive: it writes the `'\0'` characters in the elements of the string `str`. In particular, a string literal cannot be used as the first argument of `strtok`.
此函式會直接修改 `str` 指向的字串，把分隔符所在的位置改成 `\0`。因此，不可把字串常值傳給 `strtok`；應傳入可修改的字元陣列。
Each call to `strtok` modifies a static variable: is not thread safe.
每次呼叫 `strtok` 都會使用並修改內部的靜態狀態，因此它不是執行緒安全的；多個字串交錯處理時也可能互相干擾。
Unlike most other tokenizers, the delimiters in `strtok` can be different for each subsequent token, and can even depend on the contents of the previous tokens.
每次呼叫 `strtok` 都可以傳入不同的分隔字元集合，因此後續 token 的分隔方式可以改變，也可以依先前讀到的內容決定。
The `strtok_s` function differs from the POSIX `strtok_r` function by guarding against storing outside of the string being tokenized, and by checking runtime constraints. The Microsoft CRT `strtok_s` signature matches this POSIX `strtok_r` definition, not the C11 `strtok_s`.
strtok_s 函式與 POSIX strtok_r 函式的不同之處在於，它防止寫入被分詞字串之外的區域，並檢查執行時約束。Microsoft CRT 的 strtok_s 簽名與此 POSIX strtok_r 定義一致，而非 C11 的 strtok_s。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <string.h> int main(void) {  char input[] = "A bird came down the walk";  printf("Parsing the input string '%s'\n", input);  char* token = strtok(input, " ");  while (token)  {  puts(token);  token = strtok(NULL, " ");  }    printf("Contents of the input string now: '");  for (size_t n = 0; n < sizeof input; ++n)  input[n] ? putchar(input[n]) : fputs("\\0", stdout);  puts("'");   #ifdef __STDC_LIB_EXT1__  char str[] = "A bird came down the walk";  rsize_t strmax = sizeof str;  const char* delim = " ";  char* next_token;  printf("Parsing the input string '%s'\n", str);  token = strtok_s(str, &strmax, delim, &next_token);  while (token)  {  puts(token);  token = strtok_s(NULL, &strmax, delim, &next_token);  }    printf("Contents of the input string now: '");  for (size_t n = 0; n < sizeof str; ++n)  str[n] ? putchar(str[n]) : fputs("\\0", stdout);  puts("'"); #endif }
```

Possible output:
可能的輸出：

```c
Parsing the input string 'A bird came down the walk' A bird came down the walk Contents of the input string now: 'A\0bird\0came\0down\0the\0walk\0' Parsing the input string 'A bird came down the walk' A bird came down the walk Contents of the input string now: 'A\0bird\0came\0down\0the\0walk\0'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.8 The strtok function (p: TBD)
7.24.5.8 strtok 函式（p: TBD）
7.24.5.8 strtok 函式（p: TBD）

- K.3.7.3.1 The strtok_s function (p: TBD)
K.3.7.3.1 strtok_s 函式（p: TBD）
K.3.7.3.1 strtok_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.8 The strtok function (p: TBD)
7.24.5.8 strtok 函式（p: TBD）
7.24.5.8 strtok 函式（p: TBD）

- K.3.7.3.1 The strtok_s function (p: TBD)
K.3.7.3.1 strtok_s 函式（p: TBD）
K.3.7.3.1 strtok_s 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.8 The strtok function (p: 369-370)
7.24.5.8 strtok 函式（p: 369-370）
7.24.5.8 strtok 函式（p: 369-370）

- K.3.7.3.1 The strtok_s function (p: 620-621)
K.3.7.3.1 strtok_s 函式（p: 620-621）
K.3.7.3.1 strtok_s 函式（p: 620-621）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.8 The strtok function (p: 332-333)
7.21.5.8 strtok 函式（p: 332-333）
7.21.5.8 strtok 函式（p: 332-333）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.8 The strtok function
4.11.5.8 strtok 函式
4.11.5.8 strtok 函式

### See also

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

strcspn
|   | returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)   |

strspn
|   | returns the length of the maximum initial segment that consists
of only the characters found in another byte string
(function)   |

wcstokwcstok_s
(C95)(C11)
|   | finds the next token in a wide string
(function)   |

C++ documentation for strtok

---
來源頁路徑：`en.cppreference.com/c/string/byte/strtok.html`

# wcstok, wcstok_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wcstok( wchar_t* str, const wchar_t* delim, wchar_t** ptr );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
wchar_t* wcstok( wchar_t* restrict str, const wchar_t* restrict delim,  wchar_t** restrict ptr );
```
|   |   |   | (since C99) |

```c
wchar_t* wcstok_s( wchar_t* restrict str, rsize_t* restrict strmax,  const wchar_t* restrict delim, wchar_t** restrict ptr);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Finds the next token in a null-terminated wide string pointed to by `str`. The separator characters are identified by null-terminated wide string pointed to by `delim`.

This function is designed to be called multiples times to obtain successive tokens from the same string.

- If `str != NULL`, the call is treated as the first call to `wcstok` for this particular wide string. The function searches for the first wide character which is *not* contained in `delim`.
如果 str != NULL ，則該呼叫被視為對此特定寬字串的第一次 wcstok 呼叫。函式搜尋第一個不包含在 delim 中的寬字元。

- If no such wide character was found, there are no tokens in `str` at all, and the function returns a null pointer.
如果未找到這樣的寬字元，則 str 中根本沒有標記，函式傳回空指標。

- If such wide character was found, it is the *beginning of the token*. The function then searches from that point on for the first wide character that *is* contained in `delim`.
如果找到了這樣的寬字元，它就是標記的開始。然後函式從該點開始搜尋第一個包含在 delim 中的寬字元。

- If no such wide character was found, `str` has only one token, and future calls to `wcstok` will return a null pointer
如果未找到這樣的寬字元，則 str 只有一個標記，後續對 wcstok 的呼叫將傳回空指標

- If such wide character was found, it is *replaced* by the null wide character `L'\0'` and the parser state (typically a pointer to the following wide character) is stored in the user-provided location `*ptr`.
如果找到了這樣的寬字元，它將被空寬字元 L '\0' 替換，解析器狀態（通常是指向下一個寬字元的指標）儲存在使用者提供的位置 * ptr 中。
如果未找到這樣的寬字元，則 str 只有一個標記，後續對 wcstok 的呼叫將傳回空指標。如果找到了這樣的寬字元，它將被空寬字元 L '\0' 替換，解析器狀態（通常是指向下一個寬字元的指標）儲存在使用者提供的位置 * ptr 中。

- The function then returns the pointer to the beginning of the token
然後函式傳回指向標記開始處的指標
如果未找到這樣的寬字元，則 str 中根本沒有標記，函式傳回空指標。如果找到了這樣的寬字元，它就是標記的開始。然後函式從該點開始搜尋第一個包含在 delim 中的寬字元。如果未找到這樣的寬字元，則 str 只有一個標記，後續對 wcstok 的呼叫將傳回空指標。如果找到了這樣的寬字元，它將被空寬字元 L '\0' 替換，解析器狀態（通常是指向下一個寬字元的指標）儲存在使用者提供的位置 * ptr 中。然後函式傳回指向標記開始處的指標

- If `str == NULL`, the call is treated as a subsequent call to `wcstok`: the function continues from where it left in the previous invocation with the same `*ptr`. The behavior is the same as if the pointer to the wide character that follows the last detected token is passed as `str`.
如果 str == NULL ，則該呼叫被視為後續的 wcstok 呼叫：函式從上次呼叫停止的位置繼續，使用相同的 * ptr 。其行為等同於將指向最後一個檢測到的標記之後的寬字元的指標作為 str 傳遞。
如果 str != NULL ，則該呼叫被視為對此特定寬字串的第一次 wcstok 呼叫。函式搜尋第一個不包含在 delim 中的寬字元。如果未找到這樣的寬字元，則 str 中根本沒有標記，函式傳回空指標。如果找到了這樣的寬字元，它就是標記的開始。然後函式從該點開始搜尋第一個包含在 delim 中的寬字元。如果未找到這樣的寬字元，則 str 只有一個標記，後續對 wcstok 的呼叫將傳回空指標。如果找到了這樣的寬字元，它將被空寬字元 L '\0' 替換，解析器狀態（通常是指向下一個寬字元的指標）儲存在使用者提供的位置 * ptr 中。然後函式傳回指向標記開始處的指標。如果 str == NULL ，則該呼叫被視為後續的 wcstok 呼叫：函式從上次呼叫停止的位置繼續，使用相同的 * ptr 。其行為等同於將指向最後一個檢測到的標記之後的寬字元的指標作為 str 傳遞。

2) Same as (1), except that on every step, writes the number of characters left to see in `str` into `*strmax`. Repeat calls (with null `str`) must pass both `strmax` and `ptr` with the values stored by the previous call. Also, the following errors are detected at runtime and call the currently installed constraint handler function, without storing anything in the object pointed to by `ptr`
- `strmax`, `delim`, or `ptr` is a null pointer
strmax 、 delim 或 ptr 為空指標

- on a non-initial call (with null `str`), `*ptr` is a null pointer
在非初始呼叫（ str 為 null ）時， * ptr 為空指標

- on the first call, `*strmax` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
在第一次呼叫時， * strmax 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- search for the end of a token reaches the end of the source string (as measured by the initial value of `*strmax`) without encountering the null terminator
搜尋標記的結尾到達源字串的末尾（由 * strmax 的初始值度量）而未遇到空終止符
As all bounds-checked functions, `wcstok_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.

### Parameters

| str  |   | -  |   | pointer to the null-terminated wide string to tokenize  |

| delim  |   | -  |   | pointer to the null-terminated wide string identifying delimiters  |

| ptr  |   | -  |   | pointer to an object of type `wchar_t*`, which is used by both `wcstok` and `wcstok_s` to store the internal state of the parser  |

| strmax  |   | -  |   | pointer to an object which initially holds the size of `str`: wcstok_s stores the number of characters that remain to be examined  |

### Return value

Returns pointer to the beginning of the next token or null pointer if there are no more tokens.
傳回指向下一個標記開始處的指標，如果沒有更多標記則傳回空指標。

### Note

This function is destructive: it writes the `L'\0'` characters in the elements of the string `str`. In particular, a wide string literal cannot be used as the first argument of `wcstok`.
此函式具有破壞性：它在字串 str 的元素中寫入 L '\0' 字元。特別是，寬字串字面量不能用作 wcstok 的第一個參數。
Unlike strtok, `wcstok` does not update static storage: it stores the parser state in the user-provided location.
與 strtok 不同， wcstok 不更新靜態儲存：它將解析器狀態儲存在使用者提供的位置。
Unlike most other tokenizers, the delimiters in `wcstok` can be different for each subsequent token, and can even depend on the contents of the previous tokens.
與大多數其他標記器不同， wcstok 中的分隔符對於每個後續標記可以不同，甚至可以依賴於先前標記的內容。
The implementation of `wcstok_s` in the Windows CRT is incompatible with the C standard, it is merely an alias for `wcstok`.
Windows CRT 中的 wcstok_s 實現與 C 標準不相容，它僅僅是 wcstok 的別名。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h> int main(void) {  wchar_t input[] = L"A bird came down the walk";  printf("Parsing the input string '%ls'\n", input);  wchar_t* buffer;  wchar_t* token = wcstok(input, L" ", &buffer);  while (token)  {  printf("%ls\n", token);  token = wcstok(NULL, L" ", &buffer);  }  printf("Contents of the input string now: '");  for (size_t n = 0; n < sizeof input / sizeof *input; ++n)  input[n] ? printf("%lc", input[n]) : printf("\\0");  puts("'"); }
```

Output:

```c
Parsing the input string 'A bird came down the walk' A bird came down the walk Contents of the input string now: 'A\0bird\0came\0down\0the\0walk\0'
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.5.7 The wcstok function (p: 437-438)
7.29.4.5.7 wcstok 函式（頁碼：437-438）
7.29.4.5.7 wcstok 函式（頁碼：437-438）

- K.3.9.2.3.1 The wcstok_s function (p: 645-646)
K.3.9.2.3.1 wcstok_s 函式（頁碼：645-646）
K.3.9.2.3.1 wcstok_s 函式（頁碼：645-646）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.5.7 The wcstok function (p: 383-384)
7.24.4.5.7 wcstok 函式（頁碼：383-384）
7.24.4.5.7 wcstok 函式（頁碼：383-384）

### See also

strtokstrtok_s
(C11)
|   | finds the next token in a byte string
(function)   |

C++ documentation for wcstok

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcstok.html`

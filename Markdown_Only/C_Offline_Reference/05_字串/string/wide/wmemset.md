# wmemset

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wmemset( wchar_t* dest, wchar_t ch, size_t count );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Copies the wide character `ch` into each of the first `count` wide characters of the wide character array (or integer array of compatible type) pointed to by `dest`.
將寬字元 ch 複製到由 dest 指向的寬字元陣列（或相容型別的整數陣列）的前 count 個寬字元中。
If overflow occurs, the behavior is undefined.
如果發生溢位，則行為未定義。
If `count` is zero, the function does nothing.
如果 count 為零，則函式不執行任何操作。

### Parameters

| dest  |   | -  |   | pointer to the wide character array to fill  |

| ch  |   | -  |   | fill wide character  |

| count  |   | -  |   | number of wide characters to fill  |

### Return value

Returns a copy of `dest`
傳回 dest 的副本

### Notes

This function is not locale-sensitive and pays no attention to the values of the `wchar_t` objects it writes: nulls as well as invalid wide characters are written too.
此函式不區分本地化環境，也不關注它寫入的 wchar_t 物件的值：空值以及無效的寬字元也會被寫入。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> int main(void) {  wchar_t ar[10] = L"1234567890"; // no trailing null in the array  wmemset(ar, L'\U0001f34c', 5); // replaces [12345] with the 🍌 bananas  wmemset(ar + 5, L'蕉', 5); // replaces [67890] with the 蕉 bananas  setlocale(LC_ALL, "en_US.utf8");  for (size_t n = 0; n < sizeof ar / sizeof *ar; ++n)  putwchar(ar[n]);  putwchar(L'\n'); }
```

Output:

```c
🍌🍌🍌🍌🍌蕉蕉蕉蕉蕉
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.6.2 The wmemset function (p: TBD)
7.29.4.6.2 wmemset 函式（頁碼：待定）
7.29.4.6.2 wmemset 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.6.2 The wmemset function (p: TBD)
7.29.4.6.2 wmemset 函式（頁碼：待定）
7.29.4.6.2 wmemset 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.6.2 The wmemset function (p: 439)
7.29.4.6.2 wmemset 函式（頁碼：439）
7.29.4.6.2 wmemset 函式（頁碼：439）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.6.2 The wmemset function (p: 385)
7.24.4.6.2 wmemset 函式（頁碼：385）
7.24.4.6.2 wmemset 函式（頁碼：385）

### See also

memsetmemset_explicitmemset_s
(C23)(C11)
|   | fills a buffer with a character
(function)   |

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

C++ documentation for wmemset

---
來源頁路徑：`en.cppreference.com/c/string/wide/wmemset.html`

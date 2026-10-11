# c8rtomb

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t c8rtomb( char* restrict s, char8_t c8, mbstate_t* restrict ps );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Converts a single code point from UTF-8 to a narrow multibyte character representation.
將單個碼點從 UTF-8 轉換為窄多位元組字元表示。
If `s` is not a null pointer and `c8` is the last code unit in a valid UTF-8 encoding of a code point, the function determines the number of bytes necessary to store the multibyte character representation of that code point (including any shift sequences, and taking into account the current multibyte conversion state `*ps`), and stores the multibyte character representation in the character array whose first element is pointed to by `s`, updating `*ps` as necessary. At most MB_CUR_MAX bytes can be written by this function.
如果 s 不是空指標，且 c8 是某個碼點的有效 UTF-8 編碼中的最後一個碼元，則函式確定儲存該碼點的多位元組字元表示所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps ），將該多位元組字元表示儲存到首元素由 s 指向的字元陣列中，並按需更新 * ps 。此函式最多可寫入 MB_CUR_MAX 個位元組。
If `c8` is not the final UTF-8 code unit in a representation of a code point, the function does not write to the array pointed to by `s`, only `*ps` is updated.
如果 c8 不是碼點表示中的最後一個 UTF-8 碼元，則函式不寫入 s 指向的陣列，僅更新 * ps 。
If `s` is a null pointer, the call is equivalent to `c8rtomb(buf, u8'\0', ps)` for some internal buffer `buf`.
如果 s 是空指標，則該呼叫等價於對某個內部緩衝區 buf 執行 c8rtomb ( buf , u8 '\0' , ps ) 。
If `c8` is the null character `u8'\0'`, a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter `*ps` is updated to represent the initial shift state.
如果 c8 是空字元 u8 '\0' ，則儲存一個空位元組，其前面帶有恢復初始移位狀態所必需的任何移位序列，且轉換狀態參數 * ps 被更新為表示初始移位狀態。
The multibyte encoding used by this function is specified by the currently active C locale.
此函式使用的多位元組編碼由目前活動的 C 區域設定指定。

### Parameters

| s  |   | -  |   | pointer to narrow character array where the multibyte character will be stored  |

| c8  |   | -  |   | the UTF-8 code unit to convert  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

The number of bytes stored in the array object (including any shift sequences). This may be zero when `c8` is not the final code unit in the UTF-8 representation of a code point.
儲存在陣列物件中的位元組數（包括任何移位序列）。當 c8 不是碼點的 UTF-8 表示中的最後一個碼元時，該值可能為零。
If `c8` is invalid (does not contribute to a sequence of `char8_t` corresponding to a valid multibyte character), the value of the macro EILSEQ is stored in errno, `(size_t)-1` is returned, and the conversion state is unspecified.
如果 c8 無效（不構成對應於有效多位元組字元的 char8_t 序列），則將宏 EILSEQ 的值存入 errno ，傳回 ( size_t ) -1 ，且轉換狀態未指定。

### Notes

Calls to `c8rtomb` with a null pointer argument for `s` may introduce a data race with other calls to `c8rtomb` with a null pointer argument for `s`.
以空指標作為 s 實參呼叫 c8rtomb ，可能與其他同樣以空指標作為 s 實參的 c8rtomb 呼叫產生資料競爭。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.1.2 The c8rtomb function
7.30.1.2 c8rtomb 函式
7.30.1.2 c8rtomb 函式

### See also

mbrtoc8
(C23)
|   | converts a narrow multibyte character to UTF-8 encoding
(function)   |

C++ documentation for c8rtomb

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/c8rtomb.html`

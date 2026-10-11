# mbrtoc8

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t mbrtoc8( char8_t* restrict pc8, const char* restrict s, size_t n,  mbstate_t* restrict ps );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Converts a narrow multibyte character to UTF-8 encoding.
將窄多位元組字元轉換為 UTF-8 編碼。
If `s` is not a null pointer, inspects at most `n` bytes of the multibyte character string, beginning with the byte pointed to by `s` to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences). If the function determines that the next multibyte character in `s` is complete and valid, converts it to UTF-8 and stores the first UTF-8 code unit in `*pc8` (if `pc8` is not null).
如果 s 不是空指標，則檢查多位元組字串的至多 n 個位元組（從 s 指向的位元組開始），以確定完成下一個多位元組字元所需的位元組數（包括任何移位序列）。如果函式確定 s 中的下一個多位元組字元已完整且有效，則將其轉換為 UTF-8 ，並將第一個 UTF-8 碼元儲存到 * pc8 （如果 pc8 不為空）。
If UTF-8 encoding of the multibyte character in `*s` consists of more than one UTF-8 code unit, then after the first call to this function, `*ps` is updated in such a way that the next call to `mbrtoc8` will write out the additional UTF-8 code units, without considering `*s`.
如果 * s 中多位元組字元的 UTF-8 編碼由多個 UTF-8 碼元組成，則在第一次呼叫本函式後，* ps 會被更新，使得下一次呼叫 mbrtoc8 會寫出額外的 UTF-8 碼元，而無需考慮 * s 。
If `s` is a null pointer, the values of `n` and `pc8` are ignored and the call is equivalent to `mbrtoc8(nullptr, "", 1, ps)`.
如果 s 是空指標，則忽略 n 和 pc8 的值，該呼叫等價於 mbrtoc8 ( nullptr , "" , 1 , ps ) 。
If UTF-8 code unit produced is `u8'\0'`, the conversion state `*ps` represents the initial shift state.
如果產生的 UTF-8 碼元是 u8 '\0' ，則轉換狀態 * ps 表示初始移位狀態。
The multibyte encoding used by this function is specified by the currently active C locale.
此函式使用的多位元組編碼由目前活動的 C 區域設定指定。

### Parameters

| pc8  |   | -  |   | pointer to the location where the resulting UTF-8 code units will be written  |

| s  |   | -  |   | pointer to the multibyte character string used as input  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

The first of the following that applies:
以下第一個適用的條件：

- `0` if the character converted from `s` (and stored in `*pc8` if non-null) was the null character.
如果從 s 轉換的字元（若非空則儲存於 * pc8 ）是空字元，則傳回 0 。

- The number of bytes `[``1``, ``n``]` of the multibyte character successfully converted from `s`.
從 s 成功轉換的多位元組字元的位元組數 [ 1 , n ]。

- `(size_t)-3` if the next UTF-8 code unit from a character whose encoding consists of multiple code units has now been written to `*pc8`. No bytes are processed from the input in this case.
如果來自某個由多個碼元組成的字元的下一個 UTF-8 碼元現已寫入 * pc8 ，則傳回 ( size_t ) -3 。此種情況下不處理輸入的任何位元組。

- `(size_t)-2` if the next `n` bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to `*pc8`.
如果接下來的 n 個位元組構成一個尚不完整但目前有效的多位元組字元，則傳回 ( size_t ) -2 。不會向 * pc8 寫入任何內容。

- `(size_t)-1` if encoding error occurs. Nothing is written to `*pc8`, the value EILSEQ is stored in errno and the value of `*ps` is unspecified.
如果發生編碼錯誤，則傳回 ( size_t ) -1 。不會向 * pc8 寫入任何內容，EILSEQ 的值存入 errno ，且 * ps 的值未指定。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.1.1 The mbrtoc8 function
7.30.1.1 mbrtoc8 函式
7.30.1.1 mbrtoc8 函式

### See also

c8rtomb
(C23)
|   | converts UTF-8 string to narrow multibyte encoding
(function)   |

C++ documentation for mbrtoc8

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbrtoc8.html`

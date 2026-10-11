# mbstate_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |
(since C11)

Defined in header `<wchar.h>`
|   |  |   |  |

```c
struct mbstate_t;
```
|   |   |   |  (since C95)  |

|  |  |  |  |

The type `mbstate_t` is a trivial non-array type that can represent any of the conversion states that can occur in an implementation-defined set of supported multibyte character encoding rules. Zero-initialized value of `mbstate_t` represents the initial conversion state, although other values of `mbstate_t` may exist that also represent the initial conversion state.
mbstate_t 型別是一個平凡的非陣列型別，可以表示實現所定義的一組受支援多位元組字元編碼規則中可能出現的任何轉換狀態。mbstate_t 的零初始化值表示初始轉換狀態，儘管也可能存在其他同樣表示初始轉換狀態的 mbstate_t 值。
Possible implementation of `mbstate_t` is a struct type holding an array representing the incomplete multibyte character, an integer counter indicating the number of bytes in the array that have been processed, and a representation of the current shift state.
mbstate_t 的一種可能實現是一個 struct 型別，其中包含表示未完成多位元組字元的陣列、指示陣列中已處理位元組數的整數計數器，以及目前移位狀態的表示。
The following functions should not be called from multiple threads without synchronization with the `mbstate_t*` argument of a null pointer due to possible data races: mbrlen, mbrtowc, mbsrtowcs, mbtowc, wcrtomb, wcsrtombs, wctomb.
由於可能存在資料競爭，以下函式在多個執行緒中使用時不應在沒有同步的情況下將 mbstate_t * 參數傳入空指標：mbrlen 、mbrtowc 、mbsrtowcs 、mbtowc 、wcrtomb 、wcsrtombs 、wctomb 。

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.1/2 Introduction (p: 402)
7.29.1/2 引言（p: 402）
7.29.1/2 引言（p: 402）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.1/2 Introduction (p: 348)
7.24.1/2 引言（p: 348）
7.24.1/2 引言（p: 348）

### See also

mbsinit
(C95)
|   | checks if the mbstate_t object represents initial shift state
(function)   |

C++ documentation for mbstate_t

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbstate_t.html`

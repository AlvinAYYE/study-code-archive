# C attribute: noreturn, _Noreturn (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Indicates that the function does not return.
指示該函式不傳回。

### Syntax

|   |

| `**[[**` `**noreturn**` `**]]**`
`**[[**` `**__noreturn__**` `**]]**`  |   |   |   |   |

|   |

| `**[[**` `**_Noreturn**` `**]]**`
`**[[**` `**___Noreturn__**` `**]]**`  |   |   |   | (deprecated)  |

|   |

### Explanation

Indicates that the function does not return.
指示該函式不傳回。
This attribute applies to the name of the function and specifies that the function does not return by executing the return statement or by reaching the end of the function body (it may return by executing longjmp). The behavior is undefined if the function with this attribute actually returns. A compiler diagnostic is recommended if this can be detected.
此屬性適用於函式名，並指定該函式不透過執行 return 陳述式或到達函式體末尾來傳回（它可以透過執行 longjmp 傳回）。如果帶有此屬性的函式實際傳回，則行為是未定義的。如果可以檢測到，建議編譯器發出診斷。
It has been previously denoted by the keyword _Noreturn until it was deprecated since C23 and replaced by this attribute.
它之前由關鍵字 _Noreturn 表示，直到 C23 起被棄用並由該屬性取代。

### Standard library
標準函式庫

The following standard functions are declared with `noreturn` attribute (they used to be declared with _Noreturn specifier until C23):
以下標準函式宣告為帶有 noreturn 屬性（在 C23 之前它們使用 _Noreturn 說明符宣告）：

- abort()

- exit()

- _Exit()

- quick_exit()

- thrd_exit()

- longjmp()

### See also

C documentation for _Noreturn

C++ documentation for `[[noreturn]]`

---
來源頁路徑：`en.cppreference.com/c/language/attributes/noreturn.html`

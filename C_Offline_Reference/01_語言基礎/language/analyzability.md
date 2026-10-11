# Analyzability

> 來源：cppreference C 語言參考文件（離線轉換版）。

This optional extension to the C language limits the potential results of executing some forms of undefined behavior, which improves the effectiveness of static analysis of such programs. Analyzability is only guaranteed to be enabled if the predefined macro constant `__STDC_ANALYZABLE__`(C11) is defined by the compiler.
此 C 語言的可選擴充套件限制了執行某些形式的未定義行為的潛在結果，從而提高了對此類程式進行靜態分析的有效性。僅當編譯器定義了預定義宏常量 __STDC_ANALYZABLE__ (C11) 時，才保證啟用可分析性。
If the compiler supports analyzability, any language or library construct whose behavior is undefined is further classified between *critical* and *bounded* undefined behavior, and the behavior of all bounded UB cases is limited as specified below.
如果編譯器支援可分析性，則行為未定義的任何語言或庫結構會被進一步分類為關鍵未定義行為和受限未定義行為，所有受限 UB 情況的行為按以下規定加以限制。

### Critical undefined behavior
關鍵未定義行為

Critical UB is undefined behavior that might perform a memory write or a volatile memory read out of bounds of any object. A program that has critical undefined behavior may be susceptible to security exploits.
關鍵 UB 是可能越界執行記憶體寫入或易變記憶體讀取的未定義行為。具有關鍵未定義行為的程式可能容易受到安全攻擊。
Only the following undefined behaviors are critical:
只有以下未定義行為是關鍵的：

- access to an object outside of its lifetime (e.g. through a dangling pointer)
訪問超出其生存期的物件（例如透過懸垂指標）

- write to an object whose declarations are not compatible
寫入宣告不相容的物件

- function call through a function pointer whose type is not compatible with the type of the function it points to
透過型別與所指向函式型別不相容的函式指標呼叫函式

- lvalue expression is evaluated, but does not designate an object
左值表示式被求值，但不指定物件

- attempted modification of a string literal
嘗試修改字串字面量

- dereferencing an invalid (null, indeterminate, etc) or past-the-end pointer
解引用無效（空、不確定等）或越界指標

- modification of a const object through a non-const pointer
透過非 const 指標修改 const 物件

- call to a standard library function or macro with an invalid argument
以無效參數呼叫標準函式庫函式或宏

- call to a variadic standard library function with unexpected argument type (e.g. call to printf with an argument of the type that doesn't match its conversion specifier)
以意外參數型別呼叫可變參數標準函式庫函式（例如呼叫 printf 時參數型別與其轉換說明符不匹配）

- longjmp where there is no setjmp up the calling scope, across threads, or from within the scope of a VM type.
在呼叫作用域中沒有 setjmp 時執行 longjmp、跨執行緒執行 longjmp，或從 VM 型別的作用域內執行 longjmp。

- any use of the pointer that was deallocated by free or realloc
使用已被 free 或 realloc 釋放的指標

- any string or wide string library function accesses an array out of bounds
任何字串或寬字串庫函式越界訪問陣列

### Bounded undefined behavior
受限未定義行為

Bounded UB is undefined behavior that cannot perform an illegal memory write, although it may trap and may produce or store indeterminate values.
受限 UB 是不能執行非法記憶體寫入的未定義行為，儘管它可能陷阱，並可能產生或儲存不確定值。

- All undefined behavior not listed as critical is bounded, including
所有未列為關鍵的未定義行為都是受限的，包括

- multithreaded data races
多執行緒資料競爭

- use of a indeterminate values with automatic storage duration
使用自動儲存持續時間的不確定值

- strict aliasing violations
嚴格別名違規

- misaligned object access
未對齊物件訪問

- signed integer overflow
有符號整數溢位

- unsequenced side-effects modify the same scalar or modify and read the same scalar
無序副作用修改同一標量或修改並讀取同一標量

- floating-to-integer or pointer-to-integer conversion overflow
浮點到整數或指標到整數轉換溢位

- bitwise shift by a negative or too large bit count
以負數或過大位數進行按位移位

- integer division by zero
整數除以零

- use of a void expression
使用 void 表示式

- direct assignment or memcpy of inexactly-overlapped objects
直接賦值或對未精確重疊物件進行 memcpy

- restrict violations
restrict 違規

- etc.. ALL undefined behavior that's not in the critical list.
等等。。所有不在關鍵列表中的未定義行為。
多執行緒資料競爭 使用自動儲存持續時間的不確定值 嚴格別名違規 未對齊物件訪問 有符號整數溢位 無序副作用修改同一標量或修改並讀取同一標量 浮點到整數或指標到整數轉換溢位 以負數或過大位數進行按位移位 整數除以零 使用 void 表示式 直接賦值或對未精確重疊物件進行 memcpy restrict 違規 等等。。所有不在關鍵列表中的未定義行為。

### Notes

Bounded undefined behavior disables certain optimizations: compilation with analyzability enabled preserves source-code causality, which may be violated by undefined behavior otherwise.
受限未定義行為禁用某些最佳化：啟用可分析性的編譯保留了原始碼因果關係，否則可能被未定義行為破壞。
Analyzability extension permits, as a form of implementation-defined behavior, for the runtime constraint handler to be invoked when a trap occurs.
可分析性擴充套件作為一種實現定義行為，允許在發生陷阱時呼叫執行時約束處理程式。

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.8.3/1 Conditional feature macros (p: 177)
6.10.8.3/1 條件特性宏 (p: 177)
6.10.8.3/1 條件特性宏 (p: 177)

- Annex L Analyzability (p: 652-653)
附錄 L 可分析性 (p: 652-653)
附錄 L 可分析性 (p: 652-653)

---
來源頁路徑：`en.cppreference.com/c/language/analyzability.html`

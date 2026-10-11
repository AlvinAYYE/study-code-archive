# External and tentative definitions

> 來源：cppreference C 語言參考文件（離線轉換版）。

At the top level of a translation unit (that is, a source file with all the #includes after the preprocessor), every C program is a sequence of declarations, which declare functions and objects with external or internal linkage. These declarations are known as *external declarations* because they appear outside of any function.
在翻譯單元的頂層（即經過前處理器後包含所有 #include 的原始檔），每個 C 程式都是一個宣告序列，這些宣告宣告具有外部或內部連結的函式和物件。這些宣告被稱為外部宣告，因為它們出現在任何函式之外。

```c
extern int n; // external declaration with external linkage int b = 1; // external definition with external linkage static const char *c = "abc"; // external definition with internal linkage int f(void) // external definition with external linkage {  int a = 1; // non-external  return b; } static void x(void) // external definition with internal linkage { }
```

Objects declared with an external declaration have static storage duration, and as such cannot use `auto` or `register` specifiers except that `auto` can be used for type inference(since C23). The identifiers introduced by external declarations have file scope.
由外部宣告宣告的物件具有靜態儲存期，因此不能使用 auto 或 register 說明符，但 auto 可用於型別推斷（自 C23 起）。由外部宣告引入的識別符號具有檔案作用域。

### Tentative definitions
暫定定義

A *tentative definition* is an external declaration without an initializer, and either without a storage-class specifier or with the specifier `static`.
暫定定義是沒有初始化器的外部宣告，並且 要麼沒有儲存類說明符，要麼帶有說明符 static。
A *tentative definition* is a declaration that may or may not act as a definition. If an actual external definition is found earlier or later in the same translation unit, then the tentative definition just acts as a declaration.
暫定定義是一個可能充當定義也可能不充當定義的宣告。如果在同一翻譯單元中較早或較晚處找到實際的外部定義，則該暫定定義僅充當宣告。

```c
int i1 = 1; // definition, external linkage int i1; // tentative definition, acts as declaration because i1 is defined extern int i1; // declaration, refers to the earlier definition extern int i2 = 3; // definition, external linkage int i2; // tentative definition, acts as declaration because i2 is defined extern int i2; // declaration, refers to the external linkage definition
```

If there are no definitions in the same translation unit, then the tentative definition acts as an actual definition that empty-initializes the object.
如果同一翻譯單元中沒有定義，則暫定定義充當實際定義，對該物件進行空初始化。

```c
int i3; // tentative definition, external linkage int i3; // tentative definition, external linkage extern int i3; // declaration, external linkage // in this translation unit, i3 is defined as if by "int i3 = 0;"
```

Unlike the extern declarations, which don't change the linkage of an identifier if a previous declaration established it, tentative definitions may disagree in linkage with another declaration of the same identifier. If two declarations for the same identifier are in scope and have different linkage, the behavior is undefined:
與 extern 宣告不同——如果先前的宣告已確定識別符號的連結，extern 宣告不會改變它——暫定定義可能與同一識別符號的另一個宣告在連結上不一致。如果同一識別符號的兩個宣告都在作用域內且具有不同的連結，則行為是未定義的：

```c
static int i4 = 2; // definition, internal linkage int i4; // Undefined behavior: linkage disagreement with previous line extern int i4; // declaration, refers to the internal linkage definition static int i5; // tentative definition, internal linkage int i5; // Undefined behavior: linkage disagreement with previous line extern int i5; // refers to previous, whose linkage is internal
```

A tentative definition with internal linkage must have complete type.
具有內部連結的暫定定義必須具有完整型別。

```c
static int i[]; // Error, incomplete type in a static tentative definition int i[]; // OK, equivalent to int i[1] = {0}; unless redeclared later in this file
```

### One definition rule
單一定義規則

Each translation unit may have zero or one external definition of every identifier with internal linkage (a `static` global).
每個翻譯單元對於每個具有內部連結的識別符號（靜態全域性變數）可以有零個或一個外部定義。
If an identifier with internal linkage is used in any expression other than a non-VLA,(since C99) sizeof, _Alignof(since C11)(until C23), alignof(since C23), or typeof(since C23), there must be one and only one external definition for that identifier in the translation unit.
如果具有內部連結的識別符號在非 VLA、（自 C99 起）sizeof、_Alignof（自 C11 起）（至 C23 止）、alignof（自 C23 起）或 typeof（自 C23 起）以外的任何表示式中使用，則該翻譯單元中必須存在該識別符號的一個且僅一個外部定義。
The entire program may have zero or one external definition of every identifier with external linkage.
整個程式對於每個具有外部連結的識別符號可以有零個或一個外部定義。
If an identifier with external linkage is used in any expression other than a non-VLA,(since C99) sizeof, _Alignof(since C11)(until C23), alignof(since C23), or typeof(since C23), there must be one and only one external definition for that identifier somewhere in the entire program.
如果具有外部連結的識別符號在非 VLA、（自 C99 起）sizeof、_Alignof（自 C11 起）（至 C23 止）、alignof（自 C23 起）或 typeof（自 C23 起）以外的任何表示式中使用，則整個程式中某處必須存在該識別符號的一個且僅一個外部定義。

### Notes

Inline definitions in different translation units are not constrained by one definition rule. See inline for the details on the inline function definitions.
|   | (since C99) |

See storage duration and linkage for the meaning of the keyword `extern` with declarations at file scope
關於在檔案作用域宣告中關鍵字 extern 的含義，見儲存期和連結。
See definitions for the distinction between declarations and definitions.
關於宣告與定義之間的區別，見定義。
Tentative definitions were invented to standardize various pre-C89 approaches to forward declaring identifiers with internal linkage.
發明暫定定義是為了標準化 C89 之前各種前向宣告具有內部連結識別符號的方法。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.9 External definitions (p: TBD)
6.9 外部定義（第 TBD 頁）
6.9 外部定義（第 TBD 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.9 External definitions (p: 113-116)
6.9 外部定義（第 113-116 頁）
6.9 外部定義（第 113-116 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.9 External definitions (p: 155-159)
6.9 外部定義（第 155-159 頁）
6.9 外部定義（第 155-159 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.9 External definitions (p: 140-144)
6.9 外部定義（第 140-144 頁）
6.9 外部定義（第 140-144 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.7 EXTERNAL DEFINITIONS
3.7 外部定義
3.7 外部定義

---
來源頁路徑：`en.cppreference.com/c/language/extern.html`

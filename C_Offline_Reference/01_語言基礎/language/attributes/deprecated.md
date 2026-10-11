# C attribute: deprecated (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Indicates that the name or entity declared with this attribute is deprecated, that is, the use is allowed, but discouraged for some reason.
指示用這種屬性宣告的名字或實體是棄用的，即允許使用，但因某種原因不鼓勵。

### Syntax

|   |

| `**[[**` `**deprecated**` `**]]**`
`**[[**` `**__deprecated__**` `**]]**`  |   | (1)  |   |   |

|   |

| `**[[**` `**deprecated**` `**(**` string-literal `**)**` `**]]**`
`**[[**` `**__deprecated__**` `**(**` string-literal `**)**` `**]]**`  |   | (2)  |   |   |

|   |

| string-literal  |   | -  |   | text that could be used to explain the rationale for deprecation and/or to suggest a replacing entity  |

### Explanation

Indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason. Compilers typically issue warnings on such uses. The string-literal, if specified, is usually included in the warnings.
指示用這種屬性宣告的名字或實體的使用是允許的，但因某種原因不鼓勵。編譯器通常對此類使用發出警告。字串字面量（如果指定）通常包含在警告中。
This attribute is allowed in declarations of the following names or entities:
此屬性允許在以下名字或實體的宣告中使用：

- struct/union: `struct [[deprecated]] S;`,
struct / union ：struct [[ deprecated ]] S ; ，

- typedef-name: `[[deprecated]] typedef S* PS;`,
typedef 名：[[ deprecated ]] typedef S * PS ; ，

- objects: `[[deprecated]] int x;`,
物件：[[ deprecated ]] int x ; ，

- struct/union member: `union U { [[deprecated]] int n; };`,
struct/union 成員：union U { [[ deprecated ]] int n ; }; ，

- function: `[[deprecated]] void f(void);`,
函式：[[ deprecated ]] void f ( void ); ，

- enumeration: `enum [[deprecated]] E {};`,
列舉：enum [[ deprecated ]] E {}; ，

- enumerator: `enum { A [[deprecated]], B [[deprecated]] = 42 };`.
列舉器：enum { A [[ deprecated ]], B [[ deprecated ]] = 42 }; 。

A name declared non-deprecated may be redeclared deprecated. A name declared deprecated cannot be un-deprecated by redeclaring it without this attribute.
宣告為未棄用的名字可以重新宣告為棄用。宣告為棄用的名字不能透過在缺少此屬性的情況下重新宣告來取消棄用。

### Example

Run this code

```c
#include <stdio.h> [[deprecated]] void TriassicPeriod(void) {  puts("Triassic Period: [251.9 - 208.5] million years ago."); } [[deprecated("Use NeogenePeriod() instead.")]] void JurassicPeriod(void) {  puts("Jurassic Period: [201.3 - 152.1] million years ago."); } [[deprecated("Use calcSomethingDifferently(int).")]] int calcSomething(int x) {  return x * 2; } int main(void) {  TriassicPeriod();  JurassicPeriod(); }
```

Possible output:
可能的輸出：

```c
Triassic Period: [251.9 - 208.5] million years ago. Jurassic Period: [201.3 - 152.1] million years ago. prog.c:23:5: warning: 'TriassicPeriod' is deprecated [-Wdeprecated-declarations] TriassicPeriod(); ^ prog.c:3:3: note: 'TriassicPeriod' has been explicitly marked deprecated here [[deprecated]] ^ prog.c:24:5: warning: 'JurassicPeriod' is deprecated: Use NeogenePeriod() instead. [-Wdeprecated-declarations] JurassicPeriod(); ^ prog.c:9:3: note: 'JurassicPeriod' has been explicitly marked deprecated here [[deprecated("Use NeogenePeriod() instead.")]] ^ 2 warnings generated.
```

### See also

C++ documentation for deprecated

---
來源頁路徑：`en.cppreference.com/c/language/attributes/deprecated.html`

# C attribute: maybe_unused (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Suppresses warnings on unused entities.
抑制未使用實體的警告。

### Syntax

|   |

| `**[[**` `**maybe_unused**` `**]]**`
`**[[**` `**__maybe_unused__**` `**]]**`  |   |   |   |   |

|   |

### Explanation

This attribute can appear in the declaration of the following entities:
此屬性可以出現在以下實體的宣告中：

- struct/union: `struct [[maybe_unused]] S;`,
struct / union ：struct [[ maybe_unused ]] S ; ，

- typedef name: `[[maybe_unused]] typedef S* PS;`,
typedef 名：[[ maybe_unused ]] typedef S * PS ; ，

- object: `[[maybe_unused]] int x;`,
物件：[[ maybe_unused ]] int x ; ，

- struct/union member: `union U { [[maybe_unused]] int n; };`,
struct/union 成員：union U { [[ maybe_unused ]] int n ; }; ，

- function: `[[maybe_unused]] void f(void);`,
函式：[[ maybe_unused ]] void f ( void ); ，

- enumeration: `enum [[maybe_unused]] E {};`,
列舉：enum [[ maybe_unused ]] E {}; ，

- enumerator: `enum { A [[maybe_unused]], B [[maybe_unused]] = 42 };`.
列舉器：enum { A [[ maybe_unused ]], B [[ maybe_unused ]] = 42 }; 。

If the compiler issues warnings on unused entities, that warning is suppressed for any entity declared `maybe_unused`.
如果編譯器對未使用的實體發出警告，則對任何宣告為 maybe_unused 的實體都會抑制該警告。

### Example

Run this code

```c
#include <assert.h> [[maybe_unused]] void f([[maybe_unused]] _Bool cond1, [[maybe_unused]] _Bool cond2) {  [[maybe_unused]] _Bool b = cond1 && cond2;  assert(b); // in release mode, assert is compiled out, and b is unused  // no warning because it is declared [[maybe_unused]] } // parameters cond1 and cond2 are not used, no warning int main(void) {  f(1, 1); }
```

### See also

C++ documentation for maybe_unused

---
來源頁路徑：`en.cppreference.com/c/language/attributes/maybe_unused.html`

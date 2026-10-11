# C attribute: fallthrough (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough.
指示從前一個 case 標籤的貫穿是故意的，不應被在貫穿時發出警告的編譯器診斷。

### Syntax

|   |

| `**[[**` `**fallthrough**` `**]]**`
`**[[**` `**__fallthrough__**` `**]]**`  |   |   |   |   |

|   |

### Explanation

May only be used in an attribute declaration to create a *fallthrough declaration* (`[[fallthrough]];`).
只能在屬性宣告中使用以建立貫穿宣告（ [[ fallthrough ]]; ）。
A fallthrough declaration may only be used in a switch statement, where the next block item (statement, declaration, or label) to be encounted is a statement with a `case` or `default` label for that switch statement.
貫穿宣告只能在 switch 陳述式中使用，其中下一個將遇到的塊項（陳述式、宣告或標籤）是帶有該 switch 陳述式的 case 或 default 標籤的陳述式。
Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough.
指示從前一個 case 標籤的貫穿是故意的，不應被在貫穿時發出警告的編譯器診斷。

### Example

Run this code

```c
#include <stdbool.h> void g(void) {} void h(void) {} void i(void) {} void f(int n) {  switch (n) {  case 1:  case 2:  g();  [[fallthrough]];  case 3: // no warning on fallthrough  h();  case 4: // compiler may warn on fallthrough  if(n < 3) {  i();  [[fallthrough]]; // OK  }  else {  return;  }  case 5:  while (false) {  [[fallthrough]]; // ill-formed: no subsequent case or default label  }  case 6:  [[fallthrough]]; // ill-formed: no subsequent case or default label  } } int main(void) {}
```

### See also

C++ documentation for fallthrough

---
來源頁路徑：`en.cppreference.com/c/language/attributes/fallthrough.html`

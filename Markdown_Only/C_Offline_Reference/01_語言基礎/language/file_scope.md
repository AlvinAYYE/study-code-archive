# File scope

> 來源：cppreference C 語言參考文件（離線轉換版）。

If the declarator or type specifier that declares the identifier appears outside of any block or list of parameters, the identifier has file scope, which terminates at the end of the translation unit.
如果宣告識別符號的宣告器或型別說明符出現在任何塊或參數列表之外，則該識別符號具有檔案作用域，該作用域在翻譯單元末尾終止。
So, placement of an identifier's declaration (in a declarator or type specifier) outside any block or list of parameters means that the identifier has file scope. File scope of an identifier extends from the declaration to the end of the translation unit in which the declaration appears.
因此，在任何塊或參數列表之外（在宣告器或型別說明符中）放置識別符號的宣告意味著該識別符號具有檔案作用域。識別符號的檔案作用域從宣告延伸到宣告所在的翻譯單元的末尾。

### Example

Identifiers a, b, f, and g have file scope.
識別符號 a、b、f 和 g 具有檔案作用域。
Run this code

```c
#include <stdio.h> int a = 1; static int b = 2; void f (void) {printf("from function f()\n");} static void g (void) {printf("from function g()\n");} int main(void) {  f();  g();  return 0; } /* end of this translation unit, end of file scope */
```

Possible output:
可能的輸出：

```c
from function f() from function g()
```

---
來源頁路徑：`en.cppreference.com/c/language/file_scope.html`

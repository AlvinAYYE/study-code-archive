# Boolean type

> 來源：cppreference C 語言參考文件（離線轉換版）。

When any scalar value is converted to _Bool, the result is 0 if the value compares equal to 0; otherwise, the result is 1.
當任何標量值轉換為 _Bool 時，如果該值與 0 比較 相等，則結果為 0；否則結果為 1。

### Notes

NaNs do not compare equal to 0 and thus convert to 1.
NaN 與 0 比較不相等，因此轉換為 1。

### Example

Run this code

```c
#include <stdio.h> int main(void) {  _Bool a = 0.0;  _Bool b = 8;  _Bool c = 0.0/0.0;  printf("%d\n", a);  printf("%d\n", b);  printf("%d\n", c);  return 0; }
```

Possible output:
可能的輸出：

```c
0 1 1
```

---
來源頁路徑：`en.cppreference.com/c/language/boolean_type.html`

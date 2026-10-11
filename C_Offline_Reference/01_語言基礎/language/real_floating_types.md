# Real floating types

> 來源：cppreference C 語言參考文件（離線轉換版）。

When a value of real floating type is converted to a real floating type, if the value being converted can be represented exactly in the new type, it is unchanged. If the value being converted is in the range of values that can be represented but cannot be represented exactly, the result is either the nearest higher or nearest lower representable value, chosen in an implementation-defined manner. If the value being converted is outside the range of values that can be represented, the behavior is undefined. Results of some implicit conversions may be represented in greater range and precision than that required by the new type (see  Usual arithmetic conversions and  Return statement).
將實數浮點型別的值轉換為另一種實數浮點型別時，若新型別能精確表示該值，結果不變。若值落在新型別的表示範圍內但無法精確表示，結果會依實作定義，選擇最接近的較大或較小值；若值超出表示範圍，行為未定義。部分隱式轉換的結果可能以高於目標型別要求的範圍與精度表示，詳見通常算術轉換與 return 陳述式。

### Example

Run this code

```c
#include <stdio.h> #include <float.h> int main(void) {  /* The value being converted can be represented exactly in the new type. */  /* The value is unchanged in the new type. */  double d = 1.0;  float f = d;  printf("%f\n", f);  /* The value being converted is in the range of values that can be represented */  /* in the new type but cannot be represented exactly. */  /* implementation defined */  d = 1.23456789012345;  printf("%.14f\n", d);  f = d;  printf("%.14f\n", f);  /* The value being converted is outside the range of values that can be */  /* represented in the type. */  /* undefined behavior */  d = DBL_MAX;  f = d;  printf("%f\n", f);  return 0; }
```

Possible output:
可能的輸出：

```c
1.000000 1.23456789012345 1.23456788063049 inf
```

---
來源頁路徑：`en.cppreference.com/c/language/real_floating_types.html`

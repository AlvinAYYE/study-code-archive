# constexpr specifier (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

A scalar object declared with the `constexpr` storage-class specifier is a constant. It must be fully and explicitly initialized according to the static initialization rules. It still has linkage appropriate to its declaration and it exist at runtime to have its address taken; it simply cannot be modified at runtime in any way, i.e. the compiler can use its knowledge of the object’s fixed value in any other constant expression.
用 constexpr 儲存類說明符宣告的標量物件是常量。它必須按照靜態初始化規則完全且顯式地初始化。它仍然具有與其宣告相適應的連結，並且在執行時存在以便取其位址；它只是不能以任何方式在執行時被修改，即編譯器可以在任何其他常量表示式中使用其關於該物件固定值的知識。
Additionally, the constant expression that is used for the initializer of such a constant is checked at compile time.
此外，用於此類常量的初始化器的常量表示式在編譯時進行檢查。
An initializer of floating-point type must be evaluated with the translation-time floating-point environment.
浮點型別的初始化器必須在翻譯時的浮點環境中求值。
There are some restrictions on the type of an object that can be declared with `constexpr`. Namely, the following constructs are not allowed to be `constexpr`:
對於可以用 constexpr 宣告的物件的型別有一些限制。即，以下構造不允許為 constexpr：

- Pointers (except that null pointers can be `constexpr`),
指標（除了空指標可以為 constexpr），

- Variably modified types,
可變修改型別，

- Atomic types,

- volatile types,
volatile 型別，

- restrict pointers.
restrict 指標。

### Keywords

constexpr

### Notes

### Example

Run this code

```c
#include <fenv.h> #include <stdio.h> int main(void) {  constexpr float f = 23.0f;  constexpr float g = 33.0f;  fesetround(FE_TOWARDZERO);  constexpr float h = f / g; // is not affected by fesetround() above  printf("%f\n", h); }
```

Output:

```c
0.696969
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- TBD TBD (p: TBD)
TBD TBD (p: TBD)
TBD TBD (p: TBD)

### See also

C++ documentation for `constexpr` type specifier

---
來源頁路徑：`en.cppreference.com/c/language/constexpr.html`

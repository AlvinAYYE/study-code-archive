# Lifetime

> 來源：cppreference C 語言參考文件（離線轉換版）。

Every object in C exists, has a constant address, retains its last-stored value (except when the value is indeterminate), and, for VLA, retains its size(since C99) over a portion of program execution known as this object's *lifetime*.
C 中的每個物件都有固定的位址，並會保留最後儲存的值（除非該值不確定）；VLA 的大小（C99 起）也維持不變。物件在程式執行期間存在的這段時間，稱為物件的生命週期。
For the objects that are declared with automatic, static, and thread storage duration, lifetime equals their storage duration (note the difference between non-VLA and VLA automatic storage duration).
對於宣告為自動、靜態和執行緒儲存期的物件，其生命週期等於它們的儲存期（注意非 VLA 與 VLA 自動儲存期之間的差異）。
For the objects with allocated storage duration, the lifetime begins when the allocation function returns (including the return from realloc) and ends when the realloc or deallocation function is called. Note that since allocated objects have no declared type, the type of the lvalue expression first used to access this object becomes its effective type.
配置儲存期物件的生命週期，從配置函式（包括 realloc）回傳時開始，到呼叫 realloc 或釋放函式時結束。由於配置出的物件沒有宣告型別，第一次用來存取它的左值運算式型別會成為其有效型別。
Accessing an object outside of its lifetime is undefined behavior.
在物件的生命週期之外訪問該物件是未定義行為。

```c
int* foo(void) {  int a = 17; // a has automatic storage duration  return &a; } // lifetime of a ends int main(void) {  int* p = foo(); // p points to an object past lifetime ("dangling pointer")  int n = *p; // undefined behavior }
```

A pointer to an object (or one past the object) whose lifetime ended has indeterminate value.
指向生命週期已結束的物件（或該物件之後一個位置）的指標具有不確定的值。

### Temporary lifetime
臨時生命週期

Struct and union objects with array members (either direct or members of nested struct/union members) that are designated by non-lvalue expressions, have *temporary lifetime*. Temporary lifetime begins when the expression that refers to such object is evaluated and ends at the next sequence point(until C11)when the containing full expression or full declarator ends(since C11).
由非左值表示式所指定的、帶有陣列成員（無論是直接成員，還是巢狀結構體/聯合體成員的成員）的結構體和聯合體物件具有臨時生命週期。臨時生命週期在引用該物件的表示式被求值時開始，在下一個序列點結束（C11 之前），或在包含它的完整表示式或完整宣告器結束時結束（自 C11 起）。
Any attempt to modify an object with temporary lifetime results in undefined behavior.
任何修改具有臨時生命週期的物件的操作都會導致未定義行為。

```c
struct T { double a[4]; }; struct T f(void) { return (struct T){3.15}; } double g1(double* x) { return *x; } void g2(double* x) { *x = 1.0; } int main(void) {  double d = g1(f().a); // C99: UB access to a[0] in g1 whose lifetime ended  // at the sequence point at the start of g1  // C11: OK, d is 3.15  g2(f().a); // C99: UB modification of a[0] whose lifetime ended at the sequence point  // C11: UB attempt to modify a temporary object }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.2.4 Storage durations of objects (p: 30)
6.2.4 物件的儲存期（p: 30）
6.2.4 物件的儲存期（p: 30）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.2.4 Storage durations of objects (p: 38-39)
6.2.4 物件的儲存期（p: 38-39）
6.2.4 物件的儲存期（p: 38-39）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.2.4 Storage durations of objects (p: 32)
6.2.4 物件的儲存期（p: 32）
6.2.4 物件的儲存期（p: 32）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.2.4 Storage durations of objects
3.1.2.4 物件的儲存期
3.1.2.4 物件的儲存期

### See also

C++ documentation for Object lifetime

---
來源頁路徑：`en.cppreference.com/c/language/lifetime.html`

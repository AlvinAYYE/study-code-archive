# restrict type qualifier (since C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each individual type in the C type system has several *qualified* versions of that type, corresponding to one, two, or all three of the const, volatile, and, for pointers to object types, `restrict` qualifiers. This page describes the effects of the `restrict` qualifier.
C 型別系統中的每個型別都有該型別的幾個限定版本，分別對應 const、volatile 以及（對於指向物件型別的指標）restrict 限定符中的一個、兩個或全部三個。本頁描述 restrict 限定符的效果。
Only a pointer to an object type or a (possibly multi-dimensional) array thereof(since C23) may be restrict-qualified; in particular, the following are *erroneous*:
只有指向物件型別的指標或其（可能多維）陣列（C23 起）才能被 restrict 限定；特別是，以下寫法是錯誤的：

- `int restrict *p`
int restrict * p

- `float (* restrict f9)(void)`
float ( * restrict f9 )( void )

Restrict semantics apply to lvalue expressions only; for example, a cast to restrict-qualified pointer or a function call returning a restrict-qualified pointer are not lvalues and the qualifier has no effect.
restrict 語意僅適用於左值表示式；例如，轉換為 restrict 限定指標或傳回 restrict 限定指標的函式呼叫不是左值，該限定符沒有效果。
During each execution of a block in which a restricted pointer `P` is declared (typically each execution of a function body in which `P` is a function parameter), if some object that is accessible through `P` (directly or indirectly) is modified, by any means, then all accesses to that object (both reads and writes) in that block must occur through `P` (directly or indirectly), otherwise the behavior is undefined:
在宣告瞭受限指標 P 的塊的每次執行期間（通常是在 P 作為函式參數的函式體的每次執行期間），如果透過 P（直接或間接）可訪問的某個物件以任何方式被修改，則該塊中對該物件的所有訪問（讀和寫）都必須透過 P（直接或間接）進行，否則行為是未定義的：

```c
void f(int n, int * restrict p, int * restrict q) {  while (n-- > 0)  *p++ = *q++; // none of the objects modified through *p is the same  // as any of the objects read through *q  // compiler free to optimize, vectorize, page map, etc. } void g(void) {  extern int d[100];  f(50, d + 50, d); // OK  f(50, d + 1, d); // Undefined behavior: d[1] is accessed through both p and q in f }
```

If the object is never modified, it may be aliased and accessed through different restrict-qualified pointers (note that if the objects pointed to by aliased restrict-qualified pointers are, in turn, pointers, this aliasing can inhibit optimization).
如果物件從未被修改，則它可以被別名化並透過不同的 restrict 限定指標訪問（注意，如果被別名化的 restrict 限定指標所指向的物件本身又是指標，這種別名化會抑制最佳化）。
Assignment from one restricted pointer to another is undefined behavior, except when assigning from a pointer to an object in some outer block to a pointer in some inner block (including using a restricted pointer argument when calling a function with a restricted pointer parameter) or when returning from a function (and otherwise when the block of the from-pointer ended):
從一個受限指標向另一個受限指標賦值是未定義行為，除非是從外層塊中指向物件的指標向內層塊中的指標賦值（包括在呼叫具有受限指標參數的函式時使用受限指標實參），或者是從函式傳回時（以及從指標所在塊結束時）：

```c
int* restrict p1 = &a; int* restrict p2 = &b; p1 = p2; // undefined behavior
```

Restricted pointers can be assigned to unrestricted pointers freely, the optimization opportunities remain in place as long as the compiler is able to analyze the code:
受限指標可以自由地賦值給非受限指標，只要編譯器能夠分析程式碼，最佳化機會就依然存在：

```c
void f(int n, float * restrict r, float * restrict s) {  float *p = r, *q = s; // OK  while (n-- > 0)  *p++ = *q++; // almost certainly optimized just like *r++ = *s++ }
```

If an array type is declared with the restrict type qualifier (through the use of typedef), the array type is not restrict-qualified, but its element type is:
|   | (until C23) |

An array type and its element type are always considered to be identically restrict-qualified:
|   | (since C23) |

```c
typedef int *array_t[10]; restrict array_t a; // the type of a is int *restrict[10] // Notes: clang and icc reject this on the grounds that array_t is not a pointer type void *unqual_ptr = &a; // OK until C23; error since C23 // Notes: clang applies the rule in C++/C23 even in C89-C17 modes
```

In a function declaration, the keyword `restrict` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed:
在函式宣告中，關鍵字 restrict 可以出現在用於宣告函式參數陣列型別的方括號內。它限定陣列型別所轉換成的指標型別：

```c
void f(int m, int n, float a[restrict m][n], float b[restrict m][n]); void g12(int n, float (*p)[n]) {  f(10, n, p, p+10); // OK  f(20, n, p, p+10); // possibly undefined behavior (depending on what f does) }
```

### Notes

The intended use of the restrict qualifier (like the register storage class) is to promote optimization, and deleting all instances of the qualifier from all preprocessing translation units composing a conforming program does not change its meaning (i.e., observable behavior).
restrict 限定符的預期用途（與 register 儲存類一樣）是促進最佳化，從構成合規程式的所有預處理翻譯單元中刪除該限定符的所有例項不會改變其含義（即可觀察行為）。
The compiler is free to ignore any or all aliasing implications of uses of `restrict`.
編譯器可以自由忽略 restrict 使用的任何或全部別名含義。
To avoid undefined behavior, the programmer must ensure that the aliasing assertions made by the restrict-qualified pointers are not violated.
為避免未定義行為，程式設計師必須確保不違反 restrict 限定指標所做的別名斷言。
Many compilers provide, as a language extension, the opposite of `restrict`: an attribute indicating that pointers may alias even if their types differ: `may_alias` (gcc),
許多編譯器作為語言擴充套件提供了 restrict 的反面：一個表明指標即使型別不同也可能別名化的屬性：may_alias（gcc），

### Usage patterns

There are several common usage patterns for restrict-qualified pointers:
restrict 限定指標有幾種常見的使用模式：

#### File scope

A file-scope restrict-qualified pointer has to point into a single array object for the duration of the program. That array object may not be referenced both through the restricted pointer and through either its declared name (if it has one) or another restricted pointer.
檔案作用域的 restrict 限定指標在程式執行期間必須指向單個陣列物件。該陣列物件不能同時透過受限指標以及其宣告名稱（如果有的話）或另一個受限指標來引用。
File scope restricted pointers are useful in providing access to dynamically allocated global arrays; the restrict semantics make it possible to optimize references through this pointer as effectively as references to a static array through its declared name:
檔案作用域的受限指標對於訪問動態分配的全域性陣列很有用；restrict 語意使得透過該指標的引用可以像透過宣告名稱引用靜態陣列一樣得到有效最佳化：

```c
float *restrict a, *restrict b; float c[100]; int init(int n) {  float * t = malloc(2*n*sizeof(float));  a = t; // a refers to 1st half  b = t + n; // b refers to 2nd half } // compiler can deduce from the restrict qualifiers that // there is no potential aliasing among the names a, b, and c
```

#### Function parameter

The most popular use case for restrict-qualified pointers is the use as function parameters.
restrict 限定指標最流行的用途是作為函式參數。
In the following example, the compiler may infer that there is no aliasing of modified objects, and so optimize the loop aggressively. Upon entry to `f`, the restricted pointer a must provide exclusive access to its associated array. In particular, within `f` neither `b` nor `c` may point into the array associated with `a`, because neither is assigned a pointer value based on `a`. For `b`, this is evident from the const-qualifier in its declaration, but for `c`, an inspection of the body of `f` is required:
在下面的示例中，編譯器可以推斷被修改的物件沒有別名化，從而積極地最佳化迴圈。 進入 f 時，受限指標 a 必須對其關聯陣列提供獨佔訪問。特別是在 f 內，b 和 c 都不能指向與 a 關聯的陣列，因為它們都沒有被賦予基於 a 的指標值。對於 b，這一點從其宣告中的 const 限定符可以明顯看出，但對於 c，則需要檢查 f 的函式體：

```c
float x[100]; float *c; void f(int n, float * restrict a, float * const b) {  int i;  for ( i=0; i<n; i++ )  a[i] = b[i] + c[i]; } void g3(void) {  float d[100], e[100];  c = x; f(100, d, e); // OK  f( 50, d, d+50); // OK  f( 99, d+1, d); // undefined behavior  c = d; f( 99, d+1, e); // undefined behavior  f( 99, e, d+1); // OK }
```

Note that it is permitted for c to point into the array associated with b. Note also that, for these purposes, the "array" associated with a particular pointer means only that portion of an array object which is actually referenced through that pointer.
注意，允許 c 指向與 b 關聯的陣列。還要注意，就此而言，與特定指標關聯的 "array" 僅指該陣列物件中實際透過該指標引用的部分。
Note that in the example above, the compiler can infer that a and b do not alias because b's constness guarantees that it cannot become dependent on a in the body of the function. Equivalently, the programmer could write `void f(int n, float * a, float const * restrict b)`, in which case the compiler can reason that objects referenced through b cannot be modified, and so no modified object can be referenced using both b and a. If the programmer were to write `void f(int n, float * restrict a, float * b)`, the compiler would be unable to infer non-aliasing of a and b without examining the body of the function.
注意在上面的示例中，編譯器可以推斷 a 和 b 不別名，因為 b 的 const 性保證它在函式體內不能變得依賴於 a。等價地，程式設計師可以寫 void f ( int n , float * a , float const * restrict b )，在這種情況下編譯器可以推斷透過 b 引用的物件不能被修改，因此不會有被修改的物件同時透過 b 和 a 引用。如果程式設計師寫 void f ( int n , float * restrict a , float * b )，編譯器在不檢查函式體的情況下將無法推斷 a 和 b 不別名。
In general, it is best to explicitly annotate all non-aliasing pointers in a function's prototype with `restrict`.
一般來說，最好在函式原型中用 restrict 顯式標註所有不別名化的指標。

#### Block scope

A block scope restrict-qualified pointer makes an aliasing assertion that is limited to its block. It allows local assertions that apply only to important blocks, such as tight loops. It also makes it possible to convert a function that takes restrict-qualified pointers into a macro:
塊作用域的 restrict 限定指標做出的別名斷言僅限於其所在塊。它允許僅適用於重要塊（如緊密迴圈）的區域性斷言。它還使得可以將接受 restrict 限定指標的函式轉換為宏：

```c
float x[100]; float *c; #define f3(N, A, B) \ do \ { int n = (N); \  float * restrict a = (A); \  float * const b = (B); \  int i; \  for ( i=0; i<n; i++ ) \  a[i] = b[i] + c[i]; \ } while(0)
```

#### Struct members

The scope of the aliasing assertion made by a restrict-qualified pointer that is a member of a struct is the scope of the identifier used to access the struct.
作為 struct 成員的 restrict 限定指標所做的別名斷言的作用域，是用於訪問該 struct 的識別符號的作用域。
Even if the struct is declared at file scope, when the identifier used to access the struct has block scope, the aliasing assertions in the struct also have block scope; the aliasing assertions are only in effect within a block execution or a function call, depending on how the object of this struct type was created:
即使 struct 宣告在檔案作用域，當用於訪問該 struct 的識別符號具有塊作用域時，struct 中的別名斷言也具有塊作用域；別名斷言僅在塊執行或函式呼叫期間生效，具體取決於該 struct 型別物件的建立方式：

```c
struct t // Restricted pointers assert that {  int n; // members point to disjoint storage.  float * restrict p;  float * restrict q; }; void ff(struct t r, struct t s) {  struct t u;  // r,s,u have block scope  // r.p, r.q, s.p, s.q, u.p, u.q should all point to  // disjoint storage during each execution of ff.  // ... }
```

### Keywords

restrict

### Example

code generation example; compile with -S (gcc, clang, etc) or /FA (visual studio)
程式碼生成示例；使用 -S（gcc、clang 等）或 /FA（visual studio）編譯

```c
int foo(int *a, int *b) {  *a = 5;  *b = 6;  return *a + *b; } int rfoo(int *restrict a, int *restrict b) {  *a = 5;  *b = 6;  return *a + *b; }
```

Possible output:
可能的輸出：

```c
; generated code on 64bit Intel platform: foo:  movl $5, (%rdi) ; store 5 in *a  movl $6, (%rsi) ; store 6 in *b  movl (%rdi), %eax ; read back from *a in case previous store modified it  addl $6, %eax ; add 6 to the value read from *a  ret rfoo:  movl $11, %eax ; the result is 11, a compile-time constant  movl $5, (%rdi) ; store 5 in *a  movl $6, (%rsi) ; store 6 in *b  ret
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.3.1 Formal definition of restrict (p: TBD)
6.7.3.1 restrict 的形式定義 (p: TBD)
6.7.3.1 restrict 的形式定義 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.3.1 Formal definition of restrict (p: 89-90)
6.7.3.1 restrict 的形式定義 (p: 89-90)
6.7.3.1 restrict 的形式定義 (p: 89-90)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.3.1 Formal definition of restrict (p: 123-125)
6.7.3.1 restrict 的形式定義 (p: 123-125)
6.7.3.1 restrict 的形式定義 (p: 123-125)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.3.1 Formal definition of restrict (p: 110-112)
6.7.3.1 restrict 的形式定義 (p: 110-112)
6.7.3.1 restrict 的形式定義 (p: 110-112)

---
來源頁路徑：`en.cppreference.com/c/language/restrict.html`

# C attribute: unsequenced, reproducible (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Provides the compiler with information about the access of objects by a function such that certain properties of function calls can be deduced.
向編譯器提供有關函式訪問物件的資訊，以便推斷函式呼叫的某些屬性。

### Syntax

|   |

| `**[[**` `**unsequenced**` `**]]**`
`**[[**` `**__unsequenced__**` `**]]**`  |   | (1)  |   |   |

|   |

| `**[[**` `**reproducible**` `**]]**`
`**[[**` `**__reproducible__**` `**]]**`  |   | (2)  |   |   |

|   |

1) Indicates that a function is effectless, idempotent, stateless, and independent.

2) Indicates that a function is effectless and idempotent.

### Explanation

These attributes apply to a function declarator or to a type specifier that has a function type. The corresponding attribute is a property of the function type.
這些屬性適用於函式宣告符或具有函式型別的型別說明符。相應的屬性是函式型別的屬性。

#### Effectless

An evaluation of a function call is effectless if any store operation that is sequenced during the call is the modification of an object that synchronizes with the call; if additionally the operation is observable, all access to the object must be based on a unique pointer parameter of the function.
如果函式呼叫期間按序發生的任何儲存 操作都是與呼叫同步的物件的修改，則該函式呼叫的求值是無副作用的；此外，如果該操作是可觀察的，則對物件的所有訪問必須基於函式的唯一指標參數。

#### Idempotent

An evaluation E is idempotent if a second evaluation of E can be sequenced immediately after the original one without changing the resulting value, if any, or the observable state of the execution.
如果對 E 的第二次求值可以緊接在原始求值之後按序進行而不改變結果值（如果有）或執行的可觀察狀態，則求值 E 是冪等的。

#### Stateless

A function F is stateless if any definition of an object of static or thread storage duration in F or in a function that is called by F is `const` but not `volatile` qualified.
如果 F 中或被 F 呼叫的函式中任何靜態或執行緒儲存期物件的定義是 const 而非 volatile 限定的，則函式 F 是無狀態的。

#### Independent

A function F is independent if for any object X that is observed by a call to F through an lvalue that is not based on a parameter of the call, all accesses to X in all calls to F during the same program execution observe the same value; otherwise if the access is based on a pointer parameter, there shall be a unique such pointer parameter P such that any access to X shall be to an lvalue that is based on P.
如果對於透過不基於呼叫參數的左值被對 F 的呼叫觀察到的任何物件 X，在同一程式執行期間對 F 的所有呼叫中對 X 的所有訪問都觀察到相同的值； 否則，如果訪問基於指標參數，則應存在唯一的此類指標參數 P ，使得對 X 的任何訪問都應基於 P 的左值。
An object X is observed by a function call if both synchronize, if X is not local to the call, if X has a lifetime that starts before the function call, and if an access of X is sequenced during the call; the last value of X, if any, that is stored before the call is said to be the value of X that is observed by the call.
如果兩者同步、X 不是呼叫區域性的、X 的生命週期在函式呼叫之前開始、且對 X 的訪問在呼叫期間按序發生，則物件 X 被函式呼叫觀察到；呼叫之前儲存的 X 的最後一個值（如果有）稱為呼叫觀察到的 X 的值。

### Notes

These attributes exist for the purpose of compiler optimization.
這些屬性是為了編譯器最佳化而存在的。
If a function is reproducible, multiple subsequent calls can be treated as a single call.
如果函式是可重現的，多次後續呼叫可以視為單次呼叫。
If a function is unsequenced, multiple subsequent calls can be treated as a single call, and the calls can be parallelized and reordered arbitrarily.
如果函式是無序的，多次後續呼叫可以視為單次呼叫，並且這些呼叫可以並行化和任意重排。

---
來源頁路徑：`en.cppreference.com/c/language/attributes/reproducible.html`

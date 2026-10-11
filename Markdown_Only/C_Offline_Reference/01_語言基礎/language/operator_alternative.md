# Alternative operators and tokens

> 來源：cppreference C 語言參考文件（離線轉換版）。

C source code may be written in any 8-bit character set that includes the ISO 646:1983 invariant character set, even non-ASCII ones. However, several C operators and punctuators require characters that are outside of the ISO 646 codeset: `{, }, [, ], #, \, ^, |, ~`. To be able to use character encodings where some or all of these symbols do not exist (such as the German DIN 66003), there are two possibilities: alternative spellings of operators that use these characters or special combinations of two or three ISO 646 compatible characters that are interpreted as if they were a single non-ISO 646 character.
C 原始碼可以用任何包含 ISO 646:1983 不變字符集的 8 位字符集書寫，甚至包括非 ASCII 字符集。然而，若干 C 運運算元和標點符號需要 ISO 646 字符集之外的字元：{, }, [, ], #, \, ^, |, ~。為了能夠使用某些或全部符號不存在的字元編碼（如德國 DIN 66003），有兩種可能：使用這些字元的運運算元的替代拼寫，或兩個或三個 ISO 646 相容字元的特殊組合，其解釋方式如同單個非 ISO 646 字元。

## Operator macros (C95)
運運算元宏（C95）

There are alternative spellings for the operators that use non-ISO646 characters, defined in <iso646.h> as macros:
對於使用非 ISO 646 字元的運運算元，存在替代拼寫，在 <iso646.h> 中定義為宏：

Defined in header `<iso646.h>`

| Primary  |   | Alternative  |

`&&`
|   | `and`
(operator macro)  |

`&=`
|   | `and_eq`
(operator macro)  |

`&`
|   | `bitand`
(operator macro)  |

`|`
|   | `bitor`
(operator macro)  |

`~`
|   | `compl`
(operator macro)  |

`!`
|   | `not`
(operator macro)  |

`!=`
|   | `not_eq`
(operator macro)  |

`||`
|   | `or`
(operator macro)  |

`|=`
|   | `or_eq`
(operator macro)  |

`^`
|   | `xor`
(operator macro)  |

`^=`
|   | `xor_eq`
(operator macro)  |

The characters `&` and `!` are invariant under ISO-646, but alternatives are provided for the operators that use these characters anyway to accommodate even more restrictive historical charsets.
字元 & 和 ! 在 ISO 646 下是不變的，但為使用這些字元的運運算元仍提供了替代形式，以適應更受限的歷史字符集。
There is no alternative spelling (such as `eq`) for the equality operator `==` because the character `=` was present in all supported charsets.
相等運運算元 == 沒有替代拼寫（如 eq），因為字元 = 存在於所有受支援的字符集中。

## Alternative tokens (C95)
替代記號（C95）

The following alternative tokens are part of the core language, and, in all respects of the language, each alternative token behaves exactly the same as its primary token, except for its spelling (the stringification operator can make the spelling visible). The two-letter alternative tokens are sometimes called "digraphs" (even though it is four letters long `%:%:` is also considered a digraph).
以下替代記號是核心語言的一部分，並且在語言的各個方面，每個替代記號的行為與其主記號完全相同，只是拼寫不同（字串化運運算元可以使拼寫可見）。雙字母替代記號有時稱為 "digraphs"（儘管四字母長的 %:%: 也被視為 digraph）。

| Primary  |   | Alternative  |

| `{` |   | `<%`  |

| ``} |   | `%>`  |

| `[` |   | `<:`  |

| `]` |   | `:>`  |

| `#` |   | `%:`  |

| `##` |   | `%:%:`  |

## Trigraphs (removed in C23)
三字圖形符（在 C23 中移除）

The following three-character groups (trigraphs) are parsed before comments and string literals are recognized, and each appearance of a trigraph is replaced by the corresponding primary character:
以下三字元組（三字圖形符）在註釋和字串字面量被識別之前解析，每個三字圖形符的出現都被替換為對應的主字元：

| Primary  |   | Trigraph  |

| `{` |   | `??<`  |

| ``} |   | `??>`  |

| `[` |   | `??(`  |

| `]` |   | `??)`  |

| `#` |   | `??=`  |

| `\` |   | `??/`  |

| `^` |   | `??'`  |

| `|` |   | `??!`  |

| `~` |   | `??-`  |

Because trigraphs are processed early, a comment such as `// Will the next line be executed?????/` will effectively comment out the following line, and the string literal such as `"What's going on??!"` is parsed as `"What's going on|"`.
由於三字圖形符處理得早，像 // Will the next line be executed?????/ 這樣的註釋實際上會註釋掉下一行，而像 "What's going on??!" 這樣的字串字面量會被解析為 "What's going on|"。

### Example

Demonstrates alternative operator spellings from the <iso646.h> as well as use of digraphs and trigraphs. If command line arguments contain spaces they should be wrapped in the quotation marks, e.g., `"Third World!"`.
演示 <iso646.h> 中的替代運運算元拼寫以及 digraph 和 trigraph 的用法。 如果命令列參數包含空格，應將其用引號括起來，例如 "Third World!"。
Run this code

```c
%:include <stdio.h> %:include <stdlib.h> ??=include <iso646.h>   int main(int argc, char** argv) ??<  if (argc > 1 and argv<:1:> not_eq NULL)  <%  printf("Hello %s??/n", argv<:1:>);  %>  else  <%  printf("Hello %s??/n", argc? argv??(42??'42??) : __FILE__);  %>    return EXIT_SUCCESS; ??>
```

Possible output:
可能的輸出：

```c
Hello ./a.out
```

### See also

C++ documentation for Alternative operator representations

---
來源頁路徑：`en.cppreference.com/c/language/operator_alternative.html`

# Character sets and encodings

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Basic character set
基本字符集

The *basic character set* consists of the following 95 characters:
基本字符集由以下 95 個字元組成：

| Code unit |   | Character |   | Glyph  |

| U+0009 |   | Character tabulation |   |   |

| U+000B |   | Line tabulation |   |   |

| U+000C |   | Form feed (FF) |   |   |

| U+0020 |   | Space |   |   |

| U+0021 |   | Exclamation mark |   | `**!**`  |

| U+0022 |   | Quotation mark |   | `**"**`  |

| U+0023 |   | Number sign |   | `**#**`  |

| U+0025 |   | Percent sign |   | `**%**`  |

| U+0026 |   | Ampersand |   | `**&**`  |

| U+0027 |   | Apostrophe |   | `**'**`  |

| U+0028 |   | Left parenthesis |   | `**(**`  |

| U+0029 |   | Right parenthesis |   | `**)**`  |

| U+002A |   | Asterisk |   | `*****`  |

| U+002B |   | Plus sign |   | `**+**`  |

| U+002C |   | Comma |   | `**,**`  |

| U+002D |   | Hyphen-minus |   | `**-**`  |

| U+002E |   | Full stop |   | `**.**`  |

| U+002F |   | Solidus |   | `**/**`  |

| U+0030 .. U+0039 |   | Digit zero .. nine |   | `**0 1 2 3 4 5 6 7 8 9**`  |

| U+003A |   | Colon |   | `**:**`  |

| U+003B |   | Semicolon |   | `**;**`  |

| U+003C |   | Less-than sign |   | `**<**`  |

| U+003D |   | Equals sign |   | `**=**`  |

| U+003E |   | Greater-than sign |   | `**>**`  |

| U+003F |   | Question mark |   | `**?**`  |

| U+0041 .. U+005A |   | Latin capital letter A .. Z |   | `**A B C D E F G H I J K L M**`
`**N O P Q R S T U V W X Y Z**`

| U+005B |   | Left square bracket |   | `**[**`  |

| U+005C |   | Reverse solidus |   | `**\**`  |

| U+005D |   | Right square bracket |   | `**]**`  |

| U+005E |   | Circumflex accent |   | `**^**`  |

| U+005F |   | Low line |   | `**_**`  |

| U+0061 .. U+007A |   | Latin small letter a .. z |   | `**a b c d e f g h i j k l m**`
`**n o p q r s t u v w x y z**`

| U+007B |   | Left curly bracket |   | `**{**`  |

| U+007C |   | Vertical line |   | `**|**`  |

| U+007D |   | Right curly bracket |   | `**}**`  |

| U+007E |   | Tilde |   | `**~**`  |

Unlike C++, the U+000A LINE FEED (LF) character is not included in basic character set. Instead, there shall be some way of indicating the end of each line of text in the source file and the document treats such an end-of-line indicator as if it were a single new-line character.
與 C++ 不同，U+000A LINE FEED (LF) 字元不包含在基本字符集中。相反，必須有某種方式來指示原始檔中每行文字的結束，檔案將這種行結束指示符視為單個換行符。
Basic character set is also known as *basic source character set*.
基本字符集也稱為基本源字符集。

### Basic execution character set
基本執行字符集

The *basic execution character set* contains all the members of the basic character set, plus the following characters:
基本執行字符集包含基本字符集的所有成員，以及以下字元：

| Code unit |   | Character  |

| U+0000 |   | Null  |

| U+0007 |   | Bell  |

| U+0008 |   | Backspace  |

| U+000A |   | Line feed (LF)  |

| U+000D |   | Carriage return (CR)  |

For each basic execution character set, the values of the members shall be non-negative and distinct from one another. In both the source and execution basic character sets, the value of each character after 0 in the above list of decimal digits shall be one greater than the value of the previous. The U+0000 NULL character has the value 0.
對於每個基本執行字符集，成員的值應為非負且互不相同。在源基本字符集和執行基本字符集中，在上述十進位制數字列表中，0 之後的每個字元的值應比前一個字元的值大 1。U+0000 NULL 字元的值為 0。
The representation of each member of the basic execution character sets fit in a byte.
基本執行字符集中每個成員的表示都適合一個位元組。
In C++, basic execution character set is also known as *basic literal character set* and *basic execution wide-character set*.
在 C++ 中，基本執行字符集也稱為基本字面量字符集和基本執行寬字符集。

### Literal encodings
字面量編碼

The *literal encoding* is an implementation-defined mapping of the characters of the execution character set to the values in a character constant or string literal without encoding prefix. It supports a mapping from all the basic execution character set values into the implementation-defined encoding. It may contain multibyte character sequences.
字面量編碼是執行字符集字元到無編碼字首的字元常量或字串字面量中的值的實現定義對映。它支援從所有基本執行字符集值到實現定義編碼的對映。它可以包含多位元組字元序列。

The following characters are not in basic execution character set, but they are required to be encoded as a single byte in an ordinary character constant or ordinary string literal.

| Code unit |   | Character |   | Glyph  |

| U+0024 |   | Dollar Sign |   | `**$**`  |

| U+0040 |   | Commercial At |   | `**@**`  |

| U+0060 |   | Grave Accent |   | `**`**`  |
|   | (since C23) |

The *wide literal encoding* is an implementation-defined mapping of the characters of the execution character set to the values in an `L`-prefixed character constant or string literal. It supports a mapping from all the basic execution character set values into the implementation-defined encoding. If an implementation does not define `__STDC_MB_MIGHT_NEQ_WC__`, the mapping produces values identical to the literal encoding for all the basic execution character set values. One or more values may map to one or more values of the extended execution character set.
寬字面量編碼是執行字符集字元到 L 字首字元常量或字串字面量中的值的實現定義對映。它支援從所有基本執行字符集值到實現定義編碼的對映。如果實現未定義 __STDC_MB_MIGHT_NEQ_WC__ ，則該對映對所有基本執行字符集值產生與字面量編碼相同的值。一個或多個值可以對映到擴充套件執行字符集的一個或多個值。

The UTF-8 encoding is used for mapping characters of the execution character set to a `u8`-prefixed character constant or(since C23) string literal.
An implementation-defined encoding(until C23)The UTF-16 encoding(since C23) is used for mapping characters of the execution character set to a `u`-prefixed character constant or string literal.
An implementation-defined encoding(until C23)The UTF-32 encoding(since C23) is used for mapping characters of the execution character set to a `U`-prefixed character constant or string literal.
|   | (since C11) |

### See also

| ASCII chart  |

C++ documentation for Character sets and encodings

---
來源頁路徑：`en.cppreference.com/c/language/charset.html`

# Basic concepts

> 來源：cppreference C 語言參考文件（離線轉換版）。

This section provides definitions for the specific terminology and the concepts used when describing the C programming language.
本節為描述 C 程式語言時所使用的特定術語和概念提供定義。
A C program is a sequence of text files (typically header and source files) that contain declarations. They undergo translation to become an executable program, which is executed when the OS calls its main function (unless it is itself the OS or another *freestanding* program, in which case the entry point is implementation-defined).
C 程式由一系列文字檔組成，通常包含標頭檔與原始碼檔。這些檔案經過翻譯後成為可執行程式；作業系統呼叫其 main 函式時，程式便開始執行。（若程式本身是作業系統或其他獨立程式，進入點則由實作定義。）
Certain words in a C program have special meaning, they are keywords. Others can be used as identifiers, which may be used to identify objects, functions, struct, union, or enumeration tags, their members, typedef names, labels, or macros.
C 程式中的某些字有特殊意義，稱為關鍵字。其他字可以作為識別字，用來命名物件、函式、結構、聯合、列舉標籤及其成員、typedef 名稱、標籤或巨集。
Each identifier (other than macro) is only valid within a part of the program called its scope and belongs to one of four kinds of name spaces. Some identifiers have linkage which makes them refer to the same entities when they appear in different scopes or translation units.
每個識別字（巨集除外）只在稱為作用域的程式區域內有效，並且屬於四種名稱空間之一。有些識別字具有連結性，因此即使出現在不同作用域或翻譯單元，也會指向同一個實體。
Definitions of functions include sequences of statements and declarations, some of which include expressions, which specify the computations to be performed by the program.
函式的定義包含陳述式和宣告的序列，其中一些包含表示式，用於指定程式要執行的計算。
Declarations and expressions create, destroy, access, and manipulate objects. Each object, function, and expression in C is associated with a type.
宣告和表示式建立、銷燬、訪問並操作物件。C 中的每個物件、函式和表示式都與一種型別相關聯。

### See also

C++ documentation for Basic concepts

---
來源頁路徑：`en.cppreference.com/c/language/basic_concepts.html`

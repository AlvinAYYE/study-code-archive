# 工具函式庫

> 來源：cppreference C 語言參考文件（離線轉換版）。

C includes a variety of utility libraries. These libraries can be broadly divided into two groups:
C 標準函式庫提供多種工具，可概分為兩類：

- language support libraries, and
語言支援函式庫：配合語言本身的型別與功能使用；以及

- general-purpose libraries.
通用函式庫：提供程式各處都可能用到的常見功能。

## Language support
語言支援

Language support libraries provide functions that interact closely with language features and support common language idioms.
語言支援函式庫提供與 C 語言特性密切相關的功能，也涵蓋常見的程式寫法。

### Type support

Basic types (e.g. size_t, NULL)
基本型別（例如 size_t 、 NULL ）

### Dynamic memory management
動態記憶體管理

(e.g. malloc)

### Error handling

Assertions (e.g. assert)
斷言（例如 assert ）

### Variadic functions
可變參數函式

Support for functions that take an arbitrary number of parameters (via e.g. va_start, va_arg, va_end)
支援可接受不定數量引數的函式，例如使用 `va_start`、`va_arg` 和 `va_end`。

## General-purpose utilities
通用工具

###  Program utilities
程式工具

Termination (e.g. abort, atexit), environment (e.g. system), signals (e.g. raise)
包含程式終止（如 `abort`、`atexit`）、與執行環境互動（如 `system`），以及訊號處理（如 `raise`）。

### Date and time

Time tracking (e.g. time, clock)
例如用 `time` 取得日曆時間，或用 `clock` 取得處理器時間。

### See also

C++ documentation for Utility library

---
來源頁路徑：`en.cppreference.com/c/utility.html`

# Thread storage duration

> 來源：cppreference C 語言參考文件（離線轉換版）。

An object whose identifier is declared with the storage-class specifier `_Thread_local` (since C11) has thread storage duration. Its lifetime is the entire execution of the thread for which it is created, and its stored value is initialized when the thread is started. There is a distinct object per thread, and use of the declared name in an expression refers to the object associated with the thread evaluating the expression. The result of attempting to indirectly access an object with thread storage duration from a thread other than the one with which the object is associated is implementation-defined.
識別符號用儲存類說明符 _Thread_local（自 C11 起）宣告的物件具有執行緒儲存期。其生命期是為其建立的執行緒的整個執行過程，其儲存的值線上程啟動時初始化。每個執行緒有一個獨立的物件，在表示式中使用宣告的名稱指的是與求值該表示式的執行緒相關聯的物件。試圖從與該物件不關聯的執行緒間接訪問具有執行緒儲存期的物件，其結果是實現定義的。

### Example

Run this code

```c
const double PI = 3.14159; /* const variable is global to all threads */ _Thread_local unsigned int seed; /* seed is a thread-specific variable */   int main(void) {  return 0; }
```

Possible output:
可能的輸出：

```c
(none)
```

---
來源頁路徑：`en.cppreference.com/c/language/thread_storage_duration.html`

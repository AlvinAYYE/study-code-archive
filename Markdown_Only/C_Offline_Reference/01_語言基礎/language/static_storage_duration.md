# Static storage duration

> 來源：cppreference C 語言參考文件（離線轉換版）。

An object whose identifier is declared without the storage-class specifier `_Thread_local`, and either with external or internal linkage or with the storage-class specifier `static`, has static storage duration. Its lifetime is the entire execution of the program and its stored value is initialized only once, prior to program startup.
識別符號宣告時沒有儲存類說明符 _Thread_local，並且要麼具有外部或內部連結，要麼具有儲存類說明符 static 的物件，具有靜態儲存持續時間。其生存期是程式的整個執行過程，其儲存的值僅在程式啟動之前初始化一次。

### Notes

Since its stored value is initialized only once, an object with static storage duration can profile the invocations of a function.
由於其儲存的值僅初始化一次，具有靜態儲存持續時間的物件可以對函式的呼叫情況進行效能分析。
The other use of the keyword `static` is file scope.
關鍵字 static 的另一個用途是檔案作用域。

### Example

Run this code

```c
#include <stdio.h> void f (void) {  static int count = 0; // static variable   int i = 0; // automatic variable  printf("%d %d\n", i++, count++); } int main(void) {  for (int ndx=0; ndx<10; ++ndx)  f(); }
```

Output:

```c
0 0 0 1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9
```

---
來源頁路徑：`en.cppreference.com/c/language/static_storage_duration.html`

# ungetwc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t ungetwc( wint_t ch, FILE *stream );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

If `ch` does not equal WEOF, pushes the wide character `ch` into the input buffer associated with the stream `stream` in such a manner that subsequent read operation from `stream` will retrieve that wide character. The external device associated with the stream is not modified.
如果 ch 不等於 WEOF ，則將寬字元 ch 推入與流 stream 關聯的輸入緩衝區，使得隨後從 stream 進行的讀取操作能夠取回該寬字元。與該流關聯的外部裝置不會被修改。
Stream repositioning operations fseek, fsetpos, and rewind discard the effects of `ungetwc`.
流重定位操作 fseek 、 fsetpos 和 rewind 會丟棄 ungetwc 的效果。
If `ungetwc` is called more than once without an intervening read or repositioning, it may fail (in other words, a pushback buffer of size 1 is guaranteed, but any larger buffer is implementation-defined). If multiple successful `ungetwc` were performed, read operations retrieve the pushed-back wide characters in reverse order of `ungetwc`
如果在沒有插入讀取或重定位操作的情況下多次呼叫 ungetwc ，該呼叫可能會失敗（換句話說，保證有大小為 1 的回推緩衝區，但更大的緩衝區由實現定義）。如果執行了多次成功的 ungetwc ，讀取操作會以與 ungetwc 相反的順序取回被回推的寬字元
If `ch` equals WEOF, the operation fails and the stream is not affected.
如果 ch 等於 WEOF ，操作失敗且流不受影響。
A successful call to `ungetwc` clears the end of file status flag feof.
成功呼叫 ungetwc 會清除檔案結束狀態標誌 feof 。
A successful call to `ungetwc` on a stream (whether text or binary) modifies the stream position indicator in unspecified manner but guarantees that after all pushed-back wide characters are retrieved with a read operation, the stream position indicator is equal to its value before `ungetwc`.
在流（無論是文字還是二進位制）上成功呼叫 ungetwc 會以未指定的方式修改流位置指示器，但保證在所有被回推的寬字元透過讀取操作取回之後，流位置指示器等於呼叫 ungetwc 之前的值。

### Parameters

| ch  |   | -  |   | wide character to be put back  |

| stream  |   | -  |   | file stream to put the wide character back to  |

### Return value

On success `ch` is returned.
成功時傳回 ch。
On failure `WEOF` is returned and the given stream remains unchanged.
失敗時傳回 WEOF ，給定的流保持不變。

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.10 The ungetwc function (p: 425-426)
7.29.3.10 ungetwc 函式（p: 425-426）
7.29.3.10 ungetwc 函式（p: 425-426）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.10 The ungetwc function (p: 370-371)
7.24.3.10 ungetwc 函式（p: 370-371）
7.24.3.10 ungetwc 函式（p: 370-371）

### See also

ungetc
|   | puts a character back into a file stream
(function)   |

fgetwcgetwc
(C95)
|   | gets a wide character from a file stream
(function)   |

C++ documentation for ungetwc

---
來源頁路徑：`en.cppreference.com/c/io/ungetwc.html`

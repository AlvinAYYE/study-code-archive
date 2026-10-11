# Dynamic memory management

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Functions

Defined in header `<stdlib.h>`

malloc
|   | 配置指定大小的記憶體
(function)   |

calloc
|   | 配置記憶體，並將內容初始化為 0
(function)   |

realloc
|   | 調整先前配置的記憶體區塊大小
(function)   |

free
|   | 釋放先前配置的記憶體
(function)   |

free_sized
(C23)
|   | 釋放先前配置的記憶體，並由呼叫端提供區塊大小
(function)   |

free_aligned_sized
(C23)
|   | 釋放先前配置且具指定對齊方式的記憶體
(function)   |

aligned_alloc
(C11)
|   | 配置符合指定對齊要求的記憶體
(function)   |

memalignment
(C23)
|   | 查詢指定位址符合的最大對齊值
(function)   |

### See also

C++ documentation for C memory management library

---
來源頁路徑：`en.cppreference.com/c/memory.html`

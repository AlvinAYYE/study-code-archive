# UVa Online Judge C 題庫

收錄 217 份 C 題目檔，分布於 39 個 `volume` 資料夾。每題的卷別 `README.md` 都有英文題名與描述、繁體中文題名與詳細描述、涵蓋的演算法，以及原始碼連結。

## 如何找題目

1. **知道題號或題名**：開啟 [題目總索引](INDEX.md)，搜尋英文或中文題名，並點選詳細題意或原始碼。
2. **只記得題意片段**：開啟 [完整雙語索引](INDEX.tsv)，搜尋英文或中文描述。TSV 可用文字編輯器開啟，亦可用試算表依欄位篩選。
3. **想依演算法練習**：開啟 [演算法主題索引](TOPICS.md)，尋找 `dynamic-programming`、`graph`、`string` 等標籤，再點選題目說明。
4. **想依 UVa 分卷瀏覽**：使用下方卷別目錄；各卷 README 收錄每題完整介紹及相對路徑連結。

所有連結均為相對路徑，可在本機離線瀏覽。

## 卷別目錄

| 分卷 | 題數 | 收錄題號 |
| --- | ---: | --- |
| [volume001](volume001/README.md) | 13 | 100–160 |
| [volume002](volume002/README.md) | 5 | 256–299 |
| [volume003](volume003/README.md) | 5 | 350–389 |
| [volume004](volume004/README.md) | 12 | 401–499 |
| [volume005](volume005/README.md) | 11 | 530–591 |
| [volume006](volume006/README.md) | 6 | 621–694 |
| [volume008](volume008/README.md) | 1 | 847 |
| [volume013](volume013/README.md) | 1 | 1368 |
| [volume015](volume015/README.md) | 1 | 1585 |
| [volume100](volume100/README.md) | 49 | 10000–10099 |
| [volume101](volume101/README.md) | 23 | 10101–10193 |
| [volume102](volume102/README.md) | 14 | 10200–10282 |
| [volume103](volume103/README.md) | 8 | 10300–10370 |
| [volume104](volume104/README.md) | 5 | 10409–10499 |
| [volume105](volume105/README.md) | 2 | 10550–10591 |
| [volume106](volume106/README.md) | 3 | 10608–10696 |
| [volume107](volume107/README.md) | 2 | 10783–10784 |
| [volume108](volume108/README.md) | 4 | 10810–10878 |
| [volume109](volume109/README.md) | 7 | 10908–10954 |
| [volume110](volume110/README.md) | 3 | 11005–11063 |
| [volume111](volume111/README.md) | 3 | 11150–11185 |
| [volume113](volume113/README.md) | 2 | 11332–11349 |
| [volume114](volume114/README.md) | 5 | 11417–11498 |
| [volume115](volume115/README.md) | 2 | 11547–11584 |
| [volume117](volume117/README.md) | 4 | 11727–11799 |
| [volume118](volume118/README.md) | 1 | 11854 |
| [volume119](volume119/README.md) | 1 | 11984 |
| [volume120](volume120/README.md) | 1 | 12015 |
| [volume121](volume121/README.md) | 1 | 12149 |
| [volume122](volume122/README.md) | 3 | 12250–12289 |
| [volume124](volume124/README.md) | 2 | 12403–12468 |
| [volume125](volume125/README.md) | 3 | 12577–12592 |
| [volume126](volume126/README.md) | 3 | 12602–12696 |
| [volume127](volume127/README.md) | 2 | 12700–12709 |
| [volume128](volume128/README.md) | 1 | 12820 |
| [volume129](volume129/README.md) | 2 | 12908–12918 |
| [volume130](volume130/README.md) | 2 | 13012–13034 |
| [volume131](volume131/README.md) | 2 | 13178–13185 |
| [volume132](volume132/README.md) | 2 | 13216–13275 |

## 索引說明

- `volume100` 收錄 UVa 10069 的兩種 C 解法：二維 DP 與一維滾動 DP，可直接比較空間用量。
- 索引建置會檢查每個 C 檔都有對應題目、英中描述、演算法範圍與有效連結。

## 編譯範例

在儲存庫根目錄使用 GCC 編譯單題，例如：

```powershell
gcc -std=c11 -O2 UVa-c/volume001/100_the-3n-plus-1-problem.c -o uva100.exe
.\uva100.exe
```

## 更新索引

新增 C 題目檔後，先在對應卷別 README 補上雙語題意和演算法，再執行 `python UVa-c/build_index.py`。腳本會檢查每個 `.c` 是否都有對應條目，並更新本頁、`INDEX.md`、`INDEX.tsv`、`TOPICS.md`。

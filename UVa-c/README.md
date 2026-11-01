# UVa Online Judge C 題庫

收錄 1116 份 C 解答，涵蓋 1024 個不同 UVa 題號，分布於 48 個 `volume` 資料夾。每題的卷別 `README.md` 都有英文題名與描述、繁體中文題名與詳細描述、難度、涵蓋的演算法，以及原始碼連結。

## 如何找題目

1. **知道題號或題名**：開啟 [題目總索引](INDEX.md)，搜尋英文或中文題名，並點選詳細題意或原始碼。
2. **只記得題意片段**：開啟 [完整雙語索引](INDEX.tsv)，搜尋英文或中文描述。TSV 可用文字編輯器開啟，亦可用試算表依欄位篩選。
3. **想依演算法練習**：開啟 [演算法主題索引](TOPICS.md)，尋找 `dynamic-programming`、`graph`、`string` 等標籤，再點選題目說明。
4. **想依 UVa 分卷瀏覽**：使用下方卷別目錄；各卷 README 收錄每題完整介紹及相對路徑連結。

所有連結均為相對路徑，可在本機離線瀏覽。

## 卷別目錄

| 分卷 | UVa 題號數 | C 解答數 | 收錄題號 |
| --- | ---: | ---: | --- |
| [volume001](volume001/README.md) | 96 | 102 | 100–196 |
| [volume002](volume002/README.md) | 30 | 30 | 200–299 |
| [volume003](volume003/README.md) | 38 | 38 | 300–394 |
| [volume004](volume004/README.md) | 58 | 65 | 400–499 |
| [volume005](volume005/README.md) | 40 | 41 | 501–599 |
| [volume006](volume006/README.md) | 29 | 35 | 608–699 |
| [volume007](volume007/README.md) | 27 | 27 | 700–796 |
| [volume008](volume008/README.md) | 20 | 20 | 815–895 |
| [volume009](volume009/README.md) | 16 | 16 | 900–993 |
| [volume010](volume010/README.md) | 4 | 4 | 1001–1062 |
| [volume011](volume011/README.md) | 9 | 9 | 1103–1197 |
| [volume012](volume012/README.md) | 7 | 7 | 1203–1260 |
| [volume013](volume013/README.md) | 4 | 4 | 1316–1395 |
| [volume015](volume015/README.md) | 7 | 7 | 1583–1594 |
| [volume016](volume016/README.md) | 1 | 1 | 1644 |
| [volume100](volume100/README.md) | 62 | 73 | 10000–10099 |
| [volume101](volume101/README.md) | 54 | 60 | 10100–10199 |
| [volume102](volume102/README.md) | 40 | 44 | 10200–10299 |
| [volume103](volume103/README.md) | 41 | 45 | 10300–10397 |
| [volume104](volume104/README.md) | 31 | 35 | 10400–10499 |
| [volume105](volume105/README.md) | 22 | 24 | 10502–10591 |
| [volume106](volume106/README.md) | 29 | 30 | 10600–10699 |
| [volume107](volume107/README.md) | 19 | 21 | 10700–10791 |
| [volume108](volume108/README.md) | 23 | 26 | 10800–10895 |
| [volume109](volume109/README.md) | 34 | 39 | 10901–10994 |
| [volume110](volume110/README.md) | 23 | 23 | 11000–11094 |
| [volume111](volume111/README.md) | 15 | 18 | 11100–11195 |
| [volume112](volume112/README.md) | 17 | 17 | 11219–11292 |
| [volume113](volume113/README.md) | 20 | 21 | 11300–11396 |
| [volume114](volume114/README.md) | 27 | 30 | 11401–11498 |
| [volume115](volume115/README.md) | 25 | 26 | 11503–11597 |
| [volume116](volume116/README.md) | 18 | 18 | 11608–11690 |
| [volume117](volume117/README.md) | 20 | 22 | 11703–11799 |
| [volume118](volume118/README.md) | 16 | 17 | 11804–11889 |
| [volume119](volume119/README.md) | 21 | 21 | 11900–11997 |
| [volume120](volume120/README.md) | 7 | 7 | 12004–12096 |
| [volume121](volume121/README.md) | 9 | 9 | 12100–12195 |
| [volume122](volume122/README.md) | 7 | 9 | 12207–12289 |
| [volume123](volume123/README.md) | 4 | 4 | 12342–12372 |
| [volume124](volume124/README.md) | 8 | 10 | 12403–12478 |
| [volume125](volume125/README.md) | 12 | 15 | 12502–12592 |
| [volume126](volume126/README.md) | 8 | 10 | 12602–12696 |
| [volume127](volume127/README.md) | 4 | 6 | 12700–12798 |
| [volume128](volume128/README.md) | 4 | 5 | 12820–12895 |
| [volume129](volume129/README.md) | 4 | 6 | 12908–12996 |
| [volume130](volume130/README.md) | 4 | 6 | 13012–13059 |
| [volume131](volume131/README.md) | 6 | 7 | 13109–13190 |
| [volume132](volume132/README.md) | 4 | 6 | 13216–13279 |

## 索引說明

- `volume100` 收錄 UVa 10069 的兩種 C 解法：二維 DP 與一維滾動 DP，可直接比較空間用量。
- [UVa-c-2 整併紀錄](PR-IMPORT-NOTES.md)說明新增題目、保留的替代解法與重複檔案處理方式。
- 索引建置會檢查每個 C 檔都有對應題目、英中描述、演算法範圍與有效連結。

## 編譯範例

在儲存庫根目錄使用 GCC 編譯單題，例如：

```powershell
gcc -std=c11 -O2 UVa-c/volume001/100_the-3n-plus-1-problem.c -o uva100.exe
.\uva100.exe
```

## 更新索引

新增 C 題目檔後，先在程式檔頭填寫 `Difficulty` 和 `Tags`，再於對應卷別 README 補上雙語題意和演算法，最後執行 `python UVa-c/build_index.py`。腳本會檢查每個 `.c` 是否都有對應條目，並更新本頁、`INDEX.md`、`INDEX.tsv`、`TOPICS.md`。

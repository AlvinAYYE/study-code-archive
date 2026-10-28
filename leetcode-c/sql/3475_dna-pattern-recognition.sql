-- 3475. DNA 模式辨識（DNA Pattern Recognition）
-- 題目完整翻譯：對每筆 DNA 樣本辨識四種模式，並回傳原有欄位加上四個 0/1 標記：has_start 表示序列以 ATG 開頭；has_stop 表示以 TAA、TAG 或 TGA 結尾；has_atat 表示序列包含 ATAT；has_ggg 表示序列至少有連續三個 G。結果依 sample_id 升冪排列。
-- 資料表與鍵：Samples(sample_id INT, dna_sequence VARCHAR, species VARCHAR)；sample_id 為唯一鍵；序列由 A、T、G、C 字元組成。
-- 範例輸入重點：ATGCTAGCTAGCTAA 同時有起始與終止密碼子；GGGTCAATCATC 有 GGG；ATATATCGTAGCTA 含 ATAT；ATGGGGTCATCATAA 同時符合起始、終止與 GGG。
-- 範例輸出：每列保留 sample_id、dna_sequence、species，再輸出 has_start、has_stop、has_atat、has_ggg，符合該模式為 1，否則為 0。
-- 限制：題目沒有額外列出資料長度限制。
-- 解題步驟：LEFT 檢查起始三字元、RIGHT 檢查終止三字元、INSTR 搜尋 ATAT、REGEXP 搜尋 GGG；各條件用 CASE 轉成數值 1 或 0。
-- 複雜度：N 筆樣本、平均序列長度 L，四種檢查約 O(N × L)；額外空間 O(1)。

SELECT
    sample_id,
    dna_sequence,
    species,
    CASE WHEN LEFT(dna_sequence, 3) = 'ATG' THEN 1 ELSE 0 END AS has_start,
    CASE WHEN RIGHT(dna_sequence, 3) IN ('TAA', 'TAG', 'TGA') THEN 1 ELSE 0 END AS has_stop,
    CASE WHEN INSTR(dna_sequence, 'ATAT') > 0 THEN 1 ELSE 0 END AS has_atat,
    CASE WHEN REGEXP_LIKE(dna_sequence, 'GGG', 'c') THEN 1 ELSE 0 END AS has_ggg
FROM Samples
ORDER BY sample_id ASC;

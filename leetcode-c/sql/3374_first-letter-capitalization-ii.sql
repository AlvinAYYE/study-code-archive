-- 3374. 首字母大寫 II（First Letter Capitalization II）
-- 題目完整翻譯：user_content 每列有唯一 content_id 與一段文字。以空格分隔的最大非空字串視為一個單字，逐字轉換：若單字第一個字元不是英文字母，整個單字原樣保留；若單字由兩個以上非空英文字母片段以連字號連接，將每個片段的首字母改成大寫、其餘英文字母改成小寫；否則，將單字第一個字母改成大寫、其餘英文字母改成小寫。所有特殊字元與空白格式須維持原樣。回傳 content_id、原文 original_text、轉換後的 converted_text。
-- 資料表與鍵：user_content(content_id INT, content_text VARCHAR)；content_id 為唯一鍵。
-- 範例輸入：
-- 1 | hello world of SQL
-- 2 | the QUICK-brown fox
-- 3 | modern-day DATA science
-- 4 | web-based FRONT-end development
-- 範例輸出的 converted_text：
-- 1 | Hello World Of Sql
-- 2 | The Quick-Brown Fox
-- 3 | Modern-Day Data Science
-- 4 | Web-Based Front-End Development
-- 限制：content_text 只含英文字母、空格及字元 \、@、-、/、^、,。
-- 解題步驟：遞迴 CTE 逐字掃描原文，記錄目前位置與目前單字起點；依完整單字是否以字母開頭、是否符合字母片段以連字號連接的格式，決定保留、一般首字母大寫或每段首字母大寫；每輪只追加一個轉換後字元，因此連續空格與標點都不會遺失。
-- 複雜度：L 為文字總字元數。遞迴逐字掃描；每步還會檢查目前單字並累積前綴字串，最壞時間與中間字串空間約 O(L^2)。
-- 使用 MySQL 8.0 遞迴 CTE 與 REGEXP。題目未列文字長度上限；本查詢輸出欄寬為 1000 字元，且遞迴深度須符合 MySQL 設定。

WITH RECURSIVE char_walk AS (
    SELECT
        content_id,
        content_text,
        1 AS pos,
        1 AS word_start,
        CHAR_LENGTH(content_text) AS text_length,
        CAST('' AS CHAR(1000)) AS converted_text
    FROM user_content

    UNION ALL

    SELECT
        content_id,
        content_text,
        pos + 1,
        CASE
            WHEN SUBSTRING(content_text, pos, 1) = ' ' THEN pos + 1
            ELSE word_start
        END AS word_start,
        text_length,
        CONCAT(
            converted_text,
            CASE
                WHEN SUBSTRING(content_text, pos, 1) = ' ' THEN ' '
                WHEN LEFT(
                    SUBSTRING_INDEX(SUBSTRING(content_text, word_start), ' ', 1),
                    1
                ) NOT REGEXP '^[A-Za-z]$' THEN SUBSTRING(content_text, pos, 1)
                WHEN SUBSTRING_INDEX(SUBSTRING(content_text, word_start), ' ', 1)
                     REGEXP '^[A-Za-z]+(-[A-Za-z]+)+$' THEN
                    CASE
                        WHEN pos = word_start OR SUBSTRING(content_text, pos - 1, 1) = '-'
                            THEN UPPER(SUBSTRING(content_text, pos, 1))
                        ELSE LOWER(SUBSTRING(content_text, pos, 1))
                    END
                WHEN pos = word_start THEN UPPER(SUBSTRING(content_text, pos, 1))
                ELSE LOWER(SUBSTRING(content_text, pos, 1))
            END
        ) AS converted_text
    FROM char_walk
    WHERE pos <= text_length
)
SELECT
    content_id,
    content_text AS original_text,
    converted_text
FROM char_walk
WHERE pos = text_length + 1
ORDER BY content_id ASC;

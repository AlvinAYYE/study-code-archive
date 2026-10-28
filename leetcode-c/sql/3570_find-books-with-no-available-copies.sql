-- Title-CN: 找出目前沒有可借館藏的書籍
-- LeetCode 3570. Find Books with No Available Copies
-- 題意：尚未歸還（return_date 為 NULL）的借閱紀錄代表目前仍被借出。找出目前借出本數等於
--      館藏總本數的書，也就是可借本數為 0。輸出書籍資料與目前借閱人數，依人數遞減、書名遞增排序。
-- 資料表：library_books(book_id INT 主鍵, title VARCHAR, author VARCHAR, genre VARCHAR,
--        publication_year INT, total_copies INT)；borrowing_records(record_id INT 主鍵,
--        book_id INT, borrower_name VARCHAR, borrow_date DATE, return_date DATE 可為 NULL)。
-- 範例：一本書 total_copies=2，兩筆借閱紀錄的 return_date 都是 NULL，current_borrowers=2，
--      可借本數 2-2=0，因此列入結果；若其中一本已歸還，就不列入。
-- 限制：只將 return_date IS NULL 的紀錄當成目前借出；已歸還的紀錄不計數。
-- 解法：1. 以書籍為主表，左連接未歸還紀錄。2. 每本書計算目前借閱人數。3. HAVING 要求人數
--      等於館藏總本數，保留零本可借的書，再依題目排序。
-- 複雜度：掃描書籍及借閱紀錄並分組，時間約 O(B+R)，分組空間 O(B)。

SELECT b.book_id,
       b.title,
       b.author,
       b.genre,
       b.publication_year,
       COUNT(br.record_id) AS current_borrowers
FROM library_books AS b
LEFT JOIN borrowing_records AS br
  ON br.book_id = b.book_id
 AND br.return_date IS NULL
GROUP BY b.book_id, b.title, b.author, b.genre, b.publication_year, b.total_copies
HAVING COUNT(br.record_id) = b.total_copies
ORDER BY current_borrowers DESC, b.title ASC;

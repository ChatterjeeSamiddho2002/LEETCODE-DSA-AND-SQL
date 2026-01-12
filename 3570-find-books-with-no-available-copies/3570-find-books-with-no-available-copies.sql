# Write your MySQL query statement below
SELECT library_books.book_id,
       library_books.title,
       library_books.author,
       library_books.genre,
       library_books.publication_year,
       library_books.total_copies AS current_borrowers
FROM library_books
JOIN borrowing_records
  ON library_books.book_id = borrowing_records.book_id
WHERE return_date IS NULL
GROUP BY library_books.book_id,
         library_books.title,
         library_books.author,
         library_books.genre,
         library_books.publication_year,
         library_books.total_copies
HAVING COUNT(record_id) = total_copies
ORDER BY current_borrowers DESC, title;

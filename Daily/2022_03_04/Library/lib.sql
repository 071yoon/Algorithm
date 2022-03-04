SELECT buyer_id, buy_date, book_name, price
FROM library
WHERE book_name = 'Looking with Elice' 
OR (DATE_FORMAT(buy_date, '%Y-%m-%d' ) BETWEEN '2020-07-27' AND '2020-07-31')
ORDER BY buy_date
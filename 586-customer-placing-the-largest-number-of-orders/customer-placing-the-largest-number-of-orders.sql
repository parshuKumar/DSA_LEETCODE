# Write your MySQL query statement below
WITH T AS (
SELECT 
    customer_number,
    COUNT(customer_number) as cnt
FROM
    Orders
GROUP BY customer_number
)

SELECT customer_number as customer_number 
    FROM T
WHERE cnt = (SELECT MAX(cnt) FROM T);

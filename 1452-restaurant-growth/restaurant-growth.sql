# Write your MySQL query statement below

WITH total AS (
    SELECT 
        SUM(amount) as amount,
        visited_on
    FROM Customer
    GROUP BY 
        visited_on
)

SELECT * FROM
(
SELECT
    visited_on,
    SUM(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount,
    ROUND(AVG(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),2) as average_amount
FROM
    total
) t WHERE visited_on >= (SELECT MIN(visited_on) FROM total) + INTERVAL 6 DAY;

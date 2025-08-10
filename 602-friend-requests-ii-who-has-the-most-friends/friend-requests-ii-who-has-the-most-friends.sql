# Write your MySQL query statement below
WITH T AS (
SELECT
    requester_id as id,
    count(*) as total
FROM
    RequestAccepted
GROUP BY id
UNION ALL
SELECT
    accepter_id  as id,
   count(*) as total
FROM
    RequestAccepted
GROUP BY id
)


SELECT id, SUM(total) as num 
FROM T group by id
ORDER BY num desc LIMIT 1;


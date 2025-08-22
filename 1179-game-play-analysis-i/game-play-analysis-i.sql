# Write your MySQL query statement below

WITH T AS (
SELECT 
    player_id,
    event_date,
    ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) as rowN
FROM 
    Activity
)

SELECT player_id, event_date as first_login
FROM T where rowN = 1;



# Write your MySQL query statement below
WITH T AS (
SELECT actor_id, director_id, COUNT(actor_id) as cnt
FROM ActorDirector
GROUP BY actor_id, director_id
)
SELECT actor_id, director_id
FROM T where cnt >= 3;


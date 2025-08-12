# Write your MySQL query statement below

WITH cnt as( 
    SELECT 
        *,
        DENSE_RANK() OVER(PARTITION BY DepartmentId ORDER BY Salary desc) as RowN
    FROM 
        Employee 
)

SELECT
    d.name as Department,
    e.name as Employee,
    e.Salary
FROM
    Department d
LEFT JOIN
    cnt e
ON d.id = e.departmentId
WHERE e.RowN <= 3;
;

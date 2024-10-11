use dualcore;

SELECT message
FROM ratings
WHERE prod_id = (
    SELECT prod_id
    FROM ratings
    GROUP BY prod_id
    HAVING COUNT(rating) >= 50
    ORDER BY AVG(rating) ASC
)
AND message LIKE '%ten times more%';
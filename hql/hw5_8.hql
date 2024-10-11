use dualcore;

SELECT prod_id
FROM ratings
GROUP BY prod_id
HAVING COUNT(rating) >= 50
ORDER BY AVG(rating) ASC
LIMIT 1;
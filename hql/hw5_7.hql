use dualcore;

SELECT c.cust_id
FROM customer c
LEFT JOIN orders o ON c.cust_id = o.cust_id
WHERE o.cust_id IS NULL;

use dualcore;

SELECT COUNT(DISTINCT o.cust_id) AS customer_count
FROM orders o
JOIN order_details d ON  o.order_id = d.order_id
JOIN products p ON d.prod_id = p.prod_id
GROUP BY o.cust_id
HAVING SUM(p.price) > 300000;
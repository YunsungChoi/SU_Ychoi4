use dualcore;

SELECT COUNT(order_details.prod_id)
FROM orders
JOIN order_details ON orders.order_id = order_details.order_id
WHERE orders.order_id = 1071189;
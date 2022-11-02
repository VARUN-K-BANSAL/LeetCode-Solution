SELECT name AS Customers 
FROM customers WHERE id NOT IN (SELECT customerid FROM orders);
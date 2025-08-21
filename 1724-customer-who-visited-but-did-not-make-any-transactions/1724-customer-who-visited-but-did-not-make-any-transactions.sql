# Write your MySQL query statement below
SELECT v.customer_id, SUM(CASE WHEN t.transaction_id IS NULL THEN 1 ELSE 0 END) as count_no_trans
FROM Visits v
LEFT JOIN   Transactions t
on v.visit_id =  t.visit_id
GROUP BY v.customer_id
HAVING SUM(CASE WHEN t.transaction_id IS NULL THEN 1 ELSE 0 END) >=1;
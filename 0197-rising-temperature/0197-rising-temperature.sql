# Write your MySQL query statement below
SELECT curr.id as Id FROM Weather curr CROSS JOIN Weather yesterday
WHERE DATEDIFF(curr.recordDate, yesterday.recordDate) =1
AND curr.temperature > yesterday.temperature;
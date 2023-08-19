# Write your MySQL query statement below
SELECT name FROM Employee WHERE id IN (SELECT DISTINCT managerId FROM Employee 
GROUP BY managerId 
HAVING managerId IS NOT NULL and COUNT(managerId)>=5);
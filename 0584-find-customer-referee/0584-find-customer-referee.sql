# Write your MySQL query statement below
SELECT name
From Customer
WHERE ifnull(referee_id,0) !=2;
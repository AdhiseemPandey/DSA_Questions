# Write your MySQL query statement below
SELECT name FROM customer 
WHERE referee_id != 2       # id 2 ko remove kar diya 
      OR referee_id IS NULL # as NULL is empyt so use IS NULL or IS NOT NULL 
      
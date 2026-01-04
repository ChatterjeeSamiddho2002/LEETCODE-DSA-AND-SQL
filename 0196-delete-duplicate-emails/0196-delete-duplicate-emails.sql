# Write your MySQL query statement below
DELETE P1 FROM Person P1
JOIN Person P2 ON P1.Email = P2.Email
AND P1.Id > P2.Id;
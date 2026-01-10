SELECT DISTINCT
    s.student_id,
    s.subject,
    fs.score AS first_score,
    ls.score AS latest_score
FROM Scores s
JOIN Scores fs
    ON fs.student_id = s.student_id
    AND fs.subject = s.subject
    AND fs.exam_date = (
        SELECT MIN(exam_date)
        FROM Scores
        WHERE student_id = s.student_id
          AND subject = s.subject
    )
JOIN Scores ls
    ON ls.student_id = s.student_id
    AND ls.subject = s.subject
    AND ls.exam_date = (
        SELECT MAX(exam_date)
        FROM Scores
        WHERE student_id = s.student_id
          AND subject = s.subject
    )
WHERE ls.score > fs.score
ORDER BY s.student_id, s.subject;

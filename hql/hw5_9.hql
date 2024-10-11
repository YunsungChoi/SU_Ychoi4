use dualcore;

SELECT ngrams.explode AS trigram, COUNT(*) AS count
FROM(
    SELECT EXPLODE(NGRAM(MESSAGE, 3)) AS ngrams
    FROM ratings
    WHERE prod_id = (
        SELECT prod_id
        FROM ratings
        GROUP BY prod_id
        HAVING COUNT(rating) >= 50
        ORDER BY AVG(rating) ASC
        LIMIT 1
    ) 
) AS ngrams_table
GROUP BY trigram
ORDER BY count DESC
LIMIT 5;
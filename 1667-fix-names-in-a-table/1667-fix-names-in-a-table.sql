SELECT
    user_id,
    CONCAT(
        UPPER(LEFT(name, 1)),
        LOWER(SUBSTRING(name, 2, LENGTH(name)))
    ) AS name
FROM users
ORDER BY user_id;

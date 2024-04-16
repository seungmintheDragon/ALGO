SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS D
WHERE SKILL_CODE & (
    select sum(code)
    from SKILLCODES
    where category = 'Front End'
)
ORDER BY ID
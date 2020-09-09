INSERT INTO target_table (col1, col2, col3)
SELECT col1,
       col2,
       col3
FROM source_table
WHERE condition;

insert into work_app_properties(name, type) select name, 'S' from wapp_safety;

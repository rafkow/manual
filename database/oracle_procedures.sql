PROCEDURE proc_work_approve_sheet (
    isheet_id      IN  work_app_sheet_relation.sheet_id%TYPE,
    ipropertie_id  IN  VARCHAR2
) IS
BEGIN
    INSERT INTO work_app_sheet_relation (
        sheet_id,
        propertie_id
    )
        SELECT
            isheet_id,
            TRIM(regexp_substr(ipropertie_id, '[^,]+', 1, levels.column_value)) AS zmienna
        FROM
            TABLE ( CAST(MULTISET(
                SELECT
                    level
                FROM
                    dual
                CONNECT BY
                    level <= length(regexp_replace(ipropertie_id, '[^,]+')) + 1
            ) AS sys.odcinumberlist) ) levels;
END;

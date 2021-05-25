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

select * from gb_invitations i where i.id not in (select invitation_id from gb_visit group by invitation_id);
select * from gb_visit v where v.id not in (select id_visit from gb_visit2obj group by id_visit);

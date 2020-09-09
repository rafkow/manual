select to_char(exp_date,'YYYY-MM-DD HH24:MI:SS') from REFRESH_TOKEN;

select * from (
select to_char(exp_date,'YYYY-MM-DD HH24:MI:SS') from REFRESH_TOKEN order by exp_date desc
) where rownum<2

select to_char(max(exp_date),'YYYY-MM-DD HH24:MI:SS') from refresh_token

delete from REFRESH_TOKEN where (EXP_DATE < SYSDATE);

select username value from refresh_token A where TOKEN = :TOKEN and exp_date >SYSDATE and exp_date = (select max(exp_date ) FROM REFRESHTOKEN B where A.USERNAME=B.USRENAME);

SELECT
    username value, a.token
FROM
    refresh_token a
WHERE
    exp_date > SYSDATE
    AND exp_date = (
        SELECT
            MAX(exp_date)
        FROM
            refresh_token b
        WHERE
            a.username = b.username
    );

# Display unique value in column
SELECT distinct(username) FROM refresh_token;

    --Napisz zapytanie SQL wyświetlające alfabetycznie wszystkich użytkowników oraz ilość okien w poszczególnych modułach do których ma dostęp.
    select USERS.F_NM, SYS_CD, COUNT(*) from ZAA01MT USERS, SAB03MT UPRAWNIENIA
    WHERE
    USERS.EMP_NO=UPRAWNIENIA.EMP_NO
    group by
    USERS.F_NM, SYS_CD
    order by
    USERS.F_NM;
    --Napisz zapytanie SQL wyświetlające alfabetycznie wszystkich użytkowników oraz ilość okien w poszczególnych modułach do których dany użytkownik nie ma dostępu.
    select USERS.F_NM, SYS_CD, (SELECT COUNT(*) FROM SAA03MT B where B.SYS_CD=UPRAWNIENIA.SYS_CD)-  COUNT(*)  from ZAA01MT USERS, SAB03MT UPRAWNIENIA
    WHERE
    USERS.EMP_NO=UPRAWNIENIA.EMP_NO
    group by
    USERS.F_NM, SYS_CD
    order by
    USERS.F_NM;

    insert into SAB03MT
    SELECT SYS_CD, DETAIL, '030123' EMP_NO from SAB03MT where EMP_NO='030086'
    minus
    SELECT SYS_CD, DETAIL, '030123' EMP_NO from SAB03MT where EMP_NO='030123'

    --
    ;
    -- 4.        Napisz zapytania SQL wyświetlające: nazwę modułu, nazwa zakładki, ilość użytkowników którzy mają  do nich dostęp posortowane alfabetycznie po nazwie modułu i odwrotnie alfabetycznie po nazwie zakładki.
    select MODUL.SYS_NM, ZAKLADKA.PG_DESC, COUNT(*) from
    SAA03MT ZAKLADKA,
    SAA01MT MODUL,
    SAB03MT UPRAWNIENIA
    WHERE
    ZAKLADKA.SYS_CD=MODUL.SYS_CD AND
    ZAKLADKA.DETAIL=MODUL.DETAIL AND
    UPRAWNIENIA.SYS_CD=ZAKLADKA.SYS_CD AND
    UPRAWNIENIA.PG_NAME=ZAKLADKA.PG_NAME
    group by MODUL.SYS_NM, ZAKLADKA.PG_DESC
    order by MODUL.SYS_NM, ZAKLADKA.PG_DESC DESC
    ;
    --5.         Napisz zapytanie SQL wyświetlające dane w formie tabelki w wierszach alfabetycznie wszystkich użytkowników z bazy danych w formie imię i nazwisko, zaś w poszczególnych kolumnach ilość okien programu dla każdego z modułów.
    select USERS.F_NM,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PA',1,0)) PA,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PB',1,0)) PB,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PC',1,0)) PC,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PF',1,0)) PF,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PM',1,0)) PM,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PS',1,0)) PS,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PP',1,0)) PP,
    SUM(DECODE(UPRAWNIENIA.SYS_CD,'PU',1,0)) PU
    from ZAA01MT USERS, SAB03MT UPRAWNIENIA
    WHERE
    USERS.EMP_NO=UPRAWNIENIA.EMP_NO
    group by USERS.F_NM


    You are given one table:
kontrachenci którzy:
select cus_cd, (select F_NM from caa01mt b where b.cus_cd=a.cus_cd), sum(suma) from (
select cus_cd, SUM(ti_amt) suma,  substr(ti_date,1,4)
from bda01it
where
    ti_date> '2016' and USE_MK is null and bda01it.ti_class = 1
    group by cus_cd, substr(ti_date,1,4)
    having SUM(ti_amt)>10000
    ) a group by cus_cd
having count(*)>=4;

CREATE TABLE customers (
  id INT NOT NULL PRIMARY KEY,
  first_name VARCHAR(50) NOT NULL,
  last_name VARCHAR(50) NOT NULL
);
Problem statement
Find all the customers whose first and last names are not unique in our database, as well as the number of times each first and last name pair appears in our database.

Sort the received result by number of time it appears in descending order.

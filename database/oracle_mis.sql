znajdz max emp_no
select * from zaa01mt where emp_no like '030%' order by emp_no desc;
znajdz pracownika po nazwie
select * from zaa01mt where emp_no like '030%' and f_nm like '%Kostecka%' order by emp_no desc;


kopiowanie uprawnien MIS
insert into sab03mt(sys_cd, detail, pg_name, emp_no, is_admin, assigned_date, from_machine, from_osuser)
select sys_cd, detail, pg_name, '030291', 'N', SYSDATE, 'NB059', 'rkowalewski'
from sab03mt where emp_no = '030144';

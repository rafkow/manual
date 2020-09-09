select x.*, y.f_nm, q.f_nm, q.f_nm from pls_result_item x , zaa01mt y , zaa01mt z , zaa01mt q
where
x.confirm_1 = y.emp_no(+) and
x.confirm_2 = z.emp_no(+) and 
x.operator_cd = q.emp_no(+);

select x.*, y.f_nm, z.f_nm, q.f_nm from pls_result_item x
left join zaa01mt y on x.confirm_1 = y.f_nm
left join zaa01mt z on x.confirm_1 = z.f_nm
left join zaa01mt q on x.confirm_1 = q.f_nm;

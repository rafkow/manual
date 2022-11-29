EXTRACT()
DATE	YEAR, MONTH, DAY
INTERVAL YEAR TO MONTH	YEAR, MONTH
INTERVAL DAY TO SECOND	DAY, HOUR, MINUTE, SECOND
TIMESTAMP	YEAR, MONTH, DAY, HOUR, MINUTE, SECOND

SELECT
  EXTRACT( YEAR FROM TO_DATE( '31-Dec-1999 15:30:20 ',  'DD-Mon-YYYY HH24:MI:SS' ) ) YEAR
FROM
  DUAL;

TRUNC(date_time_value) - obcina godzine zostawia tylko dzień
TRUNC(SYSDATE) - today
select * from gb_enter_register where TRUNC(SYSDATE) = TRUNC(enter_date);

TO_DATE( '31-Dec-1999 15:30:20 ',  'DD-Mon-YYYY HH24:MI:SS' )
update gb_invitations set exp_date = to_date('31-12-2021', 'DD-MM-YYYY') where visit_type = 'stała';

TO_CHAR( SYSDATE, 'HH24' ) hour,
TO_CHAR( SYSDATE, 'MI' ) minute,
TO_CHAR( SYSDATE, 'SS' ) second

select to_char(SYSDATE, 'yyyyMMdd') from dual;
select add_months(trunc(sysdate, 'mm'), -1) from dual;
select to_char(add_months(SYSDATE, -36), 'yyyyMMdd') from dual;

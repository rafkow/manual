Alter Table dbo.t_result_check_item Add Id Int Identity(1, 1)

SELECT *  FROM Obecnosc where userid =  order by dzien desc;
update dbo.Obecnosc set RogerDateOut = CONVERT(DATETIME, '2021-05-27 15:07:23', 120)  where ID = 58514;
convert(DATETIME, date , x)  x - wzór daty lista wzorów na - http://www.sqlusa.com/bestpractices/datetimeconversion/

# ilość pracownikuów na terenei zakładu
SELECT count(*)
  FROM [ASERO].[dbo].[Obecnosc]
  where RogerDateIn > CONVERT(DATETIME, '2021-09-28 04:00:00', 120) and ( RogerDateOut is NULL or RogerDateOut > CONVERT(DATETIME, '2021-09-28 10:00:00', 120));

select * from Obecnosc where  
Dzien > CONVERT(DATETIME, '2022-06-01 04:00:00', 120)
and Dzien < CONVERT(DATETIME, '2022-07-01 04:00:00', 120)
and UserID in (
SELECT [ID]
FROM [ASERO].[dbo].[Pracownicy]
where ADLogin like '%kowalewski')
order by Dzien, UserID;

select RogerDateIn from Obecnosc where ID = 98589;

update Obecnosc set RogerDateIn = (select RogerDateIn from Obecnosc where ID = 98589) where ID = 94146;

update Obecnosc set RogerDateOut = (select RogerDateOut from Obecnosc where ID = 98600) where ID = 94129;
str to int:
  SELECT CAST(O.year AS UNSIGNED) FROM OfficeCatalogs O GROUP BY O.year;

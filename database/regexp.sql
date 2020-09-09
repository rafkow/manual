SELECT * FROM all_data WHERE sheet LIKE '%MPGN%';

SELECT * FROM OfficeCatalogs WHERE person REGEXP 'M/[0-9]+/[0-9]+';

SELECT * FROM OfficeCatalogs WHERE sygnature NOT REGEXP '[A-M]?/[0-9]+/[0-9]+';

SELECT * FROM OfficeCatalogs WHERE sygnature IS NULL OR sygnature='';

DELETE FROM OfficeCatalogs WHERE sygnature NOT REGEXP '[A-M]?/[0-9]+/[0-9]+';


SELECT CAST(O.year AS UNSIGNED) FROM OfficeCatalogs O GROUP BY O.year;

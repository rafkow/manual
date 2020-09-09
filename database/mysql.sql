logowanie : mysql -u [nazwa_uzytkownika] -p
            mysql -u kapiszon -p dupablada -h host

nadanie dostepu do bazy:
    GRANT ALL PRIVILEGES ON mydb.* TO 'user'@'%' WITH GRANT OPTION;


Użytkownic:
	wyswietl liste:
		SELECT User, Host FROM mysql.user;
    stworz:
		create user 'name'@'host';
    usun:
		DROP USER 'name'@'host';
    zmien haslo:
		ALTER USER 'name'@'host' IDENTIFIED BY 'new_pass';

>> '%' - all host

Wybor bazy danych:
    use dbname;

Tworzenie tabeli:
	CREATE TABLE IF NOT EXISTS devices (
		id INT (10) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
		dev_code VARCHAR(36) UNIQUE NOT NULL,
		owner_login VARCHAR(20),
		online BOOL DEFAULT FALSE,
		online_date DATE,
		description TEXT,
		reg_date datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
		);

Edycja tabeli:
    dodanie kolumny:
    ALTER TABLE contacts ADD email VARCHAR(60);
	remove column:
	ALTER TABLE contacts DROP COLUMN name;
	rename column:
	ALTER TABLE dbname.tablename CHANGE COLUMN oldname nevname VARCHAR(20);

	edycja typu danych instniejacej kolumny:
    ALTER TABLE tablename MODIFY columnname INTEGER;

Records:
	create:
	INSERT INTO table_name (variable1,...) VALUES (value1,...);

	edit:
  UPDATE nazwa_tabeli SET nazwa_pola1=wartosc_pola1 WHERE warunek

Functions:
SELECT CURDATE();
SELECT CURTIME();

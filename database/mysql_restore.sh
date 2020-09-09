restore from file:
  mysql -u [new_user] -p [database_name] < [file_name].sql

  all all_databases
  sudo mysql -u root < [file_name].sql

migrate all data
  mysqldump -u [user] -p --all-databases > all_databases.sql

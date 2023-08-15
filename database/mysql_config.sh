allow remote conncetion config
/etc/mysql/mysql.conf.d/mysqld.cnf
  bind-address            = 0.0.0.0

firewall role to remote connection
sudo ufw allow 3306/tcp
sudo service ufw restart


Step 0: sudo apt install python3-dev build-essential
Step 1: sudo apt install libssl1.1
Step 2: sudo apt install libssl1.1=1.1.1f-1ubuntu2
Step 3: sudo apt install libssl-dev
Step 4: sudo apt install libmysqlclient-dev
Step 5: pip3 install mysqlclient
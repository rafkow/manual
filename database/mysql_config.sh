allow remote conncetion config
/etc/mysql/mysql.conf.d/mysqld.cnf
  bind-address            = 0.0.0.0

firewall role to remote connection
sudo ufw allow 3306/tcp
sudo service ufw restart

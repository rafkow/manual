import pymysql

db = pymysql.connect("oniongeek.com", "geekserver","p3nt0ki3lbachy","sliderdb" )

cursor = db.cursor()

class DeviceDB:


select = 'select * from users'

try:
   cursor.execute(select)
   data = cursor.fetchone()

   print('odczytane {}'.format(data))
except:
   # Rollback in case there is any error
   db.rollback()

db.close()
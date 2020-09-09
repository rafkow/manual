import PyMySQL


# Open database connection
db = PyMySQL.connect("oniongeek.com", "geekserver","p3nt0ki3lbachy","sliderdb" )

# prepare a cursor object using cursor() method
cursor = db.cursor()

select = 'select * from users'

try:
   cursor.execute(select)
   data = cursor.fetchone()

   print('odczytane {}'.format(data))
except:
   # Rollback in case there is any error
   db.rollback()

db.close()
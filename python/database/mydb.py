import MySQLdb
db = MySQLdb.connect(user='kapiszon', password='dupablada', host='cosiestalosie.pl', database='webdb')
cursor = db.cursor()

#cursor.execute("SELECT VERSION()")
#cursor.execute("show tables")
cursor.execute("SELECT * FROM test LIMIT 3")
data = cursor.fetchone()

for i in cursor:
	print ('Database version :' + str(i))

#for (a,b,c,d) in cursor:
#    print("{} {} {} {}".format(a,b,c,d))

#cursor.close()
db.close()

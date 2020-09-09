import mysql.connector

cnx = mysql.connctor.connect(user='kapiszon', password='dupablada', host='cosiestalosie.pl', database='webdb')
cursor = cnx.cursor()

cursor.execute("SELCT * FROM test")
for (a,b,c,d) in cursor:
    print("{} {} {} {}".format(a,b,c,d))

cursor.close()
cnx.close()


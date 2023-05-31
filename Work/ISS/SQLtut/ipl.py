import sqlite3

db = sqlite3.connect('ipl.db')
cur = db.cursor()

cur.execute("select Umpire_Name from Umpire LIMIT 10;")
print("Umpire names: ", end="")
for i in cur.fetchall():
    print(i[0], end=',')

print("\n")

cur.execute("SELECT COUNT(DISTINCT Umpire_country) AS num_countries FROM Umpire;")
print("The number of countries the umpires belong to are: ", end="")
for i in cur.fetchall():
    print(i[0], end=',')

print("\n")

cur.execute("select Venue_Name from Venue order by Venue_Name ASC ;")
print("Venue Names: ", end="")
for i in cur.fetchall():
    print(i[0], end=',')

print("\n")


cur.execute("select Player_Name from Player where Country_Name = '5';")
print("Australian Players: ", end="")
for i in cur.fetchall():
    print(i[0], end=',')

print("\n")

CSKmatcheswon=cur.execute("select count(*) as match_wonby1 from match where match_winner='3';")
CSKmatcheswon=cur.fetchall()
# print(CSKmatcheswon)

RCBmatcheswon=cur.execute("select count(*) as match_wonby2 from match where match_winner='2';")
RCBmatcheswon=cur.fetchall()
# print(RCBmatcheswon)


print(f"The number of matches CSK won more than RCB:",CSKmatcheswon[0][0]- RCBmatcheswon[0][0])


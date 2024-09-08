import sqlite3

conn=sqlite3.connect("database.db")

cursor=conn.cursor()

#cursor.execute("CREATE TABLE students (name text,age integer)")

cursor.execute("INSERT INTO students (name,age) VALUES(?,?)",("Panagiotis",24))

cursor.execute("SELECT * FROM students")

cursor.execute("SELECT * FROM students WHERE name=?",("Panagiotis",))

conn.close()

conn=sqlite3.connect("example.db")


#conn.execute("""
#	CREATE TABLE users (
#	id INTEGER PRIMARY KEY,
#	name TEXT,
#	email TEXT
#	);
#	""")


conn.execute("""INSERT INTO users(id,name,email)
VALUES (1,"John Doe","john@example.com");
 """)



conn.execute("""

INSERT INTO users (id,name,email)
VALUES (2,"Jane Smith","jane@example.com");

	""")


conn.execute("""
SELECT * FROM users;

	""")

conn.execute("""
SELECT name,email FROM users;

	""")

conn.execute("""
SELECT * FROM users
WHERE id=1;

	""")


conn.execute("""
SELECT * FROM users
ORDER BY name;
	""")
# !/usr/bin/python3

import cgi
import datetime
import sys
import os

today = datetime.date.today()

print("HTTP/1.1 200 OK")
print("Content-type: text/html\r\n\r\n")
print("<html>")
print("<head>")
print("Time: ", datetime.datetime.strftime(datetime.datetime.now(), "<h1>  %H:%M:%S </h1>"))
print("Date: ", today.strftime("%d %B %Y"))
print(" ----------------------------- ")

# Get the form input (works for POST)
form = cgi.FieldStorage()
birthday_input = form.getvalue("birthday")  # DD-MM

# HTML start
print("<html><head><title>Birthday Countdown</title></head><body>")
print("<h1>🧠 42 Birthday Countdown</h1>")

try:
	birthday = datetime.strptime(birthday_input, "%d-%m").date()
	month, day = map(int, birthday_input.split("-"))

	# Today
	this_year_birthday = datetime.date(today.year, month, day)

	# If birthday has passed this year, use next year
	if this_year_birthday < today:
		next_birthday = datetime.date(today.year + 1, month, day)
	else:
		next_birthday = this_year_birthday

	delta = next_birthday - today
	print(f"<p>There are <b>{delta.days}</b> days until your next birthday 🥳</p>")

except:
	print("<p style='color:red'>Please enter your birthday in DD-MM format (e.g., 25-04)</p>")

print("</body></html>")
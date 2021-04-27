# app_skeleton.c
Using C to manage personal finance

Libraries used: GTK and SQLite.

![App](https://user-images.githubusercontent.com/73109076/103483932-b3d59a00-4de2-11eb-836a-72688760686f.png)


As you can see, the user inputs their daily expenses and incomings and the app will display useful data so that they can keep tight control of their finances.

NOTE: update in progress

compiled with:


          cc -o sql_gtk app.c -lsqlite3 `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

NOTE: update - SQLite not necessary

# black_scholes.c


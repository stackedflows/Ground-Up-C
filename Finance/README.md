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

As the underlying mathematics that is used in the modern financial world, an impliementation of the process is useful for personal understanding

Derived on the assumption that the underlying asset follows geometric brownian motion.

https://en.wikipedia.org/wiki/Geometric_Brownian_motion

https://en.wikipedia.org/wiki/Black%E2%80%93Scholes_equation#:~:text=In%20mathematical%20finance%2C%20the%20Black%E2%80%93Scholes%20equation%20is%20a,a%20variety%20of%20options%2C%20or%20more%20generally%2C%20derivatives.

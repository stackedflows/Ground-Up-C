# Installing DISLIN

the easiest way to install Dislin on Ubuntu is to use the .deb package of Dislin. If you have a 64-bit Ubuntu you have to download
the distribution dislin-10.5.linux.i586_64.deb from the site www.dislin.de. For Ubuntu 32-bit the distribution dislin-10.5.linux.i586.deb.
Since Dislin requires OpenMotif you have to install it with the command:

      sudo apt-get install libmotif4

After that you can install Dislin with

      sudo dpkg -i dislin-10.5.linux.i586_64.deb

Dislin will be installed in the directory /usr/local/dislin.


     cp -p -R /usr/local/dislin/examples $HOME

This will export the library to you home directory

# julia.c

C implimentation of the julia fractals

still some kinks to iron out . . . 

![dragon (2)](https://user-images.githubusercontent.com/73109076/112074216-bb991500-8b6d-11eb-97a7-98e72ca9f440.png)

![mandelbrotset (2)](https://user-images.githubusercontent.com/73109076/108780252-0bc98b00-7560-11eb-9484-98b8082e68a9.png)

# e8.c 

In progress. . . 

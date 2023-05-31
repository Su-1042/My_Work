-------------------------------------------------------------------------------------------------
PHASE 1
-------------------------------------------------------------------------------------------------
The basic idea behind the construction of the website using HTML was that we first read through the details
given in the pdf following which we planned a structure as to how our website would look like. 


We created different CSS files for all our pages (external css) and linked them
The navbar and toolbar are same across all pages.
There are also gradients set on pages according to the requirements.

1. Name 
    Probably the most fun part of this phase was finding a name and a tagline for the website. Canva was used to make
    the design the logo and then the name was decided mutually. The tagline was suggested by Chat GPT as mentioned 
    in the about page.

2. About Page 
    The word VIBIN' that is visible on opening the about page was written using the pre tag.
    The about page was inspired by the Medium website given as example and subsequently divisions were made with a suitable 
    color scheme.

3. Home Page
    The home page is unique and waiting for 5 sec will then display an animation effect of images of musical notes
    on the entire page.
    There are three sections on the homepage that can are each followed by a list of three top items of the 
    mentioned category.
        (a) Top artists has three artists and clicking on them will lead you to the respective pages of the artists containing all their albums
        (b) Top Albums has three top albums and clicking on them will lwad you to the page containing the songs that are listed in that album
        (c) Top Songs has three songs in front of it and these are also clickable and on clicking will take you to the album containing that song
        (The hover effect is used to display all names)
    
    Finally there is an explore artists image that takes you to the the page containing all the artists so that you can explore the site

4. Artists Page
   This page has a list of 5 artists with their images.
   The NAMES BECOME VISIBLE on HOVERING over the image of the artists
   And clicking on them will lead you to the ALBUM PAGE of the respective artist

5. Album Page
   This page again has a list of 5 albums of the chosen artist and on hovering over the image of the album you can see the name of the Album
   the year of release and the number of songs that it has.
   At the bottom is also a description of the arists whose albums are being viewed (the name and a brief description)
   
6. Songs page
   This page has an image of the respective album and the name of the album along with year of release and total duration
   Each song page is uniquely designed with a gradient to match the image of the album.

7. Navbar and Footer
   These have been implemented according to the given specifications.


HOW TO OPEN THE SITE?
Start with running the homepage.html file 
and then you can just explore he website and refer the above descriptions of the pages to continue incase 
you get stuck.
-----------------------------------------------------------------------------------------------------
PHASE 2
-----------------------------------------------------------------------------------------------------

1. The search page was implemented in which the user enters the name of the artist or the name of the song and the filters required. On pressing the submit button the corresponding results are obtained.

2. When we clear the filters we have to press the submit button again for the changes to be reflected.

3. The results are as required to find with th details o fthe song, the image and the audio snippet.

4. The artist spotlight page was implemented as required.

5. The typing effect was added oon the artist spotlight page on the top

6. The nabvbars were updated on all pages with the required specifications using javascript on all pages.

7. A few changes were made on the homepage css to make the site more aesthetic. These include an animated background and rouded solid black borders on the images on the homepage.

-----------------------------------------------------------------------------------------------------
PHASE3
-----------------------------------------------------------------------------------------------------

1. The requirments asked to implement have been fulfilled

2. A databse by the name playlis is created which has a table with the fields of song name,albumname and artist name.

3. The navbars on each page, were also updated with the inclusing of a button for the playlist page and the so was the javascript of the navbars.

4. All the song pages were editte to incorporate a button which on clicking passes the fields to be added into the table as a parameter to the function. Each song has a unique id. The following convention is used 
01-35 artist 1

01-07 a1
08-14 a2
15-21 a3
22-28 a4
29-35 a5

36-70 artist 2

36-42 a1
43-49 a2
50-56 a3
57-63 a4
64-70 a5

71-105 artist 3

71-77 a1
78-84 a2
85-91 a3
92-98 a4
99-105 a5

106-140 artist 4

106-112 a1
113-119 a2
120-126 a3
127-133 a4
134-140 a5


141-175 artist 5

141-147 a1
148-154 a2
155-161 a3
162-168 a4
169-175 a5

If the song with the given id already exists then it is not added and an error message is displayed.
5. On the playlist page all the songs that are added by the user are visible.There is a remove button beside each song which on being clicked prompts a message which states that the song has been removed and the page gets refreshed on its own with the updated playlist.

Enjoy the website!!!!!
-----------------------------------------------------------------------------------------------------
DIRECTORY STRUCTURE
-----------------------------------------------------------------------------------------------------

.
├── ASSUMPTIONS.md
├── README.md
└── Src
    ├── about.css
    ├── about.html
    ├── Art1-Alb1.html
    ├── Art1-Alb2.html
    ├── Art1-Alb3.html
    ├── Art1-Alb4.html
    ├── Art1-Alb5.html
    ├── Art1.html
    ├── Art2-Alb1.html
    ├── Art2-Alb2.html
    ├── Art2-Alb3.html
    ├── Art2-Alb4.html
    ├── Art2-Alb5.html
    ├── Art2.html
    ├── Art3-Alb1.html
    ├── Art3-Alb2.html
    ├── Art3-Alb3.html
    ├── Art3-Alb4.html
    ├── Art3-Alb5.html
    ├── Art3.html
    ├── Art4-Alb1.html
    ├── Art4-Alb2.html
    ├── Art4-Alb3.html
    ├── Art4-Alb4.html
    ├── Art4-Alb5.html
    ├── Art4.html
    ├── Art5-Alb1.html
    ├── Art5-Alb2.html
    ├── Art5-Alb3.html
    ├── Art5-Alb4.html
    ├── Art5-Alb5.html
    ├── Art5.html
    ├── Artists.html
    ├── homepage.css
    ├── homepage.html
    ├── navbar.js
    ├── Photos
    │   ├── Art1-Alb1.png
    │   ├── Art1-Alb2.png
    │   ├── Art1-Alb3.png
    │   ├── Art1-Alb4.png
    │   ├── Art1-Alb5.jpg
    │   ├── Art1-Back.jpg
    │   ├── Art2-Alb1.png
    │   ├── Art2-Alb2.png
    │   ├── Art2-Alb3.png
    │   ├── Art2-Alb4.png
    │   ├── Art2-Alb5.jpg
    │   ├── Art2-Back.jpg
    │   ├── Art3-Alb1.jpg
    │   ├── Art3-Alb2.jpg
    │   ├── Art3-Alb3.jpg
    │   ├── Art3-Alb4.jpg
    │   ├── Art3-Alb5.jpeg
    │   ├── Art3-Back.jpg
    │   ├── Art4-Alb1.png
    │   ├── Art4-Alb2.png
    │   ├── Art4-Alb3.png
    │   ├── Art4-Alb4.png
    │   ├── Art4-Alb5.png
    │   ├── Art4-Back.jpg
    │   ├── Art5-Alb1.png
    │   ├── Art5-Alb2.png
    │   ├── Art5-Alb3.png
    │   ├── Art5-Alb4.png
    │   ├── Art5-Alb5.png
    │   ├── Art5-Back2.jpg
    │   ├── Art5-Back.png
    │   ├── note1.png
    │   ├── note2.png
    │   ├── note3.png
    │   ├── playbutton.png
    │   ├── samagra.jpeg
    │   ├── sujal.jpeg
    │   ├── topalbums.png
    │   ├── topartists.png
    │   ├── tophome.png
    │   ├── topsongs.png
    │   ├── vibin.png
    │   └── wallpaper.png
    ├── Playlist.css
    ├── Playlist.html
    ├── playtable.db
    ├── search.css
    ├── search.html
    ├── song.py
    ├── songs.css
    ├── songs.js
    ├── Spotlight.css
    ├── Spotlight.html
    └── Spotlight.js

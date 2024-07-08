# 🌟 The Maze Project 🌟

Welcome to **The Maze Project**! This project showcases a maze game with custom maps using SDL2 and raytracing. Dive into the world of mazes and experience the magic of real-time rendering!

### 🎮 The birth of an A-Maze-ing game!

#### Introduction

This is the story of a game, but not any game, this is the culmination of a year of SE learning at ALX, and the starting point of the most entertaining game in the web!

The project began as a small idea: I am a gamer, I love games, what is the best portfolio project that I could make ever? Exactly! a game.

This game was created with what I learned at ALX, C variables, loops, data structures, functions and lots, lots of mathematics.

IMAGE HOLDER MEME GAME

#### The Project development process

After choosing the project, I started by reading about SDL2, Raycasting, and the mathematic calculations needed to enable raycasting.

I started experimenting with a blank SDL2 window, choosing the title, dimensions, and other settings, I started with a small c file that contains all the the needed functions, compiled, and Tada!!! it works!

IMAGE HOLDER DEMO

Now let's move to the next step, add a map.
I added an array of zeros and ones to the main function, set up values for player position, fov, camera position, and made some calculations, defined the colors of each face of the 3D representation, and after a lot of trials and errors, it did'nt work!

IMAGE HOLDER MEME PROGRAMMER

It was in this moment, that I decided to make a pause, watch some Animes, drink a cup of tea, read the documentation, then go back to work, after another session of trials and errors, it was finally alive !!!

IMAGE HOLDER WORTHY

The program was running fine, and it was colorful, the dimensions were a bit off but I managed to get them done at the end, the view was worth all that fatigue and stress!

IMAGE HOLDER A VIEW OF THE GAME

Then I needed to implement movement, I started with camera movement, using mouse and keyboard, and it worked just fine, then I implemented player's movement using WASD keys, it was looking great!

IMAGE HOLDER ANOTHER VIEW

Now it's time for a new challenge, Implementing Textures.
I started by reading the doc of SDL2-Image, choosing textures, then finding a way to apply them instead of solid colors, after a lot of trial and error again, I finished by succeeding, and the results were fabulous!

After this, I applied another texture for the floor, then choose a simple blue color for the sky, The game is looking gorgeous!!

IMAGE HOLDER SCREEN APP WITH TEXTURE

After that, I implemented a minimap that can be switched on or off using M key, it was like doing a little game inside of the main game, but the result was very satisfying!

IMAGE HOLDER MAP

After that I edited the program to accept a text mapfile as an argument, then parse it to have a customized map.

IMAGE HOLDER FILE

After everything has been done, a little problem remained: making all these c files and headers compliant with [Holeberton School Betty Style](https://github.com/alx-tools/Betty) tool. And it was quite the challenge!

Betty style imposed special guidelines when coding using C:
- A file cannot contain more than 5 functions
- All functions and data structures must be documented
- A function cannot exceed 40 lines
- A line cannot exceed 80 characters
- Global variables are forbidden

I started by splitting up my c files, splitting the lines over 80 characters, and creating smaller functions while calling them from the previous bigger functions.
One small problem was remaining, I used global variables to hold the game state, so it was inevitable that I choose another method. A friend of mine proposed Data structures, and it was awesome!

I created data structures to hold key press states, game state, and it was awesome, I was able to manipulate data over the game like before, and clean output of Betty Checker gave me a huge satisfaction!

IMAGE HOLDER BETTY

The game was ready, it was playable, and I met the deadline with more functions than I was even aiming at before, It was a tremendous success!

#### Conclusion

This was a glance behind the scenes of the creation of this project. I welcome your contributions, so feel free to fork this repository and submit pull requests with your improvements or new features!

### 🌐 Project Website

Check out our project website to learn more about The Maze Project: [Project Website](https://dexterski007.github.io/The-Maze-Project/)

### 👥 LinkedIn Profile

Connect with us on LinkedIn: [LinkedIn Profile](https://www.linkedin.com/in/mohamed-boujelfa-128b0a287/)


## 📋 Table of Contents
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Map File Format](#map-file-format)
- [Screenshots](#screenshots)
- [Authors](#authors)
- [Contributing](#Contributing)
- [Related Projects](#Related-Projects)
- [Licensing](#Licensing)

## 🛠️ Installation

(Instructions for Ubuntu and debian based distros)
To get started, you need to install the necessary prerequisites. Simply run the following script:

```bash
sudo ./install_SDL2.sh
```

## 🏗️ Compilation

(Instructions for Ubuntu and debian based distros)
Once the prerequisites are installed, compile the project by running:

```bash
./compil.sh
```

## 🚀 Usage

Execute the program using a map file (a 24 by 24 file of zeros and ones that represent a maze):

```bash
./myapp mapfile
```

Replace mapfile with the path to your maze file.

## 🗺️ Map File Format

The map file should be a 24x24 grid of zeros and ones, where:

    0 represents an open path
    1 represents a wall

Example map file:

```Map
111111111111111111111111
100000000000000000000001
101111111111111111111101
101000000000000000000101
101011111111111111110101
101010000000000000010101
101010111111111111010101
101010100000000001010101
101010101111111101010101
101010101000000101010101
101010101011111101010101
101010101010001101010101
101010101010100101010101
101010101010101101010101
101010101010101001010101
101010101010101111010101
101010101010100000010101
101010101010111111110101
101010101010000000000101
101010101011111111110101
101010101000000000010101
101010111111111111010101
101000000000000000000101
111111111111111111111111
```

## 📸 Screenshots

![Capture d’écran du 2024-06-30 20-54-52](https://github.com/dexterski007/The-Maze-Project/assets/144383579/8b1621db-b110-45db-8417-729db1626cc3)
![Capture d’écran du 2024-06-30 20-55-43](https://github.com/dexterski007/The-Maze-Project/assets/144383579/64708a4c-06e2-4327-9faa-2cb5c1909d46)
![Capture d’écran du 2024-06-30 20-56-56](https://github.com/dexterski007/The-Maze-Project/assets/144383579/122b7c31-5fb4-434e-823e-6bf3aa3db2cc)


## 👥 Authors

- dexterski007

## 🤝 Contributing
We welcome contributions to The Maze Project! If you would like to contribute, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your changes to your forked repository.
5. Open a pull request to the main repository.

We appreciate your contributions and will review your pull request as soon as possible.

## 🔗 Related Projects
Here are some related projects that you might find interesting:
- [SDL2](https://github.com/libsdl-org/SDL): SDL2 Library.
- [SDL2 Image](https://github.com/libsdl-org/SDL_image): SDL2 image library for textures.

## 📄 Licensing
The Maze Project is licensed under the MIT License. You can find the full license text in the [LICENSE](https://github.com/dexterski007/The-Maze-Project/blob/main/LICENSE) file.

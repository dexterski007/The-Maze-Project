# 🌟 The Maze Project 🌟

Welcome to **The Maze Project**! This project showcases a maze game with custom maps using SDL2 and raytracing. Dive into the world of mazes and experience the magic of real-time rendering!

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

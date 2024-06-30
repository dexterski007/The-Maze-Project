# 🌟 The Maze Project 🌟

Welcome to **The Maze Project**! This project showcases a maze generation and solving algorithm using SDL2 and raytracing. Dive into the world of mazes and experience the magic of real-time rendering!

## 📋 Table of Contents
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Map File Format](#map-file-format)
- [Screenshots](#screenshots)
- [Authors](#authors)

## 🛠️ Installation

To get started, you need to install the necessary prerequisites. Simply run the following script:

```bash
sudo ./install_SDL2.sh
```

## 🏗️ Compilation

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

## 👥 Authors

- dexterski007

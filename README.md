# AVL Tree Dictionary Search

A C++ program that uses self-balancing AVL trees to store and search dictionary words efficiently.

## Features

- Implements AVL tree insertion and searching
- Performs LL, RR, LR, and RL rotations to maintain balance
- Loads words from a dictionary file
- Processes text from Oliver Twist
- Organizes words across 26 AVL trees based on starting letter
- Tracks search comparisons to evaluate lookup efficiency

## Technologies

- C++
- AVL Trees
- File I/O
- CMake

## Files

- `AVLTree.cpp` – AVL tree implementation
- `AVLTree.h` – AVL tree class definitions
- `main.cpp` – program execution and text processing
- `random_dictionary.txt` – dictionary input
- `oliver.txt` – text input used for searching

## Running the Project

The project can be compiled using CMake or a standard C++ compiler.

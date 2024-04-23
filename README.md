# Binary Tree Program

This program is a simple implementation of a binary tree in C. It allows the user to interactively add nodes to the tree and display the tree in InOrder traversal.

## Features

1. **Add a Node**: The user can add a node to the binary tree. The tree will store an integer in each node.
2. **Display the Tree**: The user can display the content of the tree in InOrder traversal.
3. **Exit**: The user can exit the program.

## How to Run

To compile the program, use the following command:

```bash
gcc main.c -o main
```

### Or run with CMake

```bash
mkdir build
cd build
cmake ..
make
./treeDFSInorder
```

## How to Use

When you run the program, you will see a menu with three options:

Insert node: If you choose this option, you will be asked to enter the data for the node (an integer) and the direction where the node will be inserted (L for left, R for right).
Display InOrder: If you choose this option, the program will print the content of the tree in InOrder traversal.
Exit: If you choose this option, the program will end.

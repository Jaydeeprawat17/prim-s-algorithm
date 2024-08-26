# Prim's Algorithm in Turbo C++

This program implements Prim's Algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected graph. Prim's Algorithm is a greedy algorithm that finds the MST by growing the spanning tree one vertex at a time from an arbitrary starting vertex, always adding the smallest edge that connects a vertex in the tree to a vertex outside the tree.

## Features

- **Input**: The user can input the number of edges and details for each edge (two vertices and the weight of the edge).
- **Output**: The program outputs the MST in terms of the edges selected and their weights.

## How to Compile and Run

### Requirements

- Turbo C++ compiler.

### Compilation Steps

1. Open Turbo C++.
2. Create a new file and copy-paste the code into the file.
3. Save the file with a `.cpp` extension.
4. Compile the code by navigating to **Compile** > **Compile** or pressing `Alt + F9`.

### Running the Program

1. Run the program by navigating to **Run** > **Run** or pressing `Ctrl + F9`.
2. Follow the prompts to input the number of edges and the details of each edge.
3. The output will display the Minimum Spanning Tree and the total weight.

## Code Structure

The program consists of a few main parts:

- **Graph Structure**: Represents the edges and their weights.
- **Priority Queue (Q)**: Used to store vertices and their weights, mimicking a priority queue.
- **Prim's Algorithm Class**: Contains the methods to:
  - Set up the graph based on user input.
  - Initialize the priority queue.
  - Extract the minimum from the queue.
  - Execute Prim's Algorithm to find the MST.


## Notes

- **Turbo C++**: This code is specifically written for Turbo C++ and might need modifications to work in other compilers.
- **Graph Representation**: The graph is represented by its edges rather than an adjacency list or matrix, which is sufficient for Prim's Algorithm.
- **Clear Screen**: The program uses `clrscr()` and `getch()` for screen management, which are specific to Turbo C++.




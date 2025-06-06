# Knight’s Tour

## Authors

- Gal Rubinstein
- Eitan Katz

---

## Overview

This project implements a Knight’s Tour solver on a 5x5 chessboard using recursive tree-based pathfinding. It is designed as an academic assignment to explore:

- Representation of chessboard positions using custom data structures.
- Recursive generation of all possible Knight’s paths from a given start position.
- Construction of a path tree where each branch represents a potential Knight’s path visiting unique squares.
- Use of dynamic memory management and linked lists to handle paths and moves efficiently.

---

## Setup Instructions

1. **Clone the Repository**  
   ```bash
   git clone https://github.com/JusticeIL/knight-s_tour_in_c.git
   cd knight-s_tour_in_c
   ```

2. **Open the project**  
   open the file `knights_tour.sln`.


3. **Play the .sln file**  
   click the `Start Without Debugging` button and follow the menu instructions opened in a new console window.

---

## Program Features

- **Chessboard Representation:**  
  Defines a 5x5 chessboard with positions labeled from 'A' to 'E' for rows and '1' to '5' for columns.

- **Path Tree Construction:**  
  Builds a recursive tree (`pathTree`) starting from a given Knight position, where each node contains possible subsequent Knight moves without revisiting squares.

- **Move Validation:**  
  Uses a precomputed 2D array of possible Knight moves (`chessPosArray ***`) to efficiently check legal moves.

- **Memory Management:**  
  Includes functions to create and free dynamic data structures such as linked lists and trees to avoid memory leaks.

---

## License

This repository is intended for educational purposes only.

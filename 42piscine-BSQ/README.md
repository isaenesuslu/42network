
# 🟦 BSQ (Biggest Square)

> **42 Piscine Final Project**

**BSQ** is a classic algorithmic project from the 42 School Piscine curriculum. The main goal is to find the largest possible square on a given map, avoiding obstacles, and to print the map with the square filled in.

---

## 📖 About The Project

The program takes a file (or standard input) containing a map representation as an argument. It finds the largest square that can be drawn on the empty characters without crossing any obstacles.

- If multiple squares of the same size are found, it selects the **top-left most** one.
- The program handles multiple files sequentially.
- It parses valid maps and rejects invalid ones strictly according to the subject rules.

---

## 🚀 Getting Started

### Prerequisites

You need a **C compiler** (gcc or clang) and **Make** installed on your system.

### Installation

1. Clone the repository:
   ```bash
   git clone [https://github.com/isaenesuslu/42-Piscine-BSQ.git](https://github.com/isaenesuslu/42-Piscine-BSQ.git)
   cd 42-Piscine-BSQ


2.  Compile the executable using the Makefile:
    ```bash
    make
    ```
    This will generate an executable file named `bsq`.

-----

## 💻 Usage

To run the program, provide one or more map files as arguments:

```bash
./bsq map_file.txt
```

You can also pass multiple files:

```bash
./bsq map1 map2 map3
```

### Standard Input

If no arguments are provided, the program reads from the Standard Input (Ctrl+D to stop reading):

```bash
./bsq
```

-----

## 🗺️ Map Format Rules

The map file must follow a strict format to be considered valid:

1.  **First Line (Header):**

      - Must contain the number of lines, followed by three characters:
          - `Empty character` (e.g., `.`)
          - `Obstacle character` (e.g., `o`)
          - `Full character` (e.g., `x`)
      - *Example:* `9.ox` means 9 lines, empty is `.`, obstacle is `o`, and the square will be filled with `x`.

2.  **The Grid:**

      - All lines must have the same length.
      - It must contain only "empty" and "obstacle" characters.
      - There must be at least one line of at least one box.

### Example Input

```text
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

### Example Output

```text
.xxxxxxx...................
.xxxxxxxo..................
.xxxxxxx....o..............
.xxxxxxx...................
.xxxxxxxo..................
.xxxxxxx.......o...........
.xxxxxxx...................
......o..............o.....
..o.......o................
```

-----

## ⚙️ Algorithm

This project implements an efficient algorithm (typically Dynamic Programming) to solve the problem in `O(n)` time complexity rather than using a brute-force approach.

1.  An auxiliary matrix is used to store the size of the largest square ending at each point.
2.  The value is derived from the minimum of the neighboring cells (left, top, top-left) plus one.
3.  The maximum value in this matrix determines the size and position of the biggest square.


-----

*This project was completed as part of the 42 Kocaeli Piscine curriculum.*
```

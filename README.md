# Sudoku Verifier

A robust command-line utility developed in ANSI C++ to validate Sudoku solutions.

## Project Overview

The core objective is to verify if a given Sudoku grid follows the fundamental rules:
1. **Rows:** Each row must contain all integers from 1 to $N$ without repetitions.
2. **Columns:** Each column must contain all integers from 1 to $N$ without repetitions.
3. **Regions:** Each square sub-grid (region) must contain all integers from 1 to $N$ without repetitions.

The program processes input via standard input, validates the data format, prints an aesthetically pleasing representation of the board, and provides a final verdict.

## Key Features

* **Scalability:** Unlike standard verifiers limited to $9\times9$, this implementation is designed to be easily adapted to any square-region Sudoku size (e.g., $4\times4$, $16\times16$, $25\times25$) simply by modifying two constants (`MIDA_S` and `MIDA_R`).
* **Robust Error Handling:** Detects out-of-range numbers, non-numeric characters, and truncated input files, reporting the exact cell where the error occurred.
* **Formatted Output:** Features a specialized printing function that renders the grid with distinct borders for regions and rows using ASCII characters (`#===`, `+---`, etc.).
* **Efficiency:** Stops processing immediately upon finding the first rule violation (Rows -> Columns -> Regions) to optimize execution time.

## Technologies Used

* **Language:** ANSI C++.
* **Standard:** Compiled with the `-ansi` flag to guarantee standard compliance.
* **Libraries:** `stdio.h`

## How to Run

1.  **Compile the program** using the ANSI standard:
    ```bash
    g++ -ansi practica2.cpp -o practica2
    ```
2.  **Run with a Sudoku file** (using redirection):
    ```bash
    ./practica2 < Exemples/sudoku3x3.txt
    ```

## Technical Note (Language)
The source code, variable names, and internal comments are written in **Catalan**, as it was an academic project for University of Lleida (Catalonia) as part of the **Computer Science degree (Programació I, 2024-2025)**. This documentation is provided in English for universal portfolio visibility.

---
**Developed by:** Eric Buenavida Crespo.
# Matrix-Multiplication
## Project Overview
This project presents an efficient approach to matrix multiplication, specifically tailored for square matrices, by leveraging the power of POSIX Threads (pthreads). The implementation focuses on parallel computation, where the workload is distributed across multiple threads to optimize performance on multi-core processors. It adheres to a specific structure in thread management and matrix division to ensure optimal resource utilization and computational efficiency.

## Key Features
**Specialized for Square Matrices:** The algorithm is designed exclusively for the multiplication of square matrices (n × n dimensions).

**Thread Management:** The number of threads, denoted as p, is chosen based on the condition that n² is divisible by p. Additionally, p is restricted to square numbers to facilitate even workload distribution.

**Optimized Workload Distribution:** The resultant matrix is divided into blocks, forming a √p × √p array, for parallel computation.
Matrix Division and Thread Mapping
Matrix Block Division: The output matrix C is segmented into smaller blocks, each denoted as Pxy, where x and y correspond to the block’s row and column within the √p × √p block array.

**Thread-to-Block Mapping:** Each thread, identified by a rank k (0 ≤ k ≤ p − 1), is mapped to a specific block. The mapping follows two key rules:
The row of the block (x) is determined by ⌊k/√p⌋.
The column of the block (y) is calculated as k % √p.
This structure ensures that each thread is responsible for computing a specific part of the matrix, enhancing the efficiency of the multiplication process.

## System Requirements
C++ Compiler (GCC recommended) and POSIX Threads Library (pthread).

## Compilation and Execution
**To compile the program run the makefile using the make command.**

**To run the program run:**
1) First run ./matrixgen -s [sizeofMatrix]
2) Then ./main


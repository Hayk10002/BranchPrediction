# BranchPrediction

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)
- [How does this work](#how-does-this-work)

## Introduction
The purpose of this project is to analyze the impact of branch prediction on performance by testing a loop with varying probabilities of branch conditions being true. The project demonstrates how branch prediction affects execution time and provides insights into optimizing code for modern CPUs.

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/BranchPrediction

# Go into the repository
$ cd BranchPrediction

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Then, run the executable generated in the `build` directory with the vector size and iteration count to run the test.
$ your/path/to/exe/main.exe {vector_size} {iteration_count}
# example - .../main.exe 3000000 10
```

## Possible Output
(for vector size 3000000 and iteration count 10)

```
Probability of branch true:   0%, time:   66ms.
Probability of branch true:   5%, time:   59ms.
Probability of branch true:  10%, time:   69ms.
Probability of branch true:  15%, time:   92ms.
Probability of branch true:  20%, time:   90ms.
Probability of branch true:  25%, time:  114ms.
Probability of branch true:  30%, time:  121ms.
Probability of branch true:  35%, time:  132ms.
Probability of branch true:  40%, time:  171ms.
Probability of branch true:  45%, time:  179ms.
Probability of branch true:  50%, time:  203ms.
Probability of branch true:  55%, time:  173ms.
Probability of branch true:  60%, time:  166ms.
Probability of branch true:  65%, time:  156ms.
Probability of branch true:  70%, time:  139ms.
Probability of branch true:  75%, time:  113ms.
Probability of branch true:  80%, time:  101ms.
Probability of branch true:  85%, time:   83ms.
Probability of branch true:  90%, time:   67ms.
Probability of branch true:  95%, time:   38ms.
Probability of branch true: 100%, time:   10ms.
```

## How does this work
The project evaluates the performance impact of branch prediction by iterating over a vector of integers and measuring execution time for different probabilities of a branch condition being true. The results highlight how modern CPUs optimize predictable branches and struggle with unpredictable ones.

The code generates random data, processes it with varying branch probabilities, and records the time taken for each scenario. This helps in understanding how branch prediction can influence performance and guides developers in writing branch-efficient code.

From benchmarks, it can be infered that more predictable results (0% or 100% cases) yield faster execution, and the least predictable, 50/50 scenario is the worst performant one.

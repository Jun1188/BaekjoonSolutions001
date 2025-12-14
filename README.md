# BaekjoonSolutions001
My Baekjoon Online Judge Solutions (20251214~)

## About
This repository contains my solutions to problems from [Baekjoon Online Judge](https://www.acmicpc.net/), primarily written in C++.

## Structure
```
solutions/
├── template.cpp       # Template file for new solutions
└── [problem_number].cpp  # Solution files named by problem number
```

## How to Use

### Adding a New Solution
1. Copy `solutions/template.cpp` to create a new solution file
2. Name the file with the problem number (e.g., `1000.cpp`, `2557.cpp`)
3. Fill in the problem details in the header comment
4. Implement your solution

### Compiling and Running
```bash
# Compile a solution
g++ -o solution solutions/[problem_number].cpp -std=c++17

# Run the compiled solution
./solution

# Or compile and run in one command
g++ solutions/[problem_number].cpp -std=c++17 -o solution && ./solution
```

## Template Format
Each solution file includes:
- Problem number and title
- Link to the problem
- Problem tier/difficulty
- Date solved
- Brief description of the problem
- Solution approach explanation

## Progress
- Start Date: December 14, 2025
- Total Problems Solved: [Update as you go]

## Notes
- All solutions are written in C++
- Fast I/O is enabled by default in the template (`ios_base::sync_with_stdio(false)`)
- Solutions focus on correctness and efficiency

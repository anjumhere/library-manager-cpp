# Library Manager (C++)

A console-based library management system written in C++, built to apply object-oriented design, inheritance, templates, and the STL in a real (if small) system — not just isolated exercises.

## Features

- Add, remove, and search books by title, author, or ISBN
- Track book availability and issue/return status
- Book hierarchy via inheritance (e.g. `Book` → `PrintedBook` / `EBook`)
- In-memory storage using STL containers (`vector`, `map`)
- Persistent storage — library state is saved to and loaded from a file between runs
- Basic input validation and error handling

## Design

| Concept           | Where it's used                       |
| ----------------- | ------------------------------------- |
| OOP / Inheritance | Book type hierarchy                   |
| Templates         | Generic container/utility logic       |
| STL               | `vector`, `map` for in-memory catalog |
| File I/O          | Persisting catalog state to disk      |

## Build

```bash
g++ -std=c++17 -Wall src/main.cpp -o library-manager
./library-manager
```

## Status

🚧 In active development — built in daily sessions alongside ongoing DSA practice. Features are added incrementally as each concept is covered.

## Roadmap

- [ ] `Book` base class + derived types
- [ ] In-memory catalog with STL containers
- [ ] Issue/return tracking
- [ ] File persistence (save/load)
- [ ] Search and filter functionality
- [ ] Basic CLI menu system

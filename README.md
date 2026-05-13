# C++ To-Do List Application

## Overview

This project is a simple console-based To-Do List application built using C++. It allows users to:

* Display tasks
* Add new tasks
* Remove tasks
* Mark tasks as completed
* Save tasks permanently using a text file

The application uses file handling so tasks remain saved even after closing the program.

---

# Features

## 1. Display Tasks

Shows all tasks stored in the to-do list.

## 2. Add Task

Allows the user to add a new task.

## 3. Remove Task

Deletes a selected task from the list.

## 4. Complete Task

Marks a task as completed by adding `[Done]`.

## 5. File Saving

All tasks are automatically saved inside:

```txt
Todolist.txt
```

---

# Technologies Used

* C++
* Vector STL
* String Library
* File Handling (`fstream`)

---

# Libraries Used

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
```

| Library    | Purpose               |
| ---------- | --------------------- |
| `iostream` | Input and output      |
| `vector`   | Dynamic task storage  |
| `string`   | Text handling         |
| `fstream`  | Reading/writing files |

---

# Project Structure

```txt
main.cpp
Todolist.txt
README.md
```

---

# How It Works

1. The program loads tasks from `Todolist.txt`
2. Displays a menu for the user
3. Executes the selected operation
4. Saves updates automatically
5. Repeats until the user exits

---

# Functions Used

## loadTasks()

Reads tasks from the text file.

## saveTasks()

Saves all tasks into the file.

## displayTasks()

Displays all current tasks.

## addTask()

Adds a new task to the vector.

## removeTask()

Deletes a task using its index.

## completeTask()

Marks a task as completed.

## DisplayMenu()

Shows the application menu.

---

# Example Output

```txt
To-Do List Application
1. Display Tasks
2. Add Task
3. Remove Task
4. Complete Task
5. Exit
```

---

# Example Tasks

```txt
1. Study C++
2. Go Gym [Done]
3. Finish Assignment
```

---

# Future Improvements

Possible future features:

* Edit task
* Task priorities
* Due dates
* Search functionality
* GUI version
* OOP implementation using classes

---

# Author

Created as a C++ practice project for learning:

* STL
* File Handling
* Functions
* Vectors
* Strings
* Console Applications

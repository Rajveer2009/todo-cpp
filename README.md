# 📝 Todo-CPP

A simple command-line todo list manager written in C++. It lets you add, list, mark done, remove, and reset tasks stored in a text file.

## 🚀 Features

- Add tasks with timestamps.
- List tasks in different formats.
- Mark tasks as done.
- Remove tasks.
- Reset (clear) the todo list.
- Uses `TODO_PATH` environment variable for the todo file.

## 📋 How to Use

Set the path for your todo file:

```bash
export TODO_PATH=/path/to/todo.txt
```
Run the program with commands:

```bash
./todo-cpp [command] [arguments]
```

### Commands

| Command  | Arguments     | What it does                       |
|----------|---------------|------------------------------------|
| `add`    | `task`        | Add a new task                     |
| `list`   | None          | Show tasks (descriptions only)     |
| `listC`  | None          | Show tasks with numbers & details  |
| `listN`  | None      	   | Show numbered tasks (descriptions) |
| `mark`   | `task number` | Mark a task as done                |
| `remove` | `task number` | Remove a task                      |
| `reset`  | None          | Clear all tasks                    |

## 🔧 Example

```bash
export TODO_PATH=~/todo.txt

./todo-cpp add "Buy milk"
./todo-cpp list
./todo-cpp mark 1
./todo-cpp remove 1
./todo-cpp reset
```

## 🛠️ Build
To compile the program, run:

```bash
g++ -o todo-cpp todo-cpp.cpp
```

## [License](LICENSE.md)

`Copyright (C) 2025 Rajveer Singh Saggu`
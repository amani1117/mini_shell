# Mini Shell in C

A simple Linux shell implemented in C to understand process creation and execution.

## Features
- Executes system commands using fork and execvp
- Built-in cd command
- Custom input parser

## How to compile
gcc mini_shell.c -o shell

## How to run
./shell

## Todo App
A simple command-line todo app that works with the shell.

### Commands
- `todo add "task"` — add a task
- `todo show` — display all tasks
- `todo remove <id>` — remove a task by ID
- `todo clear` — clear all tasks

### How to compile
gcc todo.c -o todo

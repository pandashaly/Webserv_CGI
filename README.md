# CGI Module for 42 Webserv Project

This is a modular CGI execution system designed to plug into the 42 `webserv` project.

### 🌐 Overview

The CGI module handles execution of external scripts (e.g. Python, PHP) using the Common Gateway Interface (CGI) standard. It receives request data from the web server, builds the environment, runs the script via `execve`, and returns the output.

### 📦 Structure of my project

I've devided the logic into 4 parts:

1. **receiveRequest** – stores HTTP request data
2. **prepEnv** – builds environment variables for CGI
3. **executeScript** – forks, runs the script, and pipes output
4. **returnOutput** – reads and returns script output to the server

A wrapper class `CgiHandler` coordinates the whole process.

Dividing it into 4 different parts, respective to the 4 main steps or stages of a CGI progrmam has helped me understand how it works better.
They mirror the actual flow of CGI execution and by dividing it I can keep each stage of the CGI lifecycle clear, testable, and independently manageable.
This modular approach makes it easier to understand and debug each responsibility (input parsing, environment setup, execution, and output handling) without getting overwhelmed by a large monolithic class.
It also ensures better separation of concerns and will simplify future maintenance or extension (e.g. adding support for more languages or timeout handling for bigger servers).

A wrapper class `CgiHandler` coordinates the whole process.

### 🧪 Usage

Currently testable as a standalone module with `main.cpp`. Not yet integrated into the server.

### 🛠 Languages Supported

- Python (.py)
- Bash (.sh)

> Project is WIP to experiment independently before integration.

---

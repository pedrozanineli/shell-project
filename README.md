### Shell Project - Computer Architecture

---

An important part in the study of Computer Architecture - how the data is going to be transferred, processed, exhibited, and how to computer's hardware work in this process - is the Operating system, the software responsible for the basic functions of a machine.

Furthermore, it is essential to understand the concept of a <strong>shell</strong> as an OS service offered for communication between the user and a program. Therefore, this project has the purpose to create a command-line interface (CLI) to understand more this essential machine part.

### Main Functions

---

By running the program, it is possible to see the following visual interface and execute a command. It is also possible to see it in the following example, as well as the command "help", important to understand the main functions of the shell.

```text
Shell Project - Pedro Zanineli

> help
- rfile - read file
- lfile: list files
- tfile: file type
- dir: show directory's path
- cfile: clear file
- cpfile: copy file
- rps - play rock, paper and scissors
- clear: clear shell
- exit: end shell
>
```

With the command "dir", we can see a similar output to the Linux shell command "pwd", or print working directory

```text
Shell Project - Pedro Zanineli

> dir
Current working directory: C:\Users\Pedro-Zanineli\Desktop\Programming-Projects\Shell
>
```

### Files Disposal

In the project-shell.c file, where the "main" function is located, there is a switch-case method, executing a function according to the user input. Since it is necessary to use this method with a number char, the method "conversor" makes the conversion between the command input to the correct char option.

For this reason, there is a file dedicated to the conversion method, and also to the "rps" function - play rock, paper, and scissors - demanding three different files for the project (main file, the C library, and the header for the C lib).

> shell-project.c: main file;

> shell-lib.c: important methods;

> shell-lib.h: header for the shell-lib.c.

Once it is needed to compile the main file with the C library, the following command was executed in a Linux terminal with the GNU compiler collection (GCC):

```text
gcc shell-project.c shell-lib.c -o compiled-shell
```

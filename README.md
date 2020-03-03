# Continuous_integration_3557h
## By the incredibles
The focus of the assignment is on the testing, CI, CD and Makefiles.
The project shall use automatic tests, CI, CD, Makefiles and at least some tests
writen in Python. Start with an empty main (or something simple like a print out
to see that it is running) and then continue with CI/CD and Makefile.
Start implementing features by writing test cases and then write the code.

The projects will be presented on March 24th where you will be divided into groups with one person from each project where you will present your project.

 

These are suggestions on assignments which your group may choose.

 

- Implement a REST server (basically HTTP).
  Implement GET, PUT and DELETE to store data on the filesystem. You may store
  the data as text files.
  Possible features:
    - An index path to list all existing files

 

- ESP32 command line over UART.
  Implement a command line on the ESP32 UART where a user can run commands.
  Possible features:
  - Implement to read and write values and/or pointers from the command line.
  - Implement calling predefined functions.
  - Implement storing some values as non-volatile (i.e. keeps the value after reboot)
  Some features sholud be visible by hardware, e.g. allow you to control LEDs
  by writing a command.

 

- Write a network server
  Implement a simple TCP server which can receive commands over the network. It
  only needs to handle one client at a time.
  Possible features:
  - Commands for storing and retrieving data from files
  - Login
  - Add user/remove user


C test workflow badge:
![C/C++ CI](https://github.com/JesperMell/Continuous_integration_3557h/workflows/C/C++%20CI/badge.svg)

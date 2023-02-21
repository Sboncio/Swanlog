# Swanlog change

C++ basic logging system

## Description

This is a very basic logging system that I created to help with personal projects in the future.
It's extremely basic and easy to add to current C++ projects, providing three levels of logging.

## How to use

1. Add the .hpp file to your headers:

```cpp
    #include "swanlog.hpp"
```

2. Create a logger object with the name of your project (not essential, but helps when naming your log file):

```cpp
    swanlog logger("Swanlog");
```

In this example, I called the object 'logger' and the log file will be named "Swanlog". The program will create the folders and files for you.

3. Make a log. Use the function writeline (named after a bad experience with VB6), to write to the previously made file. You can specify the logging level in the same function:

| Level | Meaning       |
| ----- | ------------- |
| 1     | LOG (default) |
| 2     | WARNING       |
| 3     | ERROR         |

```cpp
logger.writeline("This is an example warning log", 2);

```

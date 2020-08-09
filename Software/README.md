# Software Folder

Made by Group 6 from ENGR301 & ENGR302 courses from the Victoria University of Wellington (2020).

## Description
This folder contains all the software resources for this project.

## GitLab Build Pipeline
This repository automatically verifies this software by compiling in PlatformIO.
To include a PlatformIO workspace to be a part of the automatic build checker, please ensure the folder is located in the same directory as this file and
include the name of the folder/workspace in its own line in the `platformio_workspace_paths.txt` file.

For example:

|--software
|  |
|  |--MyWorkspace - (The Workspace to Add)
|  |  ...
|  |  -src
|  |  -platformio.ini
|  |
|  |-platformio_workspace_paths.txt

We would add the following in the file `platformio_workspace_paths.txt`:
```
MyWorkspace
```

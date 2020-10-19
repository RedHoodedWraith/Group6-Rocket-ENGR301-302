#!/usr/bin/env python3

# Software Compiler Script
# Original Author: Rowan Rathod
# Made for the ENGR301/302 Group Project at VUW (2020)
#
# Description: This script checks if the provided software in this repository
# is able to be built in PlatformIO for its intended target device

import subprocess as sp

# Path to the file that contains the list of PlatformIO workspaces to compile
listfile_path = "platformio_workspace_paths.txt"

# List of Workspaces to Compile
workspace_names = []

# Dictionary of Compile Results
build_results = {}

# Boolean if the everything Succeeded
all_passed = True

# Compiles/Builds a given Workspace in PlatformIO
def compile_workspace(ws_name):
    #subprocess.call(["pio", "run", "-d", ws_name])
    sp.run(["pio", "run", "-d", ws_name]).check_returncode()

# Returns a provided word without whitespace characters
def remove_whitespaces(word):
    return word.replace('\n', '')

# Parses the File with the list of workspaces to compile
def parse_file():
    global workspace_names
    try:
        file = open(listfile_path, "r")
        workspace_names = file.readlines()
    except FileNotFoundError:
        print("Error: Couldn't find file with list of PlatformIO workspaces to compile.")
        print("Please there is a file named '" + listfile_path
        + "' in the same directory as this script")
        exit(1)

    for index, word in enumerate(workspace_names):
        new_word = remove_whitespaces(word)
        workspace_names[index] = new_word

    for word in workspace_names:
        if not word:
            workspace_names.remove(word)

# The Main Function
def main():
    global all_passed

    print ("Starting Script Runner...")
    parse_file()
    print("Attempting to compile the following workspaces:")

    # Iterates through the Workspaces & Records What Succeeded
    for ws_name in workspace_names:
        try:
            compile_workspace(ws_name)
            build_results[ws_name] = True
        except:
            build_results[ws_name] = False
            all_passed = False

    # Reports the results
    print("\nHere is a summary of the results: ")
    for ws_name in build_results:
        result = "\t* " + ws_name + " - "
        if build_results[ws_name]:
            result += "Passed"
        else:
            result += "Failed"
        print(result)

    if not all_passed:
        exit(2)

# Runs the Main Function
if __name__ == "__main__":
    main()

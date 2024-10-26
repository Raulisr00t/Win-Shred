# Secure File Deletion Utility for Windows (shred.exe)

## Overview
This C program implements a utility called shred.exe that securely deletes files by overwriting them with random data before deletion. The utility is designed for Windows systems and helps prevent data recovery by unauthorized users.

## Features
Secure Deletion: Overwrites the specified file with random bytes, making data recovery extremely difficult.
Error Handling: Provides informative error messages when file operations fail (e.g., opening, reading, deleting).
Simple Usage: Command-line interface that allows users to specify the filename for deletion.

## Usage
Compile the Code: Use a C compiler (like MinGW or MSVC) to compile the program. For example, with GCC:

``` powershell
gcc -o shred shred.c
```
Run the Executable: Execute the program from the command line, providing the filename you want to delete:

```powershell
shred.exe <filename>
```

### Example
To securely delete a file named sensitive_data.txt, run:

```powershell
shred.exe sensitive_data.txt
```
### Implementation Details
File Handling: The program uses Windows API functions to open, read, and delete files.
Random Data Generation: It fills a buffer with random data before writing it back to the file to ensure the original content is overwritten.
Memory Management: Allocates memory for the buffer dynamically and ensures it is freed after use.

### Limitations
This utility does not support overwriting multiple times; enhancing it for added security could be considered.
Make sure to use this program with caution, as it irreversibly deletes data.

## License
This project is open-source and can be modified for personal or educational use. Use at your own risk.

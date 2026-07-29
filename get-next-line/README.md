*This project has been created as part of the 42 curriculum by iuslu*

# Get Next Line

## Description
The get_next_line project is a fundamental exercise in C programming that involves creating a function to read a line from a file descriptor. The goal is to implement a solution that can handle repeated calls to return the next line of a text file, one at a time, until the end of the file is reached. This project introduces the critical concept of static variables in C and teaches efficient memory and buffer management.

## Instructions
To compile the project, use the following flags with cc:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

- BUFFER_SIZE: This macro defines the size of the buffer used for the read() function. The project must work with different buffer sizes (e.g., 1, 42, 999999).
- Mandatory Files: get_next_line.c, get_next_line_utils.c, get_next_line.h.
- Bonus Files: get_next_line_bonus.c, get_next_line_utils_bonus.c, get_next_line_bonus.h.

## Resources
During the development of this project, several resources were utilized:
- Peer Learning: Significant insights were gained through discussions with peers at the 42 Kocaeli campus regarding logic and edge case handling.
- AI Assistance: AI tools were used as a learning aid to understand the following concepts:
    * The internal mechanics of the read() function.
    * The practical application and lifecycle of static variables.
    * The impact of different BUFFER_SIZE values on performance and memory.
- Documentation: Standard C library documentation for read, malloc, and free.

## Algorithm Justification
The selected algorithm focuses on persistent data management using a static variable to store data read from the file descriptor across multiple function calls.

### Mandatory Part
1. Storage: A static string is used to keep track of the remaining characters from previous reads.
2. Detection: After each read operation, the strchr function is used to locate the first occurrence of a newline character (\n).
3. Calculation: If a newline is found, the distance between the start address and the \n address is calculated to determine the exact number of bytes needed for the current line.
4. Extraction: The line is extracted and returned to the user, while the "leftover" portion is saved back into the static variable for the next call.

### Bonus Part (Multiple File Descriptors)
For the bonus section, a "drawer" logic was implemented using only one static variable. Instead of a single pointer, the static variable is managed as an array where each index corresponds to a specific file descriptor. This allows the function to handle multiple files simultaneously without
*This project has been created as part of the 42 curriculum by iuslu*

## Description
This project is my implementation of the standard C library. Throughout this journey, I gained deep insights into string manipulation, memory management, and linked list structures. I particularly enjoyed the "reverse engineering" logic behind functions like ft_itoa and ft_atoi, where I had to deconstruct data types to transform them. Building this foundational library has been a highly rewarding experience that solidified my understanding of low-level programming.

## Instructions
The library is divided into three main sections:
- **PART 1 - Libc Functions:** Re-implementation of standard C functions (e.g., `ft_memset`, `ft_strlen`).
- **PART 2 - Additional Functions:** Utilities for string manipulation and memory (e.g., `ft_split`, `ft_itoa`).
- **PART 3 - Linked List:** Linked list management (e.g., `ft_lstmap`, `ft_lstclear`).

## Resources
During the development of this library, I utilized AI assistance for:
- **Logical Debugging:** Resolving `size_t` underflow and boundary condition issues in `ft_strnstr`.
- **System Architecture:** Understanding the behavior of file descriptors (`fd`) and error handling in `write` syscalls.

## Usage
To compile the library, run:
```bash
make        # Compiles mandatory functions
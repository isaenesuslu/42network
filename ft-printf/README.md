*This project has been created as part of the 42 curriculum by iuslu.*

---

## Description

**ft_printf** is a project that involves recoding the standard C library's `printf` function. The primary goal of this project is to understand the mechanics of **variadic functions** in C and to build an efficient data formatting system. The project supports the following conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

## Instructions

### Compilation

The project is compiled using the `Makefile` located in the root directory. You can use the following commands:

* `make`: Compiles the source files and creates the `libftprintf.a` library.
* `make clean`: Removes the object (`.o`) files.
* `make fclean`: Removes object files and the generated library file.
* `make re`: Cleans and recompiles the entire project.

### Execution

To include the `libftprintf.a` library in your own project:

1. Include the `ft_printf.h` header file in your code.
2. Link the library during compilation:
```bash
cc main.c libftprintf.a -o my_program

```

## Resources

* **Man Pages:** `man 3 printf`, `man 3 stdarg`.
* **Documentation:** [C Variadic Functions (gnu.org)](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html).
* **Reference:** Standard C Library documentation regarding `write` and `va_list`.

### AI Usage

In this project, Artificial Intelligence (Gemini) was utilized for the following tasks:

* **Debugging:** Identifying and resolving memory access issues (potential buffer overflows) and handling `NULL` pointer cases (specifically the `(nil)` output for `%p`).
* **Documentation:** Structuring this README file and refining technical explanations according to 42 requirements.

## Algorithm and Data Structure

The project is built on an algorithm that parses the format string in a **single pass**.

1. **Traversal:** The format string is scanned character by character using a `while` loop.
2. **Detection:** When a `%` character is encountered, the next character is checked to see if it is a valid conversion specifier.
3. **Dispatching:** Based on the specifier, the corresponding data type is fetched from the stack using the `va_arg` macro.
4. **Recursive Conversion:** Recursive functions are used for hexadecimal and integer conversions. This allows digits to be printed directly to the standard output without the need for a temporary buffer, ensuring memory efficiency.
5. **Counter:** Every successful `write` operation is added to the `check` counter, which serves as the function's total return value.

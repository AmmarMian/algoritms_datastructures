# Variables
CC = gcc
CFLAGS = -Wall -Wextra -I.\src -std=gnu99
SRC = src\traitements_chaines.c src\caesar.c src\decrypt_caesar.c
OBJ = $(SRC:.c=.exe)

# Targets
all: encrypt_caesar_stdin decrypt_caesar_stdin encrypt_caesar_file decrypt_caesar_file compile_tests decrypt_caesar_bruteforce

# Executable targets
encrypt_caesar_stdin: executables\encrypt_caesar_stdin.c $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@.exe

decrypt_caesar_stdin: executables\decrypt_caesar_stdin.c $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@.exe

encrypt_caesar_file: executables\encrypt_caesar_file.c $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@.exe

decrypt_caesar_file: executables\decrypt_caesar_file.c $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@.exe

decrypt_caesar_bruteforce: executables\decrypt_caesar_bruteforce.c $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@.exe

# Test compilation target
TESTS = $(patsubst tests/%.c,tests/%.exe,$(wildcard tests/*.c))

compile_tests: $(TESTS)

test:
	echo "$(TESTS)";

tests/%.exe: tests\%.c $(OBJ)
		$(CC) $(CFLAGS) $< $(OBJ) -o $@

# Test execution target
run_tests: compile_tests
		@for test in $(TESTS); do \
				echo "Running $$test..."; \
				$$test || exit 1; \
		done

# Compilation of object files
$(OBJ): %.exe: %.c
		$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
		del /Q *.exe encrypt_caesar_stdin.exe decrypt_caesar_stdin.exe encrypt_caesar_file.exe decrypt_caesar_file.exe $(TESTS)

.PHONY: all clean compile_tests run_tests
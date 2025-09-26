# Variables
CC = gcc
CFLAGS = -Wall -Wextra -I./src
SRC = src/traitements_chaines.c src/fichiers.c src/caesar.c src/decrypt_caesar.c
OBJ = $(SRC:.c=.o)

# Targets
all: encrypt_caesar_stdin decrypt_caesar_stdin encrypt_caesar_file decrypt_caesar_file

encrypt_caesar_stdin: executables/encrypt_caesar_stdin.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

decrypt_caesar_stdin: executables/decrypt_caesar_stdin.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

encrypt_caesar_file: executables/encrypt_caesar_file.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

decrypt_caesar_file: executables/decrypt_caesar_file.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation of object files
$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o encrypt_caesar_stdin decrypt_caesar_stdin encrypt_caesar_file decrypt_caesar_file

.PHONY: all clean


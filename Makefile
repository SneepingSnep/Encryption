
# main:
# # 	clang -Wall -Wextra -std=gnu2y -g -o main src/main.c src/caesar.c src/vigenere.c
# 	clang -c src/main.c src/caesar.c src/vigenere.c 
# 	clang -o main caesar.o vigenere.o main.o
#clang -Wall -Wextra -std=gnu2y -g -o main caesar.o vigenere.o main.o
	

# Clean up
# clean:
# 	rm -f main


# CC = clang
# CFLAGS = -Wall -Wextra -std=gnu2y -g
# OBJS = caesar.o vigenere.o

# all: main

# main: $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o main

# caesar.o: src/caesar.c headers/caesar.h
# 	$(CC) $(CFLAGS) -c caesar.c

# vigenere.o: src/vigenere.c headers/vigenere.h
# 	$(CC) $(CFLAGS) -c src/vigenere.c

# clean:
# 	rm -f *~ *.o sysstatd
# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=gnu2y -g -Iheaders

# Source and object files
SRC = src/main.c src/caesar.c src/vigenere.c
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = main

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
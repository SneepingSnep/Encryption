
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

ARGV1 = Vigenere LXFOPVEFRNHR d LEMON
ARGV2 = Vigenere ATTACKATDAWN e LEMON
ARGV3 = caesar GDPQ d
ARGV4 = caesar DAMN e

# Source and object files
SRC = src/main.c src/caesar.c src/vigenere.c
OBJ = $(SRC:.c=.o)
OBJ1 = ./main.exe

# Target executable
TARGET = main
TARGET1 = run1
TARGET2 = run2
TARGET3 = run3
TARGET4 = run4

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

$(TARGET1): $(OBJ1)
	$(OBJ1) $(ARGV1)

$(TARGET2): $(OBJ1)
	$(OBJ1) $(ARGV2)
	
$(TARGET3): $(OBJ1)
	$(OBJ1) $(ARGV3)

$(TARGET4): $(OBJ1)
	$(OBJ1) $(ARGV4)
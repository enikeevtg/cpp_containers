# UTILITIES
CC = gcc
# LEAKS = leaks -atExit -- 
# OS := $(shell uname)
ifeq ($(OS), Darwin)
	RM = rm -rf
else ifeq ($(OS), Linux)
	RM = rm -rf
else ifeq ($(OS), Windows_NT)
	RM = del 2> nul
endif

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++ -std=c++17

# FILENAMES
ifeq ($(OS), Darwin)
	EXE = a.out
else ifeq ($(OS), Linux)
	EXE = a.out
else ifeq ($(OS), Windows_NT)
	EXE = a.exe
endif



# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i

clean:
	$(RM) $(EXE)
	$(RM) *.gch


# EXPERIMENTS
int:
#	$(CC) $(CF) main_$@.cc
	g++ main_$@.cc
	$(LEAKS) ./$(EXE)

string:
	$(CC) $(CF) main_$@.cc
	$(LEAKS) ./$(EXE)

array:
	$(CC) $(CF) experiments/$@.cc
	./$(EXE)

vector:
	$(CC) $(CF) experiments/$@.cc
	./a.out

list:
	$(CC) $(CF) experiments/$@.cc
	./a.out


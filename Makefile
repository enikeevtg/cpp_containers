# UTILITIES
CC = gcc
LEAKS = leaks -atExit -- 

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++ -std=c++17

# FILENAMES




# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -i




# EXPERIMENTS
main:
	$(CC) $(CF) $@.cc
	$(LEAKS) ./a.out

array:
	$(CC) $(CF) experiments/$@.cc
	./a.out

vector:
	$(CC) $(CF) experiments/$@.cc
	./a.out

list:
	$(CC) $(CF) experiments/$@.cc
	./a.out


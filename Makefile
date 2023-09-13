# UTILITIES
CC = gcc

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++





# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" | xargs clang-format --style=google -i




# EXPERIMENTS
array:
	$(CC) $(CF) experiments/$@.cc
	./a.out

vector:
	$(CC) $(CF) experiments/$@.cc
	./a.out

list:
	$(CC) $(CF) experiments/$@.cc
	./a.out


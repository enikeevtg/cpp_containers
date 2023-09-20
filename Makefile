# UTILITIES
CC = gcc
# LEAKS = leaks -atExit -- 

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra -lstdc++ -std=c++17

# FILENAMES
EXE = a.out



# SERVICE
style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i

clean:
	$(RM) $(EXE)
	$(RM) *.gch


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


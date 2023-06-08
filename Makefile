all:
	gcc -O3 -std=c17 -Werror main.c catan.c -lc -o main
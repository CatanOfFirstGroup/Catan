all:
	gcc -O3 -Wall -Werror *.c

clean:
	rm -rf a.out
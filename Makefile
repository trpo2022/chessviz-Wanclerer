all: main

main: main.c
	gcc -Wall -Werror -o main main.c
clean:
	rm clean
run:
	./main

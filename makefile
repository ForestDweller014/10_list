prog: main.c mystruct.c
	gcc -o prog main.c mystruct.c -I.

run: 
	./prog
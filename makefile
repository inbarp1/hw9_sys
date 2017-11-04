all: directions.c
	gcc -o yay directions.c
run: all
	./yay


all: release counter

release:
	gcc main.c functions.c -o laboratorio1 -lm -Wall

counter:
	gcc contador.c -o contador -lm -Wall

run:
	./laboratorio1 -h 5 -m

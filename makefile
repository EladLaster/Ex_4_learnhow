.PHONY: all clean
CC = gcc
AR = ar
FLAGS= -Wall -Werror -g
all: graph 
graph: main.o graph.a
	$(CC) $(FLAGS) -o graph main.o graph.a
graph.a: graph.o Dijkstra.o TSPWORK.o
	$(AR) -rcs graph.a graph.o Dijkstra.o TSPWORK.o
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c
graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c
Dijkstra.o: Dijkstra.c graph.h
	$(CC) $(FLAGS) -c Dijkstra.c
TSPWORK.o: TSPWORK.c graph.h
	$(CC) $(FLAGS) -c TSPWORK.c
clean:
	rm -f *.o *.a graph
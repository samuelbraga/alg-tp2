CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp2
TMPOUT=tp2.testresult

$(EXEC): src/main.cpp spot.o edge.o graph.o subset.o aux.o
	$(CC) $(CFLAGS) src/main.cpp spot.o edge.o graph.o subset.o aux.o -o $(EXEC)

spot.o: src/spot/spot.cpp
	$(CC) $(CFLAGS) -c src/spot/spot.cpp -o spot.o

edge.o: src/edge/edge.cpp
	$(CC) $(CFLAGS) -c src/edge/edge.cpp -o edge.o

graph.o: src/graph/graph.cpp
	$(CC) $(CFLAGS) -c src/graph/graph.cpp -o graph.o

subset.o: src/subset/subset.cpp
	$(CC) $(CFLAGS) -c src/subset/subset.cpp -o subset.o

aux.o: src/aux/aux.cpp
	$(CC) $(CFLAGS) -c src/aux/aux.cpp -o aux.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf tp2 spot.o edge.o graph.o subset.o aux.o
	
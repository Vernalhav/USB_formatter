BIN = formatter

all: $(BIN).o
	g++ $(BIN).o -o $(BIN)

$(BIN).o: $(BIN).cpp
	g++ -g $(BIN).cpp -c

test:
	./$(BIN)

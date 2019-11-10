BIN = formatter
EXTENSION = c

CC = gcc

all: $(BIN).o
	$(CC) $(BIN).o -o $(BIN)

$(BIN).o: $(BIN).$(EXTENSION)
	$(CC) -g $(BIN).$(EXTENSION) -c

.PHONY: test, debug, clean

test:
	./$(BIN)

debug:
	gdb $(BIN)

clean:
	rm *.o $(BIN)
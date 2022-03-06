CC=g++ -std=c++11
CFLAGS=-c
SOURCES=main.cpp ../vector/vector.cpp stack.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=stack

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run

clean:
	rm $(OBJECTS) $(EXE)
	echo "Removed binary files and executable file";

run:
	./$(EXE)
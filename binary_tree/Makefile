CC=g++ -std=c++11
CFLAGS=-c
SOURCES=main.cpp binary_tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=binary_tree

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
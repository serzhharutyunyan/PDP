CC=g++ -std=c++14
CFLAGS=-c
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=hash_map

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
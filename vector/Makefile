CC=g++ -std=c++11
EXE=vector
OBJECTS=vector.o main.o
${EXE}: ${OBJECTS}
	${CC} $^ -o ${EXE}
List.o: vector.cpp vector.h
	${CC} -c $< -o $@
Main.o: Main.cpp
	${CC} -c $< -o $@
.PHONY: run
run: ./${EXE}
.PHONY: clean
clean:
	rm *.o ${EXE}
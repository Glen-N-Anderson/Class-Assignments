netflix:
	g++ struct.cpp prog.cpp -o struct
CC = g++
prog_file = struct
$(prog_file): $(prog_file).o prog.o
	$(CC) $(prog_file).o prog.o –o $(prog_file)
$(prog_file).o: $(prog_file).cpp
	$(CC) –c $(prog_file).cpp
prog.o: prog.cpp
	$(CC) –c prog.cpp 



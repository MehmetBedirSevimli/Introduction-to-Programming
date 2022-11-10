compileandrun:compile run

compile:library main 
	g++ ./lib/library.o ./lib/main.o -o ./bin/program
	
library: 
	g++ -I "./include" -c ./src/library.cpp -o ./lib/library.o

main: 
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

run: 
	./bin/program.exe
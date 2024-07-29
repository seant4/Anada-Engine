compile:./main.cpp
	g++ main.cpp -o app -lSDL2

debug:./main.cpp
	g++ main.cpp -g -o app -lSDL2
	valgrind --leak-check=yes ./app

run:
	./app

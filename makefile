compile:./main.cpp
	g++ -o app main.cpp -lSDL2

debug:./main.cpp
	g++ main.cpp -g -o app -lSDL2

leak:
	valgrind --leak-check=yes ./app

run:
	./app

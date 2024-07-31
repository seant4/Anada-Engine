compile:./main.cpp
	g++ -I ./lib/ -o app main.cpp -lSDL2 ./lib/*.cpp ./lib/Rooms/*.cpp ./lib/Objects/*.cpp

debug:./main.cpp
	g++ -g -I ./lib/ -o app main.cpp -lSDL2 ./lib/*.cpp ./lib/Rooms/*.cpp ./lib/Objects/*.cpp
run:
	./app
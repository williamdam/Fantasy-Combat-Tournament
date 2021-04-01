main: main.o Barbarian.o BlueMen.o Character.o Gameplay.o HarryPotter.o Losers.o Medusa.o Player.o Team1.o Team2.o Validate.o Vampire.o
	g++ -std=c++0x main.o Barbarian.o BlueMen.o Character.o Gameplay.o HarryPotter.o Losers.o Medusa.o Player.o Team1.o Team2.o Validate.o Vampire.o -o main

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++0x -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++0x -c BlueMen.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++0x -c Character.cpp

Gameplay.o: Gameplay.cpp Gameplay.hpp
	g++ -std=c++0x -c Gameplay.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++0x -c HarryPotter.cpp

Losers.o: Losers.cpp Losers.hpp
	g++ -std=c++0x -c Losers.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++0x -c Medusa.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++0x -c Player.cpp

Team1.o: Team1.cpp Team1.hpp
	g++ -std=c++0x -c Team1.cpp

Team2.o: Team2.cpp Team2.hpp
	g++ -std=c++0x -c Team2.cpp

Validate.o: Validate.cpp Validate.hpp
	g++ -std=c++0x -c Validate.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++0x -c Vampire.cpp

clean:
	rm *.o main
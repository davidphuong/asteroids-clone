asteroids: asteroids.o
	g++ asteroids.o -o asteroids -lsfml-graphics -lsfml-window

asteroids.o: asteroids.cpp
	g++ -c asteroids.cpp

clean:
	rm -f *.o asteroids

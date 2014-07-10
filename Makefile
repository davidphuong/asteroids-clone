asteroids: asteroids.o VisibleGameObject.o GameObjectManager.o SpaceShip.o Bullet.o
	g++ asteroids.o VisibleGameObject.o GameObjectManager.o SpaceShip.o Bullet.o -o asteroids -lsfml-graphics -lsfml-window

asteroids.o: asteroids.cpp
	g++ -c asteroids.cpp

VisibleGameObject.o: VisibleGameObject.h VisibleGameObject.cpp
	g++ -c VisibleGameObject.cpp

GameObjectManager.o: GameObjectManager.h GameObjectManager.cpp
	g++ -c GameObjectManager.cpp

SpaceShip.o: SpaceShip.h SpaceShip.cpp
	g++ -c SpaceShip.cpp

Bullet.o: Bullet.h Bullet.cpp
	g++ -c Bullet.cpp

clean:
	rm -f *.o asteroids

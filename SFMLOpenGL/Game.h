#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"

using namespace std;


class Game
{
public:
	Game();
	~Game();
	void run();
	void rotateAroundX(Vector3 t_vector, int t_i);
	void rotateAroundY(Vector3 t_vector, int t_i);
	void rotateAroundZ(Vector3 t_vector, int t_i);
	void updatePos();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	Matrix3 matrixIdentity = Matrix3(1,0,0,0,1,0,0,0,1); //Identity
	Matrix3 matrix;
	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;
	Vector3 backSide[4];
	Vector3 frontSide[4];
	Vector3 leftSide[4];
	Vector3 rightSide[4];
	Vector3 topSide[4];
	Vector3 bottomSide[4];

	float rotationAngle = 0.05f;
};
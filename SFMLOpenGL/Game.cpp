#include "Game.h"

bool updatable = false;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::rotateAroundX(Vector3 t_vector, int t_i)
{
}

void Game::rotateAroundY(Vector3 t_vector, int t_i)
{
}

void Game::rotateAroundZ(Vector3 t_vector, int t_i)
{
	matrix.setUpRow(t_vector, t_i);
}

void Game::updatePos()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glNewList(index, GL_COMPILE);
	
	glBegin(GL_QUADS);
	{

		//Front Face
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(frontSide[0].X(), frontSide[0].Y(), frontSide[0].Z());
		glVertex3f(frontSide[1].X(), frontSide[1].Y(), frontSide[1].Z());
		glVertex3f(frontSide[2].X(), frontSide[2].Y(), frontSide[2].Z());
		glVertex3f(frontSide[3].X(), frontSide[3].Y(), frontSide[3].Z());
		//Side left from face
		glColor3f(255.0f, 255.0f, 0.0f);
		glVertex3f(leftSide[0].X(), leftSide[0].Y(), leftSide[0].Z());
		glVertex3f(leftSide[1].X(), leftSide[1].Y(), leftSide[1].Z());
		glVertex3f(leftSide[2].X(), leftSide[2].Y(), leftSide[2].Z());
		glVertex3f(leftSide[3].X(), leftSide[3].Y(), leftSide[3].Z());

		//Side right from face
		glColor3f(.0f, 255.0f, 0.0f);
		glVertex3f(rightSide[0].X(), rightSide[0].Y(), rightSide[0].Z());
		glVertex3f(rightSide[1].X(), rightSide[1].Y(), rightSide[1].Z());
		glVertex3f(rightSide[2].X(), rightSide[2].Y(), rightSide[2].Z());
		glVertex3f(rightSide[3].X(), rightSide[3].Y(), rightSide[3].Z());


		//Top face
		glColor3f(255.0f, 0.0f, 255.0f);
		glVertex3f(topSide[0].X(), topSide[0].Y(), topSide[0].Z());
		glVertex3f(topSide[1].X(), topSide[1].Y(), topSide[1].Z());
		glVertex3f(topSide[2].X(), topSide[2].Y(), topSide[2].Z());
		glVertex3f(topSide[3].X(), topSide[3].Y(), topSide[3].Z());
		//Bottom face
		glColor3f(255.0f, 255.0f, 255.0f);
		glVertex3f(bottomSide[0].X(), bottomSide[0].Y(), bottomSide[0].Z());
		glVertex3f(bottomSide[1].X(), bottomSide[1].Y(), bottomSide[1].Z());
		glVertex3f(bottomSide[2].X(), bottomSide[2].Y(), bottomSide[2].Z());
		glVertex3f(bottomSide[3].X(), bottomSide[3].Y(), bottomSide[3].Z());
		//Complete the faces of the Cube

		//Back Face
		glColor3f(0.0f, 255.0f, 255.0f);
		glVertex3f(backSide[0].X(), backSide[0].Y(), backSide[0].Z());
		glVertex3f(backSide[1].X(), backSide[1].Y(), backSide[1].Z());
		glVertex3f(backSide[2].X(), backSide[2].Y(), backSide[2].Z());
		glVertex3f(backSide[3].X(), backSide[3].Y(), backSide[3].Z());

	}
	
	glEnd();
	glEndList();
}



void Game::initialize()
{

	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	backSide[0] = Vector3(1.0f, 1.0f, -15.0f);
	backSide[1] = Vector3(-1.0f, 1.0f, -15.0f);
	backSide[2] = Vector3(-1.0f, -1.0f, -15.0f);
	backSide[3] = Vector3(1.0f, -1.0f, -15.0f);

	leftSide[0] = Vector3(-1.0f, 1.0f, -5.0f);
	leftSide[1] = Vector3(-1.0f, 1.0f, -15.0f);
	leftSide[2] = Vector3(-1.0f, -1.0f, -15.0f);
	leftSide[3] = Vector3(-1.0f, -1.0f, -5.0f);

	rightSide[0] = Vector3(1.0f, 1.0f, -15.0f);
	rightSide[1] = Vector3(1.0f, 1.0f, -5.0f);
	rightSide[2] = Vector3(1.0f, -1.0f, -5.0f);
	rightSide[3] = Vector3(1.0f, -1.0f, -15.0f);

	topSide[0] = Vector3(1.0f, 1.0f, -15.0f);
	topSide[1] = Vector3(-1.0f, 1.0f, -15.0f);
	topSide[2] = Vector3(-1.0f, 1.0f, -5.0f);
	topSide[3] = Vector3(1.0f, 1.0f, -5.0f);

	bottomSide[0] = Vector3(1.0f, -1.0f, -5.0f);
	bottomSide[1] = Vector3(-1.0f, -1.0f, -5.0f);
	bottomSide[2] = Vector3(-1.0f, -1.0f, -15.0f);
	bottomSide[3] = Vector3(1.0f, -1.0f, -15.0f);

	frontSide[0] = Vector3(1.0f, 1.0f, -5.0f);
	frontSide[1] = Vector3(-1.0f, 1.0f, -5.0f);
	frontSide[2] = Vector3(-1.0f, -1.0f, -5.0f);
	frontSide[3] = Vector3(1.0f, -1.0f, -5.0f);
	
	

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		
		//Front Face
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(frontSide[0].X(), frontSide[0].Y(), frontSide[0].Z());
		glVertex3f(frontSide[1].X(), frontSide[1].Y(), frontSide[1].Z());
		glVertex3f(frontSide[2].X(), frontSide[2].Y(), frontSide[2].Z());
		glVertex3f(frontSide[3].X(), frontSide[3].Y(), frontSide[3].Z());
		//Side left from face
		glColor3f(255.0f, 255.0f, 0.0f);
		glVertex3f(leftSide[0].X(), leftSide[0].Y(), leftSide[0].Z());
		glVertex3f(leftSide[1].X(), leftSide[1].Y(), leftSide[1].Z());
		glVertex3f(leftSide[2].X(), leftSide[2].Y(), leftSide[2].Z());
		glVertex3f(leftSide[3].X(), leftSide[3].Y(), leftSide[3].Z());

		//Side right from face
		glColor3f(.0f, 255.0f, 0.0f);
		glVertex3f(rightSide[0].X(), rightSide[0].Y(), rightSide[0].Z());
		glVertex3f(rightSide[1].X(), rightSide[1].Y(), rightSide[1].Z());
		glVertex3f(rightSide[2].X(), rightSide[2].Y(), rightSide[2].Z());
		glVertex3f(rightSide[3].X(), rightSide[3].Y(), rightSide[3].Z());
		
		
		//Top face
		glColor3f(255.0f, 0.0f, 255.0f);
		glVertex3f(topSide[0].X(), topSide[0].Y(), topSide[0].Z());
		glVertex3f(topSide[1].X(), topSide[1].Y(), topSide[1].Z());
		glVertex3f(topSide[2].X(), topSide[2].Y(), topSide[2].Z());
		glVertex3f(topSide[3].X(), topSide[3].Y(), topSide[3].Z());
		//Bottom face
		glColor3f(255.0f, 255.0f, 255.0f);
		glVertex3f(bottomSide[0].X(), bottomSide[0].Y(), bottomSide[0].Z());
		glVertex3f(bottomSide[1].X(), bottomSide[1].Y(), bottomSide[1].Z());
		glVertex3f(bottomSide[2].X(), bottomSide[2].Y(), bottomSide[2].Z());
		glVertex3f(bottomSide[3].X(), bottomSide[3].Y(), bottomSide[3].Z());
		//Complete the faces of the Cube
		
		//Back Face
		glColor3f(0.0f, 255.0f, 255.0f);
		glVertex3f(backSide[0].X(), backSide[0].Y(), backSide[0].Z());
		glVertex3f(backSide[1].X(), backSide[1].Y(), backSide[1].Z());
		glVertex3f(backSide[2].X(), backSide[2].Y(), backSide[2].Z());
		glVertex3f(backSide[3].X(), backSide[3].Y(), backSide[3].Z());

	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	sf::Event event;
	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.RotationZ(0.5) * frontSide[i];
			leftSide[i] = matrixIdentity.RotationZ(0.5) * leftSide[i];
			rightSide[i] = matrixIdentity.RotationZ(0.5) * rightSide[i];
			topSide[i] = matrixIdentity.RotationZ(0.5) * topSide[i];
			bottomSide[i] = matrixIdentity.RotationZ(0.5) * bottomSide[i];
			backSide[i] = matrixIdentity.RotationZ(0.5) * backSide[i];

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.RotationX(0.5) * frontSide[i];
			leftSide[i] = matrixIdentity.RotationX(0.5) * leftSide[i];
			rightSide[i] = matrixIdentity.RotationX(0.5) * rightSide[i];
			topSide[i] = matrixIdentity.RotationX(0.5) * topSide[i];
			bottomSide[i] = matrixIdentity.RotationX(0.5) * bottomSide[i];
			backSide[i] = matrixIdentity.RotationX(0.5) * backSide[i];

		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.RotationY(0.5) * frontSide[i];
			leftSide[i] = matrixIdentity.RotationY(0.5) * leftSide[i];
			rightSide[i] = matrixIdentity.RotationY(0.5) * rightSide[i];
			topSide[i] = matrixIdentity.RotationY(0.5) * topSide[i];
			bottomSide[i] = matrixIdentity.RotationY(0.5) * bottomSide[i];
			backSide[i] = matrixIdentity.RotationY(0.5) * backSide[i];

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.Scale(0.005,0.005) * frontSide[i];
			leftSide[i] = matrixIdentity.Scale(0.005, 0.005) * leftSide[i];
			rightSide[i] = matrixIdentity.Scale(0.005, 0.005) * rightSide[i];
			topSide[i] = matrixIdentity.Scale(0.005, 0.005) * topSide[i];
			bottomSide[i] = matrixIdentity.Scale(0.005, 0.005) * bottomSide[i];
			backSide[i] = matrixIdentity.Scale(0.005, 0.005) * backSide[i];



		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.Translate(-10, 1) * frontSide[i];
			leftSide[i] = matrixIdentity.Translate(-1, 1) * leftSide[i];
			rightSide[i] = matrixIdentity.Translate(-1, 1) * rightSide[i];
			topSide[i] = matrixIdentity.Translate(-1, 1) * topSide[i];
			bottomSide[i] = matrixIdentity.Translate(-1, 1) * bottomSide[i];
			backSide[i] = matrixIdentity.Translate(-1, 1) * backSide[i];



		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 4; i++)
		{
			frontSide[i] = matrixIdentity.Translate(1, -1) * frontSide[i];
			leftSide[i] = matrixIdentity.Translate(1, -1) * leftSide[i];
			rightSide[i] = matrixIdentity.Translate(1, -1) * rightSide[i];
			topSide[i] = matrixIdentity.Translate(1, -1) * topSide[i];
			bottomSide[i] = matrixIdentity.Translate(1, -1) * bottomSide[i];
			backSide[i] = matrixIdentity.Translate(1, -1) * backSide[i];



		}
	}
	cout << "Update up" << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Y)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		updatePos();
	}
	matrixIdentity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glTranslatef(0, 0, 0);
	glLoadIdentity();
	
	

	glCallList(1);

	window.display();
	glTranslatef(0, 0, -10);
	
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}


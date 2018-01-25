#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	y = t_y;
	z = t_z;
}

Vector3::~Vector3()
{
}

void Vector3::setX(double t_x)
{
	x = t_x;
}

void Vector3::setY(double t_y)
{
	y = t_y;
}

void Vector3::setZ(double t_z)
{
	z = t_z;
}

double Vector3::X()
{
	return x;
}

double Vector3::Y()
{
	return y;
}

double Vector3::Z()
{
	return z;
}

double Vector3::Length()
{
	// A method to return the length of the vector
	return sqrt((x*x) + (y*y) + (z*z));
}

double Vector3::LengthSquared()
{// A method to return the length squared of a vector
	return ((x*x) + (y*y) + (z*z));
}

void Vector3::Normalise()
{
	//To normalize a vector, therefore, is to take a vector of any 
	//length and, keeping it pointing in the same direction,
	//change its length to 1, turning it into what is called 
	//a unit vector.Since it describes a vector
	// direction without regard to its length, it's 
	//useful to have the unit vector readily accessible
	//Definition from https://www.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-vectors/a/vector-magnitude-normalization

	if (this->Length() > 0.0)
	{
		//Divide by zero check
		double divByZero = this->Length();
		this->x /= divByZero;
		this->y /= divByZero;
		this->z /= divByZero;
	}


}

std::string Vector3::toString()
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[ %g, %g, %g ]", x, y, z);
	return tmpbuf;
}

Vector3 Vector3::operator+(const Vector3 t_v1)const 
{
	{
		return Vector3(x + t_v1.x, y + t_v1.y, z + t_v1.z);
	}
}

Vector3 Vector3::operator-(const Vector3 t_v1)const
{
	//Operator to subtract two vectors, then return the deifference as a new vector
	return Vector3(x - t_v1.x, y - t_v1.y, z - t_v1.z);
}

Vector3 Vector3::operator-()
{
	//Operator to flip the values on a vector
	Vector3 V1;
	V1.x = -x;
	V1.y = -y;
	V1.z = -z;
	return V1;
}

double Vector3::operator*(const Vector3 t_v1)const
{// An overloaded operator * to return the scalar product of 2 vectors
	return ((x * t_v1.x) + (y * t_v1.y) + (z * t_v1.z));
}

Vector3 Vector3::operator*(const double t_num)const 
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * t_num, y * t_num, z * t_num);
}

Vector3 Vector3::operator*(const float t_num)const 
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * t_num, y * t_num, z * t_num);
}

Vector3 Vector3::operator*(const int t_num)const
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * t_num, y * t_num, z * t_num);
}

Vector3 Vector3::operator^(const Vector3 t_v1) const
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(
		((y * t_v1.z) - (z * t_v1.y)),
		((z * t_v1.x) - (x * t_v1.z)),
		((x * t_v1.y) - (y * t_v1.x))
	);
}








#pragma once
#include <iostream>
#include <string>



class Vector3
{
public:
	Vector3();
	Vector3(double t_x, double t_y, double t_z);
	~Vector3();

	void setX(double t_x);
	void setY(double t_y);
	void setZ(double t_z);
	double X();
	double Y();
	double Z();

	double Length();
	double LengthSquared();
	void Normalise();
	std::string toString();

	Vector3 operator+(const Vector3 t_v1) const;
	Vector3 operator-(const Vector3 t_v1) const;
	Vector3 operator -();

	double operator*(const Vector3 t_v1) const;
	Vector3 operator*(const double t_num) const;
	Vector3 operator*(const float t_num) const;
	Vector3 operator*(const int t_num) const;
	
	Vector3 operator^(const Vector3 t_v1)const;
	

private:
	//The 3 variables, or points on each of the vectors will work 
	//off the following three variables
	double x;
	double y;
	double z;
};


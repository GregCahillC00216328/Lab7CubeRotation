
#include "Vector3.h"
#include <math.h>


class Matrix3
{
public:
	
	Matrix3();
	Matrix3(Vector3 t_row1, Vector3 t_row2, Vector3 t_row3);
	Matrix3(double t_a11, double t_a12, double t_a13,
			double t_a21, double t_a22, double t_a23,
			double t_a31, double t_a32, double t_a33);
	~Matrix3();

	Vector3 operator*(const Vector3 t_v1) const;
	Matrix3 operator-(const Matrix3 t_m1) const;
	Matrix3 operator*(const double t_x) const;
	Matrix3 operator*(Matrix3 t_m);
	Matrix3 Transpose();
	Matrix3 operator+(const Matrix3 t_m)const;
	std::string toString();

	double Determinant();
	Matrix3 Inverse();

	static Matrix3 Rotation(double t_angle);
	static Matrix3 Translate(int t_dx, int t_dy);
	static Matrix3 Scale(double t_dx, double t_dy);

	Matrix3 operator-();

	

	static Matrix3 RotationX(double t_angle);
	static Matrix3 RotationY(double t_angle);
	static Matrix3 RotationZ(double t_angle);

	static Matrix3 Scale3D(double t_dx);

	Vector3 Row(int t_i);
	Vector3 Column(int t_i);
	void setUpRow(Vector3 t_vector, int t_i);
	void setUpColumn(Vector3 t_vector, int t_i);
	

private:
	// The class has nine variables, 3 rows and 3 columns
	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;
};


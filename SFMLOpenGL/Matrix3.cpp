#include "Matrix3.h"


Matrix3::Matrix3()
{
	//This creates a matrix containing all zeros.
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(Vector3 t_row1, Vector3 t_row2, Vector3 t_row3)
{
	//This takes three vecotrs, and applies their values to the three seperate rows
	A11 = t_row1.X();
	A12 = t_row1.Y();
	A13 = t_row1.Z();

	A21 = t_row2.X();
	A22 = t_row2.Y();
	A23 = t_row2.Z();

	A31 = t_row3.X();
	A32 = t_row3.Y();
	A33 = t_row3.Z();
}

Matrix3::Matrix3(double t_a11, double t_a12, double t_a13, 
				 double t_a21, double t_a22, double t_a23, 
				 double t_a31, double t_a32, double t_a33)
{
	//Accepts nine individual values if you wish to eneter all values of the matrix individually
	A11 = t_a11; A12 = t_a12; A13 = t_a13;
	A21 = t_a21; A22 = t_a22; A23 = t_a23;
	A31 = t_a31; A32 = t_a32; A33 = t_a33;
}

Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(Vector3 t_v1)const
{//Returns the product of a matrix by a vector
	return Vector3((A11 * t_v1.X()) + (A12 * t_v1.Y()) + (A13 * t_v1.Z()),
				   (A21 * t_v1.X()) + (A22 * t_v1.Y()) + (A23 * t_v1.Z()),
				   (A31 * t_v1.X()) + (A32 * t_v1.Y()) + (A33 * t_v1.Z()));
}

Matrix3 Matrix3::Transpose()
{
	//Returns the transpose of a matrix
	return Matrix3(A11, A21, A31,
		A12, A22, A32,
		A13, A23, A33);
}

Matrix3 Matrix3::operator+(const Matrix3 t_m)const
{//Returns the sum of two matrix's
	return Matrix3(A11 + t_m.A11,A12 + t_m.A12, A13 + t_m.A13,
		A21 + t_m.A21, A22 + t_m.A22, A23 + t_m.A23,
		A31 + t_m.A31, A32 + t_m.A32, A33 + t_m.A33);
}

std::string Matrix3::toString()
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[ %g, %g, %g ]\n [ %g, %g, %g ]\n [ %g, %g, %g ]",
		A11, A12, A13,A21,A22,A23,A31,A32,A33);
	return tmpbuf;
}

Matrix3 Matrix3::operator-(const Matrix3 t_m2)const
{//Returns the differnce between two matrixs as a matrix
	return Matrix3(A11 - t_m2.A11, A12 - t_m2.A12, A13 - t_m2.A13,
				   A21 - t_m2.A21, A22 - t_m2.A22, A23 - t_m2.A23,
				   A31 - t_m2.A31, A32 - t_m2.A32, A33 - t_m2.A33);
}

Matrix3 Matrix3::operator*(const double t_x)const
{ //Multiply a matrix by a scaler, then return that as a new matrix
	Matrix3 scaledMatrix = Matrix3();
	scaledMatrix.A11 = A11 * t_x;
	scaledMatrix.A12 = A12 * t_x;
	scaledMatrix.A13 = A13 * t_x;

	scaledMatrix.A21 = A21 * t_x;
	scaledMatrix.A22 = A22 * t_x;
	scaledMatrix.A23 = A23 * t_x;

	scaledMatrix.A31 = A31 * t_x;
	scaledMatrix.A32 = A32 * t_x;
	scaledMatrix.A33 = A33 * t_x; ;

	return scaledMatrix;
}

Matrix3 Matrix3::operator*(Matrix3 t_m)
{
	
	Matrix3 answer = Matrix3();
	answer.A11 = Row(0) * t_m.Column(0);
	answer.A12 = Row(0) * t_m.Column(1);
	answer.A13 = Row(0) * t_m.Column(2);

	answer.A21 = Row(1) * t_m.Column(0);
	answer.A22 = Row(1) * t_m.Column(1);
	answer.A23 = Row(1) * t_m.Column(2);

	answer.A31 = Row(2) * t_m.Column(0);
	answer.A32 = Row(2) * t_m.Column(1);
	answer.A33 = Row(2) * t_m.Column(2);


	return answer;
}

double Matrix3::Determinant()
{
	{// method to return the determinant of a 3x3 matrix
	  
		return A11 * A22 * A33 - A11 * A32 * A23 +
			A21 * A32 * A13 - A31 * A22 * A13 +
			A31 * A12 * A23 - A21 * A12 * A33;
	}
}

Matrix3 Matrix3::Inverse()
{
	// method to return the inverse of a matrix if exists else zero vector
	double det = Determinant();
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.A11 = scale * (A22 * A33 - A23 * A32);
		answer.A12 = scale * (A13 * A32 - A12 * A33);
		answer.A13 = scale * (A12 * A23 - A13 * A22);

		answer.A21 = scale * (A23 * A31 - A21 * A33);
		answer.A22 = scale * (A11 * A33 - A13 * A31);
		answer.A23 = scale * (A13 * A21 - A11 * A23);


		answer.A31 = scale * (A21 * A32 - A22 * A31);
		answer.A32 = scale * (A12 * A31 - A11 * A32);
		answer.A33 = scale * (A11 * A22 - A12 * A21);

		return answer;
	}
}

Matrix3 Matrix3::Rotation(double t_angle)
{
	double radians = 3.14159265 / 180 * t_angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = sin(radians);
	answer.A13 = 0;
	answer.A21 = -sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Translate(int t_dx, int t_dy)
{
	Matrix3 answer =Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = t_dx;
	answer.A32 = t_dy;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale(double t_dx, double t_dy)
{
	Matrix3 answer = Matrix3();
	answer.A11 = static_cast<double>(t_dx) / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = static_cast<double>(t_dy) / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::operator-()
{
	return Matrix3((A11 * -1) , (A12 *  -1) , (A13 *  -1),
		(A21 *  -1) , (A22 *  -1) , (A23 *  -1),
		(A31 *  -1) , (A32 * -1) , (A33 *  -1));
}

Matrix3 Matrix3::RotationX(double t_angle)
{
	double radians = 3.14159265 / 180 * t_angle;
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = cos(radians);
	answer.A23 = -sin(radians);
	answer.A31 = 0;
	answer.A32 = sin(radians);
	answer.A33 = cos(radians);


	return answer;
}

Matrix3 Matrix3::RotationY(double t_angle)
{
	double radians = 3.14159265 / 180 * t_angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = 0;
	answer.A13 = sin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -sin(radians);
	answer.A32 = 0;
	answer.A33 = cos(radians);


	return answer;
}

Matrix3 Matrix3::RotationZ(double t_angle)
{
	double radians = 3.14159265 / 180 * t_angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = -sin(radians);
	answer.A13 = 0;
	answer.A21 = sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;
  
	return answer;
}

Matrix3 Matrix3::Scale3D(double t_dx)
{
	Matrix3 answer =Matrix3();
	answer.A11 = (double)t_dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)t_dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)t_dx / 100;

	return answer;
}

Vector3 Matrix3::Row(int t_i)
{//Returns a given row in a matrix as a vector
	switch (t_i)
	{
	case 0:
		return Vector3(A11, A12, A13);
		break;
	case 1:
		return Vector3(A21, A22, A23);
		break;
	case 2:
	default:
		return Vector3(A31, A32, A33);
		break;
	}
}

Vector3 Matrix3::Column(int t_i)
{//returns a given column in a matrix as a column
	switch (t_i)
	{
	case 0:
		return Vector3(A11, A21, A31);
		break;
	case 1:
		return Vector3(A12, A22, A32);
		break;
	case 2:
	default:
		return Vector3(A13, A23, A33);
		break;
	}
}

void Matrix3::setUpColumn(Vector3 t_vector, int t_i)
{
	if (t_i == 0);
	{
		A11 = t_vector.X();
		A21 = t_vector.Y();
		A31 = t_vector.Z();
	}
	if (t_i == 1);
	{
		A12 = t_vector.X();
		A22 = t_vector.Y();
		A32 = t_vector.Z();
	}
	if (t_i == 2);
	{
		A13 = t_vector.X();
		A23 = t_vector.Y();
		A33 = t_vector.Z();
	}
}

void Matrix3::setUpRow(Vector3 t_vector, int t_i)
{
	if (t_i == 0);
	{
		A11 = t_vector.X();
		A12 = t_vector.Y();
		A13 = t_vector.Z();
	}
	if (t_i == 1);
	{
		A21 = t_vector.X();
		A22 = t_vector.Y();
		A23 = t_vector.Z();
	}
	if (t_i == 2);
	{
		A31 = t_vector.X();
		A32 = t_vector.Y();
		A33 = t_vector.Z();
	}
}







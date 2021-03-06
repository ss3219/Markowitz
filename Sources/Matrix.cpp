#include "../Headers/Matrix.h"
#include <cmath>

//Product Matrix Vector
Vector operator*(const Matrix& C,const Vector& V)
{
   int d = C.size();
   Vector W(d);
   for (int j=0; j<d; j++)
   {
      W[j]=0.0;
      for (int l=0; l<d; l++) W[j]=W[j]+C[j][l]*V[l];
   }
   return W;
}

//Sum vectors
Vector operator+(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] + W[j];
   return U;
}

//Substraction vectors
Vector operator-(const Vector & V, const Vector & W)
{
	int d = V.size();
	Vector U(d);
	for (int j = 0; j<d; j++) U[j] = V[j] - W[j];
	return U;
}

//Sum constant and vector
Vector operator+(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a + V[j];
   return U;
}

//Product constant and vector
Vector operator*(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a*V[j];
   return U;
}

//Product of vectors
Vector operator*(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] * W[j];
   return U;
}

//Exponential vector
Vector exp(const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = exp(V[j]);
   return U;
}

//Power vectors
double operator^(const Vector& V,const Vector& W)
{
   double sum = 0.0;
   int d = V.size();
   for (int j=0; j<d; j++) sum = sum + V[j]*W[j];
   return sum;
}

//matrices product
Matrix operator*(const Matrix& A, const Matrix& B)
{
	int d = A.size();
	int c = B[0].size();
	Matrix W(d, Vector(d));
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			W[j][i] = 0.0;
			for (int l = 0; l<d; l++) W[j][i] = W[j][i] + A[j][l] * B[l][i];
		}
	}
	return W;
}

//product vector*Matrix
Vector operator*(const Vector & A, const Matrix & B)
{
	int d = A.size();
	int c = B[0].size();
	Vector W(c);
	for (int i = 0; i < c; i++)
	{
		for (int l = 0; l<d; l++) W[i] = W[i] + A[l] * B[l][i];
	}
	return W;
}

//Transposes vectors
Matrix vectorTranspose(const Vector& V)
{
	int d = V.size();
	Matrix M(d, Vector(1));
	for (int i = 0; i < d; i++) M[i][0] = V[i];
	return M;
}
#include <iostream>
#include <iomanip>
using namespace std;

/*





*/










int factorial(int n);
double NR(double e, double M, double delta);	//newton rhapson method
double LM(double M, double e, double mlim);	//lambert method

int main()
{
	int mlimit = 6;
	double tolerance = pow(10, -3);
	cout << "NR: "<<setprecision(11)<<NR(0.66, 7 * 3.14 / 8, tolerance) << endl;
	cout << "LM: " <<setprecision(11)<< LM(7 * 3.14 / 8,0.66, mlimit) << endl;



}

int factorial(int n)
{
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * factorial(n - 1);


}


double NR(double e, double M, double delta)
{
	double E, holder; 
	E = M;
	double num = E - e * sin(E) - M;
	double den = 1 - e * cos(E);

	holder = E;
	while (abs(E - holder) > delta)
	{
		holder = E;
		E = E - num / den;
	}

	return E;
}

double LM(double M, double e, double mlim)
{
	double E, result = 0, result1=0;
	int m=1, k=0;
	while (m <= mlim)
	{
		while (k <= 3)
		{
			 result1=result1+(pow(-1, k) * pow(.5 * m * e, m + 2 * k)) / (factorial(k) * factorial(m + k));
			k++;
		}
		result = result + 2 / m * sin(m * M) * result1;
		m++;
	}

	E = M + result;

	return E;
}
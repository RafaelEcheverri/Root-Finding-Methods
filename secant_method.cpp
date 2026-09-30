#include <iostream>
#include <cmath>
using namespace std;

void secant(double, double, double, int);
double f(double);

int main()
{
	int imax;
	double a, b;
	double epsilon;

	cout << "Enter the limits of the original search interval, a and b: ";
	cin >> a >> b;
	cout << "Enter the convergence criteria: ";
	cin >> epsilon;
	cout << "Enter the maximum number of iterations allowed: ";
	cin >> imax;

	secant(a, b, epsilon, imax); // secant method function called

	return 0;
}

void secant(double a, double b, double epsilon, int imax)
{
	int i;
	double x0, x1;
	double f0, f1;
	double dx0;
	double dx1;

	cout << "\nThe original search interval is from " << a << " to " << b
		<< "\nThe convergence criterion is: interval < " << epsilon
		<< "\nThe maximum number of iterations allowed is " << imax << endl;

	x0 = 1;
	f0 = f(x0);
	dx0 = abs(b - a);

	for (i = 1; i <= imax; i++) // secant method iterations
	{
		x1 = x0 + dx0;
		f1 = f(x1);
		if (abs(f1) < epsilon) // if root was found
		{
			cout << "\nA root at x = " << x1 + dx1 << " was found "
				<< "in " << i << " iterations" << endl;
			cout << "The value of the function is " << f1 << endl;
			return;
		}
		else // readjust calculations to continue looking for root
		{
			dx1 = (f1 / (f0 - f1)) * dx0;
			x0 = x1;
			dx0 = dx1;
			f0 = f1;
		}
	}
	cout << "After " << imax << " iterations, no root was found "
		<< "within the convergence criterion\n"
		<< "The search for a root has failed due to excessive iterations\n"
		<< "after the maximum number of " << imax << " iterations" << endl;

	return;
}

double f(double x) // function definition: f(x) = e^x - (1 + x + x^2/2)
{
	return (exp(x) - (1 + x + (x * x) / 2));
}

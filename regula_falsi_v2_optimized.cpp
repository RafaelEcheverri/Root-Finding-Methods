#include <iostream>
#include <cmath>
using namespace std;

void modregfalsi(double, double, double, int);
double f(double);

int main()
{
	int imax; // maximum number of iterations
	double a, b; // limits we are evaluating the function on
	double epsilon; // convergence criterion

	cout << "Enter the limits of the original search interval, a and b: ";
	cin >> a >> b;
	cout << "Enter the convergence criterion: ";
	cin >> epsilon;
	cout << "Enter the maximum number of iterations allowed: ";
	cin >> imax;

	modregfalsi(a, b, epsilon, imax); // calls on function to find root

	return 0;
}

void modregfalsi(double a, double b, double epsilon, int imax) // function using Regula Falsi method
{
	const double RELAX = 0.75;
	/* Reducing the relaxation factor makes the program more stable than the
	previous version, since the larger relaxation factor was causing the
	program to overshoot the root and waste iterations. In testing, this
	version took 3 fewer iterations than the previous one to find the root
	under the same parameters. */

	int i;
	double x1, x2, x3;
	double f1, f2, f3;
	double width;
	double curwidth;

	cout << "\nThe original search interval is from " << a << " to " << b
		<< "\nThe convergence criterion is: interval < " << epsilon
		<< "\nThe maximum number of iterations allowed is " << imax << endl;

	x1 = a;
	x3 = b;
	f1 = f(x1);
	f3 = f(x3);
	width = abs(b - a);

	for (i = 1; i < +imax; i++) // iterations of Regula Falsi method
	{
		curwidth = (x3 - x1) / width;
		x2 = x1 - width * curwidth * f1 / (f3 - f1);
		f2 = f(x2);
		if (abs(curwidth) < epsilon)
		{
			cout << "\nA root at x = " << x2 << " was found "
				<< "in " << i << " iterations" << endl;
			cout << "The value of the function is " << f2 << endl;
			return;
		}
		else
		{
			if (f1 * f2 < 0.0) // checks which half the root is in (if any)
			{ // left side
				x3 = x2;
				f3 = f2;
				f1 = RELAX * f1;
			}
			else if (f2 * f3 < 0.0)
			{ // right side
				x1 = x2;
				f1 = f2;
				f3 = RELAX * f3;
			}
			else
			{
				cout << "The search for a root has failed due to no root in "
					<< "the interval\n"
					<< "In step " << i << " of the iteration the function "
					<< "does not change sign" << endl;
			}
		}
	}
	cout << "\nAfter " << imax << "iterations, no root was found "
		<< "within the convergence criterion\n"
		<< "The search for a root has failed due to excessive iterations\n"
		<< "after the maximum number of " << imax << " iterations" << endl;
	return;
}

double f(double x) // function definition: f(x) = x^3 - 2x - 5
{
	return ((x * x * x) - 2 * x - 5);
}

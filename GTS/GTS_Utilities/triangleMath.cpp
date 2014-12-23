#ifndef TRIANGLE_MATH_H
#define TRIANGLE_MATH_H

/** @@ this function calculates the parameters(a, b) of simple line, if return value is equal -1, line is parallel to OY axis @@ */
int calculate_line(int x1, int y1, int x2, int y2, double &a, double &b)
{
	if(x1 == x2)
		return -1;

	a = (double)(y1 - y2)/(x1 - x2);
	b = (double)y1 - a*x1;

	return 0;
}

/** @@ this function checks whether two points are on different sides of simple line, determined by the parameters(a, b) @@ */
bool check_if_differentSide(int x1, int y1, int x2, int y2, double a, double b)
{
	double value = (a*x1 - y1 + b)*(a*x2 - y2 + b);

	if(value < 0)
		return true;

	return false;
}

/** @@ this function checks if P(x, y) is located inside triangle described by points T1, T2, T3 @@ */
bool check_if_insideTriangle(int Tx1, int Ty1, int Tx2, int Ty2, int Tx3, int Ty3,
							 int Px, int Py)
{
	double a[3] = {0};
	double b[3] = {0};

	if((Px == Tx1 && Py == Ty1)
	|| (Px == Tx2 && Py == Ty2)
	|| (Px == Tx3 && Py == Ty3))
		return true;

	calculate_line(Tx1, Ty1, Tx2, Ty2, a[0], b[0]);
	if(check_if_differentSide(Tx3, Ty3, Px, Py, a[0], b[0]) == true)
		return false;

	calculate_line(Tx1, Ty1, Tx3, Ty3, a[1], b[1]);
	if(check_if_differentSide(Tx2, Ty2, Px, Py, a[1], b[1]) == true)
		return false;

	calculate_line(Tx2, Ty2, Tx3, Ty3, a[2], b[2]);
	if(check_if_differentSide(Tx1, Ty1, Px, Py, a[2], b[2]) == true)
		return false;

	return true;
}
#endif // TRIANGLE_MATH_H

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool getEquationParams(Point const & a, Point const & b, Fixed & M, Fixed & N)
{
	Fixed ax(a.getX()), ay(a.getY()), bx(b.getX()), by(b.getY());
	if(ax > bx)
	{
		Fixed auxx = ax, auxy = ay;
		ax = bx;
		bx = auxx;
		ay = by;
		by = auxy;
	}
	Fixed xIncr(Fixed::max(ax, bx) - Fixed::min(ax, bx)), yIncr(by - ay);
	if (xIncr == 0)
	{
		M = 0;
		N = ax;
		return true;
	}
	M = yIncr / xIncr;
	Fixed mx(M * ax);
	N = ay - mx;
	return false;
}

bool isInPlane(Fixed & M, Fixed & N, Point const & a, Point const & p, bool flag)
{
	Fixed ax(a.getX()), ay(a.getY()), px(p.getX()), py(p.getY());

	if (flag)
	{
		if (((N > ax) && (N > px)) || ((N < ax) && (N < px)))
			return true;
		return false;
	}
	Fixed mx = M * ax;
	Fixed projAY(mx + N);
	mx = M * px;
	Fixed projPY(mx + N);
	if (((projAY > ay) && (projPY > py)) || ((projAY < ay) && (projPY < py)))
		return true;
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed M, N;
	bool res = false, flag = false;

	for(int i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0:
				flag = getEquationParams(a, b, M, N);
				res = isInPlane(M, N, point, c, flag);
				break;
			case 1:
				flag = getEquationParams(b, c, M, N);
				res = isInPlane(M, N, point, a, flag);
				break;
			case 2:
				flag = getEquationParams(c, a, M, N);
				res =  isInPlane(M, N, point, b, flag);
				break;
			default:
				break;
		}
		if (!res)
			return false;
	}
	return true;
}

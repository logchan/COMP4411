#include <cmath>
#include <assert.h>
#include <float.h>
#include <utility>
#include "Box.h"
#include <iostream>
using namespace std;

bool Box::intersectLocal( const ray& r, isect& i ) const
{
	vec3f origin = r.getPosition();
	vec3f dir = r.getDirection();
	double Tnear = -DBL_MAX;
	double Tfar = DBL_MAX;
	double T1, T2;
	double error = 1.0e-8;
	// X,Y,Z planes
	for (int plane = 0; plane < 3; ++plane)
	{
		if (dir[plane] == 0)
		{
			if (origin[plane]<-0.5 || origin[plane]>0.5)
			{
				return false;
			}
		}
		else
		{
			T1 = (-0.5 - origin[plane]) / dir[plane];
			T2 = (0.5 - origin[plane]) / dir[plane];
			vec3f tmpN(0, 0, 0);
			tmpN[plane] = -1;
			if (T1 > T2)
			{
				swap<double>(T1, T2);
				tmpN[plane] = 1;
			}
			if (T1 > Tnear)
			{
				Tnear = T1;
				i.N = tmpN;
			}
			if (T2 < Tfar)Tfar = T2;
			if (Tnear > Tfar || Tfar <= error)return false;
		}
	}
	i.t = Tnear;
	if (i.t < error)i.t = Tfar;
	i.obj = this;
	return true;
}

void Box::isectTo2DMap(const isect& i, const vec3f& pos, int density, int& x, int& y) const
{
	vec3f posLocal = transform->globalToLocalCoords(pos);

	if (0.5 - abs(posLocal[0]) < 1e-8)
	{
		x = (posLocal[1] + 0.5) * density;
		y = (posLocal[2] + 0.5) * density;
	}
	else if (0.5 - abs(posLocal[1]) < 1e-8)
	{
		x = (posLocal[0] + 0.5) * density;
		y = (posLocal[2] + 0.5) * density;
	}
	else
	{
		x = (posLocal[0] + 0.5) * density;
		y = (posLocal[1] + 0.5) * density;
	}

	if (x < 0) x = 0;
	if (y < 0) y = 0;
}
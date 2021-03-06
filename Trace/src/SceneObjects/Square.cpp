#include <cmath>

#include "Square.h"

bool Square::intersectLocal( const ray& r, isect& i ) const
{
	vec3f p = r.getPosition();
	vec3f d = r.getDirection();

	if( d[2] == 0.0 ) {
		return false;
	}

	double t = -p[2]/d[2];

	if( t <= RAY_EPSILON ) {
		return false;
	}

	vec3f P = r.at( t );

	if( P[0] < -0.5 || P[0] > 0.5 ) {	
		return false;
	}

	if( P[1] < -0.5 || P[1] > 0.5 ) {	
		return false;
	}

	i.obj = this;
	i.t = t;
	if( d[2] > 0.0 ) {
		i.N = vec3f( 0.0, 0.0, -1.0 );
	} else {
		i.N = vec3f( 0.0, 0.0, 1.0 );
	}

	return true;
}

void Square::isectTo2DMap(const isect& i, const vec3f& pos, int density, int& x, int& y) const
{
	vec3f posLocal = transform->globalToLocalCoords(pos);

	x = (1 - (posLocal[0] + 0.5)) * density;
	y = (posLocal[1] + 0.5) * density;

	if (x < 0) x = 0;
	if (y < 0) y = 0;
}

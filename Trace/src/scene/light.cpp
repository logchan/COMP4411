#include <cmath>

#include "light.h"
#include <iostream>
using namespace std;

double DirectionalLight::distanceAttenuation( const vec3f& P ) const
{
	// distance to light is infinite, so f(di) goes to 0.  Return 1.
	return 1.0;
}


vec3f DirectionalLight::shadowAttenuation( const vec3f& P ) const
{
	isect i;
	vec3f dir = getDirection(vec3f(0, 0, 0));
	ray r(P, dir);
	
	if (scene->intersect(r,i))
	{
		const Material& m = i.getMaterial();
		//return prod(m.kt, shadowAttenuation(P + i.t * dir));
		return m.kt;
	}
	
	return vec3f(1,1,1);
}

vec3f DirectionalLight::getColor( const vec3f& P ) const
{
	// Color doesn't depend on P 
	return color;
}

vec3f DirectionalLight::getDirection( const vec3f& P ) const
{
	return -orientation;
}

vec3f DirectionalLight::getAmbientColor(const vec3f& P) const
{
	return vec3f(0.0,0.0,0.0);
}

double PointLight::distanceAttenuation( const vec3f& P ) const
{
	// You'll need to modify this method to attenuate the intensity 
	// of the light based on the distance between the source and the 
	// point P.  For now, I assume no attenuation and just return 1.0

	//a = constant_attenuation_coeff(from the.ray file)
	//b = linear_attenuation_coeff(from the.ray file)
	//c = quadratic_attenuation_coeff(from the.ray file)
	double a = 0.25;
	double b = 0.01;
	double c = 0.01;
	double d = (position - P).length();

	double fd = min<double>(1, 1 / (a + b*d + c*d*d));

	return fd;
}

vec3f PointLight::getColor( const vec3f& P ) const
{
	// Color doesn't depend on P 
	return color;
}

vec3f PointLight::getDirection( const vec3f& P ) const
{
	return (position - P).normalize();
}


vec3f PointLight::shadowAttenuation(const vec3f& P) const
{
	vec3f dir = (position - P).normalize();
	isect i1;
	if (scene->intersect(ray(P, dir), i1))
	{
		if (i1.t < (position - P).length())
		{
			const Material& m = i1.getMaterial();
			//return prod(m.kt, shadowAttenuation(P + dir * i1.t));
			return m.kt;
		}
	}
    return vec3f(1,1,1);
}

vec3f PointLight::getAmbientColor(const vec3f& P) const
{
	return vec3f(0.0, 0.0, 0.0);
}

double AmbientLight::distanceAttenuation(const vec3f& P) const
{
	return 1.0;
}

vec3f AmbientLight::getColor(const vec3f& P) const
{
	// Color doesn't depend on P 
	return vec3f(0,0,0);
}

vec3f AmbientLight::getDirection(const vec3f& P) const
{
	return vec3f(0, 0, 0);
}

vec3f AmbientLight::shadowAttenuation(const vec3f& P) const
{
	return vec3f(1, 1, 1);
}

vec3f AmbientLight::getAmbientColor(const vec3f& P) const
{
	return color;
}

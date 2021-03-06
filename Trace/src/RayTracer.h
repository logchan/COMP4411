#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

// The main ray tracer.

#include "scene/scene.h"
#include "scene/ray.h"

class TraceUI;

class RayTracer
{
public:
    RayTracer();
    ~RayTracer();

    vec3f trace( Scene *scene, double x, double y );
	vec3f trace(Scene *scene, double x, double y, int depth);
	vec3f traceRay(Scene *scene, const ray& r, const vec3f& thresh, int depth, bool isInSpace = true, double intensity = 1.0);


	void getBuffer( unsigned char *&buf, int &w, int &h );
	double aspectRatio();
	void traceSetup( int w, int h );
	void traceLines( int start = 0, int stop = 10000000 );
	void tracePixel( int i, int j );
	void calculateAll();

	bool loadScene( char* fn );

	bool sceneLoaded();

	TraceUI* m_pUI;
	vec3f* all;

private:
	unsigned char *buffer;
	int buffer_width, buffer_height;
	int bufferSize;
	Scene *scene;

	bool m_bSceneLoaded;
};

#endif // __RAYTRACER_H__

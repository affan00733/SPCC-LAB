#include <stdio.h>
#include <math.h>
float area_rectangle(float l,float b)
{
    return l*b;
}

float volume_rectangle(float l,float b,float h)
{
    return l*b*h;
}

float volume_cube(float a)
{
    return a*a*a;
}

float volume_cylinder(float r,float h)
{
    return 3.14*(r*r)*h;
}

float volume_pyramid(float b,float h)
{
    return ((1/3)*b*h);
}

float volume_cone(float r,float h)
{
    return (h/3)*3.14*(r*r);
}

float volume_sphere(float r)
{
    return (4/3)*3.14*(r*r*r);
}

float volume_ellipsoid(float r1,float r2,float r3)
{
    return (4/3)*3.14*(r1*r2*r3);
}

double cal_log(double x)
{
    return log(x);
}

double cal_sin(double x)
{
    return sin(x);
}
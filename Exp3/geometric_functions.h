#ifndef geometric_functions_h__
#define geometric_functions_h__
extern float area_rectangle(float l,float b);
extern float volume_rectangle(float l,float b,float h);
extern float volume_cube(float a);
extern float volume_cylinder(float r,float h);
extern float volume_pyramid(float b,float h);
extern float volume_cone(float r,float h);
extern float volume_sphere(float r);
extern float volume_ellipsoid(float r1,float r2,float r3);
extern double cal_log(double x);
extern double cal_sin(double x);
#endif 
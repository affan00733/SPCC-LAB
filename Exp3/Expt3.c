/*
gcc -c -Wall -Werror -fpic geometric_functions.c
gcc -shared -o libgeometric_functions.so geometric_functions.o
gcc -L./Expt3.c -o geometric_functions -Wall -lgeometric_functions
*/
#include <stdio.h>
#include "geometric_functions.h"

int main(void)
{
    float l, b, h;
    double x;
    int ch;
    char yes = 'y';

    
    do
    {
    printf("\n1 area of rectangle\n");
    printf("2 volume of rectangle\n");
    printf("3 volume of cube\n");
    printf("4 volume of cylinder\n");
    printf("5 volume of pyramid\n");
    printf("6 volume of cone\n");
    printf("7 volume of sphere\n");
    printf("8 volume of ellipsoid\n");
    printf("9 calculate log\n");
    printf("10 calculate sin angle\n");
    printf("11 exit\n");

    printf("Enter choice : \n");
    scanf("%d",&ch);

    switch (ch)
        {
        case 1:
            printf("Enter the length of the rectangle: ");
            scanf("%f", &l);
            printf("Enter the breadth of the rectangle: ");
            scanf("%f", &b);
            printf("Area of the rectangle: %f\n", area_rectangle(l, b));
            break;
        case 2:
            printf("Enter the length of the rectangle: ");
            scanf("%f", &l);
            printf("Enter the breadth of the rectangle: ");
            scanf("%f", &b);
            printf("Enter the height of the rectangle: ");
            scanf("%f", &h);
            printf("volume of the rectangle: %f\n", volume_rectangle(l, b, h));
            break;
        case 3:
            printf("Enter the side of the cube: ");
            scanf("%f", &l);
            printf("volume of the cube: %f\n", volume_cube(l));
            break;
        case 4:
            printf("Enter the radius of the cylinder: ");
            scanf("%f", &l);
            printf("Enter the height of the cylinder: ");
            scanf("%f", &b);
            printf("Volume of the cylinder: %f\n", volume_cylinder(l, b));
            break;
        case 5:
            printf("Enter the breadth of the pyramid: ");
            scanf("%f", &l);
            printf("Enter the height of the pyramid: ");
            scanf("%f", &b);
            printf("Volume of the pyramid: %f\n", volume_pyramid(l, b));
            break;
        case 6:
            printf("Enter the radius of the Cone: ");
            scanf("%f", &l);
            printf("Enter the height of the Cone: ");
            scanf("%f", &b);
            printf("Volume of the Cone: %f\n", volume_cone(l,b));
            break;
        case 7 :
            printf("Enter the side of the sphere: ");
            scanf("%f", &l);
            printf("Volume of the sphere: %f\n", volume_sphere(l));
            break;
        case 8:
            printf("Enter the radius1 of the ellipsoid: ");
            scanf("%f", &l);
            printf("Enter the radius2 of the ellipsoid: ");
            scanf("%f", &b);
            printf("Enter the radius3 of the ellipsoid: ");
            scanf("%f", &h);
            printf("Volume of the ellipsoid: %f\n", volume_ellipsoid(l,b,h));
            break;
        case 9 :
            printf("Enter the value for log: ");
            scanf("%lf", &x);
            printf("log value: %lf\n", cal_log(x));
            break;
        case 10 :
            printf("Enter the value for sin: ");
            scanf("%lf", &x);
            printf("sin value: %lf\n", cal_sin(x));
            break;
        case 11:
            yes = 'n';
            break;
        }
    }while (yes == 'y' || yes == 'Y');

    return 0;
}
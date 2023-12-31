#include <stdio.h>
#include <math.h>
float f(float x)
{
return cos(x) - (3 * x) + 1;
}
float f_modify(float x)
{
return (cos(x) + 1) / 3.0;
}
float f_d(float x)
{
return (-sin(x) / 3.0);
}
int main()
{
float a, b;
int flag = 0;
do
{
printf("\nEnter the values of a and b : \n");
scanf("%f%f", &a, &b);
if ((f(a) * f(b)) < 0)
{
flag = 1;
printf("Two roots lie b/w %f and %f \n", a, b);
}
else
{
printf("Invalid Input. Try Again!!! \n");
}
} while (flag == 0);
float x0 = 0;
if (fabs(f(a)) < fabs(f(b)))
{
x0 = a;
}
else
{
x0 = b;
}
if (fabs(f_d(x0)) < 1)
{
printf("Roots found!\n");
}
else
{
printf("Wrong value of x0! \n");
return 0;
}
float err;
printf("\nEnter allowed error : \n");
scanf("%f", &err);
float x1 = x0;
int i = 0;
do
{
x0 = x1;
x1 = f_modify(x0);
i++;
printf("Root at iteration %d = %f\n", i, x1);
} while (fabs(x0 - x1) > err);
printf("Final root after %d iterations = %f\n", i, x1);
return 0;
}

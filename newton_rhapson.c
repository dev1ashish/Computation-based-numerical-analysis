#include <stdio.h>
#include <math.h>
float f(float x)
{
return (3 * x - cos(x) - 1);
}
float fd(float x)
{
return (3 + sin(x));
}
int main()
{
float a, b, err;
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
if (fd(x0) == 0)
{
return 0;
}
printf("Enter the allowed error : \n");
scanf("%f", &err);
printf("x0 = %f\n", x0);
float x1 = 0;
int itr = 0;
while (1)
{
itr++;
x1 = x0 - f(x0) / fd(x0);
printf("%d Iteration, value of x = %f\n", itr, x1);
if (fabs(x1) < err)
{
break;
}
x0 = x1;
}
printf("The root of the equation is %f after %d iterations.", x1, itr);
return 0;
}
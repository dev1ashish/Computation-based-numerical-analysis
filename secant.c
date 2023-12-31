#include <stdio.h>
#include <math.h>
float f(float x)
{
return (x * x * x) - (5 * x) + 3;
}
int main()
{
float x0, x1, x2, err;
int itr = 0;
printf("Enter the initial values of x0 and x1: \n");
scanf("%f%f", &x0, &x1);
printf("Enter the allowed error: \n");
scanf("%f", &err);
do
{
itr++;
x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
float ans = f(x2);
printf("%d Iteration, value of x = %f, value of f(x) is %f \n", itr,
x2, ans);
if (fabs(ans) < err)
{
break;
}
x0 = x1;
x1 = x2;
} while (1);
printf("The root of the equation is %f after %d iterations.\n", x2, itr);
return 0;
}

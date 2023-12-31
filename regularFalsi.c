#include <stdio.h>
#include <math.h>
float f(float x)
{
return (x * x * x) - (5 * x) + 3;
}
int main()
{
float a, b, err;
int flag = 0;
do
{
printf("\nEnter the values of x1 and x2 : \n");
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
printf("Enter the allowed error : \n");
scanf("%f", &err);
float x2 = 0;
int itr = 0;
while (1)
{
itr++;
x2 = a - ((b - a) / (f(b) - f(a))) * f(a);
float ans = f(x2);
printf("%d Iteration, value of x = %f, value of f(x) is %f \n", itr,
x2, ans);
if (fabs(ans) < err)
{
break;
}
else if (f(a) * f(x2) > 0)
{
a = x2;
}
else
{
b = x2;
}
}
printf("The root of the equation is %f after %d iterations.", x2, itr);
return 0;
}
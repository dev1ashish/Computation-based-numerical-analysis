#include <stdio.h>
float f(float x)
{
return (x * x) - 5;
}
int main()
{
float a, b;
int flag = 0;
do
{
printf("\nEnter the values of a and b: ");
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
int itr;
printf("\nEnter the no. of iteration: ");
scanf("%d", &itr);
int count = 1;
while (count <= itr)
{
float x2 = (a + b) / 2;
float ans = f(x2);
printf("\nx%d = %f", count, x2);
printf("\t\tf(x%d) = %f", count, ans);
if (f(a) * f(x2) > 0)
{
a = x2;
// -ve replace with -eve
// if x2 is -ve and a also -ve
// then -ve * -ve -> +ve > 0 so a = x2;
}
else
{
b = x2;
}
count++;
}
return 0;
}
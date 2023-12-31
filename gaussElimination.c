#include <stdio.h>
#include <math.h>
#define SIZE 10
int main()
{
int n;
printf("Enter the no. of rows: ");
scanf("%d", &n);
float arr[n][n + 1], value[n];
float ratio;
printf("Enter the arbitary Matrix:\n");
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n + 1; j++)
{
scanf("%f", &arr[i][j]);
}
}
for (int i = 0; i < n; i++)
{
for (int j = i + 1; j < n; j++)
{
ratio = arr[j][i] / arr[i][i];
for (int k = 0; k < n + 1; k++)
{
arr[j][k] -= (ratio * arr[i][k]);
}
}
}
printf("\nUpper Triangular matrix:\n");
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n + 1; j++)
{
printf("%0.1f\t", arr[i][j]);
}
printf("\n");
}
value[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
for (int i = n - 2; i >= 0; i--)
{
float sum = 0;
for (int j = i + 1; j < n; j++)
{
sum += arr[i][j] * value[j];
}
value[i] = (arr[i][n] - sum) / arr[i][i];
}
printf("\nSolution:\n");
for (int i = 0; i < n; i++)
{
printf("value[x%d] = %0.1f\n", i, value[i]);
}
return 0;
}

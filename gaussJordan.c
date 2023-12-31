#include <stdio.h>
#include <math.h>
int main()
{
int n;
printf("Enter the number of rows: ");
scanf("%d", &n);
float arr[n][n + 1], value[n];
float ratio;
printf("Enter the arbitrary Matrix:\n");
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n + 1; j++)
{
scanf("%f", &arr[i][j]);
}
}
// Perform Gaussian elimination
for (int i = 0; i < n; i++)
{
// Check for zero divisor
if (arr[i][i] == 0)
{
printf("Zero divisor encountered. The system may not have a unique 
solution.\n");
return 1;
}
// Make the diagonal elements 1
float divisor = arr[i][i];
for (int j = 0; j < n + 1; j++)
{
arr[i][j] /= divisor;
}
for (int j = 0; j < n; j++)
{
if (i != j)
{
ratio = arr[j][i];
for (int k = 0; k < n + 1; k++)
{
arr[j][k] -= ratio * arr[i][k];
}
}
}
}
printf("\nReduced Row-Echelon Form:\n");
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n + 1; j++)
{
printf("%0.1f\t", arr[i][j]);
}
printf("\n");
}
printf("\nSolution:\n");
for (int i = 0; i < n; i++)
{
printf("value[%d] = %0.1f\n", i, arr[i][n]);
}
return 0;
}
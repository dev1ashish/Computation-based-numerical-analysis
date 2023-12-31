#include <stdio.h>
#include <math.h>

void print(float values[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", values[i]);
    }
    printf("\n");
}

int main() {
    int n, max_itr;
    printf("Enter the number of equations and max iterations: ");
    scanf("%d %d", &n, &max_itr);
    float arr[n][n + 1], values[n], a_err;
    printf("Enter allowed error: ");
    scanf("%f", &a_err);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            printf("arr[%d] [%d] = ", i, j), scanf("%f", &arr[i][j]);
    for (int iter = 0; iter < max_itr; iter++) {
        float values_new[n];
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += arr[i][j] * values_new[j];
            }
            values_new[i] = (arr[i][n] - sum) / arr[i][i];
        }
        int flag = 1;
        for (int k = 0; k < n; k++) {
            if (fabs(values[k] - values_new[k]) >= a_err) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("Final Roots\t");
            print(values_new, n);
            return 0;
        }
        printf("%d iteration\t", iter + 1);
        print(values_new, n);
        for (int k = 0; k < n; k++)
            values[k] = values_new[k];
    }
    printf("Final Roots\t");
    print(values, n);
    return 0;
}

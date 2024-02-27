#include <stdio.h>

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int matrix[n][n];
    int i, j,num=1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
for (int i = 0; i < n; i++) {
        int row = i;
        int col = 0;

        while (row >= 0 && col <= i) {
            matrix[row][col] = num++;
            row--;
            col++;
        }
    }

    for (int i = 1; i < n; i++) {
        int row = n - 1;
        int col = i;

        while (col < n) {
            matrix[row][col] = num++;
            row--;
            col++;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%-3d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


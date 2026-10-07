#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int n, int** arr) {
    int primary = 0, secondary = 0;

    for (int i = 0; i < n; i++) {
        primary   += arr[i][i];
        secondary += arr[i][n - 1 - i];
    }

    return abs(primary - secondary);
}

int main() {
    int n;
    scanf("%d", &n);

    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(n, arr);

    char* path = getenv("OUTPUT_PATH");
    FILE* fptr = path ? fopen(path, "w") : stdout;
    fprintf(fptr, "%d\n", result);
    if (path) fclose(fptr);

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}
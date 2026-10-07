#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int** seq = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));
    int* cap  = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        cap[i] = 4;
        seq[i] = (int*)malloc(cap[i] * sizeof(int));
    }

    int* answers = (int*)malloc(q * sizeof(int));
    int count = 0;
    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (size[idx] == cap[idx]) {
                cap[idx] *= 2;
                seq[idx] = (int*)realloc(seq[idx], cap[idx] * sizeof(int));
            }
            seq[idx][size[idx]++] = y;
        } else {
            lastAnswer = seq[idx][y % size[idx]];
            answers[count++] = lastAnswer;
        }
    }

    char* path = getenv("OUTPUT_PATH");
    FILE* fptr = path ? fopen(path, "w") : stdout;
    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%d\n", answers[i]);
    }
    if (path) fclose(fptr);

    for (int i = 0; i < n; i++) free(seq[i]);
    free(seq);
    free(size);
    free(cap);
    free(answers);
    return 0;
}
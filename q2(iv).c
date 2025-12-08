int **create_matrix(int m, int n) {
    int **p;
    p = (int **) malloc(m * sizeof(int *));
    if (p == NULL)
        return NULL;

    p[0] = (int *) malloc(m * n * sizeof(int));
    if (p[0] == NULL) {
        free(p);
        return NULL;
    }

    for (int i = 1; i < m; i++) {
        p[i] = p[0] + i * n;
    }

    return p;
}

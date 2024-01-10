void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, tmp;
    
    if (matrixSize < 2) return;

    for (i = 0; i < matrixSize - 1; ++i) {
        for (j = 0; j < matrixSize - 1 - i; ++j) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - j][matrixSize - 1 - i];
            matrix[matrixSize - 1 - j][matrixSize - 1 - i] = tmp;
        }
    }

    for (i = 0; i < (matrixSize + 1) / 2; ++i) {
        for (j = 0; j < matrixSize; ++j) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - i][j];
            matrix[matrixSize - 1 - i][j] = tmp;
        }
    }
}

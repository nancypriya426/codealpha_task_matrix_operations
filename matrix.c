/*
 * Program  : Matrix Operations
 * Task     : Matrix Addition, Multiplication and Transpose
 * Author   : Nancy Priya
 * Date     : June 2026
 */

#include <stdio.h>

#define MAX 10

// ─────────────────────────────────────────────
//  INPUT
// ─────────────────────────────────────────────
void inputMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    printf("\nEnter elements of Matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("  %s[%d][%d]: ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
}

// ─────────────────────────────────────────────
//  DISPLAY
// ─────────────────────────────────────────────
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("  [ ");
        for (int j = 0; j < cols; j++)
            printf("%4d ", mat[i][j]);
        printf("]\n");
    }
}

// ─────────────────────────────────────────────
//  MATRIX ADDITION
// ─────────────────────────────────────────────
void addMatrices(int A[MAX][MAX], int B[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

// ─────────────────────────────────────────────
//  MATRIX MULTIPLICATION
// ─────────────────────────────────────────────
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX],
                      int result[MAX][MAX],
                      int rowsA, int colsA, int colsB) {
    // Initialize result to 0
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            result[i][j] = 0;

    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            for (int k = 0; k < colsA; k++)
                result[i][j] += A[i][k] * B[k][j];
}

// ─────────────────────────────────────────────
//  TRANSPOSE
// ─────────────────────────────────────────────
void transposeMatrix(int mat[MAX][MAX], int transposed[MAX][MAX],
                     int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposed[j][i] = mat[i][j];
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────
int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], transposed[MAX][MAX];
    int r1, c1, r2, c2;

    printf("========================================\n");
    printf("         MATRIX OPERATIONS MENU         \n");
    printf("========================================\n");

    // ── Dimensions for Matrix A ──
    printf("\nEnter dimensions of Matrix A:\n");
    printf("  Rows   : "); scanf("%d", &r1);
    printf("  Columns: "); scanf("%d", &c1);

    // ── Dimensions for Matrix B ──
    printf("\nEnter dimensions of Matrix B:\n");
    printf("  Rows   : "); scanf("%d", &r2);
    printf("  Columns: "); scanf("%d", &c2);

    // ── Input Matrices ──
    inputMatrix(A, r1, c1, "A");
    inputMatrix(B, r2, c2, "B");

    printf("\n========================================\n");
    printf("              YOUR MATRICES             \n");
    printf("========================================\n");
    printf("\nMatrix A (%d x %d):\n", r1, c1);
    displayMatrix(A, r1, c1);
    printf("\nMatrix B (%d x %d):\n", r2, c2);
    displayMatrix(B, r2, c2);

    // ─────────────────────────────────────────
    //  1. ADDITION  (requires same dimensions)
    // ─────────────────────────────────────────
    printf("\n========================================\n");
    printf("          1. MATRIX ADDITION            \n");
    printf("========================================\n");

    if (r1 == r2 && c1 == c2) {
        addMatrices(A, B, result, r1, c1);
        printf("\nA + B (%d x %d):\n", r1, c1);
        displayMatrix(result, r1, c1);
    } else {
        printf("\n[!] Addition NOT possible: dimensions must match.\n");
        printf("    A is %dx%d, B is %dx%d.\n", r1, c1, r2, c2);
    }

    // ─────────────────────────────────────────
    //  2. MULTIPLICATION  (cols of A == rows of B)
    // ─────────────────────────────────────────
    printf("\n========================================\n");
    printf("       2. MATRIX MULTIPLICATION         \n");
    printf("========================================\n");

    if (c1 == r2) {
        multiplyMatrices(A, B, result, r1, c1, c2);
        printf("\nA x B (%d x %d):\n", r1, c2);
        displayMatrix(result, r1, c2);
    } else {
        printf("\n[!] Multiplication NOT possible:\n");
        printf("    Columns of A (%d) must equal Rows of B (%d).\n", c1, r2);
    }

    // ─────────────────────────────────────────
    //  3. TRANSPOSE  (done for both A and B)
    // ─────────────────────────────────────────
    printf("\n========================================\n");
    printf("           3. TRANSPOSE                 \n");
    printf("========================================\n");

    transposeMatrix(A, transposed, r1, c1);
    printf("\nTranspose of A (%d x %d):\n", c1, r1);
    displayMatrix(transposed, c1, r1);

    transposeMatrix(B, transposed, r2, c2);
    printf("\nTranspose of B (%d x %d):\n", c2, r2);
    displayMatrix(transposed, c2, r2);

    printf("\n========================================\n");
    printf("               ALL DONE!                \n");
    printf("========================================\n\n");

    return 0;
}
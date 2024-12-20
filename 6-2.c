#include <stdio.h>

#define MAX_SIZE 100

void transpose(int *matrix, int *transposed, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(transposed + i * n + j) = *(matrix + j * n + i);
        }
    }
}

void multiply_matrices(int *matrix, int *transposed, int *result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(result + i * n + j) = 0;
            for (int k = 0; k < n; k++) {
                *(result + i * n + j) += *(matrix + i * n + k) * *(transposed + k * n + j);
            }
        }
    }
}

int is_symmetric(int *matrix, int *transposed, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(matrix + i * n + j) != *(transposed + i * n + j)) {
                return 0;  
            }
        }
    }
    return 1;  
}
void print_matrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n); 

    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    transpose((int *)matrix, (int *)transposed, n);

    if (is_symmetric((int *)matrix, (int *)transposed, n)) {
        printf("Symmetric Matrix\n");
        print_matrix((int *)matrix, n);
    } else {
        printf("Asymmetric Matrix\n");
        multiply_matrices((int *)matrix, (int *)transposed, (int *)result, n);
        print_matrix((int *)result, n);
    }

    return 0;
}

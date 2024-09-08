#include <stdio.h>
#define INF 2000000
// int k_arr[][]={0};
void matrix_chain(int cost[][5], int k_arr[][5], int dim[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cost[i][j] = 0;
            } else {
                cost[i][j] = INF;
            }
            k_arr[i][j] = 0;
        }
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = INF;
            for (int k = i; k < j; k++) {
                int q = cost[i][k] + cost[k + 1][j] + dim[i] * dim[k + 1] * dim[j + 1];                
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    k_arr[i][j] = k;
                }
            }
        }
    }
}
void print_parenthesis(int k_arr[][5], int i, int j) {
    if (i == j) {
        printf("M%d", i + 1);
    } else {
        int k = k_arr[i][j];
        printf("(");
        print_parenthesis(k_arr, i, k);
        print_parenthesis(k_arr, k + 1, j);
        printf(")");
    }
}

int main () {
    int num_matrix = 4;
    int dim[5] = {3, 2, 4, 2, 5}; 
    int cost[5][5] = {0};
    int k_arr[5][5] = {0};

    matrix_chain(cost, k_arr, dim, num_matrix);
    printf("Cost:\n");
    for (int i = 0; i < num_matrix; i++) {
        for (int j = 0; j < num_matrix; j++) {
            if (cost[i][j] == INF) {
                printf("0 ");
            } else {
                printf("%d ", cost[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nthe K matrix:\n");
    for (int i = 0; i < num_matrix; i++) {
        for (int j = 0; j < num_matrix; j++) {
            printf("%d ", k_arr[i][j] + 1); 
        }
        printf("\n");
    }
    printf("\noptimal solution:\n");
    print_parenthesis(k_arr, 0, num_matrix - 1);
    printf("\n");
return 0;
}
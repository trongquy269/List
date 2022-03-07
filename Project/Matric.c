#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef struct
{
    int row;
    int column;
    int M[MAX][MAX];
} MATRIX;

void Input(MATRIX *m)
{
    printf("Nhap so hang: ");
    scanf("%d", &(m->row));
    printf("Nhap so cot: ");
    scanf("%d", &(m->column));
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            printf("\nNhap gia tri tai phan tu (%d, %d): ", i + 1, j + 1);
            scanf("%d", &(m->M[i][j]));
        }
    }
}

void Output(MATRIX m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
        {
            printf("%d ", m.M[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
    Input(m);
    Output(*m);
    return 0;
}
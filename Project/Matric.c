#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef struct
{
    int row;
    int column;
    float M[MAX][MAX];
} MATRIX;

void Plus_2_matrix(MATRIX *m, MATRIX *n)
{
    if ((m->row == n->row) && (m->column == n->column))
    {
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                m->M[i][j] += n->M[i][j];
            }
        }
    }
    else
    {
        printf("\n2 matrix are not of the same level!");
        if ((m->row != n->row) && (m->column != n->column))
        {
            printf("\nROW: %d is not equal to %d", m->row, n->row);
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
        }
        else if (m->row != n->row)
        {
            printf("\nROW: %d is not equal to %d\n", m->row, n->row);
        }
        else
        {
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
        }
    }
}

void Subtract_2_matrix(MATRIX *m, MATRIX *n)
{
    if ((m->row == n->row) && (m->column == n->column))
    {
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                m->M[i][j] -= n->M[i][j];
            }
        }
    }
    else
    {
        printf("\n2 matrix are not of the same level!");
        if ((m->row != n->row) && (m->column != n->column))
        {
            printf("\nROW: %d is not equal to %d", m->row, n->row);
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
        }
        else if (m->row != n->row)
        {
            printf("\nROW: %d is not equal to %d\n", m->row, n->row);
        }
        else
        {
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
        }
    }
}

void Multiply_aNumber(MATRIX *m, float x)
{
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            m->M[i][j] *= x;
        }
    }
}

// void Multiply_2_matrix(MATRIX *m, MATRIX *n)
// {
//     if (m->row  == m->column)
//     {
//         MATRIX *temp = (MATRIX *)malloc(sizeof(MATRIX));
//         temp->row = m->row;
//         temp->column = n->column;
//         for (int i = 0; i < m->row; i++)
//         {
//             for (int k = 0; k < n->column; k++)
//             {
//                 for (int j = 0; j < m->column; j++)
//                 {
//                     temp->M[i][k] += m->M[i][j] * n->M[j][k];
//                 }
//             }
//         }
//         MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
//         m->row = temp->row;
//         m->column = temp->column;
//         for (int i = 0; i < m->row; i++)
//         {
//             for (int j = 0; j < m->column; j++)
//             {
//                 m->M[i][j] = temp->M[i][j];
//             }
//         }
//     }
// }

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
    MATRIX *n = (MATRIX *)malloc(sizeof(MATRIX));
    Input(n);
    //Multiply_2_matrix(m, n);
    Output(*m);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef struct
{
    int row;
    int column;
    float M[MAX][MAX];
} MATRIX;

int Plus_2_matrix(MATRIX *m, MATRIX *n)
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
            return 0;
        }
        else if (m->row != n->row)
        {
            printf("\nROW: %d is not equal to %d\n", m->row, n->row);
            return 0;
        }
        else
        {
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
            return 0;
        }
    }
}

int Subtract_2_matrix(MATRIX *m, MATRIX *n)
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
            return 0;
        }
        else if (m->row != n->row)
        {
            printf("\nROW: %d is not equal to %d\n", m->row, n->row);
            return 0;
        }
        else
        {
            printf("\nCOLUMN: %d is not equal to %d\n", m->column, n->column);
            return 0;
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

int Multiply_2_matrix(MATRIX *m, MATRIX *n)
{
    if (m->row  == n->column)
    {
        MATRIX *temp = (MATRIX *)malloc(sizeof(MATRIX));
        temp->row = m->row;
        temp->column = n->column;
        for (int i = 0; i < m->row; i++)
        {
            for (int k = 0; k < n->column; k++)
            {
                for (int j = 0; j < m->column; j++)
                {
                    temp->M[i][k] += m->M[i][j] * n->M[j][k];
                }
            }
        }
        m->row = temp->row;
        m->column = temp->column;
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                m->M[i][j] = temp->M[i][j];
            }
        }
    }
    else
    {
        printf("\n2 matrix are not of the same level!");
        printf("\nROW A = %d is not equal to COLUMN B = %d!\n", m->row, n->column);
        return 0;
    }
}

int Check_matrix(MATRIX *m)
{
    if (m->row != m->column)
    {
        return 0;
    }
    else
    {
        int check_above = 1;
        int check_under = 1;
        for (int i = 1; i < m->row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (m->M[i][j] == 0)
                {
                    check_above = 1;
                }
                else
                {
                    check_above = 0;
                    break;
                }
            }
            if (check_above == 0)
            {
                break;
            }
        }
        for (int i = 0; i < m->row - 1; i++)
        {
            for (int j = m->row; j > i + 1; j--)
            {
                if (m->M[i][j] == 0)
                {
                    check_under = 1;
                }
                else
                {
                    check_under = 0;
                    break;
                }
            }
            if (check_under == 0)
            {
                break;
            }
        }
        if ((check_above + check_under) == 2)
        {
            return 3;
        }
        else if ((check_above + check_under) == 1)
        {
            if (check_above == 1)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 0;
        }
    }
}

float Det_A_temp(MATRIX *m)
{
    if (m->row = 2)
    {
        float kq = 1;
        for (int i = 0; i < m->row; i++)
        {
            kq *= m->M[i][i];
        }
        return kq;
    }
    else
    {
        MATRIX *temp = (MATRIX *)malloc(sizeof(MATRIX));
        temp->row = m->row -1;
        float a = 1;
        int row = 0;
        int column = 0;
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->row; j++)
            {
                for (int k = 0; k < m->row; k++)
                {
                    if ((j == i) || (k == i))
                    {

                    }
                    else
                    {
                        temp->M[row][column] = m->M[j][k];
                        row++;
                        column++;
                    }
                }
            }
            if (i % 2 == 0)
            {
                a *= m->M[0][i] * Det_A_temp(temp);
            }
            else
            {
                a *= m->M[0][i] * Det_A_temp(temp) * (-1);
            }
        }
        free(temp);
        return a;
    }
}

float Det_A(MATRIX *m)
{
    if (m->row != m->column)
    {
        printf("\nError matrix! ROW is not equal to COLUMN");
        return 0;
    }
    else
    {
        int check;
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                if (m->M[i][j] == 0)
                {
                    check = 1;
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            if (check == 1)
            {
                return 0;
            }
        }
        for (int i = 0; i < m->column; i++)
        {
            for (int j = 0; j < m->row; j++)
            {
                if (m->M[j][i] == 0)
                {
                    check = 1;
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            if (check == 1)
            {
                return 0;
            }
        }
        for (int i = 0; i < m->row - 1; i++)
        {
            int a = m->M[i][0];
            for (int k = i + 1; k < m->row; k++)
            {
                int b = m->M[k][0];
                float kq = (float)a/b;
                for (int j = 0; j < m->row; j++)
                {
                    if ((m->M[i][j] / kq) == m->M[k][j])
                    {
                        check = 1;
                    }
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                if (check == 1)
                {
                    return 0;
                }
            }
        }
        for (int i = 0; i < m->row - 1; i++)
        {
            int a = m->M[0][i];
            for (int k = i + 1; k < m->row; k++)
            {
                int b = m->M[0][k];
                float kq = (float)a/b;
                for (int j = 0; j < m->row; j++)
                {
                    if ((m->M[j][i] / kq) == m->M[j][k])
                    {
                        check = 1;
                    }
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                if (check == 1)
                {
                    return 0;
                }
            }
        }
        if (Check_matrix(m) != 0)
        {
            float kq = 1;
            for (int i = 0; i < m->row; i++)
            {
                kq *= m->M[i][i];
            }
            return kq;
        }
        else
        {
            return Det_A_temp(m);
        }
    }
}

void Input(MATRIX *m)
{
    printf("\nNhap so hang: ");
    scanf("%d", &(m->row));
    printf("Nhap so cot: ");
    scanf("%d", &(m->column));
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            printf("\nNhap gia tri tai phan tu (%d, %d): ", i + 1, j + 1);
            scanf("%f", &(m->M[i][j]));
        }
    }
}

void Output(MATRIX m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
        {
            if (((float)m.M[i][j] - (int)m.M[i][j]) == 0)
            {
                printf("%.0f ", m.M[i][j]);
            }
            else
            {
                printf("%.2f ", m.M[i][j]);
            }
        }
        printf("\n");
    }
}

void Menu()
{
    int check;
    do
    {
        check = 0;
        system("cls");
        printf(">> MENU <<\n");
        printf("\n1. Tinh tong 2 ma tran\n");
        printf("2. Tinh hieu 2 ma tran\n");
        printf("3. Nhan ma tran voi 1 so\n");
        printf("4. Nhan 2 ma tran\n");
        printf("5. Kiem tra ma tran tam giac\n");
        printf("6. Tinh Det A\n");
        printf("0. Thoat\n");
        printf("\n>> END <<\n");
        int select;
        printf("\nSelect: ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
            {
                system("cls");
                printf("\n>> CONG 2 MA TRAN <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) 2 ma tran phai cung cap: ");
                printf("\n    (.) ROW A = ROW B");
                printf("\n    (.) COLUMN A = COLUMN B");
                printf("\n  (-) Ma tran co kieu so nguyen hoac so thuc\n");
                printf("\nNhap ma tran 1:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                printf("\nNhap ma tran 2:\n");
                MATRIX *n = (MATRIX *)malloc(sizeof(MATRIX));
                Input(n);
                system("cls");
                printf("\nMa tran 1:\n");
                Output(*m);
                printf("\nOperation: +\n\n");
                printf("Ma tran 2:\n");
                Output(*n);
                printf("\nEqual: =\n\n");
                if (Plus_2_matrix(m, n) != 0)
                {
                    Output(*m);
                }
                free(m);
                free(n);
            } break;
            case 2:
            {
                system("cls");
                printf("\n>> HIEU 2 MA TRAN <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) 2 ma tran phai cung cap: ");
                printf("\n    (.) ROW A = ROW B");
                printf("\n    (.) COLUMN A = COLUMN B");
                printf("\n  (-) Ma tran co kieu so nguyen hoac so thuc\n");
                printf("\nNhap ma tran 1:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                printf("\nNhap ma tran 2:\n");
                MATRIX *n = (MATRIX *)malloc(sizeof(MATRIX));
                Input(n);
                system("cls");
                printf("\nMa tran 1:\n");
                Output(*m);
                printf("\nOperation: -\n\n");
                printf("Ma tran 2:\n");
                Output(*n);
                printf("\nEqual: =\n\n");
                if (Subtract_2_matrix(m, n) != 0)
                {
                    Output(*m);
                }
                free(m);
                free(n);
            } break;
            case 3:
            {
                system("cls");
                printf("\n>> NHAN 1 SO VOI MA TRAN <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) Du lieu nhap vao phai la so nguyen hoac so thuc\n");
                float x;
                printf("\nNhap so can nhan: ");
                scanf("%f", &x);
                printf("\nNhap ma tran:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                system("cls");
                printf("\n%.2f\n", x);
                printf("\nOperation: *\n\n");
                printf("Ma tran:\n");
                Output(*m);
                printf("\nEqual: =\n\n");
                Multiply_aNumber(m, x);
                Output(*m);
                free(m);
            } break;
            case 4:
            {
                system("cls");
                printf("\n>> NHAN 2 MA TRAN <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) ROW A = COLUMN B");
                printf("\n  (-) Ma tran co kieu so nguyen hoac so thuc\n");
                printf("\nNhap ma tran 1:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                printf("\nNhap ma tran 2:\n");
                MATRIX *n = (MATRIX *)malloc(sizeof(MATRIX));
                Input(n);
                system("cls");
                printf("\nMa tran 1:\n");
                Output(*m);
                printf("\nOperation: *\n\n");
                printf("Ma tran 2:\n");
                Output(*n);
                printf("\nEqual: =\n\n");
                if (Multiply_2_matrix(m, n) != 0)
                {
                    Output(*m);
                }
                free(m);
                free(n);
            } break;
            case 5:
            {
                system("cls");
                printf("\n>> KIEM TRA MA TRAN TAM GIAC <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) La ma tran vuong");
                printf("\n    (.) ROW = COLUMN");
                printf("\n  (-) Du lieu nhap vao la so nguyen hoac so thuc\n");
                printf("\nNhap ma tran:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                system("cls");
                printf("Ma tran:\n");
                Output(*m);
                if (Check_matrix(m) == 1)
                {
                    printf("\nLa ma tran tam giac tren\n");
                }
                else if (Check_matrix(m) == 2)
                {
                    printf("\nLa ma tran tam giac duoi\n");
                }
                else if (Check_matrix(m) == 3)
                {
                    printf("\nLa ma tran duong cheo\n");
                }
                else
                {
                    printf("\nKhong phhai la ma tran tam giac\n");
                }
            } break;
            case 6:
            {
                system("cls");
                printf("\n>> TINH DET A <<\n");
                printf("\n(+) Dieu kien:");
                printf("\n  (-) La ma tran vuong");
                printf("\n    (.) ROW = COLUMN");
                printf("\n  (-) Du lieu nhap vao la so nguyen hoac so thuc\n");
                printf("\nNhap ma tran:\n");
                MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
                Input(m);
                system("cls");
                printf("Ma tran:\n");
                Output(*m);
                printf("\nDet A = %.2f\n", Det_A(m));
            } break;
            case 0:
            {
                exit(0);
            } break;
            default :
            {
                printf("\nInvalid selection!\n");
                check = 1;
            }
        }
    } while (check == 1);
}

int main()
{
    Menu();
    return 0;
}
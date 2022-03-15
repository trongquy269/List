#include <stdio.h>
#include <stdlib.h>

#define MAX 500 // Ma trận chứa tối đa 500 x 500 phần tử

// Khai báo cấu trúc ma trận
// Gồm 2 số nguyên row và column để quản lí số dòng và số cột
// Và mảng 2 chiều M[][] để lưu giá trị của ma trận
typedef struct
{
    int row;
    int column;
    float M[MAX][MAX];
} MATRIX;

// Hàm tính tổng 2 ma trận
// Thông số truyền vào gồm 2 con trỏ quản lí 2 ma trận riêng biệt
int Plus_2_matrix(MATRIX *m, MATRIX *n)
{
    // Phép cộng được thực hiện khi 2 ma trận m và n cùng cấp
    // ROW m = ROW n, COLUMN m = COLUMN n
    if ((m->row == n->row) && (m->column == n->column))
    {
        // Loop chạy hết từng phần tử trong 2 mảng và thực hiện cộng lại với nhau
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                // Kết quá cộng được lưu vào mảng do con trỏ *m quản lí
                m->M[i][j] += n->M[i][j];
            }
        }
    }
    // Nếu không thỏa điều kiện của phép cộng
    // In ra thông báo
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

// Hàm tính hiệu 2 ma trận
// Thông số truyền vào gồm 2 con trỏ quản lí 2 ma trận riêng biệt
int Subtract_2_matrix(MATRIX *m, MATRIX *n)
{
    // Phép trừ được thực hiện khi 2 ma trận m và n cùng cấp
    // ROW m = ROW n, COLUMN m = COLUMN n
    if ((m->row == n->row) && (m->column == n->column))
    {
        // Loop chạy hết từng phần tử trong 2 mảng và thực hiện trừ với nhau
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                // Kết quá trừ được lưu vào mảng do con trỏ *m quản lí
                m->M[i][j] -= n->M[i][j];
            }
        }
    }
    // Nếu không thỏa điều kiện của phép trừ
    // In ra thông báo
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

// Phép nhân 1 số với ma trận
// Thông số truyền vào là 1 ma trận do con trỏ *m quản lí và 1 số
void Multiply_aNumber(MATRIX *m, float x)
{
    // Loop chạy hết từng phần tử trong mảng
    // Và thực hiện nhân từng phần tử trong mảng với số đã truyền vào
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            // Kết quá trừ được lưu vào mảng do con trỏ *m quản lí
            m->M[i][j] *= x;
        }
    }
}

// Phép nhân 2 mà trận
// Thông số truyền vào là 2 ma trận do con trỏ *m và *n quản lí
int Multiply_2_matrix(MATRIX *m, MATRIX *n)
{
    // Điều kiện để thực hiện phép nhân 2 ma trận
    // ROW m = COLUMN n
    if (m->row  == n->column)
    {
        // Khai báo 1 biến con trỏ *temp có kiểu dữ liệu MATRIX (cùng kiểu với 2 mảng truyền vào)
        // Mảng do con trỏ *temp quản lí có RƠW temp = ROW m, COLUMN temp = COLUMN n
        MATRIX *temp = (MATRIX *)malloc(sizeof(MATRIX));
        temp->row = m->row;
        temp->column = n->column;
        // Loop 1: duyêt hết tất cả dòng của ma trận do con trỏ *m quản lí
        for (int i = 0; i < m->row; i++)
        {
            // Loop 2: duyệt hết tất cả cột của ma trận do con trỏ *n quản lí
            for (int k = 0; k < n->column; k++)
            {
                // Loop 3: duyệt hết tất cả cột của ma trận do con trỏ *m quản lí
                for (int j = 0; j < m->column; j++)
                {
                    // Do mảng do con trỏ *temp quản lí có RƠW temp = ROW m, COLUMN temp = COLUMN n
                    // Nên 2 giá trị bên trong mảng 2 chiều là i và k
                    // (temp)i,j = Tổng các phần tử Hi(m) * Cj(n) tương ứng
                    // (Hi là hàng thứ i, Cj là cột thứ j)
                    temp->M[i][k] += m->M[i][j] * n->M[j][k];
                }
            }
        }
        // Kết quá trừ được lưu vào mảng do con trỏ *m quản lí
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
    // Nếu không thỏa điều kiện của phép trừ
    // In ra thông báo
    else
    {
        printf("\n2 matrix are not of the same level!");
        printf("\nROW A = %d is not equal to COLUMN B = %d!\n", m->row, n->column);
        return 0;
    }
}

/*
Hàm kiểm tra ma trận tam giác, ma trận đường chéo
- Ma trận tam giác trên là ma trận vuông có mọi phần tử nằm phía dưới đường chéo chính bằng 0
- Ma trận tam giác trên là ma trận vuông có mọi phần tử nằm phía trên đường chéo chính bằng 0
- Ma trận đường chéo là ma trận vuông có mọi phần tử nằm ngoài đường chéo chính bằng 0
Thông số truyền vào là ma trận do con trỏ *m quản lí
*/
int Check_matrix(MATRIX *m)
{
    // Ma trận vuông có số hàng ROW = số cột COLUMN
    if (m->row != m->column)
    {
        return 0;
    }
    else
    {
        int check_above = 1; // Biến kiểm tra ma trận trên
        int check_under = 1; // Biến kiểm tra ma trận dưới
        // Loop duyệt hết các phần tử phía dưới đường chéo chính trong ma trận
        for (int i = 1; i < m->row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // Nếu các phần tử bên dưới đường chéo chính == 0
                // Gán biến check_above = 1
                if (m->M[i][j] == 0)
                {
                    check_above = 1;
                }
                // Ngược lại có 1 phần tử bất kì nào bên dưới đường chéo chính != 0
                // break khỏi loop
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
        // Loop duyệt hết các phần tử phía trên đường chéo chính trong ma trận
        for (int i = 0; i < m->row - 1; i++)
        {
            for (int j = m->row; j > i + 1; j--)
            {
                // Nếu các phần tử bên trên đường chéo chính == 0
                // Gán biến check_under = 1
                if (m->M[i][j] == 0)
                {
                    check_under = 1;
                }
                // Ngược lại có 1 phần tử bất kì nào bên trên đường chéo chính != 0
                // break khỏi loop
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
        /*
        - return 0 nếu không phải ma trận tam giác
        - return 1 nếu là ma trận tam giác trên
        - return 2 nếu là ma trận tam giác dưới
        - return 3 nếu là ma trận đường chéo
        */
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

// Hàm con để thực hiện tính toán cho hàm Det_A()
float Det_A_temp(MATRIX *m)
{
    if (m->row == 2)
    {
        return ((m->M[0][0] * m->M[1][1]) - (m->M[1][0] * m->M[0][1]));
    }
    else
    {
        float a = 0;
        for (int i = 0; i < m->row; i++)
        {
            MATRIX *temp = (MATRIX *)malloc(sizeof(MATRIX));
            temp->row = m->row -1;
            temp->column = m->row - 1;
            int row = 0;
            int column = 0;
            for (int j = 1; j < m->row; j++)
            {
                for (int k = 0; k < m->row; k++)
                {
                    if (i != m->row - 1)
                    {
                        if (k != i)
                        {
                            temp->M[row][column] = m->M[j][k];
                            column++;
                        }
                        if (k == m->row - 1)
                        {
                            column = 0;
                        }
                        if ((column == 0) && (k != i))
                        {
                            row++;
                        }
                    }
                    else
                    {
                        if (k != i)
                        {
                            temp->M[row][column] = m->M[j][k];
                            column++;
                        }
                        if (k == m->row - 1)
                        {
                            column = 0;
                        }
                        if ((column == 0) && (k == i))
                        {
                            row++;
                        }
                    }
                    
                }
            }
            /*
            Do hàm luôn chọn hàng 1 để tính
            Nên |A| = a(1,1)*(-1)^(1+1)*|M(1,1)| + a(1,2)*(-1)^(1+2)*|M(1,2)| +...+ a(1,n)*(-1)^(1+n)*|M(1,n)|
            Với |M(1,n)| là ma trận còn lại khi đã lượt bỏ đi hàng 1 cột n
            Vậy suy ra cột 1 sẽ nhân với 1 và cột 2 sẽ nhân với trừ 1
            => Cột 0 -> n - 1 khi cột chẵn sẽ nhân với 1 và cột lẻ sẽ nhân với -1
            */
            if (i % 2 == 0)
            {
                a += m->M[0][i] * Det_A_temp(temp);
            }
            else
            {
                a += m->M[0][i] * Det_A_temp(temp) * (-1);
            }
            free(temp);
        }
        return a;
    }
}

// Hàm tính Determinant của ma trận
// Thông số truyền vào là 1 mảng do con trỏ *m quản lí
float Det_A(MATRIX *m)
{
    // Điểu kiện để tính định thức là ma trận phải là ma trận vuông
    if (m->row != m->column)
    {
        printf("\nError matrix! ROW is not equal to COLUMN");
        return 0;
    }
    else
    {
        int check; // Khởi tạo biến check để kiểm tra
    // Loop duyệt mọi phần tử trong ma trận
        // Loop 1 kiểm tra có 1 hàng == 0
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                // check = 1 nếu có phần tử trong hàng == 1
                // nếu có phần tử trong hàng != 0 => check == 0 và break chuyển sang hàng kế tiếp
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
            // Nếu có 1 hàng mà mọi phần tử trong hàng đều == 0
            // Thì trả về giá trị 0 cho hàm <=> Det A = 0
            if (check == 1)
            {
                return 0;
            }
        }
        // Loop 2 kiểm tra có 1 cột == 0
        for (int i = 0; i < m->column; i++)
        {
            for (int j = 0; j < m->row; j++)
            {
                // check = 1 nếu có phần tử trong cột == 1
                // nếu có phần tử trong cột != 0 => check == 0 và break chuyển sang cột kế tiếp
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
            // Nếu có 1 cột mà mọi phần tử trong cột đều == 0
            // Thì trả về giá trị 0 cho hàm <=> Det A = 0
            if (check == 1)
            {
                return 0;
            }
        }
        // Loop 3 kiểm tra 2 hàng tỉ lệ nhau
        for (int i = 0; i < m->row - 1; i++)
        {
            // Khởi tạo biến a nhận giá trị đầu tiên của hàng đang xét
            // Biến này sẽ được chia với biến b nhận giá trị đầu tiên của hàng khác để lấy tỉ lệ
            float a = m->M[i][0];
            // Loop duyệt các hàng khác hàng đang xét (hàng so sánh)
            for (int k = i + 1; k < m->row; k++)
            {
                // Khởi tạo biến b nhận giá trị đầu tiên của hàng khác
                int b = m->M[k][0];
                float kq = (float)a/b; // Chia lấy tỉ lệ
                for (int j = 0; j < m->row; j++)
                {
                    // Nếu phần tử i,j tại hàng đang xét chia tỉ lệ
                    // Bằng với phần tử k,j tại hàng so sánh
                    // Thì cho biến kiểm tra check = 1;
                    if ((m->M[i][j] / kq) == m->M[k][j])
                    {
                        check = 1;
                    }
                    // Nếu có bất kì phần tử tương ứng nào không tỉ lệ
                    // Cho biến check = 0 và break để qua hàng so sánh kế tiếp
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                // Nếu có 2 hàng tỉ lệ với nhau
                // Thì trả về giá trị 0 cho hàm <=> Det A = 0
                if (check == 1)
                {
                    return 0;
                }
            }
        }
        // Loop 4 kiểm tra 2 cột tỉ lệ nhau
        for (int i = 0; i < m->row - 1; i++)
        {
            // Khởi tạo biến a nhận giá trị đầu tiên của cột đang xét
            // Biến này sẽ được chia với biến b nhận giá trị đầu tiên của cột khác để lấy tỉ lệ
            float a = m->M[0][i];
            // Loop duyệt các cột khác cột đang xét (hàm so sánh)
            for (int k = i + 1; k < m->row; k++)
            {
                // Khởi tạo biến b nhận giá trị đầu tiên của hàng khác
                int b = m->M[0][k];
                float kq = (float)a/b; // Chia lấy tỉ lệ
                for (int j = 0; j < m->row; j++)
                {
                    // Nếu phần tử i,j tại cột đang xét chia tỉ lệ
                    // Bằng với phần tử k,j tại cột so sánh
                    // Thì cho biến kiểm tra check = 1;
                    if ((m->M[j][i] / kq) == m->M[j][k])
                    {
                        check = 1;
                    }
                    // Nếu có bất kì phần tử tương ứng nào không tỉ lệ
                    // Cho biến check = 0 và break để qua cột so sánh kế tiếp
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                // Nếu có 2 hàng tỉ lệ với nhau
                // Thì trả về giá trị 0 cho hàm <=> Det A = 0
                if (check == 1)
                {
                    return 0;
                }
            }
        }
        // Kiểm tra là ma trận tam giác
        // Nếu là ma trận tam giác thì Det A = tích cả phần tử của đường chéo chính
        if (Check_matrix(m) != 0)
        {
            float kq = 1;
            for (int i = 0; i < m->row; i++)
            {
                kq *= m->M[i][i];
            }
            return kq;
        }
        // Nếu không phải các trường hợp trên thì chuyển qua hàm Det_A_temp() để thực hiện tính toán
        else
        {
            return Det_A_temp(m);
        }
    }
}

// Hàm khởi tạo ma trận đơn vị cấp n, kí hiệu I(n)
// Là ma trận vuông cấp n có mọi phần tử tại đường chéo chính == 1, ngoài đường chéo chính == 0
void Init_matrix_In(MATRIX *m)
{
    // Điểu kiện để tính định thức là ma trận phải là ma trận vuông
    if (m->row != m->column)
    {
        printf("\nError matrix! ROW is not equal to COLUMN");
    }
    else
    {
        for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->column; j++)
            {
                m->M[i][j] = 0;
                m->M[i][i] = 1;
            }
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
                if (((float)Det_A(m) - (int)Det_A(m)) == 0)
                {
                    printf("\nDet A = %.0f\n", Det_A(m));
                }
                else
                {
                    printf("\nDet A = %.2f\n", Det_A(m));
                }
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
#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc của 1 cái node (gồm 2 phần tử: dữ liệu và con trỏ)
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

// Khai báo cấu trúc của STACK, sử dụng cấu trúc của danh sách liên kết
// Được quản lí bằng 1 con trỏ *pTop
typedef struct
{
    NODE *Top;
} STACK;

// Khởi tạo STACK
void Create_Stack(STACK *s)
{
    // Cho node đỉnh trỏ đến vùng nhớ rỗng
    s->Top = NULL;
}

// Khởi tạo 1 cái node
NODE *Add_Node(int data)
{
    // Khai báo biến con trỏ p có kiểu dữ liệu NODE
    NODE *p = (NODE *)malloc(sizeof(NODE));
    // Nếu khởi tạo không thành công
    if (p == NULL)
    {
        // In ra thông báo và trả về giá trị rỗng cho hàm
        printf("Failed to add node. Out of memory!\n");
        return NULL;
    }
    else
    {
        p->data = data; // Truyền giá trị cho node p
        p->pNext = NULL;    // Con trỏ mới tạo nên độc lập nên con trỏ sẽ trỏ đến NULL
        return p;   // Trả về con trỏ p
    }
}

// Hàm kiểm tra Stack rỗng
int IsEmpty(STACK s)
{
    if (s.Top == NULL) // Nếu node đỉnh rỗng
    {
        return 1;   // Trả về giá trị true
    }
    else
    {
        return 0;   // Ngược lại trả về giá trị false
    }
}

// Hàm thêm 1 phần tử vào đỉnh Stack
void Push(STACK *s, NODE *p)
{
    // Nếu danh sách rỗng thì node đỉnh bằng node thêm vào
    if (IsEmpty(*s) == 1)
    {
        s->Top = p;
    }
    // Ngược lại
    else
    {
        p->pNext = s->Top;  // Con trỏ của node cần thêm trỏ đến node đỉnh stack
        s->Top = p; // Cập nhật lại node đỉnh stack
    }
}

// Hàm lấy phần tử ở đỉnh stack và xóa nó đi
int Pop(STACK *s)
{
    // Nếu danh sách rỗng thì in ra thông báo
    if (IsEmpty(*s) == 1)
    {
        printf("The stack is empty!\n");
    }
    // Ngược lại
    else
    {
        int value;  // Tạo biến để lưu giá trị
        value = s->Top->data;   // Truyền giá trị của node ở đỉnh stack cho biến vừa tạo
        s->Top = s->Top->pNext; // Cập nhật đỉnh stack là node bên dưới
        return value;   // Trả về giá trị node đỉnh
    }
}

// Hàm xem phần tử ở đỉnh stack
int Top(STACK s)
{
    // Nếu danh sách rỗng thì in ra thông báo
    if (IsEmpty(s) == 1)
    {
        printf("The stack is empty!\n");
    }
    // Ngược lại
    else
    {
        return s.Top->data; // Trả về giá trị đỉnh stack
    }
}

// Hàm xuất các phần tử trong stack
void OutPut(STACK s)
{
    while (s.Top != NULL)
    {
        printf("%d ", s.Top->data);
        s.Top = s.Top->pNext;
    }
}

int main()
{
    STACK *s;
    Create_Stack(s);
    printf("Nhap so luong phan tu can them: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nNhap gia tri cua phan tu thu %d: ", i);
        int value;
        scanf("%d", &value);
        NODE *p = Add_Node(value);
        Push(s, p);
    }
    printf("\nDanh sach vua nhap la: ");
    OutPut(*s);
    printf("\n");
    return 0;
}
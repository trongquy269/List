#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc của 1 cái node
// Gồm 2 thành phần là dữ liệu và con trỏ 
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

// Khai báo cấu trúc của Queue dựa vào cấu trúc của danh sách liên kết
// Được quản lí bởi 2 con trỏ đầu và cuối
typedef struct
{
    NODE *pHead;    // Con trỏ đầu
    NODE *pTail;    // Con trỏ cuối
} QUEUE;

// Khởi tạo Queue
void Create_Queue(QUEUE *q)
{
    // Cho con trỏ đầu và con trỏ cuối đều trỏ đến vùng nhớ rỗng
    // Vì mới khởi tạo nên nó đâu có phần tử nào đâu
    q->pHead = NULL;
    q->pTail = NULL;
}

// Khởi tạo 1 cái node
NODE *Add_Node(int data)
{
    // Khai báo biến con trỏ *p với kiểu dữ liệu NODE
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->data = data; // Truyền giá trị cho p
    p->pNext = NULL;    // Cho con pNext trỏ đến NULL vì đây là node độc lập chưa liên kết với node khác
}

// Hàm kiểm tra danh sách rỗng
int IsEmpty(QUEUE q)
{
    // Nếu phần tử đầu không có thì danh sách rỗng
    // Trả về giá trị true
    // Và ngược lại
    if (q.pHead == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Hàm thêm phần tử vào Queue
void Push(QUEUE *q, NODE *p)
{
    if (IsEmpty(*q) == 1)
    {
        // Nếu danh sách rỗng
        // Con trỏ đầu và con trỏ cuối cũng chính là node cần thêm
        q->pHead = q->pTail = p;
    }
    else
    {
        // Nếu queue đã có phần tử
        q->pTail->pNext = p;    // Cho con trỏ của pTail trỏ đến node cần thêm
        q->pTail = p;   // Cập nhật lại con trỏ cuối
    }
}

// Hàm lấy phần tử ở vị trí đầu Queue và xóa nó đi
int Pop(QUEUE *q)
{
    if (IsEmpty(*q) == 1)
    {
        // Nếu danh sách rỗng thì in ra thông báo
        printf("The queue if empty!\n");
    }
    else
    {
        int value;  // Tạo ra 1 biến để lưu giá trị
        value = q->pHead->data; // Truyền giá trị cho biến đó
        q->pHead = q->pHead->pNext; // Cập nhật lại node đầu là node sau
        return value;   // Trả về giá trị phần tử đầu
    }
}

// Hàm xem phần tử ở đầu Queue
int Top(QUEUE q)
{
    if (IsEmpty(q) == 1)
    {
        // Nếu danh sách rỗng thì in ra thông báo
        printf("The queue if empty!\n");
    }
    else
    {
        return q.pHead->data; // Trả về giá trị của node đầu
    }
}

// Hàm xuất ra các phần tử trong Queue
void OutPut(QUEUE q)
{
    while (q.pHead != NULL)
    {
        printf("%d ", q.pHead->data);
        q.pHead = q.pHead->pNext;
    }
}

int main()
{
    QUEUE *q;
    Create_Queue(q);
    printf("Nhap so luong cac phan tu can them: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nNhap gia tri cua phan tu thu %d: ", i);
        int value;
        scanf("%d", &value);
        NODE *p = Add_Node(value);
        Push(q, p);
    }
    printf("\nDanh sach vua nhap la: ");
    OutPut(*q);
    printf("\n");
    return 0;
}
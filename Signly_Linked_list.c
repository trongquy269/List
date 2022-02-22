#include <stdio.h>
#include <stdlib.h>

//Hàm khai báo 1 cái NODE (gồm 2 phần là dữ liệu và con trỏ)
struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

//Khai báo cấu trúc của một danh sách liên kết đơn
//Được quản lý bằng 2 con trỏ, con trỏ đầu *pHead và con trỏ cuối *pTail
typedef struct
{
    NODE* pHead;
    NODE* pTail;
} LIST;

//Khởi tạo danh sách liên kết đơn
void Create_list(LIST *l)
{
    //Danh sách mới khởi tạo nên là danh sách rỗng
    l->pHead = NULL; //Con trỏ đầu trỏ đến vùng nhớ rỗng
    l->pTail = NULL; //Con trỏ cuối trỏ đến vùng nhớ rỗng
}

//Tạo ra 1 cái node
NODE *Add_node(int value)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));  //Khởi tạo 1 node p
    if (p == NULL)
    {
        //Nếu p == NULL
        //Cấp phát vùng nhớ thất bại
        printf("Failed to add node. Out of memory!\n"); //In ra thêm nút thất bại, tràn bộ nhớ
        return NULL;
    }
    else
    {
        p->data = value;    //Truyền giá trị cho data
        p->pNext = NULL;    //Node mới tạo ra chưa có liên kết với node nào nên con trỏ trỏ tới vùng nhớ rỗng
        return p;   //Trả về cái NODE vừa tạo
    }
}

//Chèn node đã tạo vào cuối danh sách liên kết đơn
void Insert_node_tail(LIST *l, NODE *p)
{
    //Nếu danh sách đang rỗng
    if (l->pHead == NULL)
    {
        //Con trỏ đầu và con trỏ cuối đều trỏ đến node p (đầu tiên)
        l->pHead = l->pTail = p;
    }
    else
    {
        l->pTail->pNext = p; //Con trỏ của pTail trỏ đến node p
        l->pTail = p;    //Cập nhật lại con trỏ cuối pTail
    }
}

//Chèn node đã tạo vào đầu danh sách liên kết đơn
void Insert_node_head(LIST *l, NODE *p)
{
    //Nếu danh sách đang rỗng
    if (l->pHead == NULL)
    {
        //Con trỏ đầu và con trỏ cuối đều trỏ đến node p (đầu tiên)
        l->pHead = l->pTail = p;
    }
    else
    {
        p->pNext = l->pHead;    //Con trỏ của p trỏ đền node đầu tiên của danh sách
        l->pHead = p;   //Cập nhật lại con trỏ đầu pHead
    }
}

//Chèn node p đã tạo vào sau node q
void Insert_node(LIST *l, NODE *p, int locate)
{
    //Nếu danh sách rỗng
    if (l->pHead == NULL)
    {
        //Con trỏ đầu và con trỏ cuối đề trỏ đến node p (đầu tiên)
        l->pHead = l->pTail = p;
    }
    else
    {
        NODE *i = l->pHead; //Khởi tạo biến kiếm tra i
        while (i != NULL)   //i sai khi kết thúc danh sách
        {
            if (i->data == locate)
            {
                //Khởi tạo biến tạm chèn thay thế cho p
                //Fix chèn nhiều số giống nhau
                NODE *temp = Add_node(p->data);
                temp->pNext = i->pNext; //Cho con trỏ node tạm trỏ đến node sau i
                i->pNext = temp;    //Cho con trỏ node sau i trỏ đến node tạm
                i = i->pNext;   //Cho i tăn lên
                free(temp); //Giải phóng biến tạm
            }
            else
            {
                i = i->pNext;
            }
        }
    }
}

//Xóa node ở vị trí đầu của danh sách liên kết đơn
void Delete_node_head(LIST *l)
{
    //Nếu danh sách rỗng
    if (l->pHead == NULL)
    {
        //In ra thông báo
        printf("\nDelete failed. Empty list!\n");
    }
    else
    {
        //Nếu danh sách chỉ có 1 phần tử
        if (l->pHead->pNext == NULL)
        {
            l->pHead = NULL;    //Cho giá trị đầu = rỗng
            free(l->pHead); //Xóa luôn danh sách
            printf("\nList is empty!\n");   //Thông báo danh sách rỗng
        }
        else
        {
            //Cập nhật con trỏ pHead = node thứ 2
            l->pHead = l->pHead->pNext;
        }
    }
}

//Xóa node ở vị trí cuối của danh sách liên kết đơn
void Delete_node_tail(LIST *l)
{
    //Nếu danh sách rỗng
    if (l->pHead == NULL)
    {
        //In ra thông báo
        printf("\nDelete failed. Empty list!\n");
    }
    else
    {
        //Nếu danh sách chỉ có 1 phần tử
        if (l->pHead->pNext == NULL)
        {
            l->pHead = NULL;    //Cho giá trị đầu = rỗng
            free(l->pHead); //Xóa luôn danh sách
            printf("\nList is empty!\n");   //Thông báo danh sách rỗng
        }
        else
        {
            //Khởi tạo biến tạm để lưu giá trị trước của i
            NODE *temp;
            //Cho i chạy đến cuối danh sách
            for (NODE *i = l->pHead; i->pNext != NULL; i = i->pNext)
            {
                //Cho biến tạm = i
                temp = i;
            }
            l->pTail = temp;    //Cập nhật con trỏ pTail = biến tạm (giá trị trước của i)
            l->pTail->pNext = NULL; //Con trỏ của con trỏ pTail trỏ đến NULL => node cuối cùng của danh sách
        }
    }
}

//Xóa node bất kì ra khỏi danh sách liên kết
void Delete_node(LIST *l, NODE *p)
{
    //Nếu danh sách rỗng
    if (l->pHead == NULL)
    {
        //In ra thông báo
        printf("\nDelete failed. Empty list!\n");
    }
    else if ((l->pHead->pNext == NULL) && (l->pHead->data == p->data))
    {
        Delete_node_head(l);
    }
    else
    {
        //Khai báo biến chạy i kiểm tra toàn bộ danh sách liên kết
        NODE *i = l->pHead;
        while (i->pNext != NULL)
        {
            //Nếu giá trị đầu tiên = giá trị cần xóa
            if (l->pHead->data == p->data)
            {
                if (l->pHead->pNext == NULL)
                {
                    //Gọi hàm xóa giá trị đầu
                    Delete_node_head(l);
                    //Cập nhật laij vị trí đầu tiên cho i chạy kiểm tra tiếp
                    i = l->pHead;
                }
            }
            //Nếu giá trị cần xóa khác giá trị đầu
            else
            {
                //Khai báo biến tạm làm biến kiểm tra tạm thời
                NODE *temp = i->pNext;
                //Nếu giá trị của biến kiểm tra tạm thời = giá trị cần xóa
                if (temp->data == p->data)
                {
                    //Nếu biến kiểm tra tạm thời là giá trị cuối cùng của danh sách liên kết
                    if (temp->pNext == NULL)
                    {
                        //Gọi lại hàm xóa node cuối
                        Delete_node_tail(l);
                        break;  //Thoát khỏi vòng lặp
                    }
                    else
                    {
                        //Cho biến kiểm tra i trỏ đến vị trí sau biến tạm kiểm tra
                        i->pNext = temp->pNext;
                    }
                }
                else
                {
                    //Nếu giá trị của biến tạm thời != giá trị cần xóa
                    //Tăng i lên
                    i = i->pNext;
                }
            }
        }
    }
}

//Xuất danh sách liên kết đơn ra màn hình
void Output(LIST l)
{
    //Cho biến i chạy tư đầu danh sách tới cuối danh sách
    //Tức i bắt đầu từ pHead đến NULL
    for (NODE *i = l.pHead; i != NULL; i = i->pNext)
    {
        printf("%d ", i->data);
    }
}

int main()
{
    LIST *l;
    Create_list(l);
    int n;
    printf("Nhap so luong gia tri can them: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nNhap gia tri thu %d: ", i);
        int value;
        scanf("%d", &value);
        NODE *p = Add_node(value);
        Insert_node_tail(l, p);
    }
    printf("\nDanh sach vua nhap la: ");
    Output(*l);
    printf("\n");
    return 0;
}
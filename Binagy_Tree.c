// Cây tìm kiếm nhị phân gồm 1 nút gốc liên kết với nhiều nút con
// Mỗi nút gồm 1 nút gốc và 2 nút con, gồm con trái và con phải
// nút không có con nào được gọi là nút lá
// Giá trị thứ tự của các nút như sau:
// Nút con trái nhỏ hơn nút gốc
// Nút con phải lớn hơn nút gốc

#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc của 1 cái node
// Bao gồm nút gốc chứa dữ liệu và 2 nhánh của nút đó
struct node
{
    int data;
    struct node *Left_child; // Nhánh bên trái
    struct node *Right_child; // Nhánh bên phải
};
typedef struct node TREE;

// Hàm thêm node vào cây nhị phân
TREE *Insert_node(TREE *root, int value)
{
    // Nếu nút gốc đang xét = NULL (chưa có)
    if (root == NULL)
    {
        // Khởi tạo biến con trỏ leaf để chuẩn bị thêm vào cây
        TREE *leaf = (TREE*)malloc(sizeof(TREE));
        leaf->data = value; // Truyền dữ liệu vào cho con trỏ đó
        // Do nút này là nút lá nên có con trái và con phải = NULL 
        leaf->Left_child = leaf->Right_child = NULL;
        return leaf; // Trả về nút lá
    }
    // Nếu nút đang xét đã có giá trị
    else
    {
        if (value < root->data) // Nếu giá trị cần thêm mà nhỏ hơn nút gốc
        {
            // Gọi hàm đệ quy về hướng con trái của nút đang xét
            // Để kiểm tra xem nút đó đã có phần tử chưa
            // Nếu đã có phần tử thì tiếp tục đệ quy
            // Nếu chưa có phần tử, tức root == NULL
            // Thì thực hiện các lệnh trong vòng if (root == NULL)
            root->Left_child = Insert_node(root->Left_child, value);
        }
        else if (value > root->data) // Nếu giá trị cần thêm mà lớn hơn nút gốc
        {
            // Gọi hàm đệ quy về hướng con phải của nút đang xét
            // Để kiểm tra xem nút đó đã có phần tử chưa
            // Nếu đã có phần tử thì tiếp tục đệ quy
            // Nếu chưa có phần tử, tức root == NULL
            // Thì thực hiện các lệnh trong vòng if (root == NULL)
            root->Right_child = Insert_node(root->Right_child, value);
        }
    }
}

// NODE -> LEFT -> RIGHT
void OutPut(TREE *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        OutPut(root->Left_child);
        OutPut(root->Right_child);
        return;
    }
}

int main()
{
    // Khởi tạo biến con trỏ root để lưu tất cả giá trị của cây
    TREE *root;
    root = NULL; // Cây chưa có giá trị nên nút gốc sẽ bằng NULL
    printf("Nhap vao so luong phan tu cua cay: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nNhap vao phan tu thu %d: ", i);
        int value;
        scanf("%d", &value);
        if (i == 1)
        {
            // Nếu nhập giá trị cho node đầu tiên, tức root
            // cho root = Insert_node(root, value) để loại bỏ giá trị root = NULL
            root = Insert_node(root, value);
        }
        else
        {
            Insert_node(root, value);
        }
    }
    printf("\nCac phan tu cua cay la: ");
    OutPut(root);
    printf("\n");
    return 0;
}
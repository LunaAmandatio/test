#include <stdio.h>

#define MAX_SIZE 100  // 数组最大容量
#define INIT_COUNT 5   // 初始有效数据个数

// 全局变量：记录当前有效数据个数（需在insert/pop中更新）
int valid_count = INIT_COUNT;

// 插入函数：在pos位置（1-based）插入num，返回0成功，-1失败
int insert(int a[], int pos, int num) {
    // 边界检查：pos范围[1, valid_count+1]，且数组未满
    if (pos < 1 || pos > valid_count + 1 || valid_count >= MAX_SIZE) {
        printf("插入失败：位置超出有效范围或数组已满！\n");
        return -1;
    }
    // 将pos位置及之后的元素后移一位（从后往前移）
    for (int i = valid_count; i >= pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos - 1] = num;  // pos是1-based，数组下标需-1
    valid_count++;     // 有效数据个数+1
    printf("插入成功！当前有效数据个数：%d\n", valid_count);
    return 0;
}

// 删除函数：删除pos位置（1-based）的元素，返回被删除值，-1表示失败
int pop(int a[], int pos) {
    // 边界检查：pos范围[1, valid_count]，且有效数据不为空
    if (pos < 1 || pos > valid_count || valid_count <= 0) {
        printf("删除失败：位置超出有效范围或无数据可删！\n");
        return -1;
    }
    int deleted = a[pos - 1];  // 记录被删除值
    // 将pos之后的元素前移一位（从前往后移）
    for (int i = pos; i < valid_count; i++) {
        a[i - 1] = a[i];
    }
    valid_count--;  // 有效数据个数-1
    printf("删除成功！被删除值：%d，当前有效数据个数：%d\n", deleted, valid_count);
    return deleted;
}

// 打印数组前valid_count个有效元素
void print_array(int a[]) {
    printf("当前有效数据：");
    for (int i = 0; i < valid_count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[MAX_SIZE];  // 定义大小为100的数组
    // 输入前5个有效数据
    printf("请输入前5个整数（空格分隔）：");
    for (int i = 0; i < INIT_COUNT; i++) {
        scanf("%d", &a[i]);
    }
    printf("初始有效数据个数：%d\n", valid_count);
    print_array(a);

    // 示例：插入测试（在第2个位置插入300）
    insert(a, 2, 300);
    print_array(a);  // 输出：1 300 2 3 4 5

    // 示例：删除测试（删除第2个位置的元素）
    pop(a, 2);
    print_array(a);  // 输出：1 2 3 4 5

    // 边界测试：插入超出范围位置
    insert(a, 10, 999);  // 有效数据仅5个，pos=10超出范围

    return 0;
}

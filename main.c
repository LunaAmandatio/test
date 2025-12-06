#include <stdio.h>
#define N 4

int main() {
    int a[N], b[2*N];
    int i, j, k;

    // 1. 输入数组a和b
    printf("输入数组a（%d个整数）：\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    printf("输入数组b（%d个整数）：\n", 2*N);
    for (i = 0; i < 2*N; i++) {
        scanf("%d", &b[i]);
    }


    // 2. 判断b是否包含a的连续子数组
    int has_continuous = 0;  // 0：不包含，1：包含
    // 遍历b中所有可能的连续N个元素起点（共2N - N + 1 = N+1种可能）
    for (i = 0; i <= 2*N - N; i++) {
        int match = 1;  // 假设当前子数组匹配a
        for (j = 0; j < N; j++) {
            if (b[i + j] != a[j]) {  // 若有一个元素不匹配，标记为不匹配
                match = 0;
                break;
            }
        }
        if (match == 1) {  // 找到连续匹配的子数组
            has_continuous = 1;
            break;
        }
    }


    // 3. 判断b是否包含a中的每一个整数（不要求连续）
    int has_all = 1;  // 0：不包含所有，1：包含所有
    for (i = 0; i < N; i++) {
        int found = 0;  // 0：a[i]不在b中，1：在b中
        for (j = 0; j < 2*N; j++) {
            if (b[j] == a[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {  // a中存在b没有的元素
            has_all = 0;
            break;
        }
    }


    // 4. 输出a中b所没有的数
    printf("\na中b没有的数：");
    int missing_count = 0;
    for (i = 0; i < N; i++) {
        int found = 0;
        for (j = 0; j < 2*N; j++) {
            if (b[j] == a[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("%d ", a[i]);
            missing_count++;
        }
    }
    if (missing_count == 0) {
        printf("无");
    }


    // 5. 输出判断结果
    printf("\n\nb是否包含a的连续子数组：%s\n", has_continuous ? "是" : "否");
    printf("b是否包含a的所有整数：%s\n", has_all ? "是" : "否");

    return 0;
}

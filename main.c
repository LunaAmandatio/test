#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random();
int main() {
    int M,N;
    printf("输入行数\n");
    fflush(stdout);
    scanf("%d",&M);
    printf("输入列数\n");
    fflush(stdout);
    scanf("%d",&N);

    int arr[M][N];
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=random();
        }
    }

    printf("矩阵的值");
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            //数在四个角上
            if((i ==0&&j==0)||(i==N-1&&j==N-1)||(i==0&&j==N-1)||(j==0&&i==N-1)) {
                if(arr[i][j]>arr[i][j+1] && arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i+1][j+1]) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                }
            }
            //数在0行，且列不等于0/N
            if ( (i==0&&j!=0) && ( i==0&&j!= N-1) ){
                if ((arr[i][j]>arr[i][j-1]) && (arr[i][j]>arr[i][j+1]) &&(arr[i][j]>arr[i+1][j-1])&&
                    (arr[i][j]>arr[i+1][j]) && (arr[i][j]>arr[i+1][j+1]) ) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                }
            }
            //数在N行，且列不等于0/N
            if ( (i==N-1&&j!=0) && ( i==N-1&&j!= N-1) ){
                if ((arr[i][j]>arr[i][j-1]) && (arr[i][j]>arr[i][j+1]) &&(arr[i][j]>arr[i-1][j-1])&&
                    (arr[i][j]>arr[i-1][j]) && (arr[i][j]>arr[i-1][j+1]) ) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                    }
            }
            //数在0列，且行不等于0/N
            if ( (i!=0&&j==0) && ( i!=N-1&&j==0) ){
                if ((arr[i][j]>arr[i-1][j]) && (arr[i][j]>arr[i+1][j]) &&(arr[i][j]>arr[i-1][j+1])&&
                    (arr[i][j]>arr[i][j+1]) && (arr[i][j]>arr[i+1][j+1]) ) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                    }
            }
            //数在N列，且行不等于0/N
            if ( (i!=0&&j==N-1) && ( i!=N-1&&j==N-1) ){
                if ((arr[i][j]>arr[i-1][j]) && (arr[i][j]>arr[i+1][j]) &&(arr[i][j]>arr[i-1][j-1])&&
                    (arr[i][j]>arr[i][j-1]) && (arr[i][j]>arr[i+1][j-1]) ) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                    }
            }
            //数在中间
            else {
                if ((arr[i][j]>arr[i-1][j-1]) && (arr[i][j]>arr[i-1][j]) &&(arr[i][j]>arr[i-1][j+1])&&
                    (arr[i][j]>arr[i][j-1]) && (arr[i][j]>arr[i][j+1])&&
                    (arr[i][j]>arr[i+1][j-1]) && (arr[i][j]>arr[i+1][j]) &&(arr[i][j]>arr[i+1][j+1])) {
                    printf("矩阵的局部极大值：%d,行数：%d,列数：%d",arr[i][j],i,j);
                   }
            }
        }
    }
}


int random() {
    int num = rand() % 51 + 13; // 生成13~63之间的随机数
    return num;
}

#include <stdlib.h>
#include <stdio.h>
#define N 4
void selection_sort(int arr[], int len);
void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[N][N]={1,1,2,2,2,3,3,3,4,5,6,7,23,4,24,24};
    int B[N][N]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int temp_A[N*N]={0};
    int temp_B[N*N]={0};

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp_A[i*N+j]=A[i][j];
            temp_B[i*N+j]=B[i][j];
        }
    }

    selection_sort(temp_A,N*N);
    selection_sort(temp_B,N*N);

    int num[N*N] = {temp_A[0]};
    int F[N*N] = {1};
    int count=0;
    for (int i = 0; i < N*N - 1; i++) {
        if (temp_A[i+1] == temp_A[i]) {
            F[count]++; // 相同数字，频率增加
        }
        else {
            count++; // 新数字出现
            num[count] = temp_A[i+1];
            F[count] = 1; // 初始化频率为1
        }
    }
    double N1;
    double N2 = count+1;
    for(int i=0;i<N*N;i++) {
        if (temp_A[i] == temp_B[i]&&temp_A[i]!=0) {
            N1++;
        }
    }
    double sim = N1/N2;
    printf("相似度:%f\n",sim);
}


void selection_sort(int arr[], int len)
{
    int i,j;

    for (i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}
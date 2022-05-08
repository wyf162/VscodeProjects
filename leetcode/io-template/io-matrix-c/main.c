#include <stdio.h>

const int MAX = 50;

int main(){
    int a[MAX][MAX];
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    printf("m: %d, n: %d\n", m, n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
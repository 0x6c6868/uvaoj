#include<stdio.h>

int main(void){

        int T;
        scanf("%d", &T);
        while(T--){
                int rst[]={0,0,0,0,0,0,0,0,0,0};

                int n;
                scanf("%d", &n);

                while(n>0){
                        int a=n;
                        while(a>0){ rst[a%10]++; a/=10; }
                        n--;
                }

                int i=0;
                while(i<9){
                        printf("%d ", rst[i]);
                        i++;
                }
                printf("%d", rst[9]);
                putchar('\n');
        }

        return 0;
}

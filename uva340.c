#include<stdio.h>

#define maxn 1010

int main(void){
        int n;
        int a[maxn], b[maxn];

        int kase=0;
        while(scanf("%d", &n) == 1 && n){
                printf("Game %d:\n", ++kase);

                int i;
                for(i=0;i<n;i++) scanf("%d", &a[i]);

                for(;;){
                        int A=0, B=0;

                        for(i=0;i<n;i++) {
                                scanf("%d", &b[i]);
                                if(a[i]==b[i]) A++;
                        }

                        if(b[0]==0) break;

                        int d;
                        for(d=0;d<=9;d++){
                                int c1=0, c2=0;
                                for(i=0; i<n; i++){
                                        if(a[i]==d) c1++;
                                        if(b[i]==d) c2++;
                                }
                                B += c1<c2 ? c1 : c2;
                        }
                        printf("    (%d,%d)\n", A, B-A);

                }

        }

        return 0;
}

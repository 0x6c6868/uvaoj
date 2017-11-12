#include<stdio.h>

#define bool int
#define true 1
#define false 0

bool solve(int *W){
        int W1, D1, W2, D2;
        bool b1=true, b2=true;
        scanf("%d%d%d%d", &W1, &D1, &W2, &D2);
        if(!W1) b1=solve(&W1);
        if(!W2) b2=solve(&W2);
        *W=W1+W2;
        return b1 && b2 && (W1*D1 == W2*D2);
}

int main(void){

        int n, W;
        scanf("%d", &n);
        while(n--){
                if(solve(&W)) printf("YES\n");
                else printf("NO\n");
                if(n) putchar('\n');
        }
        return 0;
}

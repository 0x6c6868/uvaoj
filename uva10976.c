#include<stdio.h>

int main(void){

        int k;
        while(scanf("%d", &k)==1 && k){
                int c=0;
                for(int y=k+1;y<=2*k;y++){
                        int x=(y*k)/(y-k);
                        if(x && x*(y-k)==(y*k))
                                c++;
                }
                printf("%d\n", c);
                for(int y=k+1;y<=2*k;y++){
                        int x=(y*k)/(y-k);
                        if(x && x*(y-k)==(y*k))
                                printf("1/%d = 1/%d + 1/%d\n", k, x, y);
                }
        }
        return 0;
}

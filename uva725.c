#include<stdio.h>

#define bool int
#define true 1
#define false 0


bool judge(int a, int f){
        int flag[10]={0,0,0,0,0,0,0,0,0,0};

        if(a<10000) flag[0]++;
        if(f<10000) flag[0]++;

        for(int i=a%10;a>0;i=(a/=10)%10)
                flag[i]++;
        for(int i=f%10;f>0;i=(f/=10)%10)
                flag[i]++;

        for(int i=0;i<10;i++)
                if(flag[i]!=1)
                        return false;
        return true;
}

int main(void) {

        int n;
        bool first=true;
        while(scanf("%d", &n)==1 && n){
                if(first)
                        first=false;
                else
                        printf("\n");
                bool no_solutions=true;
                for(int f=1234; f<98765; f++){
                        int a = f*n;
                        if(a>98765)
                                continue;
                        if(judge(a, f)){
                                printf("%05d / %05d = %d\n", a, f, n);
                                no_solutions = false;
                        }
                }
                if(no_solutions) printf("There are no solutions for %d.\n", n);
        }
        return 0;
}

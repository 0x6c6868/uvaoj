#include<stdio.h>
#include<string.h>

#define maxn 100

char s[maxn];

int main(void){

        int T=0;
        scanf("%d", &T);
        while(T--){
                scanf("%s", s);
                int len = strlen(s);
                int i;
                int sum=0, tmp=1;
                for(i=0; i<len; i++){
                        if(s[i] == 'O'){
                                sum += tmp;
                                tmp++;
                        } else {
                                tmp=1;
                        }
                }
                printf("%d\n", sum);
        }

        return 0;
}

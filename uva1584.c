#include<stdio.h>
#include<string.h>

#define maxn 105

int less(const char* s, int p, int q){
        int i;
        int len = strlen(s);
        for(i=0;i<len;i++)
                if(s[(p+i)%len] != s[(q+i)%len])
                        return s[(p+i)%len] > s[(q+i)%len];
        return 0;
}

int main(void){

        int T;
        char s[maxn];
        scanf("%d", &T);

        while(T--){
                scanf("%s", s);
                int ans=0;
                int len=strlen(s);
                int i;
                for(i=0;i<len;i++)
                        if(less(s, ans, i)) ans=i;

                for(i=0;i<len;i++)
                        putchar(s[(ans+i)%len]);

                putchar('\n');
        }

        return 0;
}

#include<stdio.h>
#include<string.h>

#define maxn 16

int isp[maxn*2+10];
int A[maxn+10];
int vis[maxn+10];

void dfs(int cur, int n){
        if(cur==n && isp[A[0]+A[n-1]]){
                for(int i=0;i<n-1;i++) printf("%d ", A[i]);
                printf("%d", A[n-1]);
                putchar('\n');
        } else for(int i=2;i<=n;i++){
                if(!vis[i] && isp[i+A[cur-1]]){
                        A[cur]=i;
                        vis[i]=1;
                        dfs(cur+1, n);
                        vis[i]=0;
                }
        }
}

int is_prime(int n){
        for(int i=2;i*i<=n;i++){
                if(!(n%i)) return 0;
        }
        return 1;
}

int main(void){

        for(int i=0;i<(2*maxn+10);i++) isp[i]=is_prime(i);

        int n;
        int kase=1;
        while(scanf("%d", &n)==1 && n){
                if(kase!=1) putchar('\n');
                printf("Case %d:\n", kase++);

                memset(vis, 0, sizeof(vis));
                memset(A, 0, sizeof(A));
                A[0]=1;

                dfs(1, n);
        }
        return 0;
}

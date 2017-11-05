#include<stdio.h>
#include<stdlib.h>

#define maxn 10000

int cmp(const void *a, const void *b){
        return *(int *)a - *(int *)b;
}

int main(){
	int n, q, x, a[maxn], kase=0;
	while(scanf("%d%d", &n, &q) == 2 && n){
		printf("CASE# %d:\n", ++kase);
		for(int i=0;i<n;i++) scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		while(q--){
			scanf("%d", &x);
			void *tmp = bsearch(&x, a, n, sizeof(int), cmp);
			if(tmp==NULL)
				printf("%d not found\n", x);
			else{
				int pos = (int *)tmp-a;  
                int j = pos;  
                while(a[j] == a[pos] && j >= 0) --j;
				printf("%d found at %d\n", x, j+2);
			}
		}
	}
    return 0;
}

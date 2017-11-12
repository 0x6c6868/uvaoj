#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const int MAXN = 1000 + 10;

typedef struct {
        int a, b;
} Matrix;
Matrix *m[26];

Matrix *stack[MAXN];
int s_top=0;

void new_stack(){
        s_top=0;
}

int stack_empty(){
        return s_top == 0;
}

Matrix *stack_top(){
        return stack[s_top-1];
}

void stack_pop(){
        s_top--;
}

void stack_push(Matrix *v){
        stack[s_top] = v;
        s_top++;
}

int main(void){

        // 初始化m
        for(int i=0; i<26; i++){
                Matrix *t=(Matrix *)malloc(sizeof(Matrix));
                m[i]=t;
        }

        int n;
        while(scanf("%d", &n)==1 && n){
                for(int i=0; i<n; i++){
                        getchar();  // 跳过空格
                        char name;
                        scanf("%c", &name);
                        int k = name - 'A';
                        scanf("%d%d", &(m[k]->a), &(m[k]->b));
                }

                char expr[MAXN];
                while(scanf("%s", expr)==1){
                        int len = strlen(expr);
                        int error=0, ans=0;
                        new_stack();
                        for(int i=0; i<len; i++){
                                if(isalpha(expr[i])) stack_push(m[expr[i]-'A']);
                                else if(expr[i] == ')'){
                                        Matrix *m2 = stack_top(); stack_pop();
                                        Matrix *m1 = stack_top(); stack_pop();

                                        if(m1->b != m2->a) {error = 1; break;}
                                        ans += m1->a*m1->b*m2->b;

                                        Matrix *t=(Matrix *)malloc(sizeof(Matrix));
                                        t->a=m1->a;
                                        t->b=m2->b;
                                        stack_push(t);
                                }
                        }
                        if(error) printf("error\n");
                        else printf("%d\n", ans);
                }
        }
        return 0;
}

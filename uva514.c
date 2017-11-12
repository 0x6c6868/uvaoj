#include<stdio.h>

const int MAXN = 1000 + 10;

int n, target[MAXN];

int stack[MAXN];
int s_top=0;

void new_stack(){
        s_top=0;
}

int stack_empty(){
        return s_top == 0;
}

int stack_top(){
        return stack[s_top-1];
}

void stack_pop(){
        s_top--;
}

void stack_push(int v){
        stack[s_top] = v;
        s_top++;
}

int main(void){

        while(scanf("%d", &n) == 1){
                if(!n) break;

                while(scanf("%d", &target[0]) && target[0]){
                        for(int i=1;i<n;i++)
                                scanf("%d", &target[i]);

                        int A=1, B=0, ok=1;
                        new_stack();
                        while(B<n){
                                if(A==target[B]) {A++; B++;}
                                else if(!stack_empty() && stack_top()==target[B]) {stack_pop(); B++;}
                                else if(A <= n) stack_push(A++);
                                else {ok =0; break;}
                        }
                        printf("%s\n", ok ? "Yes": "No");

                }
                putchar('\n');
        }
        return 0;
}

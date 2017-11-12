#include<stdio.h>
#include<stdlib.h>

#define MAXN 100000 + 10

typedef struct _node {
        struct _node *left;
        struct _node *right;
        int v;
} Node;

Node *first;
Node *last;

#define append(n) \
        n->right=last;\
        n->left=last->left;\
        n->left->right=n;\
        last->left=n;

void move_left(Node *x, Node *y){
        x->left->right=x->right;
        x->right->left=x->left;

        x->right=y;
        x->left=y->left;

        y->left->right=x;
        y->left=x;
}

void move_right(Node *x, Node *y){
        x->left->right=x->right;
        x->right->left=x->left;

        x->left=y;
        x->right=y->right;

        y->right->left=x;
        y->right=x;
}

void exchange(Node *x, Node *y){
        x->left->right=y;
        x->right->left=y;

        y->left->right=x;
        y->right->left=x;

        Node *t1=x->left;
        Node *t2=x->right;

        x->left=y->left;
        x->right=y->right;

        y->left=t1;
        y->right=t2;
}

Node *nodes[MAXN];  // speed up func find_node
Node *find_node(int v){
        return nodes[v];
}

long long int count(int inv){
        int t=1;
        long long int rst=0;
        if(inv){
                for(Node *cur=first->right; cur!=last; cur=cur->right){
                        if(t%2==1){
                                rst+=cur->v;
                        }
                        t++;
                }
        }else{
                for(Node *cur=last->left; cur!=first; cur=cur->left){
                        if(t%2==1){
                                rst+=cur->v;
                        }
                        t++;
                }
        }
        return rst;
}

int main(void){

        int n, m, kase=0;

        first = (Node *)malloc(sizeof(Node));
        last = (Node *)malloc(sizeof(Node));
        Node *t=(Node *)malloc(sizeof(Node)*MAXN);

        while(scanf("%d%d", &n, &m)==2){
                first->left = last;
                first->right = last;
                last->left = first;
                last->right = first;

                for(int i=1; i<=n; i++){
                        t->v=i;
                        append(t);
                        nodes[i] = t;
                        t++;
                }

                int inv = 1;
                while(m--){
                        int op;
                        scanf("%d", &op);
                        if(op==4) inv=!inv;
                        else{
                                int X, Y;
                                scanf("%d%d", &X, &Y);
                                Node *xNode = find_node(X);
                                Node *yNode = find_node(Y);
                                switch(op){
                                        case 1:
                                        inv?move_left(xNode, yNode):move_right(xNode, yNode);
                                        break;
                                        case 2:
                                        inv?move_right(xNode, yNode):move_left(xNode, yNode);
                                        break;
                                        case 3:
                                        exchange(xNode, yNode);
                                        break;
                                }
                        }
                }
                printf("Case %d: %lld\n", ++kase, count(inv));
                t-=n;  // reset memery
        }
        return 0;
}

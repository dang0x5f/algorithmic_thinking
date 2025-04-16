#include <stdio.h>
#include <stdlib.h>

#define SIZE 255

typedef struct node {
    int candy;
    struct node *left, *right;
} node;

typedef struct stack {
    node * values[SIZE];
    int highest_used;
} stack;

node* new_house(int);
node* new_nonhouse(node *, node *);
stack* new_stack(void);
void push_stack(stack *, node *);
node* pop_stack(stack *);
int is_stack_empty(stack *);

int
main(void)
{
    stack *s;
    s = new_stack();
    node *n, *n1, *n2, *n3;
    n1 = new_house(20);
    n2 = new_house(30);
    n3 = new_house(10);
    push_stack(s, n1);
    push_stack(s, n2);
    push_stack(s, n3);
    while(!is_stack_empty(s)){
        n = pop_stack(s);
        printf("%d\n", n->candy);
    }
    return(0);
}

node* 
new_house(int candy)
{
    node *house = malloc(sizeof(node));
    if(house == NULL){
        fprintf(stderr, "malloc err\n");
        exit(1);
    }
    house->candy = candy;
    house->left = NULL;
    house->right = NULL;
    return(house);
}

node* 
new_nonhouse(node *left, node *right)
{
    node *nonhouse = malloc(sizeof(node));
    if(nonhouse == NULL){
        fprintf(stderr, "malloc err\n");
        exit(1);
    }
    nonhouse->left = left;
    nonhouse->right = right;
    return(nonhouse);
}

stack* 
new_stack(void)
{
    stack *s = malloc(sizeof(stack));
    if(s == NULL){
        fprintf(stderr, "malloc err\n");
        exit(1);
    }
    s->highest_used = -1;
    return(s);
}

void
push_stack(stack *s, node *value)
{
    s->highest_used++;
    s->values[s->highest_used] = value;
}

node*
pop_stack(stack *s)
{
    node *ret = s->values[s->highest_used];
    s->highest_used--;
    return(ret);
}

int 
is_stack_empty(stack *s)
{
    return(s->highest_used == -1);
}

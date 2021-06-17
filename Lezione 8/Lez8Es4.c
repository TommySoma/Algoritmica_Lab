#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    int key;
    struct node *left;
    struct node *right;
}
t_node;

void swap(int *a, int *b)
{
  int tmp = *a;

  *a = *b;
  *b = tmp;
}

void create_singly_list(t_node** l, int el)
{
    t_node* ult, *new_elem;

    new_elem = malloc(sizeof(t_node));

    new_elem->info = el;
    new_elem->right = NULL;
    
    if(*l == NULL)
        *l = new_elem;

    else
    {
        ult = *l;

        while (ult->right != NULL)
            ult = ult->right;
    
        ult->right = new_elem;
    }
}

void create_list(t_node** l, int el)
{
    t_node* ult, *new_elem;

    new_elem = malloc(sizeof(t_node));
    new_elem->info = el;
    new_elem->key = 0;

    
    if(*l == NULL)
    {
        new_elem->left = NULL;
        new_elem->right = NULL;
        *l = new_elem;
    }   

    else
    {
        ult = *l;

        while (ult->right != NULL)
            ult = ult->right;
        
        new_elem->left = ult;
        new_elem->right = NULL;
        ult->right = new_elem;
    }
}

int countnsort(t_node **l, int key)
{
    int pos = 0,
        stop = 0;

    if(*l != NULL)
    {
        t_node *aux = *l;

        while(aux != NULL && !stop)
        
            if(aux->info == key)
            {
                aux->key++;
                stop = 1;
            }
            else
            {
                aux = aux->right;
                pos++;
            }
        

        if(!stop) return -1;

        t_node *tmp = aux;

        while(tmp->left != NULL && tmp->key > tmp->left->key)
        {
            swap(&tmp->key, &tmp->left->key);
            swap(&tmp->info, &tmp->left->info);
            tmp = tmp->left;
        }
    }
    
    return pos;
}

int main()
{
    t_node *node = NULL,
           *out = NULL;
    int n, i, m, 
        pos = 0, 
        stop = 0;

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {   
        scanf("%d", &m);
        create_list(&node, m);
    }

    while(!stop)
    {
        scanf("%d", &n); 
        
        pos = countnsort(&node, n);
        create_singly_list(&out, pos);

        if(pos == -1)
            stop = 1;  
    }

    //print list
    while(out != NULL)
    {
        printf("%d\n", out->info);
        out = out->right;
    }

    return 0;
}

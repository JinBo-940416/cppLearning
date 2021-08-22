#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * prev;
    struct node * next;
    struct list * containing_list;
};

struct list {
    struct node * start;
    struct node * end;
};

struct list * initialize_list();
void destory_list(struct list *);
/* 1 successful, 0 fail */
int add_head(struct node *, struct list *);
int add_value_to_head(int i, struct list *);
int remove_head(struct list *);
// int add_tail(struct node *, struct list *);
// int remove_tail();

int list_size(struct list *);
void print_list(struct list *);

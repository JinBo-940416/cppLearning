#ifndef _linkedlist_h_file
#define _linkedlist_h_file
#include "linkedlist.h"
#endif

struct list * initialize_list(){

    struct list *result_list = (struct list *)malloc(sizeof(struct list));
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tail = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->next = tail;
    head->containing_list = result_list;

    tail->next = NULL;
    tail->prev = head;
    tail->containing_list = result_list;

    result_list->start = head;
    result_list->end = tail;
    return result_list;
}

void destory_list(struct list * freed_list) {
    free(freed_list->start);
    free(freed_list->end);
    free(freed_list);
}

int list_size(struct list * input_list) {
    int i = 0;
    struct node * current = input_list->start->next;

    while(current->next != NULL) {
        i++;
        current = current->next;
    }
    return i;
}

int __add_head(struct node * added_node, struct list * added_list) {

    added_node->containing_list = added_list;

    struct node * first_node = added_list->start;
    struct node * second_node = first_node->next;

    first_node->next = added_node;
    added_node->next = second_node;

    added_node->prev = first_node;
    second_node->prev = added_node;

    return 1;
}

int add_value_to_head(int input, struct list * added_list) {
    struct node * added_node = (struct node *)malloc(sizeof(struct node));
    added_node->value = input;
    __add_head(added_node, added_list);
    return 1;
}

int remove_head(struct list * input_list) {
    if (list_size(input_list) == 0) {
        printf("input list is already empty, abort remove head \n");
        return 0;
    }

    struct node * old_head = input_list->start->next;
    struct node * new_head = old_head->next;

    input_list->start->next = new_head;
    new_head->prev = input_list->start;

    free(old_head);

    return 1;
}

void print_list(struct list * input_list) {
    printf("[");
    struct node *current = input_list->start->next;
    while (current->next!= NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
    return;
}

int main(){
    struct list * my_list = initialize_list();
    int i = 20;
    while (i > 0) {
        add_value_to_head(i--, my_list);
        printf("current length of my_list: %d \n", list_size(my_list));
        print_list(my_list);
    }
    while (list_size(my_list) != 0) {
        remove_head(my_list);
        printf("current length of my_list: %d \n", list_size(my_list));
        print_list(my_list);
    }

    return 0;
}
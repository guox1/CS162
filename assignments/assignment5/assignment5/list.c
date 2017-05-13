//
//  list.c
//  assignment5
//
//  Created by Jacky on 6/3/15.
//  Copyright (c) 2015 assignment5. All rights reserved.
//

#include "list.h"

/*********************************************************************
 ** Function: length
 ** Description: geting the num of the number user input
 ** Parameters: struct node *p
 ** Pre-Conditions:
 ** Post-Conditions: j != NULL
 *********************************************************************/
int length(struct node *p){
    struct node * j = NULL;
    int i;
    j = p;
    for (i = 0; j != NULL;){
        j = j->next;
        i = i + 1;
    }
    return i;
}

/*********************************************************************
 ** Function: push
 ** Description: get all the num in front order
 ** Parameters: struct node *head, int num
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
struct node * push(struct node *head, int num){
    struct node * p = NULL;
    if(head != NULL){
        p = head;
    }
    head = (struct node *)malloc(sizeof(struct node));
    
    head->val = num;
    head->next = p;
                                 
    return head;
}

/*********************************************************************
 ** Function: append
 ** Description: get all the num in tail order
 ** Parameters: struct node **head, int num
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void append(struct node **head, int num){
    struct node* temp = malloc(sizeof(struct node));
    struct node* temp2 = malloc(sizeof(struct node));
    temp = *head;
    if(temp == NULL){
        struct node* temp = malloc(sizeof(struct node));
        temp->val = num;
        temp->next = NULL;
        *head = temp;
        return;
    }
    temp2 = *head;
    while(temp->next!=NULL){
        *head = temp;
        temp = temp->next;
    }
    temp->next = malloc(sizeof(struct node));
    temp = temp->next;
    temp->val = num;
    temp->next = NULL;
    *head = temp2;
}

/*********************************************************************
 ** Function: cleared
 ** Description: free the memory of nArray, set to NULL
 ** Parameters: struct node *head
 ** Pre-Conditions:
 ** Post-Conditions: head == NULL
 *********************************************************************/
struct node * cleared(struct node *head){
    while(1){
        if(head == NULL)
            break;
        free(head);
        head = head->next;
    }
    return head;
}

/*********************************************************************
 ** Function: removed
 ** Description: removing a specific num from the list
 ** Parameters: struct node *head, int num
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
struct node * removed(struct node *head, int num){
    int i;
    struct node * p = NULL;
    struct node * temp = NULL;
    p = head;
    for (i = 0; p != NULL;){
        if(i + 1 == num){
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            break;
        }
        p = p->next;
        i = i + 1;
    }
    return head;
}

/*********************************************************************
 ** Function: sort_ascending
 ** Description: seting all the num from small to large in order
 ** Parameters: struct node *head
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
struct node * sort_ascending(struct node * head){
    int *nArry;
    int temp, l, i, m;
    struct node * p = NULL;
    
    p = head;
    
    l = length(head);
    nArry = (int *)malloc(sizeof(int)*l);
    
    for (i = 0; i < l; i++){
        nArry[i] = p->val;
        p = p->next;
    }
    
    for (m = 0; m < l - 1; m++){
        for (i = 0; i < l - 1; i++){
            if(nArry[i] > nArry[i+1]){
                temp = nArry[i];
                nArry[i] = nArry[i+1];
                nArry[i+1] = temp;
            }
        }
    }
    p = head;
    for (i = 0; i < l; i++){
        p->val = nArry[i];
        p = p->next;
    }
    return head;
}

/*********************************************************************
 ** Function: sort_descending
 ** Description: seting all the num from large to small in order
 ** Parameters: struct node *head
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
struct node * sort_descending(struct node *head){
    int *nArry;
    int temp, l, i, m;
    struct node * p = NULL;
    
    p = head;
    
    l = length(head);
    nArry = (int *)malloc(sizeof(int)*l);
    
    for (i = 0; i < l; i++){
        nArry[i] = p->val;
        p = p->next;
    }
    
    for (m = 0; m < l - 1; m++){
        for (i = 0; i < l - 1; i++){
            if(nArry[i] < nArry[i+1]){
                temp = nArry[i];
                nArry[i] = nArry[i+1];
                nArry[i+1] = temp;
            }
        }
    }
    p = head;
    for (i = 0; i < l; i++){
        p->val = nArry[i];
        p = p->next;
    }
    return head;

}

/*********************************************************************
 ** Function: insert_middle
 ** Description: inserting a specific num to a specific place
 ** Parameters: struct node *head, int num1, int num2
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
struct node * insert_middle(struct node *head, int num1, int num2){
    int i;
    struct node * p = NULL;
    struct node * j = NULL;
    p = head;
    j = (struct node *)malloc(sizeof(struct node));
    j->val = num2;
    
    if(num1 == 1){
        j->next = head;
        p = j;
        return p;
    }
    
    for(i = 0; p != NULL;){
        if(i + 2 == num1){
            j->next = p->next;
            p->next = j;
            break;
        }
        p = p->next;
        i = i + 1;
    }
    return head;
}

/*********************************************************************
 ** Function: print
 ** Description: print out all the num base on the order user has chosen
 ** Parameters: struct node *head, int length
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void print(struct node *head, int length){
    int i;
    for(i=1;i <= length;){
        printf("%d ", head->val);
        head = head->next;
        i = i + 1;
    }
}

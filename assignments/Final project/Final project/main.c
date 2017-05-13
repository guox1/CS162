//
//  main.c
//  Final project
//
//  Created by Jacky on 6/8/15.
//  Copyright (c) 2015 Final project. All rights reserved.
//

#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

struct node * append(struct node * tail, int num_Now)
{
    if (tail == NULL)
    {
        tail = (struct node *)malloc(sizeof(struct node));
        tail->info = num_Now;
        tail->next = NULL;
        return tail;
    }
    else
    {
        tail->next = (struct node *)malloc(sizeof(struct node));
        tail->next->info = num_Now;
        tail->next->next = NULL;
        tail = tail->next;
        return tail;
    }
}

int length(struct node * head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

void print(struct node * head, int nodeNumbers)
{
    printf("The merge sorted list is: \n");
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}


int main (  )
{
    int num1, num2;
    int i, j = 1;
    
    struct node *head = NULL;
    struct node *tail = NULL;
    
    printf("How many numbers do you want to Enter? ");
    scanf("%d", &num2);
    
    for(i = 1; i <= num2; i++){
        printf("Enter the number%d: ", i);
        scanf("%d", &num1);
        tail = append(tail, num1);
        if (j == 1)
        {
            j = 0;
            head = tail;
        }

    }
    
    mergeSort(&head, &tail);
    print(head, length(head));

    return 0;
}

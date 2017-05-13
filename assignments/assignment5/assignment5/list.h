//
//  list.h
//  assignment5
//
//  Created by Jacky on 6/3/15.
//  Copyright (c) 2015 assignment5. All rights reserved.
//

#ifndef __assignment5__list__
#define __assignment5__list__

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
//Implemented in Lab #9, but now return new head address
int length(struct node *);
void print(struct node *, int);
struct node * push(struct node *, int); //put at front
void append(struct node **, int); //put at back

struct node * cleared(struct node *);
struct node * removed(struct node *, int);
struct node * sort_ascending(struct node *);
struct node * sort_descending(struct node *);
//insert into a specific location in the list
struct node * insert_middle(struct node *, int, int);

#endif /* defined(__assignment5__list__) */

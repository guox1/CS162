//
//  merge.h
//  Final project
//
//  Created by Jacky on 6/8/15.
//  Copyright (c) 2015 Final project. All rights reserved.
//

#ifndef __Final_project__merge__
#define __Final_project__merge__

#include <stdio.h>

struct node {
    int info;
    struct node *next;
};
void divideList(struct node *,struct node **);
struct node * mergeList(struct node *,struct node *);
void recMergeSort(struct node **);
void mergeSort(struct node **, struct node **);


#endif /* defined(__Final_project__merge__) */

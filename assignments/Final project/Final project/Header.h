//
//  Header.h
//  Final project
//
//  Created by Jacky on 6/10/15.
//  Copyright (c) 2015 Final project. All rights reserved.
//

#ifndef Final_project_Header_h
#define Final_project_Header_h

struct node {
    int info;
    struct node *next;
};
void divideList(struct node *,struct node **);
struct node * mergeList(struct node *,struct node *);
void recMergeSort(struct node **);
void mergeSort(struct node **, struct node **);

#endif

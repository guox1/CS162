//
//  main.c
//  assignment5
//
//  Created by Jacky on 6/1/15.
//  Copyright (c) 2015 assignment5. All rights reserved.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main (){
    char ans[2];
    int num;
    struct node *head = NULL;
    do {
        do {
            printf("Enter a number: ");
            scanf("%d", &num);
            head = push(head, num);//Can change to append
            
            printf("Do you want another num (y or n): ");
            scanf("%1s",ans);
        } while(ans[0] == 'y');
        
        printf("Sort ascending or descending (a or d)? ");
        scanf("%1s",ans);
        if(ans[0] == 'a') head=sort_ascending(head);
        else if(ans[0] == 'd') head=sort_descending(head);
        
        print(head, length(head));
        printf("Do you want to do this again (y or n)? ");
        scanf("%1s",ans);
        if(ans[0] == 'y') head = cleared(head);
        
    } while(ans[0] == 'y');
    return 0;
}
#ifndef _DEFRAG
#define _DEFRAG
#include <stdio.h>
#include "linkedlist.h"
#include "free.h"


// to defragment memory
void defragment(int arr[], struct LinkedList list[], struct LinkedList* free, int num_lists, int size);

#endif
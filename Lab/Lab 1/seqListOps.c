/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
	int idx = sl.head;
	ORDER result = compare(j, st[idx]);
	while(result == LESSER) {
		idx = st[idx].next;
		result = compare(j, st[idx]);			
	}
		
	sl.size++;
	nextidx = st[idx].next;
	st[idx].next = nextfreeloc;
	st[nextfreeloc].ele = j;
	st[nextfreeloc].next = nextidx;
	nextfreeloc++;	
	return sl;	
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
	for(int i = 0; i < size; i++) {
		j = list[i];
		if(list.pri == PRI_0)
			insert(j, s[0]);
		else if(list.pri == PRI_1)
			insert(j, s[1]);
		else 
			insert(j, s[2]);
	}

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
	priority2idx = s[2].head;
	priority1idx = s[1].head;
	priority0idx = s[0].head;
	int i = 0;

	while(priority2idx == -1) {
		ele[i] = st[priority2idx].ele;
		i++;
		priority2idx = st[priority2idx].next;
	}

	while(priority1idx == -1) {
		ele[i] = st[priority1idx].ele;
		i++;
		priority2idx = st[priority1idx].next;
	}

	while(priority0idx == -1) {
		ele[i] = st[priority0idx].ele;
		i++;
		priority2idx = st[priority0idx].next;
	}

}

void printlist(SeqList sl)
{

// Implement this function
	idx = sl.head;
	while(idx == -1) {
		printJob(st[idx].ele);
		idx = st[idx].next;
	}


}

void printJobList(JobList list, int size)
{

// Implement this function
	for(int i = 0; i < size; i++) {
		printJob(list[i]);
	}

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "que.h"


int main() {
	struct Queue q = newQ();
	q = addQ(q, 1);
	printf("%d\n", front(q));
	q = delQ(q);
	printf("%d\n", front(q));
}
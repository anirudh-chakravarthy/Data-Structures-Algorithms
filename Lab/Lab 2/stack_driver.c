#include "stack.h"

int main(int argc, char* argv[]) {
	FILE* fptr = fopen(argv[1], "r");
	struct linkedList* head = (struct linkedList*) malloc(sizeof(struct linkedList));

	int num;
	while(fscanf(fptr, "%d", &num) != EOF) {
		push(head, num);
	}

	fclose(fptr);

	struct node* tmp = head->first;
	while(tmp != NULL) {
		printf("%d ", tmp->element);
		tmp = tmp->next;
	}

}

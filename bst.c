#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *lc, *rc;
}Node;

Node * create_node(int val) {
	Node *temp = NULL;

	temp = (Node*)malloc(sizeof(Node));
	if (NULL == temp) {
		printf(" Low memory... wait...exit...\n");
		// exit(-1);
	}
	temp->data = val;
	temp->lc = temp->rc = NULL;
	return temp;
}

void create_tree(Node **p, int info) {
	if (!*p)
		*p = create_node(info);
	else
		info < (*p)->data ?		
		create_tree(&((*p)->lc), info) :
		create_tree(&((*p)->rc), info);
}

void pre_order(Node *p) {
	if (p) {
		printf("%d, ", p->data);
		pre_order(p->lc);
		pre_order(p->rc);
	}
}

void post_order(Node *p) {
	if (p) {
		post_order(p->lc);
		post_order(p->rc);
		printf("%d, ", p->data);
	}
}

void in_order(Node *p) {
	if (p) {
		in_order(p->lc);
		printf("%d, ", p->data);
		in_order(p->rc);
	}
}

// --- app ---
int main() {
	int arr[] = { 111,  0, 143, 501, 225, 99, 125, 175, 50 }, n = 9, i = 0;
	Node *root = NULL;

	for (i = 0; i < n; i++)
		create_tree(&root, arr[i]);
	printf("--------------------\n");
	printf("Pre-order: ");
	pre_order(root);
	printf("\n");
	printf("--------------------\n");
	printf("Post-order: ");
	post_order(root);
	printf("\n");
	printf("--------------------\n");
	printf("In-order: ");
	in_order(root);
	printf("\n");
}

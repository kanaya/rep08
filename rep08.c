#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct xy {
	double x, y;
};

typedef struct xy XY;

struct list_node {
	XY p;
	struct list_node *next;
};

typedef struct list_node ListNode;

ListNode *back(ListNode *ln) {
	if (ln == NULL) {
		return NULL;
	}
	else {
		if (ln->next == NULL) {
			return ln;
		}
		else {
			return back(ln->next);
		}
	}
}

ListNode *append(ListNode *ln, const XY *p) {
	if (ln == NULL) {
		assert(ln = (ListNode *)calloc(1, sizeof(ListNode)));
		if (ln != NULL) {
			ln->p = *p;
			ln->next = NULL;
		}
	}
	else {
		ListNode *b = back(ln);
		ListNode *a;
		assert(a = (ListNode *)calloc(1, sizeof(ListNode)));
		if (b != NULL) {
			b->next = a;
			a->next = NULL;
			a->p = *p;
		}
	}
	return ln;
}

double len(const ListNode *ln, double a) {
	if (ln == NULL) {
		return a;
	}
	else {
		if (ln->next == NULL) {
			return a;
		}
		else {
			double dx = ln->p.x - ln->next->p.x;
			double dy = ln->p.y - ln->next->p.y;
			double dd = dx * dx + dy * dy;
			return len(ln->next, a + sqrt(dd));
		}
	}
}

void print(const ListNode *ln) {
	if (ln != NULL) {
		printf("%f, %f\n", ln->p.x, ln->p.y);
		print(ln->next);
	}
}

int main() {
	ListNode *ln = NULL;
	XY p0 = { 0.0, 0.0 }, p1 = { 3.0, 4.0}, p2 = { 8.0, 16.0 };

	ln = append(ln, &p0);
	ln = append(ln, &p1);
	ln = append(ln, &p2);
	print(ln);
	printf("Length = %f\n", len(ln, 0.0));
	return 0;
}
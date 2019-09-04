#include <stdio.h>

struct Node {
	char c;
	Node *prev;
	Node *next;
	Node() {
		c = '-';
		prev = next = 0;
	}
	Node(char c):c(c) {
		prev = next = 0;
	}
};

struct node {
	node *prev;
	node *next;
	Node *right;
	node() {
		prev = next = 0;
		right = 0;
	}
};

struct cursor {
	node *r;
	Node *c;
};
cursor cs;
struct dll {
	Node *head;
	dll() {
		head = new Node;
		head->next = 0;
		head->c = -1;
	}

	void clear() {
		for (Node *it = head->next; it!=0;) {
			Node *temp = it;
			it = it->next;
			delete temp;
		}
	}
};

struct DLL {
	node *head, *tail, *midd;
	dll list;
	DLL() {
		head = new node;
		midd = new node;
		tail = new node;
		head->next = midd;
		midd->prev = head;
		midd->next = tail;
		tail->prev = midd;
		midd->right = list.head;
	}

	void insert(node *cur) {
		node *now = new node;
		now->next = cur;
		cur->prev->next = now;
		now->prev = cur->prev;
		cur->prev = now;
		cs.r = now;

		dll List;
		now->right = List.head;
	}

	void Rinsert(char a, Node *cur) {
		Node *now = new Node(a);
		cs.c = now;
		if (cur->next == 0) {
			cur->next = now;
			now->prev = cur;
		}
		else {
			Node *nex = cur->next;
			now->next = nex;
			nex->prev->next = now;
			now->prev = nex->prev;
			nex->prev = now;
		}
	}

	void clear() {
		for (node *it = head->next->next; it != tail; ) {
			for (Node *iter = it->right->next; iter!=0;) {
				Node *temp = iter;
				if (iter->next == 0)break;
				iter = iter->next;
				delete temp;
			}
			node *temp = it;
			it = it->next;
			delete temp;
		}
		list.clear();
		head->next = midd;
		midd->prev = head;
		midd->next = tail;
		tail->prev = midd;
		midd->right = list.head;
	}
};

DLL list;
int curCol = 0;


void swapList(DLL &List) {
	DLL LIST, temp;
	temp = List;
	List = LIST;
	LIST = temp;
}

void init(int n) {
	swapList(list);
	cs.r= list.head->next;
	cs.c= list.head->next->right;
	curCol = 0;
}

void input_char(char in_char) {
	list.Rinsert(in_char, cs.c);
	curCol++;
}

void input_newline() {
	list.insert(cs.r->next);
	curCol = 0;
	if (cs.c->next != 0) {
		cs.c = cs.c->next;
		cs.c->prev->next = 0;
		cs.c->prev = cs.r->right;
		cs.r->right->next = cs.c;
		cs.c = cs.c->prev;
	}
	else cs.c = cs.r->right;
}

void move_cursor(int direction) { // 0: Up, 1: Down, 2: Left, 3: Right
	if (direction == 0) {
		if (cs.r->prev == list.head)return;
		int c = 0; cs.r = cs.r->prev;
		for (Node *it = cs.r->right; ; it = it->next) {
			if (it->next == 0) {
				cs.c = it;
				curCol = c;
				break;
			}
			if (c == curCol) {
				cs.c = it;
				break;
			}
			c++;
		}
	}
	else if (direction == 1) {
		if (cs.r->next == list.tail)return;
		int c = 0; cs.r = cs.r->next;
		for (Node *it = cs.r->right; ; it = it->next) {
			if (it->next == 0) {
				cs.c = it;
				curCol = c;
				break;
			}
			if (c == curCol) {
				cs.c = it;
				break;
			}
			c++;
		}
	}
	else if (direction == 2) {
		if (cs.r->prev == list.head && curCol == 0)return;
		if (curCol == 0) {
			int c = 0; cs.r = cs.r->prev;
			for (Node *it = cs.r->right; it!=0 ; it = it->next) {
				if (it->next == 0) {
					cs.c = it;
					curCol = c;
					break;
				}
				c++;
			}
			curCol = c;
		}
		else {
			cs.c = cs.c->prev;
			curCol--;
		}
	}
	else if (direction == 3) {
		if (cs.r->next == list.tail && cs.c->next == 0)return;
		if (cs.c->next == 0) {
			cs.r = cs.r->next;
			cs.c = cs.r->right;
			curCol = 0;
		}
		else {
			cs.c = cs.c->next;
			curCol++;
		}
	}
}

char get_char(int row, int column) {
	int r = 0, c = 0;
	for (node *it = list.head->next; it != list.tail; it = it->next) {
		r++;
		if (r == row) {
			for (Node *iter = it->right->next; iter!=0 ; iter = iter->next) {
				c++;
				if (c == column) {
					return iter->c;
				}
			}
		}
	}
}

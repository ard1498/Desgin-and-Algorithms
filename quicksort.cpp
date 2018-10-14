#include <iostream>

using namespace std;

struct node {
	int data;
	node * next;
	node * prev;

	node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

class lists {
	node * start;

public:
	node * head;
	lists() {
		start = NULL;
		head = NULL;
	}

	void insertion(int item) {
		if (start == NULL) {
			start = new node(item);
			head = start;
			//cout<<"\nstart is:"<<start->data;
			return;
		}
		node * newnode = new node(item);
		newnode->prev = start;
		start->next = newnode;
		start = newnode;
		//cout<<"\nstart is:"<<start->data;
		//cout<<"\nhead is:"<<head->data;
	}

	void display() {
		if (start == NULL) {
			cout << "\nlists is empty.";
			return;
		}
		node * ptr = head;

		while (ptr != NULL) {
			cout << ptr->data<<"\t";
			ptr = ptr->next;
		}

		return;
	}

	void swapp(int &n1, int &n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
		return;
	}

	void callsort() {
		quicksort(head, start);
		return;
	}

	void quicksort(node * left, node * right) {
		if (left != NULL && right != NULL && left != right) {
			node * loc = parts(left, right);
			if (loc == left) {
				quicksort(loc->next, right);
			}
			else if (loc == right) {
				quicksort(left, loc->prev);
			}
			else {
				quicksort(left, loc->prev);
				quicksort(loc->next, right);
			}
		}
		else
			return;
	}

	node * parts(node * left, node * right) {
		node * i = NULL;
		node * j = left;

		while (j != right) {
			if (j->data <= right->data) {
				if (i == NULL)
					i = left;
				else
					i = i->next;
				swapp(i->data, j->data);
			}
			j = j->next;
		}
		if (i == NULL)
			i = left;
		else
			i = i->next;
		swapp(i->data, right->data);
		return i;
	}
};
int main()
{
	lists l1;
	l1.insertion(10);
	l1.insertion(8);
	l1.insertion(11);
	l1.insertion(9);

	cout << "\n";
	l1.display();

	l1.callsort();
	cout << "\n";

	l1.display();
	return 0;
}

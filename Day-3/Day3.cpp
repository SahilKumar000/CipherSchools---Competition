#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}
};

Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

Node *midpoint(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head -> next;

    while(fast!=NULL && fast -> next!=NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node *merge(Node* head1, Node* head2){
	Node* head = NULL;
	Node* tail = NULL;

	if(head1 == NULL && head2 == NULL){
		return head;
	}

	if(head1 == NULL){
		return head2;
	}

	if(head2 == NULL){
        return head1;
    }

	if(head1->data < head2->data){
		head = head1;
		tail = head1;
		head1 = head1->next;
	}
	else if(head1->data >= head2->data){
		head = head2;
		tail = head2;
		head2 = head2->next;
	}

	while(head1 != NULL && head2 != NULL){
		if(head1->data < head2->data){
			tail->next = head1;
			tail = head1;
			head1 = head1->next;
		}
		else if(head1->data >= head2->data){
			tail->next = head2;
			tail = head2;
			head2 = head2->next;
		}
	}

	if(head2 == NULL && head1 != NULL){
        while(head1 != NULL){
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
    }
	else if(head1 == NULL && head2 != NULL){
		while(head2 != NULL){
			tail->next = head2;
			tail = head2;
			head2 = head2->next;
		}
	}
	tail->next = NULL;
	return head;
}


Node *merge_sort(Node *head){
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node *mid = midpoint(head);
    Node *head1 = mid -> next;
    mid -> next = NULL;

    head  = merge_sort(head);
    head1 = merge_sort(head1);
    return merge(head,head1);

}

int main(){
    Node *head = takeInput();
    print(head);
    head = merge_sort(head);
    print(head);
}

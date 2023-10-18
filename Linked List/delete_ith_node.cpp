#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
    return;
}

int length(Node *head) {
    Node* temp = head;
    int length = 0;
    while(temp != nullptr) {
        temp = temp->next;
        length++;
    }
    return length;
}

Node *deleteNode(Node *head, int pos) {
    int l = length(head);
    if(head == nullptr or pos >= l) return head;
    int count = 0;
    Node* temp = head;
    while(temp != nullptr and count < pos - 1) {
        temp = temp->next;
    }

    
}

int main () {
    Node* head = takeinput();
    int pos;
    cin >> pos;
    Node* updatedList = deleteNode(head, pos);
    print(updatedList);
}
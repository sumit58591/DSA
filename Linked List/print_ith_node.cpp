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

void printIthNode(Node *head, int i) {
    if(head == nullptr) return;
    Node* temp = head;
    int count = 0;
    while(temp != nullptr and count < i) {
        count++;
        temp = temp->next;
    }
    if(temp == nullptr) return;
    cout << temp->data << endl;
}

int main () {
    Node* head = takeinput();
    int i;
    cin >> i;
    printIthNode(head, i);
}
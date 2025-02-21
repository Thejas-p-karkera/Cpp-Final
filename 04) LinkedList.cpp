// Use the functions to perform the following:
// i. Create a singly linked list of integers.
// ii. Delete a given integer from the above linked list.
// iii. Display the contents of the above list after deletion.

#include<iostream>
using namespace std;

class Node
{
	public:
		int val;
		Node* next;

		Node(int data)
		{
			val = data;
			next = NULL;
		}
};

void insertAtHead(Node* &head, int val)
{
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
}

void insertAtTail(Node*& head, int val)
{
	Node* newNode = new Node(val);

	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	//newNode->next = NULL;
}

void insertAtPosition(Node*& head, int val, int pos)
{
	if (pos == 0)
	{
		insertAtHead(head, val);
		return;
	}

	Node* newNode = new Node(val);
	Node* temp = head;
	int currentPos = 0;
	while (currentPos != pos - 1)
	{
		temp = temp->next;
		currentPos++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void updateAtPosition(Node*& head, int val, int pos)
{
	Node* temp = head;
	int	currentPos = 0;
	while (currentPos != pos)
	{
		temp = temp->next;
		currentPos++;
	}

	//Temp will be pointing to posTh node
	temp->val = val;
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	head= temp->next;
	free(temp);
}

void deleteAtTail(Node*& head)
{
	Node* secondLast = head;
	while (secondLast->next->next != NULL)
	{
		secondLast = secondLast->next;
	}

	Node* temp;
	temp = secondLast->next;
	secondLast->next = NULL;
	free(temp);
}

void deleteAtPosition(Node*& head, int pos)
{
	if (pos == 0)
	{
		deleteAtHead(head);
		return;
	}

	Node* prev = head;
	int currentPos = 0;

	while (currentPos != pos - 1 && prev->next != NULL)
	{
		prev = prev->next;
		currentPos++;
	}

	if (prev->next == NULL)
	{
		cout << "Position out of bounds." << endl;
		return;
	}

	Node* temp = prev->next;
	prev->next = temp->next;
	delete temp;
}

void display(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	Node* head = NULL;

	while (true)
	{
		int ch;
		int ele;
		int pos;

		cout << "\n1. Display." << endl;
		cout << "2. Insert at Front." << endl;
		cout << "3. Insert at Rear." << endl;
		cout << "4. Insert at a position." << endl;
		cout << "5. Update value at a position." << endl;
		cout << "6. Delete at Front." << endl;
		cout << "7. Delete at Rear." << endl;
		cout << "8. Delete at a position." << endl;
		cout << "9. Exit." << endl;
		cout << "Enter your choice: ";

		cin >> ch;

		switch (ch)
		{
			case 1:
				display(head);
				break;

			case 2:
				cout << "Enter the element you want to insert at front: ";
				cin >> ele;
				insertAtHead(head,ele);
				break;

			case 3:
				cout << "Enter the element you want to insert at rear: ";
				cin >> ele;
				insertAtTail(head,ele);
				break;

			case 4:
				cout << "Enter the element you want to insert at a perticular position: ";
				cin >> ele;
				cout << "Enter the position: ";
				cin >> pos;
				insertAtPosition(head,ele,pos);
				break;

			case 5:
				cout << "Enter the new element you want to update at a position: ";
				cin >> ele;
				cout << "Enter the position: ";
				cin >> pos;
				updateAtPosition(head,ele,pos);
				break;

			case 6:
				deleteAtHead(head);
				break;

			case 7:
				deleteAtTail(head);
				break;

			case 8:
				cout << "Enter the position where you want to delete: ";
				cin >> pos;
				deleteAtPosition(head,pos);
				break;

			case 9:
				return 0;

		}
	}
}


//---------------------------------------------------------------------------------------------------------


#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void insertAtFront(Node*& head)
{
	int ele;
	cout << "Enter the element to insert: ";
	cin >> ele;

	Node* newNode = new Node(ele);
	newNode->next = head;
	head = newNode;
}

void insertAtRear(Node*& head)
{
	int ele;
	cout << "Enter the element to insert: ";
	cin >> ele;

	Node* newNode = new Node(ele);
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void displayList(Node*& head)
{
	if (head == NULL)
	{
		cout << "Empty List";
		return;
	}

	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void deleteInt(Node*& head)
{
	int ele;
	cout << "Enter the element to delete: ";
	cin >> ele;

	Node* temp = head;
	Node* dlt;

	while (temp != NULL)
	{
		if (temp->next->data == ele)
		{
			dlt = temp->next;
			temp->next = dlt->next;
			free(dlt);
			break;
		}
		else
		{
			temp = temp->next;
		}
		if (temp->next == NULL)
		{
			cout << "The ele does not found";
			break;
		}
	}

	
}

void main()
{
	Node* head = NULL;

	while (true)
	{
		cout << "\n1. Insert at front\n";
		cout << "2. Insert at Rear\n";
		cout << "3. Delete\n";
		cout << "4. Display\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		int ch;
		cin >> ch;

		switch (ch)
		{
			case 1:
				insertAtFront(head);
				break;

			case 2:
				insertAtRear(head);
				break;

			case 3:
				deleteInt(head);
				break;

			case 4:
				displayList(head);
				break;

			case 5:
				return;

			default:
				cout << "Enter a valid choice";
				break;
		}

	}

}

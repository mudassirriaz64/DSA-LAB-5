//#include <iostream>
//using namespace std;
//
//typedef struct Node* Nodeptr;
//
//struct Node
//{
//	int info;
//	Nodeptr next;
//};
//
//class LinkedList
//{
//private:
//	Nodeptr List;
//public:
//	LinkedList();
//	void traverse();       
//	Nodeptr find(int);      
//	void iAS(int);       
//	int dAS();       
//	void iAE(int); 
//	int dAE();      
//	void iAM(int); 
//	int dAM(int);
//};
//
//LinkedList::LinkedList()
//{
//	List = NULL;
//}
//
//void LinkedList::iAS(int x)
//{
//	Nodeptr p = new Node;
//	p->info = x;
//	p->next = List;
//	List = p;
//}
//
//int LinkedList::dAS()
//{
//	if (List == NULL)
//		return -999;
//
//	Nodeptr p = List->next;
//	int x = List->info;
//	delete List;
//	List = p;
//	return x;
//}
//
//void LinkedList::traverse()
//{
//	for (Nodeptr p = List; p != NULL; p = p->next)
//	{
//		cout << p->info << " ";
//	}
//	cout << endl;
//}
//
//void LinkedList::iAE(int x)
//{
//	if (List == NULL)
//		iAS(x);
//	else
//	{
//		Nodeptr p = List;
//		while (p->next != NULL)
//		{
//			p = p->next;
//		}
//		Nodeptr q = new Node;
//		p->next = q;
//		q->next = NULL;
//		q->info = x;
//	}
//}
//
//int LinkedList::dAE()
//{
//	if (List == NULL)
//		return -999;
//
//	if (List->next == NULL)
//		return dAS();
//
//	Nodeptr p = List;
//	Nodeptr q = NULL;
//
//	while (p->next->next != NULL)
//	{
//		p = p->next;
//	}
//
//	q = p->next;
//	int x = q->info;
//	p->next = NULL;
//	delete q;
//	return x;
//}
//
//Nodeptr LinkedList::find(int x)
//{
//	for (Nodeptr p = List; p != NULL; p = p->next)
//	{
//		if (p->info == x)
//		{
//			return p;
//		}
//	}
//	return NULL;
//}
//
//void LinkedList::iAM(int x)
//{
//	Nodeptr p = find(x);
//
//	if (p == NULL)
//	{
//		iAE(x);
//	}
//
//	else
//	{
//		Nodeptr q = new Node;
//		q->info = x;
//		q->next = p->next;
//		p->next = q;
//	}
//}
//
//int LinkedList::dAM(int x)
//{
//	Nodeptr p = List, q = NULL;
//
//	while (p != NULL && p->info != x)
//	{
//		q = p;
//		p = p->next;
//	}
//
//	if (p == NULL)
//
//	{
//		return -999;
//	}
//
//	if (q == NULL)
//	{
//		List = p->next;
//	}
//	else
//	{
//		q->next = p->next;
//	}
//
//	delete p;
//	return 1;
//}
//
//int main()
//{
//	LinkedList list;
//
//	list.iAS(10);
//	list.iAE(20);
//	list.iAE(30);
//	list.iAS(5);
//
//	int choice, value, result;
//
//	do 
//	{
//		system("cls");
//		cout << "\nMENU\n";
//		cout << "1. Insert at Start\n";
//		cout << "2. Delete from Start\n";
//		cout << "3. Insert at End\n";
//		cout << "4. Delete from End\n";
//		cout << "5. Insert After Match\n";
//		cout << "6. Delete Matching Element\n";
//		cout << "7. View List\n";
//		cout << "8. Find Element\n";
//		cout << "9. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter value to insert at start: ";
//			cin >> value;
//			list.iAS(value);
//			cout << "Inserted " << value << " at start.\n";
//			break;
//
//		case 2:
//			result = list.dAS();
//			if (result != -999)
//				cout << "Deleted " << result << " from start.\n";
//			else
//				cout << "List is empty, cannot delete.\n";
//			break;
//
//		case 3:
//			cout << "Enter value to insert at end: ";
//			cin >> value;
//			list.iAE(value);
//			cout << "Inserted " << value << " at end.\n";
//			break;
//
//		case 4:
//			result = list.dAE();
//			if (result != -999)
//				cout << "Deleted " << result << " from end.\n";
//			else
//				cout << "List is empty, cannot delete.\n";
//			break;
//
//		case 5:
//			cout << "Enter value to insert after matching element: ";
//			cin >> value;
//			list.iAM(value);
//			cout << "Inserted after " << value << ".\n";
//			break;
//
//		case 6:
//			cout << "Enter value to delete: ";
//			cin >> value;
//			result = list.dAM(value);
//			if (result != -999)
//				cout << "Deleted element " << value << ".\n";
//			else
//				cout << "Element not found.\n";
//			break;
//
//		case 7:
//			cout << "List elements: ";
//			list.traverse();
//			break;
//
//		case 8:
//			cout << "Enter value to find: ";
//			cin >> value;
//			if (list.find(value) != NULL)
//				cout << "Element " << value << " found in the list.\n";
//			else
//				cout << "Element not found.\n";
//			break;
//
//		case 9:
//			cout << "Exiting...\n";
//			break;
//
//		default:
//			cout << "Invalid choice. Please try again.\n";
//			break;
//		}
//		cout << "\nPress any key to continue...";
//		cin.ignore();
//		cin.get();
//	} while (choice != 9);
//
//	return 0;
//}

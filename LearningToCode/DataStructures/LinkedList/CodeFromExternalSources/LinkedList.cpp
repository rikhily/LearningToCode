#include <cstdlib>
#include <iostream>

using namespace std;

// Node class
class Node {
    int data;
    Node* next;

public:
    Node() {};
    
	void SetData(int aData){ 
		data = aData; 
	};
    
	void SetNext(Node* aNext){ 
		next = aNext; 
	};
    
	int Data(){ 
		return data; 
	};
    
	Node* Next(){ 
		return next; 
	};
};

// List class
class List {
    Node* head;

public:
	List(){ 
		head = NULL; 
	};
	
	void Add_End(int data);
	
	void Delete(int data);

	void Delete_Front();

	void Add_Front(int data);
	
	void Delete_End();
	
	Node* Find(int data);
	
	void Print();

};

//FUNCTION DEFINITIONS:  - 
//
//YOU MUST WRITE THESE
//Add_End, Delete, Delete_Front
//
//Append a node to END of the linked list
void List::Add_End(int data) {
	//Implementation--> create a new node
	//append the new node to the end
	//Create a new node
    Node* lastNode = new Node();
	if(head == NULL){
		head = lastNode;
		lastNode->SetData(data);
		lastNode->SetNext(NULL);
	}
//	cout << "-->"<< "\t";
//	else{
//		while(head!= NULL){
//			head = head->Next();
//		}
//		head = lastNode;
//		lastNode->SetData(data);
//		lastNode->SetNext(NULL);
//	}
    return;	
}

/* Delete a node from the list */
 
void List::Delete(int data){
//	//List is empty
//	if(head == NULL){
//		cout << "Cannot delete";
//	}
//	
//	//List has one element
//	else if(head->Data() == data){
//		head = NULL;
//		return;
//	}
//	
//	else{
//		//Traverse the list to find it
//		Node* prev;
//		Node* curr = head;
//		while(curr->Data() != data){
//			prev = curr;
//			curr = curr->Next();		
//		}
//		prev->SetNext(curr->Next());
//		return;
//	}
	
			//Traverse the list to find it
		Node* prev;
		Node* curr = head;
		while(curr->Data() != data){
			prev = curr;
			curr = curr->Next();		
		}
		prev->SetNext(curr->Next());
		return;
}

void List::Delete_Front(){
	
}

void List::Add_Front(int data){
	// Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(head);
    head = newNode;
    return;
}
  	
void List::Delete_End(){
  	if(head == NULL){
  	 	cout<<"List has no member so cannot delete end"<<endl;
        return;	 	
	}
	   
	// check if one in length 
	if(head->Next() == NULL){
       	head = NULL;
       	return;
	}
	// 2 or greater in length

    Node *current;
    Node *prev;
    prev = head;

	for(current = head->Next(); current->Next() != NULL; current = current->Next())	 {
       	prev = current;
	}
	prev->SetNext(NULL);
    return;
}  
  
Node* List::Find(int data){
	Node *current;
    	
    for(current = head; current!= NULL && current->Data() != data; current = current->Next()){
		if(current == NULL){
			cout<<"Did not find "<<data<<"."<<endl;
           	return  NULL;
		}
		else // found
		{
			cout<<"Found "<<data<<"."<<endl;
			return current;
		}
	}
}

void List::Print(){
	if(head == NULL)
		cout << "List is empty!" << endl;
	else{
		while(head != NULL){
			cout << head->Data() << "\t";
			head = head->Next();
		}
	}
	return;
}

int main(){
    // New list
    List list;
	Node *answer;
    // Add_End nodes to the list
    list.Add_End(111);
    list.Print();
    list.Add_End(222);
    list.Print();
    list.Add_End(333);
    list.Print();
    list.Add_End(444);
    list.Print();
    list.Add_End(555);
    list.Print();
	cout << endl << endl;

    // Delete nodes from the list
    list.Delete(444);
    list.Print();
//    list.Delete(333);
//    list.Print();
//    list.Delete(222);
//    list.Print();
//    list.Delete(555);
//    list.Print();
//    list.Delete(111);
//    list.Print();
//    cout<<endl<<endl;
//	
//	cout << "Testing Add_Front: and others"<<endl;
//    list.Add_Front(888);
//    list.Print();
//	list.Add_Front(999);
//	list.Print();
//	list.Add_Front(49);
//	list.Print();
//	cout<<endl<<endl;
	
//	cout << "Checking find function"<<endl;
//	answer = list.Find(888);
//	cout<<"Value for node returned by find function call with 888 is "<<answer->Data()<<"."<<endl;
//	cout<<"Checking find function"<<endl;
//	answer = list.Find(999);
//	cout<<"Value for node returned by find function call with 888 is "<<answer->Data()<<"."<<endl;
//	
//	cout<<"Checking find function"<<endl;
//	answer = list.Find(49);
//	cout<<"Value for node returned by find function call with 888 is "<<answer->Data()<<"."<<endl;
//	cout<<"Call find function with value not in list."<<endl;
//	answer = list.Find(7);
//    if(answer == NULL)
//	{
//		cout<<"returned null pointer since 7 not found"<<endl;
//       	
//	}
//	else
//	{
//	   	cout<< "in else of answer == NULL where Value for node returned by find function call with 7 is "<<answer->Data()<<"."<<endl;
//	}
//	
//	cout<<"testing delete_front: "<<endl;
//	list.Delete_Front();
//	list.Print();
//	cout<<"testing delete_end: "<<endl;
//	
//	list.Delete_End();
//	list.Print();
	
    return 0;
}
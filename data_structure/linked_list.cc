#include <iostream>
#include <list> // build in linked list (Doubly linked list)

class Node{
public:
  int data;
  Node* next;

  Node(int data) : data(data), next(NULL) {};
  ~Node(){delete next;}
};

int main(){

  Node* head = new Node(3);
  std::cout<< "Head data: "<< (*head).data <<  "\nNext: " << head->next << std::endl;

  
  // declare linked list
  std::list<int> llist;
  
  // add element in linked list
  llist.push_back(3);
  llist.push_back(4);
  llist.push_back(5);


  // Displaying elements using an iterator
  std::cout << "Element in the linked list: ";

  for(auto element : llist){
    std::cout << element << "-";
  }


  // Using Iterator
  std::cout << "Using Iterator" << std::endl;

  std::list<int>::iterator it;
  for(it = llist.begin(); it != llist.end(); it++){
    std::cout << *it << std::endl;  
  }
  
}

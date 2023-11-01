#include <iostream>
#include "SingleLinkList.h"

void SingleLinkList::addtoFront(SingleLinkList *myList){
	std::cout<<"Enter the value to be added at end of the list"<<std::endl;
        int value;
        std::cin>>value;	
	start = new SingleLinkListDefination(value,start);
}

SingleLinkList::~SingleLinkList(){
	std::cout<<"Inside the Single Link List"<<std::endl;
	for (SingleLinkListDefination *p ; !isEmpty();){
		p = start->upcoming;
		delete start;
		start = p;
	}
}

void SingleLinkList::addtoEnd(SingleLinkList *myList){
	std::cout<<"Enter the value to be added at end of the list"<<std::endl;
	int value;
	std::cin>>value;
	SingleLinkListDefination *endNode = new SingleLinkListDefination(value);
	if (myList->isEmpty())
		myList->start = endNode;
	else{
		SingleLinkListDefination *current = myList->start;
                while (current->upcoming != nullptr)
		{
			current = current->upcoming;		
		
		}
			current->upcoming = endNode;
	}
}


int  SingleLinkList::deleteFromFront(void){
	if(start == nullptr){
		std::cout<<"List is empty"<<std::endl;
		return 0;
	}
	int value = start->data;
	SingleLinkListDefination *tmp = start;
	start = start->upcoming;
	delete tmp;
	return value;
}
int SingleLinkList::deleteFromEnd(void) {
    if (start == nullptr) {
	std::cout<<"List is empty"<<std::endl;
        // List is empty, handle this case appropriately (e.g., throw an exception).
        return 0;
    }
   if(start->upcoming == nullptr){
	int value = start->data;
	delete start;
	return value;
   }

    int value;
        // Traverse the list to find the second-to-last node
        SingleLinkListDefination *current = start;
        while (current->upcoming->upcoming != nullptr) {
            current = current->upcoming;
        }
        
        // Now, tmp points to the second-to-last node
        value = current->upcoming->data;
        delete current->upcoming;
        current->upcoming = nullptr;
    
    return value;
}


void SingleLinkList::ShowList(SingleLinkList *myList)
{

    SingleLinkListDefination* current = myList->getStart();
   if(current == nullptr)
	std::cout<<"Fill the value in the list.List Is Empty"<<std::endl;
   std::cout <<"___________________________________________________"<<std::endl;
    std::cout << " list: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->upcoming;
   }
  std::cout<<std::endl;
  std::cout <<"____________________________________________________"<<std::endl;
}

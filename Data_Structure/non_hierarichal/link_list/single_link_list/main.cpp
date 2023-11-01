#include <iostream>
#include "SingleLinkList.h"
int main() {
    SingleLinkList myList;
   
    // Add elements to the front of the list
    while (true) {
        std::cout << "Menu:" << std::endl;
	std::cout << "1. Add to the Beginning" << std::endl; 
        std::cout << "2. Add to the end" << std::endl;
        std::cout << "3. Delete from the end" << std::endl;
	std::cout << "4. Delete from the front" << std::endl;
        std::cout << "5. Show List" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
	std::cout <<"_______________________________________________________"<<std::endl;
        switch (choice) {
	    case 1: myList.addtoFront(&myList);break;
            case 2: myList.addtoEnd(&myList); break;
            case 3: myList.deleteFromEnd(); break;
	    case 4: myList.deleteFromFront(); break;
            case 5: myList.ShowList(&myList); break;
            case 6: std::cout << "Exiting the program." << std::endl; return 0;
            default: std::cout << "Invalid choice. Please enter a valid option." << std::endl; break;
        }
    }

    return 0;
}

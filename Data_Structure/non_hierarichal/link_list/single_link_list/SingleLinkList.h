//Single link list class to store the integer

#ifndef SINGLE_LINK_LIST
#define SINGLE_LINK_LIST

class SingleLinkListDefination {
	public:
		SingleLinkListDefination(){
		upcoming=nullptr;
	} 
	SingleLinkListDefination(int value, SingleLinkListDefination *ptr = nullptr){
       		data = value; 
		upcoming = ptr;
	}
	int data;
	SingleLinkListDefination *upcoming;
};

class SingleLinkList {
	public:
		SingleLinkList(){
		start = nullptr;
		}
		~SingleLinkList();	
		bool isEmpty() const	
		{
			return start == nullptr;
		}
		void ShowList(SingleLinkList *);
		void addtoFront(SingleLinkList *);
		void addtoEnd(SingleLinkList *);
		int deleteFromFront(void);
		int deleteFromEnd(void);
		 // New public member function to get the current start pointer
    		SingleLinkListDefination* getStart(){
        		return start;
   		}
		//void deleteValue(int);
		//bool isValueInList(int) const;
	private:
		SingleLinkListDefination *start;
};
#endif
		
	
		

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class ListElement{
	
	private:
	
		int key;
		ListElement *next;
		ListElement *prev;
	public:
	
		ListElement(int newKey, ListElement *newNext, ListElement *newPrev){
			setKey(newKey);
			setNext(newNext);
			setPrev(newPrev);
		}
		
		void setKey(int newKey){
			key = newKey;
		}
		
		int getKey(){
			return key;
		}
		
		void setNext(ListElement *newNext){
			next = newNext;
		}
		
		ListElement *getNext(){
			return next;
		}
		
		void setPrev(ListElement *newPrev){
			prev = newPrev;
		}
		
		ListElement *getPrev(){
			return prev;
		}
};

class List{

	private:
	
		int size;
		ListElement *head;
		ListElement *tail;
	public:
	
		List(){
			setSize(0);
			setHead(NULL);
			setTail(NULL);
		}
		
		void setSize(int newSize){
			size = newSize;
		}

		int getSize(){
			return size;
		}
	
		void setHead(ListElement *newHead){
			head = newHead;
		}
		
		ListElement *getHead(){
			return head;
		}
			
		void setTail(ListElement *newTail){
			tail = newTail;
		}
		
		ListElement *getTail(){
			return tail;
		}

		void pushForward(int newKey){
			ListElement *newElement = new ListElement(newKey, getHead(), NULL);
			ListElement *pointer = getHead();
			setHead(newElement);
			if(pointer != NULL)
				pointer -> setPrev(newElement);
			else setTail(getHead());
			setSize(getSize() + 1);
		}	
		
		void pushBack(int newKey){
			ListElement *newElement = new ListElement(newKey, NULL, getTail());
			ListElement *pointer = getTail();
			setTail(newElement);
			if(pointer != NULL)
				pointer -> setNext(newElement);
			else setHead(newElement);
			setSize(getSize() + 1);
		}
		
		void popForward(){
			ListElement *pointer = getHead();
			setHead(pointer -> getNext());
			if(getHead() != NULL)
				getHead() -> setPrev(NULL);
			else setTail(NULL);
			setSize(getSize() - 1);
		}
		
		void popBack(){
			ListElement *pointer = getTail();
			setTail(pointer -> getPrev());
			if(getTail() != NULL)
				getTail() -> setNext(NULL);
			else setHead(NULL);
			setSize(getSize() - 1);
		}
		
		void printList(){
			ListElement *pointer;
			int index = 0;
			pointer = getHead();
			cout << "Lista: " << endl;
			while(pointer != NULL){
				index++;
				cout << index << ". " << pointer ->getKey() << endl;
				pointer = pointer -> getNext();
			}
		}
};

class Interface{

	private:
		
	public:
		
};

int main(){

	return 0;	
}

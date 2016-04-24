#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
chrono::time_point<std::chrono::system_clock> start;

void timeStart(){
	start = std::chrono::system_clock::now();
}

double timeEnd(){
	chrono::time_point<std::chrono::system_clock> end;
	end = chrono::system_clock::now();
   	chrono::duration<double> elapsed_seconds = end-start;
  	return elapsed_seconds.count();
}


class Node{
	
	private:
	
		int key;
		Node *next;
		Node *prev;
		
	public:
	
		Node(int newKey, Node *newNext, Node *newPrev){
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
		
		void setNext(Node *newNext){
			next = newNext;
		}
		
		Node *getNext(){
			return next;
		}
		
		void setPrev(Node *newPrev){
			prev = newPrev;
		}
		
		Node *getPrev(){
			return prev;
		}
};

class List{

	private:
	
		int size;
		Node *head;
		Node *tail;
		
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
	
		void setHead(Node *newHead){
			head = newHead;
		}
		
		Node *getHead(){
			return head;
		}
			
		void setTail(Node *newTail){
			tail = newTail;
		}
		
		Node *getTail(){
			return tail;
		}

		void pushForward(int newKey){
			Node *newNode = new Node(newKey, getHead(), NULL);
			Node *pointer = getHead();
			setHead(newNode);
			if(pointer != NULL)
				pointer -> setPrev(newNode);
			else setTail(getHead());
			setSize(getSize() + 1);
		}	
		
		void pushBack(int newKey){
			Node *newNode = new Node(newKey, NULL, getTail());
			Node *pointer = getTail();
			setTail(newNode);
			if(pointer != NULL)
				pointer -> setNext(newNode);
			else setHead(newNode);
			setSize(getSize() + 1);
		}
		
		void popForward(){
			Node *pointer = getHead();
			setHead(pointer -> getNext());
			if(getHead() != NULL)
				getHead() -> setPrev(NULL);
			else setTail(NULL);
			setSize(getSize() - 1);
		}
		
		void popBack(){
			Node *pointer = getTail();
			setTail(pointer -> getPrev());
			if(getTail() != NULL)
				getTail() -> setNext(NULL);
			else setHead(NULL);
			setSize(getSize() - 1);
		}
		
		void insert(int index, int newKey){
			Node *pointer;
			if(index > 0 && index <= getSize()){
				if(index < getSize() / 2){
					pointer = getHead();
					for(int i = 1; i < index; i++)
						pointer = pointer -> getNext();
				}
				else{
					pointer = getTail();
					for(int i = getSize(); i > index; i--)
						pointer = pointer -> getPrev();
				}
				Node *newNode = new Node(newKey, pointer, pointer -> getPrev());
				if(pointer -> getPrev() != NULL)
					pointer -> getPrev() -> setNext(newNode);
				else setHead(newNode);
				pointer -> setPrev(newNode);
				setSize(getSize() + 1);
			}
			if(index == getSize() + 1)
				pushBack(newKey);
		}
		
		void remove(int newKey)
		{
			Node *pointer = (Node*) search(newKey);
			if (pointer != NULL){
				if(pointer -> getNext() != NULL)
					pointer -> getNext() -> setPrev(pointer -> getPrev());
				else{
					setTail(pointer -> getPrev());
					if(pointer -> getPrev() != NULL)
						pointer -> getPrev() -> setNext(NULL);
				}
				if(pointer -> getPrev() != NULL)
					pointer -> getPrev() -> setNext(pointer -> getNext());
				else{
					setHead(pointer -> getNext());
					if(pointer -> getNext() != NULL)
						pointer -> getNext() -> setPrev(NULL);
				}
				delete pointer;
				setSize(getSize() - 1);
			}
		}
		
		void printList(){
			Node *pointer;
			int index = 0;
			pointer = getHead();
			while(pointer != NULL){
				index++;
				cout << index << ". " << pointer ->getKey() << endl;
				pointer = pointer -> getNext();
			}
		}
		
		Node *search(int newKey){
			Node *pointer = getHead();
			while (pointer != NULL){
				if (pointer->getKey() == newKey)	
					return pointer;
				pointer = pointer->getNext();
			}
			return NULL ;
		}
		
		void clear(){
			setSize(0);
			setHead(NULL);
			setTail(NULL);
		}
};

class Interface{
	
	private:
	
		int amountOfElements[5] = {1000, 2000, 5000, 10000, 20000};
		int amountOfTests = 100;
		int elementCounter = 0;
		List list;
	public:
		
		Interface(){
			srand(time(NULL));
		}
		
		void measurements(){
			cout << "Measuring... Please hold." << endl;
			fstream file; 
			while(elementCounter <= 4){
			cout << "Stage: " << elementCounter + 1 << endl;
				for(int i = 0; i < amountOfTests; i++){
					file.open("/home/jacek/projekt/list/listPushFront", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.pushForward(rand());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
					file.open("/home/jacek/projekt/list/listPopFront", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.popForward();
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
					
					file.open("/home/jacek/projekt/list/listPushBack", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.pushBack(rand());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
					
					file.open("/home/jacek/projekt/list/listPopBack", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.popBack();
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					file.open("/home/jacek/projekt/list/listInsert", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.insert(rand(), rand() % amountOfElements[elementCounter]);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					file.open("/home/jacek/projekt/list/listSearch", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.search(rand());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					
 					file.open("/home/jacek/projekt/list/listPopRandom", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						list.remove(rand() % amountOfElements[elementCounter]);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					list.clear();
				}
			elementCounter++;
			}
		}
};

int main(){
	Interface interface;
	interface.measurements();
	return 0;	
}

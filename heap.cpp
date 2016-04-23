
///////////////////////////
/* Jacek Głąb 209904 */////
/* PnN = 13:15       */////
///////////////////////////
/* Implementacja kopca   */
///////////////////////////

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class HeapElement{

	private:
	
		int value;
		int key;
	
	public:
	
		HeapElement(){
			setValue(0);
			setKey(0);
		}
		
		HeapElement(int newValue, int newKey){
			setValue(newValue);
			setKey(newKey);
		}
	
		void setValue(int newValue){
			value = newValue;
		}
		
		int getValue(){
			return value;
		}
		
		void setKey(int newKey){
			key = newKey;
		}
		
		int getKey(){
			return key;
		}		
		
		int getParent(){
			return ((key - 1) / 2);
		}
		
				
		int getChildLeft(){
			return key * 2 + 1;
		}
		
				
		int getChildRight(){
			return key * 2 + 2;
		}
		
};

class Heap{
	
	private:
	
		HeapElement *element; //dynamicznie alowana tablica przechowująca elementy kopca
		int size;
	
	public:
	
		Heap(){
			setSize(0);
			setElement(NULL);
			element = new HeapElement[getSize()];
		}
		
		void setElement(HeapElement *newElement){
			element = newElement;
		}
		
		HeapElement *getElement(){
			return element;
		}
		
		void setSize(int newSize){
			size = newSize;
		}

		int getSize(){
			return size;
		}
		
		void pushBegining(int newValue){
			push(newValue, 0);
		}
		
		void pushEnd(int newValue){
			push(newValue, 0);
		}
		
		void push(int newValue, int index){
			setSize(getSize() + 1);
			int newKey = getSize();
			HeapElement *move = new HeapElement[getSize()];
			for(int i = 0; i < getSize() - 1; i++){
				*(move + i) = *(getElement() + 1);
			}
			delete getElement();
			setElement(move);
			
			HeapElement *newElement = new HeapElement (newValue, newKey);
			*(getElement() + newKey - 1) = *newElement;
			
			HeapElement *tmp = (getElement() + newKey - 1);
			int help;
			
			while(tmp -> getParent()){
				if(tmp -> getValue() > (getElement() + tmp -> getParent() - 1) -> getValue()){
					help = tmp -> getValue();
					tmp -> setValue((getElement() + tmp -> getParent() - 1) -> getValue());
					(getElement() + tmp -> getParent() - 1) -> setValue(help);
				}
				else break;
				tmp = (getElement() + tmp -> getParent() - 1);
			}
		}
		
		void printHeap(){
			int j = 2;
			cout << "Heap: " << endl;
			for(int i = 0; i < getSize(); i++){
				if(i + 1 == j){
					cout << endl;
					j = 2 * j;
				}
				cout << "<" << i + 1 << "> " << (getElement() + i) -> getValue() << " ";
			} 
		}
};

class HeapInterface{
private:

public:

	HeapInterface(){
	
	}
};
int main(){
	Heap heap;
	return 0;
	
}

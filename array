#include <stdlib.h>
#include <iostream>

using namespace std;

			///////////////////////////
			/* Implementacja tablicy */
			///////////////////////////

class ArrayElement{

	private:
		int value;
	
	public:
		void setValue(int newValue){
			value = newValue;
		}
		
		int getValue(){
			return value;
		}
};

class Array{

	private:
		int size;
		ArrayElement * array;
	
	public:
		Array(){
			setSize(0);
			setArray(NULL);
		}
		
		void setSize(int newSize){
			size = newSize;
		}

		int getSize(){
			return size;
		}
	
		void setArray(ArrayElement* newElement){
			array = newElement;
		}
		
		ArrayElement* getArray(){
			return array;
		}
		
		void push(int newValue, int index){
			if(index <= getSize() + 1){
				array = (ArrayElement*)realloc(array, (getSize() + 1) * sizeof(ArrayElement*));
				for(int i = getSize() - 1; i >= index; i--){
					*(array + i + 1) = *(array + i);
				}
				(array + index) -> setValue(newValue);
				setSize(getSize() + 1);
			}
		}
		
		void pop(int index){
			if(index <= getSize()){
				for(int i = index; i < (getSize()-1); i++){
					*(array + i ) = *(array + i + 1);
				}
				setSize(getSize() - 1);
				array = (ArrayElement*)realloc(array, getSize() * sizeof(ArrayElement*));
			}
		}
		
		void printArray(){
			for(int i = 0; i < getSize(); i++){
				cout << "[" << i << "] " << (array + i) -> getValue() << endl;
			}
		}
		
		ArrayElement* find(int newValue){
			for(int i = 0; i < getSize(); i++){
				if((array + i) -> getValue() == newValue){
					return (array + i);
				}
			}
		}	
};


int main(){

return 0;
}

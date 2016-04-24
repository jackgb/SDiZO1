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
		
		void clear(){
			setSize(0);
			array = (ArrayElement*)realloc(array, getSize() * sizeof(ArrayElement*));
		}
};

class Interface{
	
	private:
	
		int amountOfElements[5] = {1000, 2000, 5000, 10000, 20000};
		int amountOfTests = 100;
		int elementCounter = 0;
		Array array;
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
					file.open("/home/jacek/projekt/array/arrayPushFront", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.push(rand(), 0);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
					file.open("/home/jacek/projekt/array/arrayPopFront", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.pop(0);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
					
					file.open("/home/jacek/projekt/array/arrayPushBack", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.push(rand(), array.getSize());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
					
					file.open("/home/jacek/projekt/array/arrayPopBack", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.pop(array.getSize());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					file.open("/home/jacek/projekt/array/arrayPushRandom", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.push(rand(), rand() % amountOfElements[elementCounter]);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					file.open("/home/jacek/projekt/array/arraySearch", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.find(rand());
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					
 					file.open("/home/jacek/projekt/array/arrayPopRandom", ios::out|ios::app);
					timeStart();
					for(int i = 0; i <= amountOfElements[elementCounter]; i++){
						array.pop(rand() % amountOfElements[elementCounter]);
					}
					file << amountOfElements[elementCounter] << "		" << timeEnd() << endl;
 					file.close();
 					
 					array.clear();
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

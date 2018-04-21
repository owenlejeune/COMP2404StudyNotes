#include <iostream>
using namespace std;

template <class T>
class OrderedCollection {

  public:
    OrderedCollection(int aCapacity = 100);

    OrderedCollection(const OrderedCollection<T> & c);

    ~OrderedCollection() { delete [] buffer; }

    int getSize() const { return size; }
    bool isFull() const{ //answer if full
        return size == capacity;
    }

    OrderedCollection<T> & addLast(T & element){ //add to end
        if(isFull()) return *this;
        buffer[size] = &element;
        size++;
        return *this;
    }

    OrderedCollection<T> & addFirst(T & element){ //add to front
        if(isFull()) return *this;
        int i = size;
        while(size > 0){
            buffer[i] = buffer[i-1];
            i--;
        }
        buffer[0] = &element;
        return *this;
    }

    T & removeLast(){ //remove last element
        if(size == 0) return NULL;
        size--;
        T temp = buffer[size];
        delete buffer[size];
        buffer[size] = 0;
        return temp;
    }

    T & removeFirst(){ //remove first element
        if(size == 0) return NULL;
        T temp = buffer[0];
        delete buffer[0];
        for(int i=0; i < size; i++){
            buffer[i] = buffer[i+1];
        }
        buffer[size] = 0;
        return temp;
    }

    OrderedCollection<T> & remove(const T & element){ //remove all items == element
        if(size == 0) return *this;
        for(int i=0; i<size; i++){
            delete buffer[i];
            for(int j=i; j<size; j++){
                buffer[j] = buffer[j+1];
            }
        }
        return *this;
    }

    void print(){
	  cout << "Collection\n";
	  cout << "==========\n";
	  for(int i=0; i<size; i++) cout << *(buffer[i]);
    }

  private:
    const int capacity;            //maximum size of the container
    int size;                      //number of actual elements in the container
    T **buffer;                    //pointer to memory for holding elements
};

#include <iostream>
using namespace std;

template <class T>
class OrderedCollection {

public:
	OrderedCollection(int aCapacity = 100);
	OrderedCollection(const OrderedCollection<T> & c);
	~OrderedCollection() { delete[] buffer; }

	int getSize() const { return size; }
	bool isFull() const;                          //answer if full

	OrderedCollection<T> & addLast(T & element);  //add to end
	OrderedCollection<T> & addFirst(T & element); //add to front
	T & removeLast();                             //remove last element
	T & removeFirst();                            //remove first element
	OrderedCollection<T> & remove(const T & element); //remove all items == element

	void print() {
		cout << "Collection\n";
		cout << "==========\n";
		for (int i = 0; i<size; i++) cout << *(buffer[i]);
	}

private:
	const int capacity;            //maximum size of the container
	int size;                      //number of actual elements in the container
	T **buffer;                    //pointer to memory for holding elements
};

template <class T>
OrderedCollection<T>::OrderedCollection(int cap) : capacity(cap) {
	size = 0;
	buffer = new T*[capacity];
}

template <class T>
OrderedCollection<T>::OrderedCollection(const OrderedCollection<T> & c) : capacity(c.capacity) {
	size = c.size;
	// buffer = c.buffer;
	buffer = new T*[capacity];
	for(int i=0; i<size; i++){
		buffer[i] = c.buffer[i];
	}
}

template <class T>
bool OrderedCollection<T>::isFull() const{
	return size == capacity;
}

template <class T>
OrderedCollection<T>& OrderedCollection<T>::addLast(T & element) {
	T* temp = &element;
	if (!isFull()) {
		buffer[size] = temp;
		size++;
	}
	return *this;
}

template <class T>
OrderedCollection<T>& OrderedCollection<T>::addFirst(T & element) {
	if (!isFull()) {
		for (int i = size - 1; i > 0; i--) {
			*buffer[i] = *buffer[i - 1];
		}
		*buffer[0] = element;
	}
	return *this;
}

template <class T>
T& OrderedCollection<T>::removeLast() {
	T x = *buffer[size - 1];
	*buffer[size--] = NULL;
	return x;
}

template <class T>
T& OrderedCollection<T>::removeFirst() {
	T x = *buffer[0];
	for (int i = size - 1; i > 0; i++) {
		*buffer[i - 1] = buffer[i];
	}
	size--;
	return x;
}

template <class T>
OrderedCollection<T>& OrderedCollection<T>::remove(const T & element) {
	for (int i = 0; i < size; i++) {
		if (*buffer[i] == element) {
			for (int j = i; j < size-1; j++) {
				*buffer[j] = *buffer[j + 1];
			}
			size--;
		}
	}
	return *this;
}

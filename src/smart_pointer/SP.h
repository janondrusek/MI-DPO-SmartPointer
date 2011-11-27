/*
 * SP.h
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef SP_H_
#define SP_H_

using namespace std;

#include <iostream>
#include "RC.h"

template<typename T> class SP {
private:
	T* pData; // pointer
	RC* reference; // Reference count

public:
	SP() :
			pData(0), reference(0) {
		// Create a new reference
		reference = new RC();
		// Increment the reference count
		reference->AddRef();
	}

	SP(T* pValue) :
			pData(pValue), reference(0) {
		// Create a new reference
		reference = new RC();
		// Increment the reference count
		reference->AddRef();
	}

	SP(const SP<T>& sp) :
			pData(sp.pData), reference(sp.reference) {
		// Copy constructor
		// Copy the data and reference pointer
		// and increment the reference count
		reference->AddRef();
	}

	~SP() {
		// Destructor
		// Decrement the reference count
		// if reference become zero delete the data
		if (reference->Release() == 0) {
			delete pData;
			delete reference;
			cout << "Bye bye" << reference << "\n";
		}
	}

	T& operator*() {
		return *pData;
	}

	T* operator->() {
		return pData;
	}

	SP<T>& operator =(const SP<T>& sp) {
		// Assignment operator
		if (this != &sp) // Avoid self assignment
				{
			// Decrement the old reference count
			// if reference become zero delete the old data
			if (reference->Release() == 0) {
				delete pData;
				delete reference;
			}

			// Copy the data and reference pointer
			// and increment the reference count
			pData = sp.pData;
			reference = sp.reference;
			reference->AddRef();
		}
		return *this;
	}
};

#endif /* SP_H_ */

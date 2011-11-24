/*
 * SP.cpp
 *
 *  Created on: 24.11.2011
 *      Author: Ján Ondrušek
 */

#include "RC.h"
#include "SP.h"

using namespace std;

template<typename T> SP<T>::SP() :
		pData(0), reference(0) {
	// Create a new reference
	reference = new RC();
	// Increment the reference count
	reference->AddRef();
}

template<typename T> SP<T>::SP(T* pValue) :
		pData(pValue), reference(0) {
	// Create a new reference
	reference = new RC();
	// Increment the reference count
	reference->AddRef();
}

template<typename T> SP<T>::SP(const SP<T>& sp) :
		pData(sp.pData), reference(sp.reference) {
	// Copy constructor
	// Copy the data and reference pointer
	// and increment the reference count
	reference->AddRef();
}

template<typename T> SP<T>::~SP() {
	// Destructor
	// Decrement the reference count
	// if reference become zero delete the data
	if (reference->Release() == 0) {
		delete pData;
		delete reference;
	}
}

template<typename T> T& SP<T>::operator*() {
	return *pData;
}

template<typename T> T* SP<T>::operator->() {
	return pData;
}

template<typename T> SP<T>& SP<T>::operator =(const SP<T>& sp) {
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


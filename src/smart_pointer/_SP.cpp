/*
 * _SP.cpp
 *
 *  Created on: 24.11.2011
 *      Author: Ján Ondrušek
 */

template<typename T> class _SP {
private:
	T* pData; // pointer
	RC* reference; // Reference count

public:
	_SP() :
		pData(0), reference(0) {
		// Create a new reference
		reference = new RC();
		// Increment the reference count
		reference->AddRef();
	}

	_SP(T* pValue) :
		pData(pValue), reference(0) {
		// Create a new reference
		reference = new RC();
		// Increment the reference count
		reference->AddRef();
	}

	_SP(const _SP<T>& sp) :
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
		}
	}

	T& operator*() {
		return *pData;
	}

	T* operator->() {
		return pData;
	}

	SP<T>& operator =(const _SP<T>& sp) {
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

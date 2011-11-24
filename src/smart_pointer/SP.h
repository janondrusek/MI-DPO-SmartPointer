/*
 * SP.h
 *
 *  Created on: 24.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef SP_H_
#define SP_H_

using namespace std;

template<typename T> class SP {
private:
	T* pData; // pointer
	RC* reference; // Reference count

public:
	SP();

	SP(T* pValue);

	SP(const SP<T>& sp);

	virtual ~SP();

	T& operator*();

	T* operator->();

	SP<T>& operator=(const SP<T>& sp);
};

#endif /* SP_H_ */
/*
 * RC.h
 *
 *  Created on: 24.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef RC_H_
#define RC_H_

using namespace std;

class RC {

private:
	int count; // Reference count

public:
	RC();

	virtual ~RC();

	void AddRef();

	int Release();

};

#endif /* RC_H_ */

/*
 * RC.h
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef RC_H_
#define RC_H_

class RC {
public:
	RC();
	virtual ~RC();

	void AddRef();
	int Release();
	int getRefsCount();

private:
	int count; // Reference count
};

#endif /* RC_H_ */

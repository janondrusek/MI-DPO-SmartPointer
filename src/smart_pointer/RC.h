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

	void RC::AddRef();
	int RC::Release();

private:
	int count; // Reference count
};

#endif /* RC_H_ */

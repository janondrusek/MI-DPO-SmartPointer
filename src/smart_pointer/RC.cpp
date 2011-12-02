/*
 * RC.cpp
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

using namespace std;

#include "RC.h"
#include <iostream>

RC::RC() {
	count = 0;
}

RC::~RC() {
}

void RC::AddRef() {
	// Increment the reference count
	count++;
}

int RC::Release() {
	// Decrement the reference count and
	// return the reference count.
	return --count;
}

int RC::getRefsCount() {
	return count;
}

/*
 * RC.cpp
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

#include "RC.h"

RC::RC() {

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


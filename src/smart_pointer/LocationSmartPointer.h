/*
 * LocationSmartPointer.h
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef LOCATIONSMARTPOINTER_H_
#define LOCATIONSMARTPOINTER_H_

#include "../Location.h"

using namespace std;

typedef map<string, AgentPointer> AgentList;

class LocationSmartPointer: public Location {
private:
	AgentList agents;
public:
	LocationSmartPointer(EventLogger* logger, string name) :
			Location(logger, name) {
	}
	;

	void agentEnters(AgentPointer a);

	void agentLeaves(AgentPointer a);

	AgentList agentsInside();
};

#endif /* LOCATIONSMARTPOINTER_H_ */

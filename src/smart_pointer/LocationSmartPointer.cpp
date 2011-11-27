/*
 * LocationSmartPointer.cpp
 *
 *  Created on: 27.11.2011
 *      Author: Ján Ondrušek
 */

#include "LocationSmartPointer.h"

using namespace std;

void LocationSmartPointer::agentEnters(AgentPointer a) {
	agents[a->getName()] = a;
}

void LocationSmartPointer::agentLeaves(AgentPointer a) {
	cout << "adios agent " << a->getName() << endl;
	agents.erase(a->getName());
}

AgentList LocationSmartPointer::agentsInside() {
	return agents;
}

/*
 * WorldFacadeSmartPointerImpl.cpp
 *
 *  Created on: 26.11.2011
 *      Author: Ján Ondrušek
 */

#include "WorldFacadeSmartPointerImpl.h"
#include <iostream>

using namespace std;

WorldFacadeSmartPointerImpl::WorldFacadeSmartPointerImpl(EventLogger* logger) {
	cout << "SmartPointer Implementation Of World Facade created!" << endl;
	acceptLogger(logger);
	getLogger()->logEvent(EventLogger::constructorString());
}

WorldFacadeSmartPointerImpl::~WorldFacadeSmartPointerImpl() {
	cout << "Delete world! locations: " << locations.size() << endl;
	for (LocationSmartPointerMap::iterator it = locations.begin();
			it != locations.end(); it++) {
		deleteLocation(it->second->getName());
	}
	getLogger()->logEvent(EventLogger::destructorString());
	cout << "Deleted world! locations: " << locations.size() << endl;
}

void WorldFacadeSmartPointerImpl::createLocation(string lName) {
	LocationSmartPointerPtr l(new LocationSmartPointer(getLogger(), lName));
	locations[lName] = l;
}

void WorldFacadeSmartPointerImpl::deleteLocation(string lName) {
	cout << "Adios location " << lName << endl;
	AgentList agentsInside = locations[lName]->agentsInside();
	for (AgentList::const_iterator it2 = agentsInside.begin();
			it2 != agentsInside.end(); it2++) {
		locations[lName]->agentLeaves(it2->second);
	}
	locations.erase(lName);
}

void WorldFacadeSmartPointerImpl::createAgent(string aName, string lName) {
	SP<Agent> a(new Agent(getLogger(), aName));
	locations[lName]->agentEnters(a);
}

AgentPointer WorldFacadeSmartPointerImpl::getAgentWithId(string id) {
	return findAgentByName(id);
}

AgentPointer WorldFacadeSmartPointerImpl::findAgentByName(string name) {
	for (LocationSmartPointerMap::const_iterator it = locations.begin();
			it != locations.end(); it++) {
		LocationSmartPointerPtr location = it->second;
		//cout << "FOUND LOCATION: " << *location << endl;
		AgentList agentsInside = location->agentsInside();
		for (AgentList::const_iterator it2 = agentsInside.begin();
				it2 != agentsInside.end(); it2++) {
			AgentPointer agent = it2->second;
			//cout << "FOUND AGENT: " << *agent << endl;
			if (name == agent->getName()) {
				//cout << "AGENT MATCH NAME: " << name << endl;
				return agent;
			}
		}
	}
	return NULL;
}

StringList WorldFacadeSmartPointerImpl::getAgentsInLocation(string lName) {
	AgentList agentsInside = locations[lName]->agentsInside();
	list<string> l;

	for (AgentList::iterator iter = agentsInside.begin();
			iter != agentsInside.end(); iter++) {
		l.push_back(iter->second->getName());
	}

	return l;
}

StringList WorldFacadeSmartPointerImpl::getLocationsInWorld() {
	StringList l;
	for (LocationSmartPointerMap::iterator it = locations.begin();
			it != locations.end(); it++) {
		l.push_back(it->second->getName());
	}
	return l;
}

StringList WorldFacadeSmartPointerImpl::getAgentsInWorld() {
	StringList l;
	cout << "locsInWorld size: " << locations.size() << endl;

	for (LocationSmartPointerMap::const_iterator it = locations.begin();
			it != locations.end(); it++) {
		LocationSmartPointerPtr location = it->second;
		AgentList agentsInside = location->agentsInside();

		for (AgentList::const_iterator it2 = agentsInside.begin();
				it2 != agentsInside.end(); it2++) {
			AgentPointer agent = it2->second;
			l.push_back(agent->getName());
		}
	}
	cout << "locsInWorld size: " << locations.size() << endl;
	return l;
}

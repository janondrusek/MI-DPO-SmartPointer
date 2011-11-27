/*
 * WorldFacadeSmartPointerImpl.h
 *
 *  Created on: 26.11.2011
 *      Author: Ján Ondrušek
 */

#ifndef WORLDFACADESMARTPOINTERIMPL_H_
#define WORLDFACADESMARTPOINTERIMPL_H_

#include "SP.h"

#include "../WorldFacade.h"
#include "LocationSmartPointer.h"

using namespace std;

typedef SP<LocationSmartPointer> LocationSmartPointerPtr;
typedef map<string, LocationSmartPointerPtr> LocationSmartPointerMap;

class WorldFacadeSmartPointerImpl: public WorldFacade {
public:
	WorldFacadeSmartPointerImpl(EventLogger* logger);
	virtual ~WorldFacadeSmartPointerImpl();

	virtual void createLocation(string lName);
	virtual void createAgent(string aName, string lName);
	virtual void deleteLocation(string lName);

	virtual StringList getLocationsInWorld();
	virtual StringList getAgentsInWorld();

	virtual StringList getAgentsInLocation(string lName);
	virtual AgentPointer getAgentWithId(string id);

private:
	LocationSmartPointerMap locations;
	void freeUpLocations();
	AgentPointer findAgentByName(string name);
};

#endif /* WORLDFACADESMARTPOINTERIMPL_H_ */

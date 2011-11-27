/*
 * WorldFacade.cpp
 *
 *  Created on: 6 Sep 2010
 *      
 */

#include "WorldFacade.h"
#include <iostream>

#include "smart_pointer/WorldFacadeSmartPointerImpl.h"

using namespace std;

WorldFacade* WorldFacade::createWorldFacade(EventLogger* logger)
{
	WorldFacade* facade;

	// Use your own implementation of the WorldFacade here
	facade = new WorldFacadeSmartPointerImpl(logger);

	return facade;
}

/**
 *
 */
#ifndef MIDPOUTILS_H_
#define MIDPOUTILS_H_

#include "Agent.h"
#include "smart_pointer/SP.h"
#include <string>
#include <list>
#include <map>

using namespace std;

typedef SP<Agent> AgentPointer;

string serializeStringList(StringList list);

/**
 * Return true if there is a event in the events vector somewhere in the
 * 	between from and to index.
 *
 * @param events vector of events
 * @param event required event
 * @param from start index - the event must be on or after this index.
 * @param to end index - the event must be on or before this index.
 */
bool isEventInRange(StringVector events, string event, int from, int to);

#endif /* MIDPOUTILS_H_ */

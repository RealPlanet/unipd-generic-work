/*
	Fabio Ruscica - 1229076
*/

#ifndef transittrack_h
#define transittrack_h

#include "Track.h"

/*
* Implementa Track
*/
class TransitTrack : public Track
{
	TransitTrack() : Track(TrackType::TRANSIT) {} //Le funzioni base sono gi� implementate in track
};

#endif // !transittrack_h





#include "PolyVsa.h"
PolyVsa::PolyVsa()
{
	poly=nullptr;
	label=-1;
}

PolyVsa::~PolyVsa()
{
	poly=nullptr;
	label=-1;
}

void PolyVsa::setLabel(int incomingLabel)
{
	label = incomingLabel;
}
int PolyVsa::getLabel()
{
	return label;
}

void PolyVsa::setHandle(YsShellPolygonHandle incomingPoly)
{
	poly= incomingPoly;
}


YsShellPolygonHandle PolyVsa::getHandle()
{
	return poly;
}



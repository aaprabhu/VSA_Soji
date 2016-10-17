#ifndef POLYVSA_IS_INCLUDED
#define POLYVSA_IS_INCLUDED
#include "ysshell.h"

class PolyVsa
{
private:
	YsShellPolygonHandle poly;
	int label;
public:
	PolyVsa();
	~PolyVsa();
	void setLabel(int incomingLabel);
	int getLabel();
	void setHandle(YsShellPolygonHandle incomingPoly);
	YsShellPolygonHandle getHandle();
};


#endif

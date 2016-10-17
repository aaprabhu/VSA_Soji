#ifndef VSAQUEUE_IS_INCLUDED
#define VSAQUEUE_IS_INCLUDED
#include "ysshell.h"

class VsaQueue
{
private:
	YsShell::PolygonHandle poly;
	int proxyTestLabel;
	double error;
public:
	VsaQueue();
	~VsaQueue();
	void setProxyTestLabel(int incomingLabel);
	int getProxyTestLabel();
	void setError(double err);
	double getError();
	bool operator<=(VsaQueue op2);
	bool operator>=(VsaQueue op2);
	double operator[](VsaQueue op2);
	void setHandle(YsShell::PolygonHandle incomingPoly);
	YsShell::PolygonHandle getHandle();
};

#endif

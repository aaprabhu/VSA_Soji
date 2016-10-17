
#include "VsaQueue.h"
VsaQueue::VsaQueue()
{
	error = 0;
	proxyTestLabel = -1;
}
VsaQueue::~VsaQueue()
{
	error = 0;
	proxyTestLabel = -1;
}
void VsaQueue::setProxyTestLabel(int incomingLabel)
{
	proxyTestLabel = incomingLabel;
}
int VsaQueue::getProxyTestLabel()
{
	return proxyTestLabel;
}
void VsaQueue::setError(double err)
{
	error = err;	
}
double VsaQueue::getError()
{
	return error;
}

bool VsaQueue::operator<=(VsaQueue op2)
{
	if(this->error<=op2.getError())
		return true;
	else	
		return false;
}

bool VsaQueue::operator>=(VsaQueue op2)
{
	if(this->error>=op2.getError())
		return true;
	else	
		return false;
}
double VsaQueue::operator[](VsaQueue op2)
{
	printf("using overload!\n");
	return op2.error;
}

void VsaQueue::setHandle(YsShell::PolygonHandle incomingPoly)
{
	poly= incomingPoly;
}


YsShell::PolygonHandle VsaQueue::getHandle()
{
	return poly;
}



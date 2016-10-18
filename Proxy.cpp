
#include "Proxy.h"
Proxy::Proxy()
{
	prxNumber = -1;
	poly =nullptr;
}

Proxy::~Proxy()
{
	prxNumber = -1;
	poly =nullptr;
}

void Proxy::setNumber(int incomingNumber){
    prxNumber = incomingNumber;
}

int Proxy::getNumber() const
{
    return prxNumber;
}
void Proxy::setPolygon(YsShell::PolygonHandle &incomingPolygon)
{
    poly = incomingPolygon;
}

YsShell::PolygonHandle Proxy::getPolygon() const
{
    return poly;
}
bool Proxy::operator==(Proxy op2)
{
	if (this->getNumber()!=op2.getNumber())
	{
		return false;
	}
	if (this->getPolygon()!=op2.getPolygon())
	{
		return false;
	}
	return true;
}


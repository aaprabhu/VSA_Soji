
#include "Proxy.h"

Proxy::Proxy()
{
	prxyNumber = 0;
	plHd = nullptr;	
}
Proxy::~Proxy()
{

	prxyNumber = 0;
	plHd = nullptr;
}
void Proxy::setNumber(int incomingNumber) 
{
    prxyNumber=incomingNumber;
}
const int Proxy::getNumber() const
{
    return prxyNumber;
}

const YsShell::PolygonHandle Proxy::getPolygon() const
{
	return plHd;
}

void Proxy::setPolygon(YsShell::PolygonHandle pl)
{
	plHd = pl;
}

bool Proxy::operator==(Proxy op2)
{
	if(this->plHd!=op2.getPolygon())
	{
		return false;
	}
	if(this->prxyNumber!=op2.getNumber())
	{
		return false;
	}
	return false;
}
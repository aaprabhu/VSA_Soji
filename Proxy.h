#ifndef PROXY_IS_INCLUDED
#define PROXY_IS_INCLUDED
#include "ysshell.h"

class Proxy {
private:
    int prxyNumber;
	YsShell::PolygonHandle plHd;
public:
    Proxy();
    ~Proxy();
    void setNumber(int incomingNumber);
    const int getNumber() const;
	const YsShell::PolygonHandle getPolygon() const;	
	void setPolygon(YsShell::PolygonHandle pl);
	bool operator==(Proxy op2);
};



#endif

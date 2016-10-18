#ifndef Proxy_IS_INCLUDED
#define Proxy_IS_INCLUDED
#include "ysshell.h"

class Proxy {
private:
    int prxNumber;
	YsShell::PolygonHandle poly;
public:
    Proxy();
    ~Proxy();
    void setNumber(int incomingNumber);
    int getNumber() const;
    void setPolygon(YsShell::PolygonHandle &incomingPolygon);
    YsShell::PolygonHandle getPolygon() const;
	bool operator==(Proxy op2);
};

#endif

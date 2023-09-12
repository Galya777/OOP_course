#include "Conrfigurator.h"

Conrfigurator::Conrfigurator(const Store& store, Requirement& req)
{
    this->store = store;
    this->req = req;
}

Conrfigurator::Conrfigurator()
{
    
}

Configuration Conrfigurator::createConfig()
{
    Configuration curr;
    
    for (int i = 0; i < store.getSize(); ++i) {
         Configuration curr(store.getComponent(i),store.getPrice());
         if (req.hasSameTypes(curr) && req.hasBetterCharacteristics(curr)) {
             con.addComponent(curr.getComponent(i));
             store.removeComponent(i);
        }
    }
    return con;
}

bool Conrfigurator::isEmpty()
{
    if (con.getSize() == 0) {
        return true;
    }
    return false;
}

Configuration Conrfigurator::returnConfig()
{
    return con;
}

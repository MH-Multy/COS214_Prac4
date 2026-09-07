#include "ProductionGroup.h"
#include <iostream>

#include "ProductionGroup.h"
#include <iostream>

ProductionGroup::ProductionGroup(const std::string& name)
{
    this->name = name;
}

ProductionGroup::~ProductionGroup()
{
    for (unsigned int i = 0; i < children.size(); i++)
    {
        delete children[i]; //goes through tree,cascades 
    }
}

void ProductionGroup::add(ProductionComponent* component)
{
    children.push_back(component); //adds to vector
}

void ProductionGroup::remove(ProductionComponent* component)
{
    for (unsigned int i = 0; i < children.size(); i++)
    {
        if (children[i] == component) //goes trhough tree, if child is found, delete
        {
            children.erase(children.begin() + i);
            return;
        }
    }
}

void ProductionGroup::process()
{
    std::cout << "Processing group: " << name << std::endl;

    for (unsigned int i = 0; i < children.size(); i++)
    {
        children[i]->process(); //call each proccess on child in tree
    }
}

std::string ProductionGroup::getName() const
{
    return name;
}
#include "SafetyDecorator.h"

SafetyDecorator::SafetyDecorator(ProductionComponent* component) : ShotDecorator(component)
{
    //inline, calls parent
}

void SafetyDecorator::process()
{
    cout << "Prefroming safety checks...\n";
    component->process();
}

string SafetyDecorator::getName() const
{
    return "Safety Checked: " + component->getName();
}
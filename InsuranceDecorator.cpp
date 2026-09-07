#include "InsuranceDecorator.h"

InsuranceDecorator::InsuranceDecorator(ProductionComponent* component) : ShotDecorator(component)
{
    //inline
}

void InsuranceDecorator::process()
{
    cout << "Chechking insurance requirements...\n";
    component->process();
}

string InsuranceDecorator::getName() const
{
    return "Insured " + component->getName();
}
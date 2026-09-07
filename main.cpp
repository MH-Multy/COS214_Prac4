#include <iostream>
#include <vector>
#include "ProductionGroup.h"
#include "Shot.h"
#include "SafetyDecorator.h"
#include "InsuranceDecorator.h"
#include "HierarchyIterator.h"
#include "ShotIterator.h"

using namespace std;

int main() {
    cout << "Testing film production setup...\n\n";

    ProductionGroup* featureFilm = new ProductionGroup("Feature Film: Cyber Heist");
    
    ProductionGroup* act1 = new ProductionGroup("Act 1: The Setup");
    ProductionGroup* act2 = new ProductionGroup("Act 2: The Action");

    Shot* shot1 = new Shot("Shot 1A (Wide Alley)");
    Shot* shot2 = new Shot("Shot 1B (Dialogue)");
    Shot* shot3 = new Shot("Shot 2A (Explosion)");

    ProductionComponent* heavilyGuardedShot = new InsuranceDecorator(new SafetyDecorator(shot3));

    act1->add(shot1);
    act1->add(shot2);
    act2->add(heavilyGuardedShot);

    featureFilm->add(act1);
    featureFilm->add(act2);

    cout << "Testing states:\n";
    shot1->startRecording();
    shot1->startRecording();
    shot1->stopRecording();
    cout << "\n";

    cout << "Removing shot2 from act1:\n";
    act1->remove(shot2);
    delete shot2;
    cout << "\n";

    cout << "Printing full hierarchy:\n";
    Iterator* fullIterator = featureFilm->createIterator();
    
    for (fullIterator->first(); !fullIterator->isDone(); fullIterator->next()) {
        ProductionComponent* current = fullIterator->currentItem();
        cout << current->getName() << "\n";
    }
    cout << "\n";

    cout << "Processing shots only:\n";
    vector<ProductionComponent*> snapshotList;
    featureFilm->collect(snapshotList);
    Iterator* shotOnlyIterator = new ShotIterator(snapshotList);

    for (shotOnlyIterator->first(); !shotOnlyIterator->isDone(); shotOnlyIterator->next()) {
        ProductionComponent* current = shotOnlyIterator->currentItem();
        current->process(); 
        cout << "\n";
    }

    delete fullIterator;
    delete shotOnlyIterator;

    cout << "Deleting featureFilm...\n";
    delete featureFilm; 
    
    cout << "Done.\n";
    return 0;
}
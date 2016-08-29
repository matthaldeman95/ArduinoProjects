#include "inventory.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include "recipe.h"


Recipe Components [8] {
                {"Carite Sheet", std::make_tuple("Iron", 50), std::make_tuple("", 0), std::make_tuple("", 0)},
                {"Microdensity Fabric", std::make_tuple("Iron", 50), std::make_tuple("Platinum", 10), std::make_tuple("", 0)},
                {"Electron Vapor", std::make_tuple("Suspension Fluid", 1), std::make_tuple("Plutonium", 100), std::make_tuple("", 0)},
                {"Suspension Fluid", std::make_tuple("Carbon", 50), std::make_tuple("", 0), std::make_tuple("", 0)},
                {"Antimatter", std::make_tuple("Electron Vapor", 1), std::make_tuple("Heridium", 50), std::make_tuple("Zinc", 20)},
                {"Dynamic Resonator", std::make_tuple("Antimatter", 2), std::make_tuple("Chrysonite", 100), std::make_tuple("Microdensity Fabric", 4)},
                {"Terumin", std::make_tuple("Emeril", 40), std::make_tuple("Gold", 40), std::make_tuple("Herox", 1)},
                {"Grantine", std::make_tuple("Iridium", 150), std::make_tuple("Copper", 50), std::make_tuple("Aronium", 1) }
                        };


extern Inventory(w);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Inventory(w);
    w.show();


    return a.exec();
}

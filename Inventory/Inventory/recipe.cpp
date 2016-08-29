#include "recipe.h"
#include "inventory.h"
#include <iostream>

Recipe::Recipe(std::string ename, std::tuple<std::string,int> elementq1, std::tuple<std::string,int> elementq2, std::tuple<std::string,int> elementq3)
{
    name = ename;
    element1 = elementq1;
    element2 = elementq2;
    element3 = elementq3;
}



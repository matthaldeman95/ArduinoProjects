#ifndef RECIPE_H
#define RECIPE_H

#include <tuple>
#include "inventory.h"

class Recipe
{
public:
    std::string name;
    std::tuple<std::string, int> element1, element2, element3;
    Recipe(){}
    //Recipe(std::tuple<std::string, int>,std::tuple<std::string, int>,std::tuple<std::string, int>);
    Recipe(std::string, std::tuple<std::string, int>,std::tuple<std::string, int>,std::tuple<std::string, int>);

};

#endif // RECIPE_H

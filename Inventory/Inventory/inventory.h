#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include <recipe.h>

//extern Recipe CariteSheet;
extern Recipe Components[8];

namespace Ui {
class Inventory;
}

class Inventory : public QWidget
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = 0);
    ~Inventory();
void initialize();
void updateInventory();
bool canMake(Recipe);
bool canMakeIndividual(std::string, int);
std::map <std::string, int> inventory;


private slots:
void on_updateButton_clicked();

private:
    Ui::Inventory *ui;

};

#endif // INVENTORY_H

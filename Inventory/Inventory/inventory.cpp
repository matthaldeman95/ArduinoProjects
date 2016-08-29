#include "inventory.h"
#include "ui_inventory.h"
#include <QDebug>
#include <iostream>
#include <recipe.h>

//extern Recipe Recipes[1];
//extern Recipe CariteSheet;

Inventory::Inventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inventory)
{
    ui->setupUi(this);
    Inventory::initialize();
}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::initialize(){
    Inventory::inventory["Aluminium"] = 0;
    Inventory::inventory["Antimatter"] = 0;
    Inventory::inventory["AquaSphere"] = 0;
    Inventory::inventory["Aronium"] = 0;
    Inventory::inventory["Calium"] = 0;
    Inventory::inventory["Carbon"] = 0;
    Inventory::inventory["Carite Sheet"] = 0;
    Inventory::inventory["Chrysonite"] = 0;
    Inventory::inventory["Copper"] = 0;
    Inventory::inventory["Dimensional Matrix"] = 0;
    Inventory::inventory["Dynamic Resonator"] = 0;
    Inventory::inventory["Electron Vapor"] = 0;
    Inventory::inventory["Emeril"] = 0;
    Inventory::inventory["Gold"] = 0;
    Inventory::inventory["Gravitino Ball"] = 0;
    Inventory::inventory["Heridium"] = 0;
    Inventory::inventory["Herox"] = 0;
    Inventory::inventory["Iridium"] = 0;
    Inventory::inventory["Iron"] = 0;
    Inventory::inventory["Microdensity Fabric"] = 0;
    Inventory::inventory["Murrine"] = 0;
    Inventory::inventory["Neutrino Module"] = 0;
    Inventory::inventory["Nickel"] = 0;
    Inventory::inventory["Omegon"] = 0;
    Inventory::inventory["Platinum"] = 0;
    Inventory::inventory["Platonium"] = 0;
    Inventory::inventory["Power Canister"] = 0;
    Inventory::inventory["Power Gel"] = 0;
    Inventory::inventory["Radnox"] = 0;
    Inventory::inventory["Shielding Plate"] = 0;
    Inventory::inventory["Shielding Shard"] = 0;
    Inventory::inventory["Suspension Fluid"] = 0;
    Inventory::inventory["Thamium9"] = 0;
    Inventory::inventory["Titanium"] = 0;
    Inventory::inventory["Unstable Plasma"] = 0;
    Inventory::inventory["Vortex Cube"] = 0;
    Inventory::inventory["Warp Cell"] = 0;
    Inventory::inventory["Zinc"] = 0;

    ui->aluminiumEntry->setText("0");
    ui->antimatterEntry->setText("0");
    ui->aquaSphereEntry->setText("0");
    ui->aroniumEntry->setText("0");
    ui->caliumEntry->setText("0");
    ui->carbonEntry->setText("0");
    ui->cariteSheetEntry->setText("0");
    ui->chrysoniteEntry->setText("0");
    ui->copperEntry->setText("0");
    ui->dimMatrixEntry->setText("0");
    ui->dynResonEntry->setText("0");
    ui->electronVaporEntry->setText("0");
    ui->emerilEntry->setText("0");
    ui->goldEntry->setText("0");
    ui->gravBallEntry->setText("0");
    ui->heridiumEntry->setText("0");
    ui->heroxEntry->setText("0");
    ui->iridiumEntry->setText("0");
    ui->ironEntry->setText("0");
    ui->microFabricEntry->setText("0");
    ui->murrineEntry->setText("0");
    ui->neutrinoModuleEntry->setText("0");
    ui->nickelEntry->setText("0");
    ui->omegonEntry->setText("0");
    ui->platinumEntry->setText("0");
    ui->plutoniumEntry->setText("0");
    ui->powerCanEntry->setText("0");
    ui->powerGelEntry->setText("0");
    ui->radnoxEntry->setText("0");
    ui->shieldingPlateEntry->setText("0");
    ui->shieldingShardEntry->setText("0");
    ui->suspensionFluidEntry->setText("0");
    ui->thamium9Entry->setText("0");
    ui->titaniumEntry->setText("0");
    ui->unstablePlasmaEntry->setText("0");
    ui->vortexCubeEntry->setText("0");
    ui->warpCellEntry->setText("0");
    ui->zincEntry->setText("0");




}

void Inventory::updateInventory() {
    Inventory::inventory["Carbon"] = (ui->carbonEntry->text()).toInt();
    Inventory::inventory["Aluminium"] = (ui->aluminiumEntry->text()).toInt();
    Inventory::inventory["Antimatter"] = (ui->antimatterEntry->text()).toInt();
    Inventory::inventory["AquaSphere"] = (ui->aquaSphereEntry->text()).toInt();
    Inventory::inventory["Aronium"] = (ui->aroniumEntry->text()).toInt();
    Inventory::inventory["Calium"] = (ui->caliumEntry->text()).toInt();
    Inventory::inventory["Carbon"] = (ui->carbonEntry->text()).toInt();
    Inventory::inventory["Carite Sheet"] = (ui->cariteSheetEntry->text()).toInt();
    Inventory::inventory["Chrysonite"] = (ui->chrysoniteEntry->text()).toInt();
    Inventory::inventory["Copper"] = (ui->copperEntry->text()).toInt();
    Inventory::inventory["Dimensional Matrix"] = (ui->dimMatrixEntry->text()).toInt();
    Inventory::inventory["Dynamic Resonator"] = (ui->dynResonEntry->text()).toInt();
    Inventory::inventory["Electron Vapor"] = (ui->electronVaporEntry->text()).toInt();
    Inventory::inventory["Emeril"] = (ui->emerilEntry->text()).toInt();
    Inventory::inventory["Gold"] = (ui->goldEntry->text()).toInt();
    Inventory::inventory["Gravitino Ball"] = (ui->gravBallEntry->text()).toInt();
    Inventory::inventory["Heridium"] = (ui->heridiumEntry->text()).toInt();
    Inventory::inventory["Herox"] = (ui->heroxEntry->text()).toInt();
    Inventory::inventory["Iridium"] = (ui->iridiumEntry->text()).toInt();
    Inventory::inventory["Iron"] = (ui->ironEntry->text()).toInt();
    Inventory::inventory["Microdensity Fabric"] = (ui->microFabricEntry->text()).toInt();
    Inventory::inventory["Murrine"] = (ui->murrineEntry->text()).toInt();
    Inventory::inventory["Neutrino Module"] = (ui->neutrinoModuleEntry->text()).toInt();
    Inventory::inventory["Nickel"] = (ui->nickelEntry->text()).toInt();
    Inventory::inventory["Omegon"] = (ui->omegonEntry->text()).toInt();
    Inventory::inventory["Platinum"] = (ui->platinumEntry->text()).toInt();
    Inventory::inventory["Plutonium"] = (ui->plutoniumEntry->text()).toInt();
    Inventory::inventory["Power Canister"] = (ui->powerCanEntry->text()).toInt();
    Inventory::inventory["Power Gel"] = (ui->powerGelEntry->text()).toInt();
    Inventory::inventory["Radnox"] = (ui->radnoxEntry->text()).toInt();
    Inventory::inventory["Shielding Plate"] = (ui->shieldingPlateEntry->text()).toInt();
    Inventory::inventory["Shielding Shard"] = (ui->shieldingShardEntry->text()).toInt();
    Inventory::inventory["Suspension Fluid"] = (ui->suspensionFluidEntry->text()).toInt();
    Inventory::inventory["Thamium9"] = (ui->thamium9Entry->text()).toInt();
    Inventory::inventory["Titanium"] = (ui->titaniumEntry->text()).toInt();
    Inventory::inventory["Unstable Plasma"] = (ui->unstablePlasmaEntry->text()).toInt();
    Inventory::inventory["Vortex Cube"] = (ui->vortexCubeEntry->text()).toInt();
    Inventory::inventory["Warp Cell"] = (ui->warpCellEntry->text()).toInt();
    Inventory::inventory["Zinc"] = (ui->zincEntry->text()).toInt();


    //qDebug() << Inventory::inventory["Carbon"];

}


void Inventory::on_updateButton_clicked()
{
    Inventory::updateInventory();
    for (int i = 0; i < 8; i++){
        std::cout << Components[i].name << ": " << Inventory::canMake(Components[i]) << std::endl;
    }
    //std::cout << Inventory::canMake(Components[0]) << std::endl;
}

bool Inventory::canMake(Recipe r)
{
    bool cm = true;
    std::string name1 = std::get<0>(r.element1);
    int req1 = static_cast<int>(std::get<1>(r.element1));
    cm = canMakeIndividual(name1, req1);
    if (cm == 0){return false;}
    std::string name2 = std::get<0>(r.element2);
    if (!name2.empty()){
        int req2 = static_cast<int>(std::get<1>(r.element2));
        cm = canMakeIndividual(name2, req2);
        if (cm == 0){return false;}
        std::string name3 = std::get<0>(r.element3);
        if (!name3.empty()){
            int req3 = static_cast<int>(std::get<1>(r.element3));
            cm = canMakeIndividual(name3, req3);
        }
    }
    return cm;
}


bool Inventory::canMakeIndividual(std::string element, int req)
{
    int have = Inventory::inventory[element];
    if (have < req){return false;}
    else{
        return true;}
}

//extern Inventory w;



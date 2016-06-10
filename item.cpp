//Item.cpp
#include "Item.h"
#include<string>
using namespace std;

void Item::updateName(string Name) {
    this -> Name = Name;
}
void Item::updatePrice(int Price) {
    this -> Price = Price;
}
void Item::updateCost(int Cost) {
	this -> Cost = Cost;
}
void Item::updateSupplier( string Supplier) {
	this -> Supplier = Supplier;
}
string Item::getMonth() {
    return this->currentMonth;
}
string Item::getName() {
    return this->Name;
}
int Item::getCode() {
    return this->Code;
}
int Item::getActualQuantity() {
    return this->actualQuantity;
}
int Item::getDesiredQuantity() {
    return this->desiredQuantity;
}
int Item::getCost() {
    return this->Cost;
}
int Item::getPrice() {
    return this->Price;
}
string Item::getSupplier() {
    return this->Supplier;
}
int Item::getShelflife() {
    return this->shelfLife;
}
int Item::getAverageVolume() {
    return this->averageVolume;
}
double Item::getTotalSales() {
    return this->totalSales;
}
        
void Item::updateWhole(string Month, string Name, int Code, int actualQuantity, 
                 int desiredQuantity, int Cost, int Price, string Supplier, 
                 int shelfLife, int averageVolume, double totalSales) 
{
    this -> currentMonth = Month;
    this -> Name = Name;
    this -> Code = Code;
    this -> actualQuantity = actualQuantity;
    this -> desiredQuantity = desiredQuantity;
    this -> Cost = Cost;
    this -> Price = Price;
    this -> Supplier = Supplier;
    this -> shelfLife = shelfLife;
    this -> averageVolume = averageVolume;
    this -> totalSales = totalSales;
}
void Item::resetSales() {
    this -> totalSales = 0;
}
void Item::updateDesiredQuantity(int desiredQuantity) {
    this -> desiredQuantity = desiredQuantity;
}
void Item::updateActualQuantity(int actualQuantity){
    this -> actualQuantity = actualQuantity;
}
void Item::decreaseActualQuantity() {
    (this -> actualQuantity) --;
}
void Item::increaseSales() {
    (this -> totalSales) += this -> Price;
}
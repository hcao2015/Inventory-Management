//Item.h
#ifndef ITEM_H
#define ITEM_H
#include<string>
#include<cstring>
using namespace std;

class Item {
    private:
        string currentMonth;
        string Name; // item name
        int Code; // the item's unique identification number
        int actualQuantity; // actual quantity of the current month
        int desiredQuantity; // desired quantity of the current month
        int Cost;
        int Price;
        string Supplier;
        int shelfLife;
        int averageVolume; // average volume of the current month
        double totalSales; // total sales in the current month
    public:
    	// these functions take the related values as their names indicate
        string getMonth();
        string getName();
        int getCode();
        int getActualQuantity();
        int getDesiredQuantity();
        int getCost();
        int getPrice();
        string getSupplier();
        int getShelflife();
        int getAverageVolume();
        double getTotalSales();
        // after editing item, it updated in below function
        void updateWhole(string Month, string Name, int Code, int actualQuantity, int desiredQuantity, int Cost, int Price, string Supplier, int shelfLife, 
            int averageVolume, double totalSales);
        void resetSales();
        void updateDesiredQuantity(int desiredQuantity);
        void updateActualQuantity(int actualQuantity);
        void decreaseActualQuantity();
        void increaseSales();
        void updateName(string Name);
        void updatePrice(int Price);
        void updateCost(int Cost);
        void updateSupplier(string Supplier);
};
#endif
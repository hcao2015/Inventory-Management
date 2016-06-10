//Main.cpp
#include<iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include<sstream>
#include<fstream>
#include "Item.h"
using namespace std;

/*******************************************************
*Interaction menu that prompt user to make a choice
*******************************************************/ 
void menu()
{
	cout <<("----Welcome to Grocery's Store Inventory--");
	cout <<("\n=     Main Menu                        =");
	cout <<("\n=   	 0. Exit                          =");
	cout <<("\n=     1. Item Sale                     =");
	cout <<("\n=     2. Daily Report                  =");
	cout <<("\n=     3. Weekly Check                  =");
	cout <<("\n=     4. Monthly Update                =");
	cout <<("\n=     5. Load Inventory File           =");
	cout <<("\n=     6. Sort File by Key              =");
	cout <<("\n=     7. Save Inventory to a File      =");
	cout <<("\n=     8. Add a new Item                =");
	cout <<("\n=     9. Edit an item                  =");
	cout <<("\n=     10.Delete an Item                =");
	cout <<("\n======================================\n");
	cout <<("\n Please select an option from the menu above");
}
vector<Item* > List;
/**********************************************************************
* Menu 1
*  It prompts for an item's unique identification number and quantity sold. 
*  It then updates the associated structure members
**********************************************************************/
void menu1() {
    cout << "Enter identification number: " << endl;
    int ID, quantity;
    cin >> ID;
    cout << "Enter quantity sold: " << endl;
    cin >> quantity;
    for(int i = 0; i < int(List.size()); i ++) {
        if (List[i] -> getCode() == ID) {
            List[i] -> decreaseActualQuantity();
            List[i] -> increaseSales();
        }
    }
}
/**********************************************************************
* Menu 2
*  It  generates a report that prints each item's unique identification 
*  number, name, and current sales total. 
**********************************************************************/
void menu2() {
    cout << "Report: " << endl;
    for(int i = 0; i < int(List.size()); i ++) {
        cout << "Product no. " << i + 1 << ": " << endl;
        cout << "Name: " << List[i] -> getName() << endl;
        cout << "Identification number: " << List[i] -> getCode() << endl;
        cout << "Current Sales: " << List[i] -> getTotalSales() << endl;
    }
}
/**********************************************************************
* Menu 3
*  It determines whether any item is in low supply and issues a warning 
*  message for every such item.  
**********************************************************************/
void menu3() {
    for(int i = 0; i < int(List.size()); i ++) {
        if (List[i] -> getActualQuantity() < List[i] -> getDesiredQuantity()) {
            cout << "Product name " << List[i] -> getName() << ", ID " 
			     << List[i] -> getCode() << " is low in stock. "<< endl;
        }
    }
}
/**********************************************************************
* Menu 4
*  It  prompts for the current month (a character string), the actual quantity 
*    in stock, and the desired quantity in stock. The program then updates the 
*    appropriate structure variables  
**********************************************************************/
void menu4() {
	string Month;
	int actualQuantity, desiredQuantity;
    cout << "Input Month: " << endl;
    cin >> Month;
    cout << "Enter Actual Quantity: " << endl;
    cin >> actualQuantity;
    cout << "Enter desired Quantity: " << endl;
    cin >> desiredQuantity;
    for(int i = 0; i < int(List.size()); i ++) {
        if ((List[i] -> getMonth()) == Month) {
            List[i] -> updateActualQuantity(actualQuantity);
            List[i] -> updateDesiredQuantity(desiredQuantity);
            List[i] -> resetSales();
        }
    }
}
/**********************************************************************
* Menu 5
*  It  prompts for the filename of the inventory file, opens the text file
*  and loads the file into an adjustable size array of pointers to structures  
**********************************************************************/
void menu5(string iFile) {
    ifstream fi;
    fi.open(iFile);
    while (!fi.eof()) {
        string s;
        getline(fi, s);
        istringstream is(s);
        Item * p = new Item;
        string Month, Name, Supplier;
        int Code, actualQuantity, desiredQuantity, Cost, Price;
        int shelfLife, averageVolume;
        double totalSales;
        is >> Month >> Name >> Code >> actualQuantity  
            >> desiredQuantity >> Cost >> Price
            >> Supplier >> shelfLife >> averageVolume
            >> totalSales;
        p->updateWhole(Month, Name, Code, actualQuantity, desiredQuantity, Cost,
				 Price, Supplier, shelfLife,averageVolume, totalSales);
        List.push_back(p);       
    }
    fi.close();
}
/***********************************************************
* Menu 6
*   It prompt the user for the sort key and then use insertion 
*    sort to sort the array of pointers by the given key. 
************************************************************/
void menu6() {
    for(int i = 1; i < int(List.size()); i ++) {
        int j = i;
        while (true) {
            if (List[j] -> getCode() < List[j - 1] -> getCode()) {
                Item * t = List[j - 1];
                List[j - 1] = List[j];
                List[j] = t;
            }
            else break;
            j --;
            if (j <= 0) break;
        }
    }
}
/**********************************************************
* Menu 7
*  It prompts for the new filename and write the objects to 
*   the file in sorted order.
**********************************************************/
void menu7(string oFile) {
	//cout << "here" << endl;
    menu6();
    ofstream fo;
    fo.open(oFile);
    for(int i = 0; i < int(List.size()); i ++) {
        fo << List[i] -> getName() << " " << List[i] -> getActualQuantity() << " "
            << List[i] -> getDesiredQuantity() << " " << List[i] -> getCost()
            << List[i] -> getPrice() << " " << List[i] -> getSupplier()
            << List[i] -> getShelflife() << " " << List[i] -> getAverageVolume() << " " 
            << List[i] -> getTotalSales() << endl;
    }
    fo.close();
}
/**********************************************************
* Menu 8
*  Add new item
**********************************************************/
void menu8() {
    Item * p = new Item;
    string Month, Name, Supplier;
    int Code, actualQuantity, desiredQuantity, Cost, Price;
    int shelfLife, averageVolume;
    double totalSales;
	cout << "\nInput the current month : ";
    cin >> Month;
	cout << "\nInput the item name : ";
	cin >> Name;
	cout << "\nInput the Unique identification code : ";
	cin >> Code;
	cout << "\nInput its actual quantity : ";
	cin >> actualQuantity;
	cout << "\nInput its desired Quantity : ";
	cin >> desiredQuantity;
	cout << "\nInput its cost ";
	cin >> Cost;
	cout << "\nInput the price you will sell : ";
	cin >> Price;
	cout << "\nInput the supplier brand : ";
	cin >> Supplier; 
	cout << "\nInput the shelflife : ";
	cin >> shelfLife;
	cout << "\nInput the average volume and total sales ";
	cin >> averageVolume >> totalSales;
    p->updateWhole(Month, Name, Code, actualQuantity, desiredQuantity, Cost, Price, Supplier, shelfLife, 
            averageVolume, totalSales);
    List.push_back(p);
    
}
/**********************************************************
* Menu 10
*  Delete a item
**********************************************************/
void menu10() {
    cout << "Enter ID to delete: " << endl;
    int ID;
    cin >> ID;
    for(int i = 0; i < int(List.size()); i ++) {
        if (List[i] -> getCode() == ID) {
            List.erase(List.begin() + i);
            break;
        }
    }
}
/**********************************************************
* Menu 9
*  Edit a item
**********************************************************/
void menu9() {
    string Name, Supplier;
    int Price, Cost;
    int ID;
    cout << "Enter ID to edit: " << endl;
    cin >> ID;
    for(int i = 0; i < int(List.size()); i ++) {
        if (List[i] -> getCode() == ID) {
            cout << "Which element do you want to edit? " << endl;
            cout << "1. Name" << endl;
            cout << "2. Price" << endl;
            cout << "3. Cost" << endl;
            cout << "4. Supplier" << endl;
            int input;
            cin >> input;
            if (input == 1) {
                cout << "New Name: " << endl;
                cin >> Name;
                List[i] -> updateName(Name);
            }
            if (input == 2) {
                cout << "New Price: " << endl;
                cin >> Price;
                List[i] -> updatePrice(Price);
            }
            if (input == 3){
            	cout << "New Cost : " << endl;
            	cin >> Cost;
            	List[i] -> updateCost(Cost);
            }
            if (input == 4){
            	cout << "New Supplier: " << endl;
            	cin >> Supplier;
            	List[i] -> updateSupplier(Supplier);
            }
            break;
        }
    }
}

int main()
{
	int choice;
    string fileName;
    ifstream inFile;
	ofstream outFile;
	
	while(1)
	{
   		 menu();
		 cin >> choice;
 		 switch (choice)
 			{
 				case 0: return 0;
 				    break;
 				case 1: menu1();
 				    break;
 				case 2: menu2();
 				    break;
 				case 3: menu3();
 				    break;
 				case 4: menu4();
 				    break;
				case 5:{
					
               		 	cout << "Enter the filename you want to open:" <<endl;
               		 	cin >> fileName;
                		inFile.open(fileName);

                		 if (inFile.fail())
    						{
        						cout << "File not found." << endl;
   							}
    					else
   						    {
        						cout << "Successfully loaded!" << endl;
    							menu5(fileName);
   						    }
						inFile.close();
				       }
   				    break;
   		         case 6: menu6(); 
   		            break;
                 case 7: {
					
               		 	cout << "Enter the filename you want to write to: \n";
               		 	cin >> fileName;
               		 	cout << endl;

                		outFile.open(fileName);

                		 if (outFile == NULL)
    						{
        						cout << "File not found." << endl;
   							}
    					else
   						    {
        						cout << "Successfully loaded!" << endl;
    							menu7(fileName);
   						    }
						outFile.close();
				       }
					break;
                 case 8: menu8();
                    break;
                 case 9: menu9();
                    break;
                 case 10: menu10(); 
                    break;
             }        	
		} 
    return 0;
}
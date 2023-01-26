#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void confirmationYN(int& userInput) {
	char userConfirmation;
	while (true) {
		cout << "Are you sure? (Y/N)\n>";
		cin >> userConfirmation;

		if (userConfirmation == 'Y' || userConfirmation == 'y') {
			break;
		} else if (userConfirmation == 'N' || userConfirmation == 'n') {
			userInput = 0;
			break;
		} else {
			cout << "Invalid. Please only input Y/N!" << endl << endl;
		}
	}
}

void printItem(string items[], double itemsCost[], int sizeOfArray) {
	cout << left; //left alignment
	cout << "List of Items available: " << endl;
	cout << "\t" << setw(20) << "Name of Item" << setw(12) << "Unit Price" << endl;
	cout << "\t" << setw(20) << "------------------" << setw(12) << "-----------" << endl;
	for (int i = 0; i < sizeOfArray; i++) {
		cout << "\t";
		cout << setw(20) << items[i];
		cout << setw(3) << "RM" << setprecision(2) << fixed << itemsCost[i];
		cout << endl;
	}
	cout << endl << endl;
	cout << right; //right alignment	
}

void printCart(char customerName[], string cart[], int cartQuantity[], double cartCost[], double totalCost[], int itemCount) {
	cout << customerName << "'s Cart:" << endl << endl;
	
	cout << left; //left alignment
	cout << setw(6) << "Index" << setw(20) << "Name of Item" << setw(10) << "Quantity" << setw(12) << "Unit Price" << setw(13) << "Total Price" << endl;
	cout << setw(6) << "-----" << setw(20) << "------------------" << setw(10) << "--------" << setw(12) << "-----------" << setw(13) << "------------" << endl;

	for (int i = 0; i < itemCount; i++) {
		cout << left;
		
		//index
		cout << setw(6) << i+1 ;
		//item
		cout << setw(20) << cart[i];
		//quantity
		cout << setw(10) << cartQuantity[i];
		//unit price
		cout << setw(3)<< "RM" << setw(9) << setprecision(2) << fixed << cartCost[i];
		//total price
		cout << setw(3)  << "RM" << setw(6) << setprecision(2) << fixed << totalCost[i];

		cout << endl;
	}
	cout << right; // reset to right
	cout << endl;
		
} 


void printInventory(string items[], double itemsCost[], int inventoryCount){
	cout << left; //left alignment
	cout << setw(6) << "Index" << setw(20) << "Name of Item" << setw(12) << "Unit Price" << endl;
	cout << setw(6) << "-----" << setw(20) << "------------------" << setw(12) << "-----------" << endl;

	for (int i = 0; i < inventoryCount; i++) {
		//index
		cout << setw(6) << i+1 ;
		//item
		cout << setw(20) << items[i] << "\t\t\t";
		//unit price
		cout << setw(3)<< "RM" << setw(9) << setprecision(2) << fixed << itemsCost[i];

		cout << endl;
	}	
	cout << right; //reset to right
}

void displayReceipt(char customer[], int totalQuantity, double totalPrice, double gstAmount, double totalPayment, int customerCount){
	//checking out
	cout << endl << endl;
	cout << "=========================================" << endl;
	cout << "\tSPEED MART TAPAH" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Name of Customer: " << customer << endl;
	cout << "Customer Number: " << customerCount+1 << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
	cout << "****** PAYMENT SUMMARY ********" << endl;
	cout << endl;
	cout << "ITEM COUNT\t: " << totalQuantity << endl;
	cout << "PRICE\t\t: RM" << setprecision(2) << fixed << totalPrice << endl;
	cout << "GST\t\t: RM" << setprecision(2) << fixed << gstAmount << endl;
	cout << "-----------------------------------------" << endl;
	cout << "NET AMOUNT\t: RM" << setprecision(2) << fixed << totalPayment << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl << endl;

	cout << "*** THANKS YOU FOR VISITING ***" << endl << endl;
	
	cout << "-----------------------------------------" << endl;
	cout << "Press any key to continue..";
	system("pause>0");	
	
}

void displayFinal(char customer[][30], int customerCount, int quantity[], double netAmount[]){
	//final display
	double profit = 0, GST = 0, totalProfit;
	
	cout << endl << endl;
	cout << "================================================================" << endl;
	cout << "\t\t\tSPEED MART TAPAH" << endl;
	cout << "----------------------------------------------------------------" << endl;		
	cout << endl;
	cout << "\t*********** TODAY'S SUMMARY *************" << endl << endl;
	cout << "Total Customer: " << customerCount << endl;
	cout << "--------------" << endl;
	cout << endl;
		
	cout << left; //left alignment
	cout << setw(6) <<  "Index" << setw(30) << "Name" << setw(15)<< "Item Bought" << setw(16) <<"Total Paid" << endl;
	cout << setw(6) <<  "-----" << setw(30) << "------------------------" << setw(15)<< "----------" << setw(16) <<"-----------" << endl;
	for (int i = 0; i < customerCount; i++){
		//index
		cout << setw(6) << i+1 ;
		//customer name
		cout << setw(30) << customer[i];
		//quantity
		cout << setw(15) <<  quantity[i];
		//amount paid
		cout << setw(3) << "RM" << setprecision(2) << fixed << netAmount[i] << endl;
		
		//counts the total
		profit += netAmount[i];
	}
	//arithmetic
	GST = profit * 6 / 100;
	totalProfit = profit - GST;
	//output
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;	
	cout << "REVENUE   \t\t\t\t\t: RM" << profit << endl;
	cout << "GST   \t\t\t\t\t\t: RM" << GST << endl;
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;	
	cout << "TOTAL REVENUE   \t\t\t\t: RM" << totalProfit << endl;
	cout << endl;		
	cout << "----------------------------------------------------------------" << endl;	
	cout << endl ;	
	cout << "\t****** THANK YOU FOR YOUR HARDWORK ******" << endl;
	cout << endl;
	cout << "\t\t  YOU MAY GO HOME NOW!" << endl << endl;
	cout << "\t=========================================" << endl;
}

void displayStart(){
	cout << "***** Super-Market Management System ***** ~ Created by GROUP1";
	cout << endl << endl;
	cout << "============ SPEED MART TAPAH's MANAGEMENT SYSTEM ============" << endl;
}
//very epic functions

string lowerCase(string str){
	//lower casing
	for (int i = 0; i < str.length(); i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

bool compareString(string input, string original){
	if (lowerCase(input) == lowerCase(original)){
		return true;
	}
	return false;
}

int main() {
	//supermarket management system 
	char customerName[100][30];
	//items available at supermarket
	string items[100] = {"Milk","Cheese", "Cake", "Meat", "Bread", "Potato", "Banana", "Fruit", "Eggs", "Rice"}; //initializing
	double itemsCost[100] = {3.60, 4.50, 10.30, 5.20, 2.40, 0.50, 0.80, 1.20, 0.90, 20.10};
	//cart (storage)
	string cart[100];
	int cartQuantity[100];
	double cartCost[100], totalCost[100];
	//input 
	int userInput, inputQuantity, inputIndex;
	string inputItem;
	//output
	double price, GST;
	double netAmount[100];
	int quantityTotal[100];
	
	//others
	int itemCount = 0, customerCount = 0;
	
	//admin route var
	double inputPrice;
	int inventoryCount = 10; //size of items
	
	//Start Menu
	do{
		//reset variables (arrays don't need to be reset, we can overwrite it)
		price = 0, GST = 0, itemCount = 0;
		//end
		displayStart();
		
		cout << endl;
		
		cout << "[MAIN MENU]:" << endl;
		cout << "\t1. Customer" << endl;
		cout << "\t2. Administrator" << endl;
		cout << "\t3. Exit Program" << endl;
		cout << endl;
		
		cout << "> ";
		cin >> userInput;
		cout << endl;
		cin.ignore(256, '\n');
		
		//clears screen
		system("cls");
		if (userInput == 1){
			displayStart();
			
			cout << endl;
			//customer route
			cout << "------------------CUSTOMER------------------" << endl;
			cout << "Please enter your name here: ";
			cin.getline(customerName[customerCount], 30);		
			cout << endl;
			cout << "-------------------------------------------";
			cout << endl;
			//clears screen
			system("cls");
			//customer route loop
			do {
				displayStart();
				
				cout << endl;
				cout << "What would you like to do?: " << endl;
				cout << "\t1. Add Item to Cart." << endl;
				cout << "\t2. Remove Item from Cart." << endl;
				cout << "\t3. Your shopping Cart." << endl;
				cout << "\t4. Checkout." << endl;
				cout << endl;
		
				cout << "> ";
				cin >> userInput;
				cout << endl;
		
				//Add item
				if (userInput == 1) {
					cout << "-------------------------------------------" << endl;
					//prints items in supermarket
					printItem(items, itemsCost, inventoryCount);
					//ignore
					cin.ignore(256, '\n');
					//user input
					cout << "Enter the name of Item " << itemCount+1 << ": ";
					getline(cin, inputItem);
					
					//check if item exist in inventory
					bool validItem = false;
					for (int i = 0; i < inventoryCount; i++) {
						if (compareString(inputItem, items[i])) {
							validItem = true;
							//add to cart
							cart[itemCount] = items[i];
							cartCost[itemCount] = itemsCost[i];
							break;
						}
					}
					if (validItem != true) {
						cout << endl;
						cout << "Invalid item." << endl;
						cout << "Press any key to continue..";
						system("pause>0");
						//clears screen
						system("cls");
						continue;
					}
					
					cout << "Enter Item's quantity: ";
					cin >> inputQuantity;
		
					//check quantity
					if (inputQuantity < 0) {
						cout << endl;
						cout << "Invalid quantity." << endl;
						cout << "Press any key to continue..";
						system("pause>0");
						//clears screen
						system("cls");
						continue;
					}
		
					//save quantity and cost
					cartQuantity[itemCount] = inputQuantity;
					totalCost[itemCount] = cartQuantity[itemCount] * cartCost[itemCount];
		
					//increments item count
					itemCount++;
		
					cout << endl;
					//print Cart!
					printCart(customerName[customerCount], cart, cartQuantity, cartCost, totalCost, itemCount);
					cout << "-------------------------------------------" << endl;
					cout << "Press any key to continue..";
					system("pause>0");
		
				}
				//remove
				else if (userInput == 2) {
					cout << "-------------------------------------------" << endl;
					printCart(customerName[customerCount], cart, cartQuantity, cartCost, totalCost, itemCount);
					cout << endl << endl;
					//removes according to index
					cout << "Enter the index of the Item you'd like to remove: ";
					cin >> inputIndex;
		
					//check if index exist (max index is itemCount+1)
					if (inputIndex <= 0 || inputIndex > itemCount) {
						cout << endl;
						cout << "Invalid index." << endl;
						cout << "Press any key to continue..";
						system("pause>0");
						//clears screen
						system("cls");
						continue;
					}
		
					//remove item from list by displacing it
					for (int i = inputIndex; i < itemCount; i++) {
						cart[i-1]=cart[i];
						cartQuantity[i-1]= cartQuantity[i];
						cartCost[i-1] = cartCost[i];
						totalCost[i-1] = totalCost[i];
					}
					//deduct itemCount
					itemCount--;
					
					cout << endl;
					cout << "-------------------------------------------" << endl;
					cout << endl;
					//print Cart!
					printCart(customerName[customerCount], cart, cartQuantity, cartCost, totalCost, itemCount);
					cout << "-------------------------------------------" << endl;
					cout << "Press any key to continue..";
					system("pause>0");
		
				}
				//check cart
				else if (userInput == 3) {
					//print Cart!
					printCart(customerName[customerCount], cart, cartQuantity, cartCost, totalCost, itemCount);
					cout << "-------------------------------------------" << endl;
					cout << "Press any key to continue..";
					system("pause>0");
				}
				//check out confirmation
				else if (userInput == 4) {
					confirmationYN(userInput);
				}
				//clears screen
				system("cls");
			} while(userInput != 4);
			//arithmetic..? (it's just increments)
			int totalQuantity = 0;
			for (int i = 0; i < itemCount; i++) {
					price += totalCost[i];
					totalQuantity += cartQuantity[i];
				}
			GST = price * (6.0/100.0);
			
			//for final print
			netAmount[customerCount] = price + GST;
			quantityTotal[customerCount] = totalQuantity;
			
			//checking out
			displayReceipt(customerName[customerCount], quantityTotal[customerCount], price, GST, netAmount[customerCount], customerCount);
			//increments customer
			customerCount++;
			//end customer
		}
		else if (userInput == 2){
			displayStart();
			cout << endl;
			//admin route
			cout << "---------------ADMINISTRATOR----------------" << endl;
			cout << "Press any key to continue..";
			system("pause>0");
			//clears screen
			system("cls");
			//admin route loop
			do {
				displayStart();
				
				cout << endl;
				cout << "What would you like to do?: " << endl;
				cout << "\t1. Add Item to Inventory." << endl;
				cout << "\t2. Remove Item from Inventory." << endl;
				cout << "\t3. View Store Inventory." << endl;
				cout << "\t4. Exit." << endl;
				cout << endl;
		
				cout << "> ";
				cin >> userInput;
				cout << endl;
		
				//Add item to inventory
				if (userInput == 1) {
						cout << "-------------------------------------------" << endl;
						//ignore()
						cin.ignore(256, '\n');
						//user input
						cout << "Set the name of Item " << inventoryCount+1 << ": ";
						getline(cin, inputItem);
						
						//check if item exist in inventory
						bool validItem = true;
						for (int i = 0; i < inventoryCount; i++) {
							if (compareString(inputItem, items[i])  || inputItem.length() > 20) {
								validItem = false;
								break;
							}
						}
						if (validItem != true) {
							cout << endl;
							cout << "Invalid Item. The Item's' name is either too long or it already exists." << endl;
							cout << "Press any key to continue..";
							system("pause>0");
							//clears screen
							system("cls");
							continue;
						}
						
						cout << "Set Item's price: ";
						cin >> inputPrice;
		
						//check price
						if (inputPrice < 0) {
							cout << endl;
							cout << "Invalid price!" << endl;
							cout << "Press any key to continue..";
							system("pause>0");
							//clears screen
							system("cls");
							continue;
						}
		
						
						//save cost
						items[inventoryCount] = inputItem;
						itemsCost[inventoryCount] = inputPrice;
						
						//increment
						inventoryCount++;
		
						cout << endl;
						//print inventory
						printInventory(items, itemsCost, inventoryCount);
						cout << "Press any key to continue..";
						system("pause>0");
		
					}
				//remove item to inventory
				else if (userInput == 2) {
						cout << "-------------------------------------------" << endl;
						printInventory(items, itemsCost, inventoryCount);
						cout << endl;
						//removes according to index
						cout << "Enter the index of the Item you'd like to remove: ";
						cin >> inputIndex;
		
						//check if index exist 
						if (inputIndex <= 0 || inputIndex > inventoryCount) {
							cout << endl;
							cout << "Invalid index." << endl;
							cout << "Press any key to continue..";
							system("pause>0");
							//clears screen
							system("cls");
							continue;
						}
		
						//remove item from list by displacing it
						for (int i = inputIndex; i < inventoryCount; i++) {
							items[i-1]=items[i];
							itemsCost[i-1] = itemsCost[i];
						}
						//deduct 
						inventoryCount--;
		
						cout << endl;
						//print inv!
						printInventory(items, itemsCost, inventoryCount);
						cout << "Press any key to continue..";
						system("pause>0");
					}
				//check inventory
				else if (userInput == 3) {
					//print inv!
					printInventory(items, itemsCost, inventoryCount);
					cout << "Press any key to continue..";
					system("pause>0");
				}
				//exit confirmation
				else if (userInput == 4) {
						confirmationYN(userInput);
				}
				//clears screen
				system("cls");
			} while(userInput != 4);
			//exiting
			cout << "============================================" << endl;
			cout << endl;
		}
		else if (userInput == 3){
			displayStart();
			cout << endl;
			confirmationYN(userInput);
		}	
		//clears screen
		system("cls");
	} while (userInput != 3);
	//Exit Program
	displayFinal(customerName, customerCount, quantityTotal, netAmount);
	
	system("pause<0");
	return 0;
}

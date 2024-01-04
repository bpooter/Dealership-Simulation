#include <iostream>
#include "Car.cpp"

using namespace std;
//added the option to add things to Service side of dealership. I know it wasn't in the write up but thought it would be cool to have 2 lots separate

//declaring static variables to control lot size
static int lotSize = 20;

static int serviceSize = 20;

static int currentLot = 0;

static int currentService = 0;

//function prototypes
void displayMenu(bool firstChoice);

void menu();

void addCar(CarForSale carsOnLot[], CarForService carsInService[]);

void updateCar(CarForSale carsOnLot[]);

void displayAll(CarForSale carsOnLot[], CarForService carsInService[]);

void displayChoice(CarForSale carsOnLot[], int choice);

void displayAverageMileageOfSales(CarForSale carsOnLot[]);

void viewCarOnSale(CarForSale carsOnLot[]);

void populateDealer(CarForSale carsOnLot[], CarForService carsInService[]);

void swap(CarForSale &car1, CarForSale &car2);

void bubbleSort(CarForSale carsOnLot[], int currentLot);

int main()
{   
    menu();
}

void displayMenu(bool firstChoice)
{   
        if (firstChoice)
        {
            cout << "Welcome to our dealership choose what you would like to do from the choices below\n";
    
    cout << "\n------------------------\n1 to Add a car to inventory\n\n2 to Update a car on lot\n\n3 to See information about a car\n\n4 to display information about all cars on lot"
            "\n\n5 to see the average mileage for all cars on our lot\n\n6 to see the lowest priced car on the lot\n\n7 view a car that is on sale\n\n8 to check the status of your car in service\n------------------------\n";
        }
        else
        {   
            cout << "\n------------------------\nWould you like to make another selection? -1 to end------------------------\n" << endl;
            cout << "\n1: Add a car\n\n2: Update a car\n\n3: See information about a car\n\n4: Display all cars on lot"
            "\n\n5: See average mileage for all cars on lot\n\n6: See lowest priced car\n\n7: View car that is on sale\n\n8: Status of your car in service\n";
        }
    
}

void menu()
{   int input, choice;
    bool firstChoice = true;
    
    CarForSale carsOnLot[20];
    CarForService carsInService[20];
    
    populateDealer(carsOnLot, carsInService);
    
    cout << "Welcome to our dealership choose what you would like to do from the choices below\n";
    
    displayMenu(firstChoice);
    
    cin >> input;

    while (input != -1)
    {
        switch (input)
        {
            case 1:
                firstChoice = false;
                addCar(carsOnLot, carsInService);
                break;

            case 2:
                firstChoice = false;
                updateCar(carsOnLot);
                break;

            case 3:
                firstChoice = false;
                cout << "Which vehicle would you like to see on the lot?\nEnter a number of 1 - " << currentLot << endl;
                cin >> choice;
                displayChoice(carsOnLot, choice);
                break;

            case 4:
                firstChoice = false;
                displayAll(carsOnLot, carsInService);
                break;

            case 5:
                firstChoice = false;
                displayAverageMileageOfSales(carsOnLot);
                break;
            
            case 6:
                firstChoice = false;
                bubbleSort(carsOnLot, currentLot);
                cout << "The cheapest car is " << endl;
                carsOnLot[0].displayCar();
                break;

            case 7:
                firstChoice = false;
                viewCarOnSale(carsOnLot);
                break;
            
            case 8:
                firstChoice = false;
                cout << "Enter the number of vehicle you are searching for we have " << currentService << " vehicles in service.\n";
                cin >> choice;
                carsInService[choice-1].displayCar();
                break;
        }
        
        displayMenu(firstChoice);
        cin >> input;
    }

    cout << "Thank you for working with us today" << endl;
}

void addCar(CarForSale carsOnLot[], CarForService carsInService[])
{   bool errorOccured = true;
    int choice;
    string vin;
    string make;
    string model;
    int year;
    int mileage;
    double price;
    string ownerName;
    bool onSale = false;
    double discount = 0.0;
    bool ready = false;

    cout << "Will you be adding a car to the lot or the service? 1 for lot\n2 for service" << endl;
    cin >> choice;

    if (choice == 1)
    {   
        cout << "Enter the Vin of the car\n";
        cin >> vin;
        
        cout << "Enter the make of the car\n";
        cin >> make;
        
        cout << "Enter the model of the car\n";
        cin >> model;
        
        cout << "Enter the year of the car\n";
        cin >> year;
        
        cout << "Enter the mileage of the car\n";
        cin >> mileage;
        
        cout << "Enter the price of the car\n";
        cin >> price;

        CarForSale car(vin, make, model, year, mileage, price, onSale, discount);
        carsOnLot[currentLot] = car;
        currentLot++;
    }
    else if (choice == 2)
    {   
        cout << "Enter the Vin of the car\n";
        cin >> vin;
        
        cout << "Enter the make of the car\n";
        cin >> make;
        
        cout << "Enter the model of the car\n";
        cin >> model;
        
        cout << "Enter the year of the car\n";
        cin >> year;
        
        cout << "Enter the mileage of the car\n";
        cin >> mileage;
        
        cout << "Enter the owners name\n";
        cin >> ownerName;

        CarForService car(vin, make, model, year, mileage, ownerName, ready);
        carsInService[currentService] = car;        
        currentService++;
    }
    else
    {
        cout << "Error returning to main menu" << endl;
        displayMenu(errorOccured);
    }
}

void displayAll(CarForSale carsOnLot[], CarForService carsInService[])

{   
    int input;

    cout << "Enter 1 to see all cars for sale\nEnter 2 to see all cars in service\n";
    cin >> input;

    CarForSale * pSaleCars = &carsOnLot[0];
    CarForService *pServiceCars = &carsInService[0];

    if (input == 1)
    { 
        for (int i = 0; i < currentLot; i++)
        {   
            (*(pSaleCars)).displayCar();
            * pSaleCars ++;
        }
        
    }
    else if (input == 2)
    {
        for (int i = 0; i < currentService; i++)
        {
            (*(pServiceCars)).displayCar();
            * pServiceCars ++;
        }
    }
}

void populateDealer(CarForSale carsOnLot[], CarForService carsInService[])

{   
    CarForSale car1("9597989085", "Kia", "Rio", 2015, 4574, 9550.0, true, 800.0);
    CarForSale car2("3524161461", "Hyundai", "Sonata", 2019, 13598, 12650.0, false, 0.0);
    CarForSale car3("1213456789", "Honda", "Odyssey", 2019, 13598, 22850.0, false, 0.0);
    CarForSale car4("3789316981", "Dodge", "Ram", 2019, 98505, 42399.0, true, 1500.0);
    CarForSale car5("4561781387", "Chevrolet", "Traverse", 2020, 10111, 42599.0, false, 0.0);
    CarForSale car6("1345789251", "Chevrolet", "Silverado", 2007, 215002, 8999.0, true, 500.0);
    CarForSale car7("4981378181", "Pontiac", "G8", 2007, 103598, 19199.0, false, 0.0);
    CarForSale car8("7235787831", "GMC", "Denali", 2021, 23100, 62999.0, false, 0.0);
    CarForSale car9("7123158767", "Porsche", "911", 2022, 1398, 122988.0, true, 2988.0);

    CarForService serviceCar1("1042152613", "Honda", "Civic", 2021, 13123, "Johnson", true);
    CarForService serviceCar2("1114154321", "VW", "Golf", 2005, 312241, "Settle", false);
    CarForService serviceCar3("3523612931", "Dodge", "Dart", 2019, 33764, "Richards", true);
    CarForService serviceCar4("8755094709", "BMW", "i8", 2017, 33219, "Davidson", true);
    CarForService serviceCar5("6875694773", "VW", "Passat", 2009, 313749, "Yamata", false);
    CarForService serviceCar6("1534285976", "Chrysler", "300C", 2008, 343203, "Gill", true);
    
    carsOnLot[currentLot] = car1;
    currentLot++;
    carsOnLot[currentLot] = car2;
    currentLot++;
    carsOnLot[currentLot] = car3;
    currentLot++;
    carsOnLot[currentLot] = car4;
    currentLot++;
    carsOnLot[currentLot] = car5;
    currentLot++;
    carsOnLot[currentLot] = car6;
    currentLot++;
    carsOnLot[currentLot] = car7;
    currentLot++;
    carsOnLot[currentLot] = car8;
    currentLot++;
    carsOnLot[currentLot] = car9;
    currentLot++;

    carsInService[currentService] = serviceCar1;
    currentService++;
    carsInService[currentService] = serviceCar2;
    currentService++;
    carsInService[currentService] = serviceCar3;
    currentService++;
    carsInService[currentService] = serviceCar4;
    currentService++;
    carsInService[currentService] = serviceCar5;
    currentService++;
    carsInService[currentService] = serviceCar6;
    currentService++;
}

void displayChoice(CarForSale carsOnLot[], int choice)
{
    carsOnLot[choice-1].displayCar();
}

void displayAverageMileageOfSales(CarForSale carsOnLot[])
{
    int totalMiles = 0;
    double averageMiles;   
        
        for (int i = 0; i < currentLot; i++)
        {
            totalMiles = totalMiles + carsOnLot[i].getMileage();
        }
    averageMiles = totalMiles / currentLot;

    cout << "The average mileage for the lot is " << averageMiles <<" miles." << endl;
}

void updateCar(CarForSale carsOnLot[])
{   
    bool firstChoice = false;
    int choice, updateChoice, updatedValue;
    string updatedString;
    double discount;
    cout << "Enter the number of the car you would like to update.\nWe currently have " << currentLot << " cars on the lot.\n";
    cin >> choice;

    CarForSale * pCar = &carsOnLot[choice-1];
    cout << "What would you like to change?\n1 for VIN\n2 for Make\n3 for Model\n4 for Year\n5 for Mileage\n6 for price\n7 for On-Sale Status\n-1 to end this screen" << endl;
    cin >> updateChoice;

    while (updateChoice != -1)
    {
        switch (updateChoice)
        {
            case 1:
                cout << "Enter the new VIN number:\n";
                cin >> updatedString;
                (*(pCar)).setVin(updatedString);
                break;
            
            case 2:
                cout << "Enter the new Make:\n";
                cin >> updatedString;
                (*(pCar)).setMake(updatedString);
                break;
            
            case 3:
                cout << "Enter the new Model:\n";
                cin >> updatedString;
                (*(pCar)).setModel(updatedString);
                break;
            
            case 4:
                cout << "Enter the new Year:\n";
                cin >> updatedValue;
            
                if ((*(pCar)).setYear(updatedValue) == false)
                {
                    cout << "There was an error updating the year" << endl;
                    cout << "Returning to main menu" << endl;
                    return;
                } 
                
                else 
                {
                    cout << "Updated Year successfully\nIf you would like to update another Value enter 1 Or -1 to go to main menu" << endl;
                    cin >> updateChoice;
                    
                    if (updateChoice == -1)
                    {
                        return;
                    }
                    
                    else
                    {
                        cout << "What would you like to change?\n1 for VIN\n2 for Make\n3 for Model\n4 for Year\n5 for Mileage\n6 for price\n7 for On-Sale Status\n-1 to end this screen" << endl;
                        cin >> updateChoice;
                        break;
                    }
                }
                
                break;
            
            case 5:
                cout << "Enter the new Mileage:\n";
                cin >> updatedValue;
                
                if ((*(pCar)).setMileage(updatedValue) == false)
                {
                    cout << "There was an error updating the mileage" << endl;
                    cout << "Returning to main menu" << endl;
                    return;
                } 
                
                else 
                {
                    cout << "Updated Mileage successfully\nIf you would like to update another Value enter 1 Or -1 to go to main menu" << endl;
                    cin >> updateChoice;
                    
                    if (updateChoice == -1)
                    {
                        return;
                    }
                    
                    else
                    {
                        cout << "What would you like to change?\n1 for VIN\n2 for Make\n3 for Model\n4 for Year\n5 for Mileage\n6 for price\n7 for On-Sale Status\n-1 to end this screen" << endl;
                        cin >> updateChoice;
                    break;
                    }               
                }
                break;
            
            case 6:
                
                cout << "Enter the new Price:\n";
                cin >> updatedValue;
                
                if ((*(pCar)).setPrice(updatedValue) == false)
                {
                    cout << "There was an error updating the price" << endl;
                    cout << "Returning to main menu" << endl;
                    return;
                } 
                else 
                {
                    cout << "Updated Price successfully\nIf you would like to update another Value enter 1 Or -1 to go to main menu" << endl;
                    cin >> updateChoice;
                    
                    if (updateChoice == -1)
                    {
                        return;
                    }
                    
                    else
                    {
                        cout << "What would you like to change?\n1 for VIN\n2 for Make\n3 for Model\n4 for Year\n5 for Mileage\n6 for price\n7 for On-Sale Status\n-1 to end this screen" << endl;
                        cin >> updateChoice;
                        break;
                    }               
                break;
                }

                case 7:
                        cout << "Enter 1 to put this car on sale or 2 to take it off sale" << endl;
                        cin >> updateChoice;
                        if (updateChoice == 1)
                        {   
                            if ((*(pCar)).getOnSale() == true)
                            {
                                cout << "This vehicle is already dicounted" << endl;
                                return;
                            }
                            else 
                            {
                                (*(pCar)).setOnSale(true);
                                cout << "Enter the amount you would like to discount this vehicle" << endl;
                                cin >> discount;
                                (*(pCar)).setDiscount(discount);
                                return;
                            }
                        }
                        else
                        {
                            (*(pCar)).setOnSale(false);
                            return;
                        }
                    break;
        }
    }
}

void bubbleSort(CarForSale carsOnLot[], int currentLot)
{   
    int maxElement;
    int index;

    for(maxElement = currentLot - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (carsOnLot[index].getPrice() > carsOnLot[index + 1].getPrice())
            {
                swap(carsOnLot[index], carsOnLot[index + 1]);
            }
        }
    }
}

void viewCarOnSale(CarForSale carsOnLot[])
{   
    int numOfCarsOnSale = 0;
    for (int i = 0; i < currentLot; i++)
    {
        if (carsOnLot[i].getOnSale() == true)
        {   
            numOfCarsOnSale++;
            carsOnLot[i].displayCar();
        }
        else if (numOfCarsOnSale == 0)
        {
            cout << "No cars currently on sale" << endl;
        }
    }
}

void swap(CarForSale &car1, CarForSale &car2)
{
    CarForSale temp = CarForSale();
    temp = car1;
    car1 = car2;
    car2 = temp;
}
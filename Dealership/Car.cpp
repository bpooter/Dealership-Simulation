#include <iostream>

using namespace std;
//base class of car
class Car
{
    protected:
        string internalVin = "";
        string internalMake = "";
        string internalModel = "";
        int internalYear = 0;
        int internalMileage = 0;

    public:
        Car(){}
        Car(string vin, string make, string model, int year, int mileage)
        {
            this->internalVin = vin;
            this->internalMake = make;
            this->internalModel = model;
            setYear(year);
            setMileage(mileage);
        }

        void setVin(string vin)
        {
            this->internalVin = vin;
        }

        void setMake(string make)
        {
            this->internalMake = make;
        }

        void setModel(string model)
        {
            this->internalModel = model;
        }

        bool setYear(int year)
        {
            bool validYear = true;
            if (year > 1950)
            {
                this->internalYear = year;
            }
            else
            { 
            validYear = false;
            }
            
            return validYear;
        }

        bool setMileage(int mileage)
        {
            bool validMiles = true;

            if (mileage > 0)
            {
                this->internalMileage = mileage;
            }
            else
            {
                validMiles = false;
            }
            return validMiles;
        }

        string getVin()
        {
            return internalVin;
        }

        string getMake()
        {
            return internalMake;
        }

        string getModel()
        {
            return internalModel;
        }

        int getYear()
        {
            return internalYear;
        }

        int getMileage()
        {
            return internalMileage;
        }

        void virtual displayCar() = 0;

};
//car for sale that inherits from base car
class CarForSale:public Car
{
    private:
        double internalPrice = 0.0;
        bool internalOnSale = false;
        double internalDiscount = 0.0;
    
    public:
        CarForSale(){}
        CarForSale(string vin, string make, string model, int year, int mileage, double price, bool onSale, double discount):Car(vin, make, model, year, mileage)
        {
            setPrice(price);
            this->internalOnSale = onSale;
            setDiscount(discount);

        }
        bool setPrice(double price)
        {   
            bool validPrice = true;

            if (price >5000)
            {
                this->internalPrice = price;
            }
            else
            {
                validPrice = false;
            }
            return validPrice;
        }

        double getDiscount()
        {
            return internalDiscount;
        }

        void setDiscount(double discount)
        {   
            double discountedPrice;
            if (internalOnSale == false)
            {
                this->internalDiscount = 0.0;
            }
            else 
            {
                discountedPrice = internalPrice - discount;
                bool validInternalPrice = setPrice(discountedPrice);
                if (validInternalPrice == true)
                {
                    this->internalDiscount = discount;
                }
                else
                {
                    cout << "There was an error setting the discount" << endl;
                }
            }
        }

        double getPrice()
        {
            return internalPrice;
        }

         void setOnSale(bool onSale)
        {
            this->internalOnSale = onSale;
        }

        bool getOnSale()
        {
            return internalOnSale;
        }

        void virtual displayCar()
        {
            if (internalOnSale)
            {
            cout << "\n\n-------Manager Special!!!-------\n\nVin: " << internalVin << "\nMake: " << internalMake << "\nModel: " << internalModel << "\nYear: " << internalYear << "\nMileage: " << internalMileage << "\nPrice: $" << internalPrice << "\nNow marked down : $" << internalDiscount <<"\n\n------------------------\n\n\n";
            }
            else
            {
                cout << "Vin: " << internalVin << "\nMake: " << internalMake << "\nModel: " << internalModel << "\nYear: " << internalYear << "\nMileage: " << internalMileage << "\nPrice: " << internalPrice << "\n\n";
            }
        }
};
//car for service that inherits from base car
class CarForService:public Car
{
    private:
        string internalOwnerName = "";
        bool inService = true;

    public:
        CarForService(){}
        CarForService(string vin, string make, string model, int year, int mileage, string ownerName, bool service):Car(vin, make, model, year, mileage)
        {
            this->internalOwnerName = ownerName;
            this->inService = service;
        }

        void setService(bool service)
        {
            this->inService = service;
        }

        bool getServiceStatus()
        {
            return inService;
        }
        
        void setOwnerName(string ownerName)
        {
            this->internalOwnerName = ownerName;
        }
        string getOwnerName()
        {
            return internalOwnerName;
        }
        void virtual displayCar()
        {   
            if (inService == false)
            {
                cout << "Vin: " << internalVin << "\nMake: " << internalMake << "\nModel: " << internalModel << "\nYear: " << internalYear << "\nMileage: " << internalMileage << "\nOwner Name: " << internalOwnerName << "\nStatus: In Shop\n\n";    
            }
            else
            {
            cout << "Vin: " << internalVin << "\nMake: " << internalMake << "\nModel: " << internalModel << "\nYear: " << internalYear << "\nMileage: " << internalMileage << "\nOwner Name: " << internalOwnerName << "\nStatus: Ready For Pickup\n\n";
            }
        }
};
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Medicine
{
    private:
        double priceInDollars;
        int quantityOfTablets;
        string name;
        int expirationYear;
        bool isPrescriptionNeeded;

    public:
        void SetPriceInDollars(double newPrice)
        {
            priceInDollars = newPrice;
        }

        double GetPriceInDollars()
        {
            return priceInDollars;
        }
        int GetQuantityOfTablets() 
        {
            return quantityOfTablets;
        }
        string GetName() 
        {
            return name;
        }
        int GetExpirationDate() 
        {
            return expirationYear;
        }
        bool GetIsPrescriptionNeeded() 
        {
            return isPrescriptionNeeded;
        }

    Medicine(double priceInDollars, int quantityOfTablets, string name, int expirationYear, bool isPrescriptionNeeded)
    {
        this->priceInDollars = priceInDollars;
        this->quantityOfTablets = quantityOfTablets;
        this->name = name;
        this->expirationYear = expirationYear;
        this->isPrescriptionNeeded = isPrescriptionNeeded;
    }
    
    void Print() 
    {
            cout << endl;
            cout << "Price in dollars: " << priceInDollars << endl;
            cout << "Guantity of tablets: " << quantityOfTablets << endl;
            cout << "Medicine name: " << name << endl;
            cout << "Experation date: " << expirationYear << endl;
            cout << "Is prescription needed: " << isPrescriptionNeeded << endl;
    }
    
    ~Medicine() {};
};

class Pharmacy
{
private:
    string name;
    list<Medicine*> medications;
public:
    string GetPharmacyName() 
    {
        return name;
    }

    list<Medicine*> GetMedicationList()
    {
        return medications;
    }

    Pharmacy() {};
    Pharmacy(string name)
    {
        this->name = name;
    }

    void AddMedication(Medicine* m)
    {
        this->medications.push_back(m);
    }

    void DeleteOldMedications()
    {
        list<Medicine*>::iterator i = medications.begin();
        while (i != medications.end())
        {
            if ((*i)->GetExpirationDate() <= 2022)
            {
                medications.erase(i++);
            }
            else
            {
                ++i;
            }
        }
    }


    void Print() 
    {
        cout << endl;
        cout << "Pharmacy Firm: " << name << endl;
        for (auto med : medications) 
        {
            med->Print();
        }
    }

    double FindLowestPrice() 
    {
        double lowestPrice = medications.front()->GetPriceInDollars();
        for (auto i = medications.begin(); i != medications.end(); ++i) 
        {
            if ((*i)->GetPriceInDollars() < lowestPrice) 
            {
                lowestPrice = (*i)->GetPriceInDollars();
            }
        }

        return lowestPrice;
    }

    void RedusePriceBy10Persent()
    {
        for(auto i = medications.begin(); i != medications.end(); ++i)
        {
            double newPriceInDollars = (*i)->GetPriceInDollars() * 0.9;
            (*i)->SetPriceInDollars(newPriceInDollars);
        }
    }

    ~Pharmacy() {};
};


int main() 
{
    Medicine* ibuprofen = new Medicine(20.5, 60, "Ibuprofen", 2023, false);
    Medicine* copacyl = new Medicine(50, 120, "Copacyl", 2024, false);
    Medicine* nospa = new Medicine(15.75, 100, "Nospa", 2025, false);
    Medicine* paracylamol = new Medicine(27, 30, "Paracylamol", 2021, true);
    Medicine* veleriana = new Medicine(45, 200, "Veleriana", 2020, false);

    Pharmacy* pharmacy = new Pharmacy("DS");

    pharmacy->AddMedication(ibuprofen);
    pharmacy->AddMedication(copacyl);
    pharmacy->AddMedication(nospa);
    pharmacy->AddMedication(paracylamol);
    pharmacy->AddMedication(veleriana);

    pharmacy->Print();
    cout << "______________________________________________" << endl;
    cout << "Lowest Price: " << pharmacy->FindLowestPrice() << endl;

    cout << "______________________________________________" << endl;
    cout << "Redusing price by 10%: " << endl;
      
    pharmacy->RedusePriceBy10Persent();

    pharmacy->Print();

    cout << "______________________________________________" << endl;
    cout << "List of medications after deleting expiered ones:  " << endl;

    pharmacy->DeleteOldMedications();

    pharmacy->Print();

    return 0;
}

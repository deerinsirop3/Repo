#include <iostream>
#include <string>
#include <vector>


class CashRegister
{
private Members:
int СashOnHand = 100;
    int cash = 0;
public Members:
    CashRegister(int newcash)
    {
        cash = newcash;
    }
    CashRegister()
    {
        cash = 500;
    }
    int getCurrentBalance()
    {
        return cashOnHand;
    }
    int acceptAmount(int Cost)
    {
        cashOnHand -= Cost;
        cash += Cost;
    }
};
СashRegister::~СashRegister()
{

};
class dispenserType
{
private :
    int numberOfItems;
    int TypeCost;
public:
   dispenserType()
   {
    int numberOfItems = 50;
    int TypeCost = 50;
   }
   dispenserType(int numberOfItems, int TypeCost)
       : numberOfItems(numberOfItems), TypeCost(TypeCost) {}

   int getNoOfItems()
       return NumberOfItems;

   int getCost()
       return getCost;

  int  makeSale()
       numberOfItems--;
}
;
int main()
{
    dispenserType cookes;
    dispenserType cokacola;
    dispenserType snikers;
    dispenserType candies;
    CashRegister dengi;
    return 0;
}
void showSelection()
{
    string Product{ "cookes", "cokacola", "snikers", "candies" };
    for (int i = 0; i < 4; i++)
    {
        cout <<Product[i] << endl;
    }
}
int sellProduct(dispenserType numberOfItems)
{
    setlocale(LC_ALL, "Russian");
    int name;
    cout << "Введите номер товара: " << endl;
    cin << name;
    if (name == 0)
        cookes.makeSale();
    cookes.getCost();
    dengi.acceptAmount(cookes.getCost());
    if (name == 1)
    {
        cokacola.makeSale();
        cokacola.getCost();
        dengi.acceptAmount(cokacola.getCost());
    }
    if (name == 2)
    {
        snikers.makeSale();
        snikers.getCost();
        dengi.acceptAmount(snikers.getCost());
    }
    if (name == 3)
    {
        candies.makeSale();
        candies.getCost();
        dengi.acceptAmount(candies.getCost());
    }
    return 0;
}
/****************************************************************************************************************************
Title         :   Drink.hpp
Auhor         :   Yasmeen Yousef
Description   :   header/interface file of a drink food class
****************************************************************************************************************************/

#ifndef DRINK_
#define DRINK_

#include "Grocery.hpp"

class Drink: public Grocery
{
public:
    /**
        unit of price: dollars
        unit of weight: pounds (lb)
    */
    Drink(std::string name, double price, double weight);
protected:
    /**
     total_price_ <-   product of: quantity, weight per liter, 
                                                and price per liter
    */
    void updateCost() override;   // updates total_price_    
};

#endif
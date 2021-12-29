/****************************************************************************************************************************
Title         :   JunkFood.hpp
Auhor         :   Yasmeen Yousef
Description   :   header/interface file of a junk food class
****************************************************************************************************************************/

#ifndef JUNKFOOD_
#define JUNKFOOD_

#include "Grocery.hpp"

class JunkFood: public Grocery
{
public:
    /**
        unit of price: dollars
        unit of weight: pounds (lb)
    */
    JunkFood(std::string name, double price, double weight);
protected:
    /**
     total_price_ <-   product of: quantity and price per unit
    */
    void updateCost() override;   // updates total_price_
};

#endif
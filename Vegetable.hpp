/****************************************************************************************************************************
Title         :   Vegetable.hpp
Auhor         :   Yasmeen Yousef
Description   :   header/interface file of a vegetable food class
****************************************************************************************************************************/

#ifndef VEGETABLE_
#define VEGETABLE_

#include "Grocery.hpp"

class Vegetable: public Grocery
{
public:
    /**
        unit of price: dollars
        unit of weight: pounds (lb)
    */
    Vegetable(std::string name, double price, double weight);
protected:
    /**
     total_price_ <- product of: quantity, weight per item, 
                                                    and price per pound
    */
    void updateCost() override;   // updates total_price_
};

#endif
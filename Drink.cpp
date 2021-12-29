/****************************************************************************************************************************
Title          :   Drink.cpp
Auhor          :   ** ENTER YOUR NAME **
Description    :   implementation file of a drink food class
Dependencies   :   Drink.hpp
****************************************************************************************************************************/

#include "Drink.hpp"

Drink::Drink(std::string name, double price, double weight)
    : Grocery(name, price, weight)
{
    updateCost();
}

/**
     total_price_ <-   product of: quantity, weight per liter, 
                                                and price per liter
*/
void Drink::updateCost()
{
    // Note: weight / liter ==  unit_weight_ * 16 / FLOZ_PER_LITER
    // Note: 1 liter == 33.814 fluid ounces
    double weight_per_liter = unit_weight_ * 16 / 33.814;    
    total_price_ = quantity_ * weight_per_liter * unit_price_;
}
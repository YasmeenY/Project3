/****************************************************************************************************************************
Title          :   JunkFood.cpp
Auhor          :   Yasmeen Yousef
Description    :   implementation file of a junk food class
Dependencies   :   JunkFood.hpp
****************************************************************************************************************************/

#include "JunkFood.hpp"

JunkFood::JunkFood(std::string name, double price, double weight)
    : Grocery(name, price, weight)
{
    updateCost();
}

/**
     total_price_ <-   product of: quantity and price per unit
*/
void JunkFood::updateCost()
{
    total_price_ = quantity_ * unit_price_;
}
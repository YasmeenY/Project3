/****************************************************************************************************************************
Title          :   ShoppingCart.cpp
Auhor          :   Yasmeen Yousef
Description    :   implementation file of a shopping cart class
Dependencies   :   ShoppingCart.hpp
****************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "ShoppingCart.hpp"

/* Default Constructor */
ShoppingCart::ShoppingCart() : DynamicArray<Grocery *>()
{
}

/** 
     must call the destructor of DynamicArray
*/
ShoppingCart::~ShoppingCart()
{
}

/**
    adds new_entry to the caller; if the entry
    already exists in the caller, increment
    quantity_ in the object, and increment 
    the curr_contents_weight_ of the caller
    by the unit_weight_ of the added item.
    
    @pre    :   the addition of the weight of 
                new_entry does not bring the
                curr_contents_weight_ over the 
                carrying capacity
        
    @return :   true if the addition is successful            
*/
bool ShoppingCart::add(Grocery *new_entry)
{
    // precondition
    if (!canAdd(new_entry))
        return false;

    Grocery *item = find(new_entry);
    if (item)
    {
        item->incrementQuantity();
    }
    else
    {
        item = new_entry;
        DynamicArray<Grocery *>::add(item); // method of the base class
    }

    curr_contents_weight_ += item->getUnitWeight();
    return true;
}

/**  
     removes the first instance of an_item from the caller; 
    if the entry already exists in the caller, decrement
    quantity_ in the object, and decrement the 
    curr_contents_weight_ of the caller by the 
    unit_weight_ of the added item.
    --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
    @return :   true if the addition is successful            
*/
bool ShoppingCart::remove(Grocery *an_item)
{
    Grocery *item = find(an_item);
    if (item)
    {
        item->decrementQuantity();
        curr_contents_weight_ -= an_item->getUnitWeight();
        garbageClear();
        return true;
    }

    return false;
}

/** displays shopping cart contents in required format */
double ShoppingCart::checkout()
{
    if (getOccupiedSpaces() == 0)
    {
        std::cout << "Your cart is empty!" << std::endl;
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < getOccupiedSpaces(); i++)
    {
        std::cout << "\n"
                  << std::setw(10) << std::left << getItems()[i]->getName()
                  << "\t" << getItems()[i]->getQuantity()
                  << "\t" << std::fixed << std::setprecision(2)
                  << getItems()[i]->getTotalPrice();
        total += getItems()[i]->getTotalPrice();
    }

    std::cout << std::setfill('-') << std::setw(40) << "\n"
              << std::endl
              << "Total:                  "
              << total << std::endl
              << std::endl;
    clear();
    curr_contents_weight_ = 0;
    return total;
}

/** 
     iterates through caller and removes items whose quantity_ == 0
    --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
    @post   :   every item in the caller has quantity_ >= 1
*/

void ShoppingCart::garbageClear()
{
    int i = 0;
    while (i < getOccupiedSpaces())
    {
        Grocery *item = getItems()[i];

        if (item->getQuantity() == 0)
        {
            DynamicArray<Grocery *>::remove(item); // method of the base class
        }
        else
        {
            ++i;
        }
    }
}

/* Getter: curr_contents_weight_ */
double ShoppingCart::getCurrentWeight()
{
    return curr_contents_weight_;
}

/** find grocery by name */
Grocery *ShoppingCart::find(Grocery *an_item)
{
    Grocery **items = getItems();
    int size = getOccupiedSpaces();
    // find grocery by name
    for (int i = 0; i < size; ++i)
    {
        if (items[i]->getName() == an_item->getName())
        {
            return items[i];
        }
    }
    return nullptr;
}

/** Can add an item to the cart? */
bool ShoppingCart::canAdd(Grocery *an_item)
{
    return curr_contents_weight_ + an_item->getUnitWeight() <= MAX_CAPACITY;
}
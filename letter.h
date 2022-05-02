//
// Created by Максим Уланов on 26.04.2022.
//
#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "StreamTable.h"
#include "fio.h"
#include "address.h"

class fio;
class address;

class letter
{
private:
    double price;

public:
    fio fio_recipient;
    address recipient;
    address sender;

    static int count;

    double GetPrice() {return price;};

    void SetPrice(double new_price)
    {
        price = new_price;
    }

    letter()
    {
        count=0;
        price = 0.0;
    }

    friend void Input(letter* Obj,int amount);
    friend void SearchSender(letter* Obj, int amount);
    friend void SearchRecipient(letter* Obj, int amount);
    friend void SortedPrice(letter* &Obj, int amount);
    friend void SortedSender(letter* &Obj, int amount);
    friend void Save(letter* Obj, int amount, std::string filename);
    friend void Read(letter* &Obj, int amount, std::string filename);
};
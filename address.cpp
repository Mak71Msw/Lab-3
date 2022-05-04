//
// Created by Максим Уланов on 03.05.2022.
//

#include "address.h"
#include <iostream>

std::string full_address(address &Obj) {
    std::string address = "Country:" +Obj.GetCountry()+ " " +
                          "City:" +Obj.GetCity()+ " " + "House:" +Obj.GetHouse();
    return address;
}
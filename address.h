//
// Created by Максим Уланов on 02.05.2022.
//
#pragma once
#include <iostream>

class address {
public:
    std::string country;
    std::string city;
    std::string house;

    std::string GetCountry() { return country; };

    std::string GetCity() { return city; };

    std::string GetHouse() { return house; };

    void SetCountry(std::string new_country) {
        country = new_country;
    }

    void SetCity(std::string new_city) {
        city = new_city;
    }

    void SetHouse(std::string new_house) {
        house = new_house;
    }

    friend class letter;

    address() {
        country = "country";
        city = "city";
        house = "house";
    }
    friend std::string full_address(address &Obj);
};
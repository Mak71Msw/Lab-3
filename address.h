//
// Created by Максим Уланов on 02.05.2022.
//
#pragma once

class address {
private:
    std::string country;
    std::string city;
    std::string house;

public:
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

    bool operator ! () const
    {

    }

    address() {
        country = "country";
        city = "city";
        house = "house";
    }
    friend std::string full_address(address &Obj);
};

    std::string full_address(address &Obj) {
        std::string address = "Country: " +Obj.GetCountry()+ "/ " +
                               "City: " +Obj.GetCity()+ "/ " + "House: " +Obj.GetHouse();
    return address;
}
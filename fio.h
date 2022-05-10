//
// Created by Максим Уланов on 26.04.2022.
//
#pragma once

class fio {
public:
    std::string surname_recipient;
    std::string name_recipient;
    std::string patronymic_recipient;

    std::string GetSurname() { return surname_recipient; };
    std::string GetName() { return name_recipient; };
    std::string GetPatronymic() { return patronymic_recipient; };

    void SetSurname(std::string new_surname) {
        surname_recipient = new_surname;
    }
    void SetName(std::string new_name) {
        name_recipient = new_name;
    }
    void SetPatronymic(std::string new_patronymic) {
        patronymic_recipient = new_patronymic;
    }

    friend class letter;

    fio() {
        surname_recipient = "surname";
        name_recipient = "name";
        patronymic_recipient = "patronymic";
    }
};
//
// Created by szindzeks on 11.04.2024.
//

#ifndef START_ADDRESS_H
#define START_ADDRESS_H

/// @brief Represents physical postal address
class Address {

private:
    std::string city;
    std::string street;
    std::string number;

public:
    /**
     * @brief constructor
     *
     * @param city - city name
     * @param street - street name
     * @param number - street number
     */
    Address(std::string city, std::string street, std::string number);

    /// @brief destructor
    ~Address();

    /// @return all field values concatenated into one string
    std::string getInfo();

    /// @return get city name
    std::string getCity();

    /// @return get street name
    std::string getStreet();

    /// @return get street number
    std::string getNumber();

    /// @brief sets city name to a new value
    /// @param city - new value of city. Has to be a non-empty string.
    void setCity(std::string city);

    /// @brief sets street name to a new value
    /// @param street - new value of lastName. Has to be a non-empty string.
    void setStreet(std::string street);

    /// @brief sets street number to a new value
    /// @param number - new value of number. Has to be a non-empty string.
    void setNumber(std::string number);
};


#endif //START_ADDRESS_H

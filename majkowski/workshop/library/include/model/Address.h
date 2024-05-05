//
// Created by szindzeks on 11.04.2024.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

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
    Address(const std::string &city, const std::string &street, const std::string &number);

    /// @brief destructor
    ~Address();

    /// @return all field values concatenated into one string
    std::string getInfo() const;

    /// @return get city name
    const std::string & getCity() const;

    /// @return get street name
    const std::string & getStreet() const;

    /// @return get street number
    const std::string & getNumber() const;

    /// @brief sets city name to a new value
    /// @param city - new value of city. Has to be a non-empty string.
    void setCity(const std::string &city);

    /// @brief sets street name to a new value
    /// @param street - new value of lastName. Has to be a non-empty string.
    void setStreet(const std::string &street);

    /// @brief sets street number to a new value
    /// @param number - new value of number. Has to be a non-empty string.
    void setNumber(const std::string &number);
};


#endif //CARRENTAL_ADDRESS_H

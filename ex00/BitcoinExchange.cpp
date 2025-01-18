/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:40:45 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/18 13:56:38 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::cout << "Constructor Called" << std::endl;
    this->value = 0;
    std::ifstream data("data.csv");
    if (!data.is_open())
        std::cerr << "Error: Database not found" << std::endl;
    std::string line;
    int pos = 0;
    std::string key;
    double value;
    while (std::getline(data, line)){
        pos = line.find(',');
        key = line.substr(0, pos);
        line = line.substr(pos + 1);
        value = strtod(line.c_str(), NULL);
        databaseMap[key] = value;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs){
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs){
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &rhs){
        databaseMap.clear();
        databaseMap = rhs.databaseMap;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){
    std::cout << "Destructor called" << std::endl;
}

std::string    BitcoinExchange::get_Date(std::string line, std::string delimiter){
    int pos;

    pos = line.find(delimiter);
    if (pos == -1){
        date = line;
        throw "Error: bad input => ";
    }
    return (line.substr(0, pos));
}
void    BitcoinExchange::check_format(std::string str, std::string str_cmp){
    for (size_t i = 0; i < str_cmp.length(); i++){
        if (str[i] != str_cmp[i])
            throw "Error: not a valide format";
    }
}
void    BitcoinExchange::check_date_numbers(std::string year, std::string month, std::string day){
    for (size_t i = 0; i < year.size(); i++){
        if (!isdigit(year[i]))
            throw "Error: not a number(year)";
    }
    for (size_t i = 0; i < month.size(); i++){
        if (!isdigit(month[i]))
            throw "Error: not a number(month)";
    }
    for (size_t i = 0; i < day.size(); i++){
        if (!isdigit(day[i]))
            throw "Error: not a number(day)";
    }
}
void    BitcoinExchange::check_date(std::string year, std::string month, std::string day){
    int day_value = 0;
    int month_value = 0;

    if (year.size() != 4 ||  month.size() != 2 || day.size() != 2)
        throw "Error: not a valide date";
    check_date_numbers(year, month, day);
    day_value = strtod(day.c_str(), NULL);
    month_value = strtod(month.c_str(), NULL);
    if (day_value > 31)
        throw "Error: not a valide day";
    if ( month_value > 12)
        throw "Error: not a valide month";
}
void    BitcoinExchange::check_value_number(std::string line){
    int c = 0;
    
    if (line[0] == '-')
        throw "Error: not a positive number.";
    if (line[0] == '+')
        line = line[1];
    for (size_t i = 0; i < line.length(); i++){
        if (line[i] == '.')
            c++;
        else if (!isdigit(line[i]))
            throw "Error: not a valid number";
    }
    if (c > 1)
        throw "Error: not a valid number";
}
void    BitcoinExchange::check_line(std::string line){
    std::string year;
    std::string month;
    std::string day;
    int pos;

    pos = line.find('-');
    year = line.substr(0, pos);
    line = line.substr(pos + 1);
    pos = line.find('-');
    month = line.substr(0, pos);
    line = line.substr(pos + 1);
    pos = line.find(' ');
    day = line.substr(0, pos);
    check_format(line.substr(pos), " | ");
    pos = line.find('|');
    line = line.substr(pos + 2);
    check_date(year, month, day);
    check_value_number(line);
    this->value = std::strtod(line.c_str(), NULL);
    if (this->value > 1000 || this->value == INT_MIN)
        throw "Error: too large a number.";
}
void    BitcoinExchange::search_in_data_print(std::string date){
    std::map<std::string, double>::iterator it;
    
    it = databaseMap.find(date);
    if (it == databaseMap.end()){
        it = databaseMap.lower_bound(date);
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    else
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
void    BitcoinExchange::parseline(std::string line){
    std::string date;

    date = get_Date(line, " ");
    check_line(line);
    search_in_data_print(date);
}
void    BitcoinExchange::read_inputfile(std::string _file){
    std::ifstream file(_file);

    if (!file.is_open())
        std::cerr << "Error: Cannot found the file" << std::endl;
    std::string line;
    while(std::getline(file, line)){
        try{
            parseline(line);
        }
        catch(const char* err){
            if (strcmp(err, "Error: bad input => "))
                std::cout << err << std::endl;
            else
                std::cout << err << date << std::endl;       
        }
    }
}
void    BitcoinExchange::print_datacsv(){
    for(it = databaseMap.begin(); it != databaseMap.end(); it++)
        std::cout << "Key: " << it->first << " - Value: " << it->second << std::endl;
}

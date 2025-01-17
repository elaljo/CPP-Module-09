/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:24:04 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/17 18:58:06 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange{
    private:
        std::map<std::string, double> databaseMap;
        std::map<std::string, double>::iterator it;
        
        std::string date;
        double value;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& rhs);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();
        
        void        read_inputfile(std::string _file);
        void        parseline(std::string line);
        std::string get_Date(std::string line, std::string delimiter);
        void        check_line(std::string line);
        void        check_format(std::string str, std::string cmp);
        void        check_date(std::string year, std::string month, std::string day);
        void        check_date_numbers(std::string year, std::string month, std::string day);
        void        check_value_number(std::string line);
        void        search_in_data_print(std::string date);
        void        print_datacsv();
};

#endif
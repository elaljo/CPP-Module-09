/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:40:45 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/15 16:27:13 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string _file){
    std::cout << "Constructor Called" << std::endl;
    std::ifstream file(_file);
    if (!file.is_open())
        std::cerr << "Error: File not found" << std::endl;
        
}
BitcoinExchange::~BitcoinExchange(){
    std::cout << "Destructor called" << std::endl;
}
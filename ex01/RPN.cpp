/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:08:14 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/18 16:18:28 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    std::cout << "Constructor Called" << std::endl;
}
RPN::RPN(const RPN& rhs){
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}
RPN& RPN::operator=(const RPN& rhs){
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &rhs){
        while(!myStack.empty())
            myStack.pop();
        this->myStack = rhs.myStack;
    }
    return *this;
}
RPN::~RPN(){
    std::cout << "Destructor called: Stack cleaned up." << std::endl;
    while(!myStack.empty())
        myStack.pop();
}
void    RPN::is_valid_argument(std::string line){
    for (size_t i = 0; i < line.length() - 1; i++){
        if ((line[i] > 32 && line[i] < 41) || (line[i] >= 58 && line[i] < 127) || line[i] == '.' || line[i] == ',')
            throw "Error";
        if (isdigit(line[i]) && isdigit(line[i + 1]))
            throw "Error";
    }
}
void    RPN::read_line(std::string line){
    is_valid_argument(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:08:14 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/19 19:07:51 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    std::cout << "Constructor Called" << std::endl;
    this->result = 0;
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
        this->result = rhs.result;
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
int    RPN::rem_spaces_begin(std::string line){
    for(size_t i = 0; i < line.length(); i++){
        if (line[i] != ' ' && line[i] != '\t')
            return (i);
    }
    return 0;
}
int     RPN::rem_spaces_last(std::string line){
    int last = 0;

    last = line.length();
    if (line[last - 1] == ' ')
        last = line.find_last_not_of(" \t") + 1;
    return (last);
}
int    RPN::is_number(std::string c){
    if (isdigit(c[0]))
        return 1;
    return 0;
}
void    RPN::start_calcul(std::string c){
    int n1;
    int n2;
    
    if (stack_size() <= 1)
        throw "Error: invalid input";
    n1 = myStack.top();
    myStack.pop();
    n2 = myStack.top();
    myStack.pop();
    if (c == "*")
        result = n2 * n1;
    else if (c == "/")
        result = n2 / n1;
    else if (c == "-")
        result = n2 - n1;
    else if (c == "+")
        result = n2 + n1;
    myStack.push(result);
}
void    RPN::store_and_push(std::string line){
    std::string c;
    int num;
    
    line = line.substr(rem_spaces_begin(line));
    line = line.substr(0, rem_spaces_last(line));
    while (line.length()){
        c = line.substr(0, 1);
        line = line.substr(1);
        line = line.substr(rem_spaces_begin(line));
        if (is_number(c)){
            num = std::strtod(c.c_str(), NULL);
            myStack.push(num);
        }
        else
            start_calcul(c);
    }
}

int RPN::stack_size(){
    return (myStack.size());
}
int RPN::get_result(){
    return (result);
}

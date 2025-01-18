/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:12 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/18 15:37:58 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc == 2){
        RPN rpn;
        try{
            rpn.read_line(argv[1]);
        }
        catch(const char* err){
            std::cout << err << std::endl;
        }
    }
    else
        std::cerr << "Arguments not valid" << std::endl;
    return (0);
}
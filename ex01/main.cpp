/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:12 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/19 19:08:17 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc == 2){
        RPN rpn;
        try{
            rpn.is_valid_argument(argv[1]);
            rpn.store_and_push(argv[1]);
            if (rpn.stack_size() == 1)
                std::cout << rpn.get_result() << std::endl;
            else
                std::cout << "Error: not valid input" << std::endl;
        }
        catch(const char* err){
            std::cout << err << std::endl;
        }
    }
    else
        std::cerr << "Arguments not valid" << std::endl;
    return (0);
}
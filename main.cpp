/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:25:09 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/15 23:27:10 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
    if (argc == 2){
        BitcoinExchange Btc;
        Btc.read_inputfile(argv[1]);
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
    return (0);
}
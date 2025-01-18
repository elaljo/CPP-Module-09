/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:45 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/18 16:16:39 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN{
    private:
        std::stack<std::string> myStack;
    public:
        RPN();
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);
        ~RPN();
        void    read_line(std::string line);
        void    is_valid_argument(std::string line);
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:45 by moelalj           #+#    #+#             */
/*   Updated: 2025/01/19 18:29:49 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN{
    private:
        std::stack<int> myStack;
        int result;
    public:
        RPN();
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);
        ~RPN();

        void    is_valid_argument(std::string line);
        void    store_and_push(std::string line);
        int     rem_spaces_begin(std::string line);
        int     rem_spaces_last(std::string line);
        int     is_number(std::string c);
        void    start_calcul(std::string c);

        int     stack_size();
        int     get_result();

};
#endif
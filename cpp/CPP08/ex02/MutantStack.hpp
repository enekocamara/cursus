/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:48:23 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/05 11:52:35 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        typedef typename std::stack<T, Container>::container_type container_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;
        iterator begin() {return (std::begin(std::stack<T, Container>::c));};
        iterator end() {return (std::end(std::stack<T, Container>::c));};
        const_iterator begin() const {return (std::begin(std::stack<T, Container>::c));};
        const_iterator end() const {return (std::end(std::stack<T, Container>::c));};
};

#endif
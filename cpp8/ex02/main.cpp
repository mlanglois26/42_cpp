/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:30:14 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/13 12:30:16 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {

    {
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Check that after pushing 5 and 17, top element is ";
        std::cout << mstack.top() << std::endl;
        std::cout << "Check that after pushing 5 and 17, stack size is ";
        std::cout << mstack.size() << std::endl;

        mstack.pop();
        std::cout << "Check that after calling .pop(), top element is now ";
        std::cout << mstack.top() << std::endl;
        std::cout << "And the new size is ";
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "After pushing 3, 5, 737, 0, top element is ";
        std::cout << mstack.top() << std::endl;
        std::cout << "And the new size is ";
        std::cout << mstack.size() << std::endl;
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        
        std::cout << "\nCheck regular iterator" << std::endl;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }

        std::cout << "\n\nCheck reverse iterator" << std::endl;
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        ++rit;
        --rit;
        
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }

        std::cout << "\n\nCheck copy" << std::endl;

        std::stack<int> s(mstack);
        std::cout << "Copy size = " << s.size() << std::endl;
        std::cout << "Copy top elem = " << mstack.top() << std::endl;

    }

    {
        std::cout << "\nCheck with std::list\n" << std::endl;
        std::list<int> mlist;
        
        mlist.push_front(5);
        mlist.push_front(17);
        
        std::cout << "Check that after pushing_front 17, front element is ";
        std::cout << mlist.front() << std::endl;
        std::cout << "Check that after pushing_front 5 and 17, stack size is ";
        std::cout << mlist.size() << std::endl;

        mlist.pop_front();
        std::cout << "Check that after calling .pop_front(), front element is now ";
        std::cout << mlist.front() << std::endl;
        std::cout << "And the new size is ";
        std::cout << mlist.size() << std::endl;
        
        mlist.push_front(3);
        mlist.push_front(5);
        mlist.push_front(737);
        mlist.push_front(0);

        std::cout << "After pushing_front 3, 5, 737, 0, front element is ";
        std::cout << mlist.front() << std::endl;
        std::cout << "And the new size is ";
        std::cout << mlist.size() << std::endl;
        
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        
        std::cout << "\nCheck regular iterator" << std::endl;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }

        std::cout << "\n\nCheck reverse iterator" << std::endl;
        std::list<int>::reverse_iterator rit = mlist.rbegin();
        std::list<int>::reverse_iterator rite = mlist.rend();
        ++rit;
        --rit;
        
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
    }
    return 0;
}

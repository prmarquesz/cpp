/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:36:00 by proberto          #+#    #+#             */
/*   Updated: 2023/05/07 14:46:59 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal *animals[10];
	int i = 0;

	std::cout << std::endl << "Half of dogs: " << std::endl;
	for (; i < 5; i++)
		animals[i] = new Dog();
	std::cout << "*************************************" << std::endl;
	
	std::cout << std::endl << "Half of cats: " << std::endl;
	for (; i < 10; i++)
		animals[i] = new Cat();
	std::cout << "*************************************" << std::endl;
	
	std::cout << std::endl << "Destructors: ";
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << "*************************************" << std::endl;
	
	std::cout << "Shallow or deep copy? "<< std::endl;
	Dog *dog = new Dog();
	dog->haveIdea("I'm a dog");
	dog->showIdeas();
	Dog *dog2 = new Dog(*dog);
	dog2->showIdeas();
	Dog dog3 = *dog;
	dog3.showIdeas();

	delete dog;
	delete dog2;
	
	return (0);
}

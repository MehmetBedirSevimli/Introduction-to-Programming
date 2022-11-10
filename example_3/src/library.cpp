#include "Library.hpp"
#include <iostream>

Library::Library(int number)
{
	m_Number = number;
}

void Library::print()
{
	std::cout<<"Number...:"<<m_Number<<std::endl;
}
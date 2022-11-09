#include <iostream>
#include "Library.hpp"
int main(int argc, char**argv)
{
	Library* k = new Library(123);

	k->print();
}
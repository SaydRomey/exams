
#include "Warlock.hpp"

// c++ -Wall -Wextra -Werror -std=c++98 Warlock.cpp main.cpp

int main(void)
{
	Warlock const	richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock*	jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	return (0);
}

// expected output:
/*
Richard: This looks like another boring day.
Richard: I am Richard, Mistress of Magma!
Richard - Mistress of Magma
Jack: This looks like another boring day.
Jack: I am Jack, the Long!
Jack: I am Jack, the Mighty!
Jack: My job here is done!
Richard: My job here is done!
*/

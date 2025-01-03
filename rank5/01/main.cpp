
// c++ -Wall -Wextra -Werror -std=c++98 Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp main.cpp

#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

int	main(void)
{
	Warlock	richard("Richard", "the Titled");

	Dummy	bob;
	Fwoosh*	fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);
	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	delete fwoosh;

	return (0);
}

// expected output:
/*
Richard: This looks like another boring day.
Richard: I am Richard, the Titled!
Target Practice Dummy has been fwooshed!
Richard: My job here is done!
*/

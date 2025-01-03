
// c++ -Wall -Wextra -Werror -std=c++98 Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp main.cpp

#include "Warlock.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

int	main(void)
{
	Warlock	richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall	model1;

	Polymorph*	polymorph = new Polymorph();
	TargetGenerator	tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball*	fireball = new Fireball();
	richard.learnSpell(fireball);

	ATarget*	wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);

	delete polymorph;
	delete fireball;

	return (0);
}

// expected output:
/*
Richard: This looks like another boring day.
Richard: I am Richard, Hello, I'm Richard the Warlock!!
Inconspicuous Red-brick Wall has been turned into a critter!
Inconspicuous Red-brick Wall has been burnt to a crisp!
Richard: My job here is done!
*/

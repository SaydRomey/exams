
#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

/* (Concrete Class)
A spell with name = "Polymorph" and effects = "turned into a critter".
Implements clone().
*/
class Polymorph : public ASpell
{
	public:
		Polymorph(void);
		virtual ~Polymorph(void);

		virtual Polymorph*	clone(void) const;
};

#endif // POLYMORPH_HPP

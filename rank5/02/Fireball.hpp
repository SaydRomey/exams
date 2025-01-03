
#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

/* (Concrete Class)
A spell with name = "Fireball" and effects = "burnt to a crisp".
Implements clone().
*/
class Fireball : public ASpell
{
	public:
		Fireball(void);
		virtual ~Fireball(void);

		virtual Fireball*	clone(void) const;
};

#endif // FIREBALL_HPP

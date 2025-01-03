
#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

/* (Concrete Class)
A spell with name = "Fwoosh" and effects = "fwooshed".
Implements clone().
*/
class Fwoosh : public ASpell
{
	public:
		Fwoosh(void);
		virtual ~Fwoosh(void);

		virtual Fwoosh*	clone(void) const;
};

#endif // FWOOSH_HPP

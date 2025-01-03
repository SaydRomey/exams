
#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

/* (Concrete Class)
A target with type = "Target Practice Dummy".
Implements clone().
*/
class Dummy : public ATarget
{
public:
	Dummy(void);
	virtual ~Dummy(void);

	virtual Dummy*	clone(void) const;
};

#endif // DUMMY_HPP

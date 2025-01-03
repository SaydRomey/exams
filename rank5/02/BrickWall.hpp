
#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

/* (Concrete Class)
A target with type = "Inconspicuous Red-brick Wall".
Implements clone().
*/
class BrickWall : public ATarget
{
public:
	BrickWall(void);
	virtual ~BrickWall(void);

	virtual BrickWall*	clone(void) const;
};

#endif // BRICKWALL_HPP

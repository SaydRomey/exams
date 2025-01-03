
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell; // Forward declaration

/* (Abstract Class)
Represents generic targets with a type.
Includes a clone() pure virtual function.
Implements getHitBySpell().
*/
class ATarget
{
	protected:
		std::string	_type;

	public:
		ATarget(const std::string& type);
		virtual ~ATarget(void);

		const std::string&	getType(void) const;

		virtual ATarget*	clone(void) const = 0;
		void	getHitBySpell(const ASpell& spell) const;
};

#endif // ATARGET_HPP

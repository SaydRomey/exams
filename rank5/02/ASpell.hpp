
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget; // Forward declaration

/* (Abstract Class)
Represents generic spells with name and effects.
Includes a clone() pure virtual function.
Implements launch() to hit an ATarget.
*/
class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell(const std::string& name, const std::string& effects);
		virtual ~ASpell(void);

		const std::string&	getName(void) const;
		const std::string&	getEffects(void) const;

		virtual ASpell*	clone(void) const = 0;
		void	launch(const ATarget& target) const;
};

#endif // ASPELL_HPP

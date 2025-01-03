
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

# include <map>
# include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	_spells;

		SpellBook(const SpellBook&);
		SpellBook&	operator=(const SpellBook&);

	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spellName);
		ASpell*	createSpell(const std::string& spellName) const;
};

#endif // SPELLBOOK_HPP

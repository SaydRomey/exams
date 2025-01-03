
#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.begin();
	while (it != _spells.end())
	{
		delete it->second;
		++it;
	}
}

void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(const std::string& spellName)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);
	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

ASpell*	SpellBook::createSpell(const std::string& spellName) const
{
	std::map<std::string, ASpell*>::const_iterator	it = _spells.find(spellName);
	if (it != _spells.end())
		return (it->second->clone());
	return (NULL);
}


#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
	: _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << _name << ": My job here is done!" << std::endl;

	std::map<std::string, ASpell*>::iterator	it = _spells.begin();
	while (it != _spells.end())
	{
		delete it->second;
		++it;
	}
	_spells.clear();
}

const std::string&	Warlock::getName(void) const { return (_name); }
const std::string&	Warlock::getTitle(void) const {	return (_title); }

void	Warlock::setTitle(const std::string& title) { _title = title; }

void	Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(const std::string& spellName)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);
	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

void	Warlock::launchSpell(const std::string& spellName, const ATarget& target)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);

	if (it != _spells.end())
		it->second->launch(target);
}

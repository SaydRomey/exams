
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

// # include <iostream>
// # include <string>
# include "SpellBook.hpp"
# include "TargetGenerator.hpp"
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock
{
	private:
		std::string		_name;
		std::string		_title;
		SpellBook		_spellBook;
		TargetGenerator	_targetGenerator;

		Warlock(void);
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock(void);

		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;

		void	setTitle(const std::string& title);

		void	introduce(void) const;

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spellName);
		void	launchSpell(const std::string& spellName, const ATarget& target);
};

#endif // WARLOCK_HPP
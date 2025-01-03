

#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::~ATarget(void) {}

const std::string&	ATarget::getType(void) const { return (_type); }

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

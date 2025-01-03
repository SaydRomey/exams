
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void)
{
	std::map<std::string, ATarget*>::iterator	it = _targets.begin();
	while ( it != _targets.end())
	{
		delete it->second;
		++it;
	}
}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		_targets[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType(const std::string& targetType)
{
	std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
	if (it != _targets.end())
	{
		delete it->second;
		_targets.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string& targetType) const
{
	std::map<std::string, ATarget*>::const_iterator it = _targets.find(targetType);
	if (it != _targets.end())
		return (it->second->clone());
	return (NULL);
}

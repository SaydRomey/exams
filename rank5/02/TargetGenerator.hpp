
#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*>	_targets;

		TargetGenerator(const TargetGenerator&);
		TargetGenerator&	operator=(const TargetGenerator&);

	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(const std::string& targetType);
		ATarget*	createTarget(const std::string& targetType) const;
};

#endif // TARGETGENERATOR_HPP

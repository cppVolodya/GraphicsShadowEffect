// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "types_aliases.hpp"


namespace N_GraphicsShadowEffect::N_Utilities
{
static constexpr inline N_TypesAliases::T_Thickness GetZeroIfNegative(N_TypesAliases::T_Thickness number)
{
	N_TypesAliases::T_Thickness result{0.0};
	if (number < 0.0)
	{
		result = 0.0;
	}
	else
	{
		result = number;
	}

	return result;
}
}  // namespace N_GraphicsShadowEffect::N_Utilities

#endif  // UTILITIES_HPP

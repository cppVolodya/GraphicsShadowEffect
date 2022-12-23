// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef BASE_THICKNESS_FOR_ELEMENT_OF_WIDGET_HPP
#define BASE_THICKNESS_FOR_ELEMENT_OF_WIDGET_HPP

#include "types_aliases.hpp"
#include "utilities.hpp"



namespace N_GraphicsShadowEffect
{
class Thickness
{
public:
	constexpr inline Thickness() noexcept;

	[[maybe_unused]] explicit constexpr inline Thickness(N_TypesAliases::T_Thickness top,
											  		     N_TypesAliases::T_Thickness bottom,
											  		     N_TypesAliases::T_Thickness left,
											  		     N_TypesAliases::T_Thickness right) noexcept;

	[[maybe_unused]] explicit constexpr inline Thickness(N_TypesAliases::T_Thickness universal_thickness) noexcept;

	[[nodiscard]] constexpr inline N_TypesAliases::T_Thickness GetTop   () const noexcept;
	[[nodiscard]] constexpr inline N_TypesAliases::T_Thickness GetBottom() const noexcept;
	[[nodiscard]] constexpr inline N_TypesAliases::T_Thickness GetLeft  () const noexcept;
	[[nodiscard]] constexpr inline N_TypesAliases::T_Thickness GetRight () const noexcept;

	constexpr inline void SetTop   (N_TypesAliases::T_Thickness top   ) noexcept;
	constexpr inline void SetBottom(N_TypesAliases::T_Thickness bottom) noexcept;
	constexpr inline void SetLeft  (N_TypesAliases::T_Thickness left  ) noexcept;
	constexpr inline void SetRight (N_TypesAliases::T_Thickness right ) noexcept;

	constexpr inline void SetThickness(N_TypesAliases::T_Thickness top,
									   N_TypesAliases::T_Thickness bottom,
									   N_TypesAliases::T_Thickness left,
									   N_TypesAliases::T_Thickness right) noexcept;

	constexpr inline void SetThickness(N_TypesAliases::T_Thickness thickness) noexcept;
private:
	N_TypesAliases::T_Thickness m_top;
	N_TypesAliases::T_Thickness m_bottom;
	N_TypesAliases::T_Thickness m_left;
	N_TypesAliases::T_Thickness m_right;
};

constexpr inline Thickness::Thickness() noexcept
	: m_top   (0.0),
	  m_bottom(0.0),
	  m_left  (0.0),
	  m_right (0.0)
{
}

constexpr inline Thickness::Thickness(const N_TypesAliases::T_Thickness top,
									  const N_TypesAliases::T_Thickness bottom,
									  const N_TypesAliases::T_Thickness left,
									  const N_TypesAliases::T_Thickness right) noexcept
	: Thickness()
{
	this->SetThickness(top,
					   bottom,
					   left,
					   right);
}

constexpr inline Thickness::Thickness(const N_TypesAliases::T_Thickness universal_thickness) noexcept
	: Thickness(universal_thickness,
				universal_thickness,
				universal_thickness,
				universal_thickness)
{
}

constexpr inline N_TypesAliases::T_Thickness Thickness::GetTop() const noexcept
{
	return this->m_top;
}

constexpr inline N_TypesAliases::T_Thickness Thickness::GetBottom() const noexcept
{
	return this->m_bottom;
}

constexpr inline N_TypesAliases::T_Thickness Thickness::GetLeft() const noexcept
{
	return this->m_left;
}

constexpr inline N_TypesAliases::T_Thickness Thickness::GetRight() const noexcept
{
	return this->m_right;
}

constexpr inline void Thickness::SetTop(const N_TypesAliases::T_Thickness top) noexcept
{
	this->m_top = N_Utilities::GetZeroIfNegative(top);
}

constexpr inline void Thickness::SetBottom(const N_TypesAliases::T_Thickness bottom) noexcept
{
	this->m_bottom = N_Utilities::GetZeroIfNegative(bottom);
}

constexpr inline void Thickness::SetLeft(const N_TypesAliases::T_Thickness left) noexcept
{
	this->m_left = N_Utilities::GetZeroIfNegative(left);
}

constexpr inline void Thickness::SetRight(const N_TypesAliases::T_Thickness right) noexcept
{
	this->m_right = N_Utilities::GetZeroIfNegative(right);
}

constexpr inline void Thickness::SetThickness(const N_TypesAliases::T_Thickness top,
											  const N_TypesAliases::T_Thickness bottom,
											  const N_TypesAliases::T_Thickness left,
											  const N_TypesAliases::T_Thickness right) noexcept
{
	this->SetTop   (top   );
	this->SetBottom(bottom);
	this->SetLeft  (left  );
	this->SetRight (right );
}

constexpr inline void Thickness::SetThickness(const N_TypesAliases::T_Thickness thickness) noexcept
{
	this->SetThickness(thickness,
					   thickness,
					   thickness,
					   thickness);
}
}  // namespace N_GraphicsShadowEffect

#endif  // BASE_THICKNESS_FOR_ELEMENT_OF_WIDGET_HPP

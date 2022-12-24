// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef GRAPHICS_SHADOW_EFFECT_HPP
#define GRAPHICS_SHADOW_EFFECT_HPP

#include <QGraphicsEffect>

#include "types_aliases.hpp"
#include "thickness.hpp"
#include "painter_of_save_and_restore_transform.hpp"


namespace N_GraphicsShadowEffect
{
class GraphicsShadowEffect : public QGraphicsEffect
{
	Q_OBJECT
public:
	[[maybe_unused]] explicit inline GraphicsShadowEffect
		(QObject 		              *parent     = nullptr,
		 const QColor 	              &color 	  = QColor(),
		 const Thickness              &thickness  = Thickness(),
		 N_TypesAliases::T_BlurRadius blur_radius = 0.0);

	[[nodiscard]] inline QColor GetColor() const noexcept;

	[[nodiscard]] inline const Thickness& GetThickness() const noexcept;

	[[nodiscard]] inline N_TypesAliases::T_BlurRadius GetBlurRadius() const noexcept;

	inline void SetColor(const QColor &) noexcept;

	inline void SetThicknessOfTop   (N_TypesAliases::T_Thickness) noexcept;
	inline void SetThicknessOfBottom(N_TypesAliases::T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (N_TypesAliases::T_Thickness) noexcept;
	inline void SetThicknessOfRight (N_TypesAliases::T_Thickness) noexcept;

	inline void SetThickness(const Thickness &) noexcept;

	inline void SetThickness(N_TypesAliases::T_Thickness,
							 N_TypesAliases::T_Thickness,
							 N_TypesAliases::T_Thickness,
							 N_TypesAliases::T_Thickness) noexcept;

	inline void SetThickness(N_TypesAliases::T_Thickness) noexcept;

	inline void SetBlurRadius(N_TypesAliases::T_BlurRadius) noexcept;
protected:
	void draw(QPainter *) override;

	[[nodiscard]] QRectF boundingRectFor(const QRectF &) const override;
private:
	QColor m_color;

	Thickness m_thickness;

	N_TypesAliases::T_BlurRadius m_blur_radius;
};

[[maybe_unused]] inline GraphicsShadowEffect::GraphicsShadowEffect
	(QObject 	   						*parent,
	 const QColor						&color,
	 const Thickness 					&thickness,
	 const N_TypesAliases::T_BlurRadius blur_radius)
	: QGraphicsEffect(parent     ),
	  m_color		 (color		 ),
	  m_thickness    (thickness  ),
	  m_blur_radius  (blur_radius)
{
}

[[nodiscard]] inline QColor GraphicsShadowEffect::GetColor() const noexcept
{
	return this->m_color;
}

[[nodiscard]] inline const Thickness& GraphicsShadowEffect::GetThickness() const noexcept
{
	return this->m_thickness;
}

[[nodiscard]] inline N_TypesAliases::T_BlurRadius GraphicsShadowEffect::GetBlurRadius() const noexcept
{
	return this->m_blur_radius;
}

inline void GraphicsShadowEffect::SetColor(const QColor	&color) noexcept
{
	this->m_color = color;
}

inline void GraphicsShadowEffect::SetThicknessOfTop(const N_TypesAliases::T_Thickness thickness_of_top) noexcept
{
	this->m_thickness.SetTop(thickness_of_top);
	this->updateBoundingRect();
}

inline void GraphicsShadowEffect::SetThicknessOfBottom(const N_TypesAliases::T_Thickness thickness_of_bottom) noexcept
{
	this->m_thickness.SetBottom(thickness_of_bottom);
	this->updateBoundingRect();
}

inline void GraphicsShadowEffect::SetThicknessOfLeft(const N_TypesAliases::T_Thickness thickness_of_left) noexcept
{
	this->m_thickness.SetLeft(thickness_of_left);
	this->updateBoundingRect();
}

inline void GraphicsShadowEffect::SetThicknessOfRight(const N_TypesAliases::T_Thickness thickness_of_right) noexcept
{
	this->m_thickness.SetRight(thickness_of_right);
	this->updateBoundingRect();
}

inline void GraphicsShadowEffect::SetThickness(const Thickness &thickness) noexcept
{
	this->m_thickness = thickness;
	this->updateBoundingRect();
}

inline void GraphicsShadowEffect::SetThickness(const N_TypesAliases::T_Thickness thickness_of_top,
											   const N_TypesAliases::T_Thickness thickness_of_bottom,
											   const N_TypesAliases::T_Thickness thickness_of_left,
											   const N_TypesAliases::T_Thickness thickness_of_right) noexcept
{
	Thickness thickness(thickness_of_top,
						thickness_of_bottom,
						thickness_of_left,
						thickness_of_right);

	this->SetThickness(thickness);
}

inline void GraphicsShadowEffect::SetThickness(const N_TypesAliases::T_Thickness universal_thickness) noexcept
{
	this->SetThickness(universal_thickness,
					   universal_thickness,
					   universal_thickness,
					   universal_thickness);
}

inline void GraphicsShadowEffect::SetBlurRadius(const N_TypesAliases::T_BlurRadius blurRadius) noexcept
{
	this->m_blur_radius = N_Utilities::GetZeroIfNegative(blurRadius);
	this->updateBoundingRect();
}
}  // namespace N_GraphicsShadowEffect

#endif  // GRAPHICS_SHADOW_EFFECT_HPP

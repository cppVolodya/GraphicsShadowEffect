// Copyright [2022] <Volodymyr Dorozhovets>"

#include <QPainter>
#include <QMessageBox>

#include "graphics_shadow_effect.hpp"

QT_BEGIN_NAMESPACE
extern Q_WIDGETS_EXPORT void qt_blurImage(QPainter *painter,
										  QImage   &blur_image,
										  qreal     blur_radius,
										  bool 	    quality,
										  bool 	    alphaOnly,
										  int 	    transposed = 0);
QT_END_NAMESPACE


namespace N_GraphicsShadowEffect
{
void GraphicsShadowEffect::draw(QPainter *painter)
{
	QPoint offset_of_pixel_map_of_source;
	const QPixmap pixel_map_of_source{ this->GetPixelMapOfSource(offset_of_pixel_map_of_source) };

	if(!pixel_map_of_source.isNull())
	{
		PainterOfSaveAndRestoreTransform painter_saver(*painter);

		QImage image{ this->GetImageWithSetThickness(pixel_map_of_source) };
		this->SetBlurRadiusOnImage(image);
		this->SetColorOnImage(image);

		GraphicsShadowEffect::DrawCurrentEffect(painter, offset_of_pixel_map_of_source, image			   );
		GraphicsShadowEffect::DrawCurrentSource(painter, offset_of_pixel_map_of_source, pixel_map_of_source);
	}
}

inline void GraphicsShadowEffect::DrawCurrentEffect(QPainter *painter,
													const QPoint &offset_of_pixel_map_of_source,
													const QImage &image)
{
	painter->drawImage(offset_of_pixel_map_of_source, image);
}

inline void GraphicsShadowEffect::DrawCurrentSource(QPainter *painter,
													const QPoint &offset_of_pixel_map_of_source,
													const QPixmap &pixel_map_of_source)
{
	painter->drawPixmap(offset_of_pixel_map_of_source, pixel_map_of_source);
}

QRectF GraphicsShadowEffect::boundingRectFor(const QRectF &geometry_of_widget) const
{
	const QRectF adjusted_geometry{this->GetAdjustedGeometry(geometry_of_widget)};

	QRectF bounding_rectangle{geometry_of_widget.united(adjusted_geometry)};

	return bounding_rectangle;
}

[[nodiscard]] inline QRectF GraphicsShadowEffect::GetAdjustedGeometry(const QRectF &geometry_of_widget) const
{
	const Thickness distance{this->GetDistance()};

	QRectF adjusted_geometry{geometry_of_widget.adjusted(-distance.GetTop   (), -distance.GetLeft (),
														  distance.GetBottom(),  distance.GetRight())};

	return adjusted_geometry;
}

[[nodiscard]] Thickness GraphicsShadowEffect::GetDistance() const noexcept
{
	Thickness distance;

	distance.SetTop	  (this->GetThickness().GetTop   () + this->GetBlurRadius());
	distance.SetBottom(this->GetThickness().GetBottom() + this->GetBlurRadius());
	distance.SetLeft  (this->GetThickness().GetLeft  () + this->GetBlurRadius());
	distance.SetRight( this->GetThickness().GetRight () + this->GetBlurRadius());

	return distance;
}
}  // namespace N_GraphicsShadowEffect

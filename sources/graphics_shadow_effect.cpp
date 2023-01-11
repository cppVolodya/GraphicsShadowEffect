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

QPixmap GraphicsShadowEffect::GetPixelMapOfSource(QPoint &offset_of_pixel_map)
{
	constexpr Qt::CoordinateSystem coordinate_system{ Qt::DeviceCoordinates };

	constexpr QGraphicsEffect::PixmapPadMode padded_mode{ QGraphicsEffect::PadToEffectiveBoundingRect };

	QPixmap pixel_map{ this->sourcePixmap(coordinate_system,
										  &offset_of_pixel_map,
										  padded_mode) };

	return pixel_map;
}

QImage GraphicsShadowEffect::GetImageWithSetThickness(const QPixmap &pixel_map_of_source)
{
	QSizeF adjusted_size{ this->GetAdjustedSize(pixel_map_of_source) };

	QImage image(adjusted_size.toSize(), QImage::Format_ARGB32_Premultiplied);
	image.fill(0U);

	QPixmap adjusted_scale{ pixel_map_of_source.scaled(adjusted_size.toSize()) };
	this->DrawOnImageWithSetThickness(image, adjusted_scale);

	return image;
}

[[nodiscard]] QSizeF GraphicsShadowEffect::GetAdjustedSize(const QPixmap &pixel_map_of_source) const noexcept
{
	QSizeF adjusted_size;

	adjusted_size.setWidth(static_cast<qreal>(pixel_map_of_source.size().width()) +
		this->GetThickness().GetRight() + this->GetThickness().GetLeft());

	adjusted_size.setHeight(static_cast<qreal>(pixel_map_of_source.size().height()) +
		this->GetThickness().GetBottom() + this->GetThickness().GetTop());

	return adjusted_size;
}

void GraphicsShadowEffect::DrawOnImageWithSetThickness(QImage		 &image_with_set_thickness,
													   const QPixmap &adjusted_scale) const
{
	QPainter painter(&image_with_set_thickness);
	painter.setCompositionMode(QPainter::CompositionMode_Source);

	painter.drawPixmap(QPointF(-this->GetThickness().GetLeft(),
							   -this->GetThickness().GetTop ()), adjusted_scale);

	QMessageBox::StandardButton button_pressed{ QMessageBox::NoButton };
	QWidget temporary;

	if(!painter.end())
	{
		qDebug() << "Error completing drawing graphics shadow effect - DrawOnImageWithSetThickness()!";
		button_pressed = QMessageBox::critical(&temporary, "Rss Feed Reader",
											   "Error completing drawing graphics shadow effect -"
											   "DrawOnImageWithSetThickness()!",
											   QMessageBox::Ok);
	}

	if(button_pressed == QMessageBox::Ok)
	{
		throw std::runtime_error("Error completing drawing graphics shadow effect - "
								 "DrawOnImageWithSetThickness()!");
	}
}

void GraphicsShadowEffect::SetBlurRadiusOnImage(QImage &old_image) const
{
	QImage new_image{old_image.size(), QImage::Format_ARGB32_Premultiplied};
	new_image.fill(0U);

	this->DrawOnImageWithSetBlurRadius(new_image, old_image);

	old_image = new_image;
}

void GraphicsShadowEffect::DrawOnImageWithSetBlurRadius(QImage &new_image, QImage &old_image) const
{
	constexpr bool quality   {true};
	constexpr bool alpha_only{true};

	QPainter painter{&new_image};
	qt_blurImage(&painter, old_image, this->GetBlurRadius(), quality, alpha_only);

	QMessageBox::StandardButton button_pressed{ QMessageBox::NoButton };
	QWidget temporary;

	if(!painter.end())
	{
		qDebug() << "Error completing drawing graphics shadow effect - DrawOnImageWithSetBlurRadius()!";
		button_pressed = QMessageBox::critical(&temporary, "Rss Feed Reader",
											   "Error completing drawing graphics shadow effect - "
											   "DrawOnImageWithSetBlurRadius()!",
											   QMessageBox::Ok);
	}

	if(button_pressed == QMessageBox::Ok)
	{
		throw std::runtime_error("Error completing drawing graphics shadow effect - "
								 "DrawOnImageWithSetBlurRadius()!");
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

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
}  // namespace N_GraphicsShadowEffect

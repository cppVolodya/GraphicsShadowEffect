// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef PAINTER_OF_SAVE_AND_RESTORE_TRANSFORM_HPP
#define PAINTER_OF_SAVE_AND_RESTORE_TRANSFORM_HPP

#include <QPainter>


namespace N_GraphicsShadowEffect
{
class PainterOfSaveAndRestoreTransform final
{
public:
	explicit inline PainterOfSaveAndRestoreTransform(QPainter &);

#pragma region RuleOfZero
	PainterOfSaveAndRestoreTransform(const PainterOfSaveAndRestoreTransform &) = delete;
	PainterOfSaveAndRestoreTransform(PainterOfSaveAndRestoreTransform &&)	   = delete;

	PainterOfSaveAndRestoreTransform& operator=(const PainterOfSaveAndRestoreTransform &) = delete;
	PainterOfSaveAndRestoreTransform& operator=(PainterOfSaveAndRestoreTransform &&)	  = delete;

	inline ~PainterOfSaveAndRestoreTransform();
#pragma endregion RuleOfZero
private:
	QPainter &m_painter;

    QTransform m_transform;
};

inline PainterOfSaveAndRestoreTransform::PainterOfSaveAndRestoreTransform(QPainter &painter)
	: m_painter(painter)
{
    this->m_transform = this->m_painter.worldTransform();
    this->m_painter.setWorldTransform(QTransform());
}

inline PainterOfSaveAndRestoreTransform::~PainterOfSaveAndRestoreTransform()
{
    this->m_painter.setWorldTransform(this->m_transform);
}
}  // namespace N_GraphicsShadowEffect

#endif  // PAINTER_OF_SAVE_AND_RESTORE_TRANSFORM_HPP

// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <QPainterPath>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>


#include "graphics_shadow_effect.hpp"


namespace N_GraphicsShadowEffect
{
class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
protected:
	void paintEvent(QPaintEvent *event) override;

	void mousePressEvent  (QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseMoveEvent   (QMouseEvent *event) override;
private slots:
	void SlotOpenColorDialog();

	void SlotSetBlurRadiusForGraphicsShadowEffect		(qreal value);
	void SlotSetThicknessForGraphicsShadowEffect	    (qreal value);
	void SlotSetAlphaColorChannelForGraphicsShadowEffect(int value);

	void SlotSetStateForCheckBoxOfWindow(int state);
	void SlotSetStateForCheckBoxOfWidget(int state);
};
}  // namespace N_GraphicsShadowEffect

#endif  // MAIN_WINDOW_H

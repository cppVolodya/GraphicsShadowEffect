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
private:
	GraphicsShadowEffect *m_graphics_shadow_effect_for_window;
	GraphicsShadowEffect *m_graphics_shadow_effect_for_widget;

	QPainterPath m_window_shape;

	QPushButton *m_button_widget;
	QPushButton *m_exit_button;

	QSlider *m_slider_of_blur_radius;
	QSlider *m_slider_of_thickness;
	QSlider *m_slider_of_alpha_color_channel;

	QLabel *m_label_of_blur_radius;
	QLabel *m_label_of_thickness;
	QLabel *m_label_of_alpha_color_channel;

	QCheckBox *m_check_box_of_window;
	QCheckBox *m_check_box_of_widget;

	QColor m_chosen_color;

	QPointF m_last_drag_position;

	int m_state_of_check_box_of_window;
	int m_state_of_check_box_of_widget;

	bool m_mouse_is_pressed;
};
}  // namespace N_GraphicsShadowEffect

#endif  // MAIN_WINDOW_H

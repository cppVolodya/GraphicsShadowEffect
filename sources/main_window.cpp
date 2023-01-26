// Copyright [2022] <Volodymyr Dorozhovets>"

#include <QMouseEvent>
#include <QColorDialog>

#include "main_window.hpp"
#include "default_values.hpp"


namespace N_GraphicsShadowEffect
{
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent, Qt::Window),
	  m_graphics_shadow_effect_for_window(std::make_unique<GraphicsShadowEffect>(this).release()),
      m_graphics_shadow_effect_for_widget(std::make_unique<GraphicsShadowEffect>(this).release()),

	  m_button_widget(nullptr),
	  m_exit_button  (nullptr),

	  m_slider_of_blur_radius	     (nullptr),
	  m_slider_of_thickness  		 (nullptr),
	  m_slider_of_alpha_color_channel(nullptr),

	  m_label_of_blur_radius		(nullptr),
	  m_label_of_thickness  		(nullptr),
	  m_label_of_alpha_color_channel(nullptr),

	  m_check_box_of_window(nullptr),
	  m_check_box_of_widget(nullptr),

	  m_state_of_check_box_of_window(0),
	  m_state_of_check_box_of_widget(0),

	  m_mouse_is_pressed(false)
{
	this->SetDefaultSettings			();
	this->CustomizeGraphicsShadowEffects();
	this->CustomizeWidgets				();
	this->ConfigureBoxLayout			();
	this->SetGraphicsShadowEffects  	();
	this->ConnectSignalsToSlots			();
}

void MainWindow::SetDefaultSettings()
{
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowFlag(Qt::FramelessWindowHint);

	this->setWindowIcon(QIcon(N_DefaultValues::S_PATH_TO_ICON_OF_WINDOW.data()));

	this->resize(N_DefaultValues::S_WIDTH_OF_WINDOW,
				 N_DefaultValues::S_HEIGHT_OF_WINDOW);

	this->m_window_shape.addRoundedRect(N_DefaultValues::S_WINDOW_RECT,
										N_DefaultValues::S_ROUNDNESS_OF_WINDOW_SHAPE,
										N_DefaultValues::S_ROUNDNESS_OF_WINDOW_SHAPE);
}
}  // namespace N_GraphicsShadowEffect

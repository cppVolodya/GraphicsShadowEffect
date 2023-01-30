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

inline void MainWindow::CustomizeGraphicsShadowEffects()
{
	MainWindow::CustomizeGraphicsShadowEffects(this->m_graphics_shadow_effect_for_window);
	MainWindow::CustomizeGraphicsShadowEffects(this->m_graphics_shadow_effect_for_widget);
}

void MainWindow::CustomizeGraphicsShadowEffects(GraphicsShadowEffect *graphics_shadow_effect)
{
	graphics_shadow_effect->SetBlurRadius(N_DefaultValues::S_BLUR_RADIUS);
	graphics_shadow_effect->SetThickness (N_DefaultValues::S_THICKNESS  );
	graphics_shadow_effect->SetColor	  (N_DefaultValues::S_COLOR		 );
}

inline void MainWindow::CustomizeWidgets()
{
	this->CustomizeButtonWidgets  ();
	this->CustomizeCheckBoxWidgets();
	this->CustomizeSliderWidgets  ();
	this->CustomizeLabelWidgets	  ();
}

inline void MainWindow::CustomizeButtonWidgets()
{
	this->m_button_widget = std::make_unique<QPushButton>("Change Color", this).release();
	this->m_exit_button   = std::make_unique<QPushButton>("Exit", 		  this).release();
}

void MainWindow::CustomizeCheckBoxWidgets()
{
	this->m_check_box_of_window = std::make_unique<QCheckBox>("Window", this).release();
	this->m_check_box_of_window->setChecked(false);
	this->m_check_box_of_widget = std::make_unique<QCheckBox>("Widget", this).release();
	this->m_check_box_of_widget->setChecked(false);
}

void MainWindow::CustomizeSliderWidgets()
{
	this->CustomizeSliderWidgetsOfBlurRadius	   ();
	this->CustomizeSliderWidgetsOfThickness 	   ();
	this->CustomizeSliderWidgetsOfAlphaColorChannel();
}

inline void MainWindow::CustomizeSliderWidgetsOfBlurRadius()
{
	this->m_slider_of_blur_radius = std::make_unique<QSlider>(Qt::Horizontal, this).release();
	this->m_slider_of_blur_radius->setRange(N_DefaultValues::S_RANGE_FOR_SLIDER_MIN,
											N_DefaultValues::S_RANGE_FOR_SLIDER_OF_BLUR_RADIUS_MAX);
}

inline void MainWindow::CustomizeSliderWidgetsOfThickness()
{
	this->m_slider_of_thickness = std::make_unique<QSlider>(Qt::Horizontal, this).release();
	this->m_slider_of_thickness->setRange(N_DefaultValues::S_RANGE_FOR_SLIDER_MIN,
										  N_DefaultValues::S_RANGE_FOR_SLIDER_OF_THICKNESS_MAX);
}

inline void MainWindow::CustomizeSliderWidgetsOfAlphaColorChannel()
{
	this->m_slider_of_alpha_color_channel = std::make_unique<QSlider>(Qt::Horizontal, this).release();
	this->m_slider_of_alpha_color_channel->setRange(N_DefaultValues::S_RANGE_FOR_SLIDER_MIN, N_DefaultValues::S_RANGE_FOR_SLIDER_OF_COLOR_MAX);
}

inline void MainWindow::CustomizeLabelWidgets()
{
	this->m_label_of_blur_radius = std::make_unique<QLabel>		   ("Blur Radius        ", this).release();
	this->m_label_of_thickness = std::make_unique<QLabel>  		   ("Thickness          ", this).release();
	this->m_label_of_alpha_color_channel = std::make_unique<QLabel>("Alpha Color Channel", this).release();
}
}  // namespace N_GraphicsShadowEffect

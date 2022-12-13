// Copyright [2022] <Volodymyr Dorozhovets>"

#ifndef DEFAULT_VALUES_HPP
#define DEFAULT_VALUES_HPP

#include <QColor>
#include <QtGlobal>


namespace N_GraphicsShadowEffect::N_DefaultValues
{
inline constexpr static int S_WIDTH_OF_WINDOW {600};
inline constexpr static int S_HEIGHT_OF_WINDOW{600};

inline constexpr static qreal S_ROUNDNESS_OF_WINDOW_SHAPE{20.0};

inline constexpr static qreal  S_BLUR_RADIUS{30.0};
inline constexpr static qreal  S_THICKNESS{3.0};
inline constexpr static QColor S_COLOR{166, 166, 166, 255};

inline constexpr static int S_OFFSET_RECT_OF_WINDOW_FROM_TOP {50};
inline constexpr static int S_OFFSET_RECT_OF_WINDOW_FROM_LEFT{50};

inline constexpr static int S_OFFSET_RECT_OF_WINDOW_FROM_BOTTOM{100};
inline constexpr static int S_OFFSET_RECT_OF_WINDOW_FROM_RIGHT {100};

inline constexpr static QRect S_WINDOW_RECT{S_OFFSET_RECT_OF_WINDOW_FROM_TOP,
							  				S_OFFSET_RECT_OF_WINDOW_FROM_LEFT,
												S_WIDTH_OF_WINDOW  - S_OFFSET_RECT_OF_WINDOW_FROM_BOTTOM,
												S_HEIGHT_OF_WINDOW - S_OFFSET_RECT_OF_WINDOW_FROM_RIGHT};

inline constexpr static int S_RANGE_FOR_SLIDER_MIN{0};

inline constexpr static int S_RANGE_FOR_SLIDER_OF_BLUR_RADIUS_MAX{100};
inline constexpr static int S_RANGE_FOR_SLIDER_OF_THICKNESS_MAX  {100};
inline constexpr static int S_RANGE_FOR_SLIDER_OF_COLOR_MAX		 {255};

inline constexpr static int S_CONTENTS_MARGINS_OF_WINDOW{S_OFFSET_RECT_OF_WINDOW_FROM_BOTTOM};

inline constexpr static std::string_view S_PATH_TO_ICON_OF_WINDOW{":/resources/graphics_shadow_effect.ico"};
}  // namespace N_GraphicsShadowEffect::N_DefaultValues

#endif  // DEFAULT_VALUES_HPP

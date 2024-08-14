#include "ui.h"

void ui_Screen4_screen_init(void)
{
ui_Screen4 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton4 = lv_imgbtn_create(ui_Screen4);
lv_imgbtn_set_src(ui_ImgButton4, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1658756774, NULL);
lv_obj_set_height( ui_ImgButton4, 37);
lv_obj_set_width( ui_ImgButton4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_ImgButton4, -128 );
lv_obj_set_y( ui_ImgButton4, -97 );
lv_obj_set_align( ui_ImgButton4, LV_ALIGN_CENTER );

ui_BrightnessSlider = lv_slider_create(ui_Screen4);
lv_slider_set_value( ui_BrightnessSlider, 80, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_BrightnessSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_BrightnessSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_BrightnessSlider, 174);
lv_obj_set_height( ui_BrightnessSlider, 23);
lv_obj_set_x( ui_BrightnessSlider, -8 );
lv_obj_set_y( ui_BrightnessSlider, -51 );
lv_obj_set_align( ui_BrightnessSlider, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0x88FBDE), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0x88FBDE), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_BrightnessSlider, 10, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0x0D9ADD), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_BrightnessSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_BrightnessSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_BrightnessSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_BrightnessSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_CelsiusFarenheitButton = lv_btn_create(ui_Screen4);
lv_obj_set_width( ui_CelsiusFarenheitButton, 95);
lv_obj_set_height( ui_CelsiusFarenheitButton, 52);
lv_obj_set_x( ui_CelsiusFarenheitButton, -96 );
lv_obj_set_y( ui_CelsiusFarenheitButton, 71 );
lv_obj_set_align( ui_CelsiusFarenheitButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_CelsiusFarenheitButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_CelsiusFarenheitButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_CelsiusFarenheitButton, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_CelsiusFarenheitButton, lv_color_hex(0x88FBDE), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_CelsiusFarenheitButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LanguageButton = lv_btn_create(ui_Screen4);
lv_obj_set_width( ui_LanguageButton, 151);
lv_obj_set_height( ui_LanguageButton, 51);
lv_obj_set_x( ui_LanguageButton, 54 );
lv_obj_set_y( ui_LanguageButton, 70 );
lv_obj_set_align( ui_LanguageButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_LanguageButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_LanguageButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_LanguageButton, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LanguageButton, lv_color_hex(0x0D9ADD), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LanguageButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BrightnessLabel = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_BrightnessLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BrightnessLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_BrightnessLabel, -8 );
lv_obj_set_y( ui_BrightnessLabel, -107 );
lv_obj_set_align( ui_BrightnessLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_BrightnessLabel,"BRIGHTNESS");
lv_obj_set_style_text_color(ui_BrightnessLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BrightnessLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BrightnessLabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label13 = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label13, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label13, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label13, -126 );
lv_obj_set_y( ui_Label13, -49 );
lv_obj_set_align( ui_Label13, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label13,"0");
lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label5 = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 125 );
lv_obj_set_y( ui_Label5, -50 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"100%");
lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CelsiusFarenheitLabel = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_CelsiusFarenheitLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_CelsiusFarenheitLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_CelsiusFarenheitLabel, -99 );
lv_obj_set_y( ui_CelsiusFarenheitLabel, 71 );
lv_obj_set_align( ui_CelsiusFarenheitLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_CelsiusFarenheitLabel,"°C");
lv_obj_set_style_text_color(ui_CelsiusFarenheitLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_CelsiusFarenheitLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_CelsiusFarenheitLabel, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LanguageLabel = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_LanguageLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LanguageLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LanguageLabel, 55 );
lv_obj_set_y( ui_LanguageLabel, 72 );
lv_obj_set_align( ui_LanguageLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_LanguageLabel,"ENGLISH");
lv_obj_set_style_text_color(ui_LanguageLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LanguageLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LanguageLabel, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BrightnessValueLabel = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_BrightnessValueLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BrightnessValueLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_BrightnessValueLabel, -3 );
lv_obj_set_y( ui_BrightnessValueLabel, -85 );
lv_obj_set_align( ui_BrightnessValueLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_BrightnessValueLabel,"80%");
lv_obj_set_style_text_color(ui_BrightnessValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BrightnessValueLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BrightnessValueLabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_ImgButton4, ui_event_ImgButton4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_BrightnessSlider, ui_event_BrightnessSlider, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_CelsiusFarenheitButton, ui_event_CelsiusFarenheitButton, LV_EVENT_ALL, NULL);

}

#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include <time.h>  
#include <max6675.h>


int thermoDO = 12;
int thermoCS = 5;
int thermoCLK = 6;

//Relay pins

int grillrelay = 12;
int warmerrelay = 13;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// Actual Temperature for Grill and warmer
//In celcius
int16_t GrillTemperatureC;
int16_t WarmerTemperatureC;
//In farenheit
int16_t GrillTemperatureF;
int16_t WarmerTemperatureF;

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

// TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
TFT_eSPI tft = TFT_eSPI();

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch( &touchX, &touchY, 600 );

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print( "Data x " );
        Serial.println( touchX );

        Serial.print( "Data y " );
        Serial.println( touchY );
    }
}


// Task to update system time on the display

void displayTimeTask(void *Parameters) {    
    for (;;) {

        // Get current system time
        time_t now = time(NULL);
        struct tm *local = localtime(&now);
        
        // Format time as "MM:SS"
        char minutesStr[3];
        char secondsStr[3];
        lv_snprintf(minutesStr, sizeof(minutesStr), "%02d", local->tm_hour);
        lv_snprintf(secondsStr, sizeof(secondsStr), "%02d", local->tm_min);


        // Update label text
        lv_label_set_text(ui_MinutesLabel, minutesStr);
        lv_label_set_text(ui_SecondsLabel, secondsStr);        
    
        // Delay for 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}



//Function to get current temperature of grill and warmer every 1 sec
void GetTemp(void *parameter){
  for(;;)
  {

  GrillTemperatureC = thermocouple.readCelsius();  //random values for testing
  WarmerTemperatureC = thermocouple.readFahrenheit();  //random values for testing
  char buf1[_UI_TEMPORARY_STRING_BUFFER_SIZE];
  char buf2[_UI_TEMPORARY_STRING_BUFFER_SIZE];
  if(Celcius)
  {
    lv_snprintf(buf1, sizeof(buf1), "%d", GrillTemperatureC);
    lv_label_set_text(ui_GCurrentTempLabel, buf1);
    lv_snprintf(buf2, sizeof(buf2), "%d", WarmerTemperatureC);
    lv_label_set_text(ui_WCurrentTempLabel, buf2);
  }
  else
  {
    //for Fahrenheit conversion
    GrillTemperatureF = (0.5556*GrillTemperatureC) + 32;
    WarmerTemperatureF = (0.5556*WarmerTemperatureC) + 32;

    lv_snprintf(buf1, sizeof(buf1), "%d", GrillTemperatureF);
    lv_label_set_text(ui_GCurrentTempLabel, buf1);
    lv_snprintf(buf2, sizeof(buf2), "%d", WarmerTemperatureF);
    lv_label_set_text(ui_WCurrentTempLabel, buf2);

    }
  
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */

    pinMode(grillrelay, OUTPUT);
    pinMode(warmerrelay, OUTPUT);

    String LVGL_Arduino = "Hello! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    lv_init();
//    lvgl_refresh_timestamp = millis();


#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    tft.setRotation( 1 ); /* Landscape orientation, flipped */

    // Calibration Values for my Setup
    uint16_t calData[5] = { 393, 3484, 305, 3314, 7 };
    tft.setTouch(calData);

    // lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );


    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );

    ui_init();

    //Current temperature task
    xTaskCreate(GetTemp,"Update temperature", 5000, NULL, 2, NULL);

    //Current temperature task
    xTaskCreate(displayTimeTask,"display Time", 5000, NULL, 2, NULL);

    Serial.println( "Setup done" );
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}

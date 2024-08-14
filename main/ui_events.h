#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void Grill_On(lv_event_t * e);
void Grill_Off(lv_event_t * e);
void Warmer_On(lv_event_t * e);
void Warmer_Off(lv_event_t * e);
void DecrementGTemperature(lv_event_t * e);
void DecrementWTemperature(lv_event_t * e);
void IncrementGTemperature(lv_event_t * e);
void IncrementWTemperature(lv_event_t * e);
void SwapCelsiusFarenheit(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

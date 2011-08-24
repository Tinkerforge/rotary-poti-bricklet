/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_ROTARY_POTI_H
#define BRICKLET_ROTARY_POTI_H

#include "ip_connection.h"

typedef Device RotaryPoti;

#define ROTARY_POTI_CALLBACK_POSITION 13
#define ROTARY_POTI_CALLBACK_ANALOG_VALUE 14
#define ROTARY_POTI_CALLBACK_POSITION_REACHED 15
#define ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED 16

void rotary_poti_create(RotaryPoti *rotary_poti, const char *uid);

int rotary_poti_get_position(RotaryPoti *rotary_poti, int16_t *ret_position);
int rotary_poti_get_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value);
int rotary_poti_set_position_callback_period(RotaryPoti *rotary_poti, uint32_t period);
int rotary_poti_get_position_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period);
int rotary_poti_set_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t period);
int rotary_poti_get_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period);
int rotary_poti_set_position_callback_threshold(RotaryPoti *rotary_poti, char option, int16_t min, int16_t max);
int rotary_poti_get_position_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max);
int rotary_poti_set_analog_value_callback_threshold(RotaryPoti *rotary_poti, char option, uint16_t min, uint16_t max);
int rotary_poti_get_analog_value_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);
int rotary_poti_set_debounce_period(RotaryPoti *rotary_poti, uint32_t debounce);
int rotary_poti_get_debounce_period(RotaryPoti *rotary_poti, uint32_t *ret_debounce);
int rotary_poti_position(RotaryPoti *rotary_poti, int16_t *ret_position);
int rotary_poti_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value);
int rotary_poti_position_reached(RotaryPoti *rotary_poti, int16_t *ret_position);
int rotary_poti_analog_value_reached(RotaryPoti *rotary_poti, uint16_t *ret_value);

void rotary_poti_register_callback(RotaryPoti *rotary_poti, uint8_t cb, void *func);

#endif
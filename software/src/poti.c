/* rotary-poti-bricklet
 * Copyright (C) 2010-2012 Olaf Lüke <olaf@tinkerforge.com>
 *
 * poti.c: Implementation of Rotary Poti Bricklet messages
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "poti.h"

#include "bricklib/bricklet/bricklet_communication.h"
#include "bricklib/utility/util_definitions.h"
#include "brickletlib/bricklet_entry.h"
#include "brickletlib/bricklet_simple.h"
#include "bricklib/drivers/adc/adc.h"
#include "config.h"

#define MAX_ADC_VALUE ((1  << 12) - 1)
#define MAX_ROTATIONAL_ANGLE 300
#define POTI_AVERAGE 50

#define SIMPLE_UNIT_POSITION 0
#define SIMPLE_UNIT_ANALOG_VALUE 1

const SimpleMessageProperty smp[] = {
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // TYPE_SET_POSITION_SIGNAL_PERIOD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION_SIGNAL_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // TYPE_SET_ANALOG_VALUE_SIGNAL_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE_SIGNAL_PERIOD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // TYPE_SET_POSITION_SIGNAL_THRESHOLD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION_SIGNAL_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // TYPE_SET_ANALOG_VALUE_SIGNAL_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE_SIGNAL_THRESHOLD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_SET}, // TYPE_SET_DEBOUNCE_PERIOD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_GET}, // TYPE_GET_DEBOUNCE_PERIOD
};

const SimpleUnitProperty sup[] = {
	{position_from_analog_value, SIMPLE_SIGNEDNESS_INT, FID_POSITION, FID_POSITION_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // position
	{analog_value_from_mc, SIMPLE_SIGNEDNESS_UINT, FID_ANALOG_VALUE, FID_ANALOG_VALUE_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // analog value
};

const uint8_t smp_length = sizeof(smp);

void invocation(const ComType com, const uint8_t *data) {
	simple_invocation(com, data);

	if(((MessageHeader*)data)->fid > FID_LAST) {
		BA->com_return_error(data, sizeof(MessageHeader), MESSAGE_ERROR_CODE_NOT_SUPPORTED, com);
	}
}

void constructor(void) {
	_Static_assert(sizeof(BrickContext) <= BRICKLET_CONTEXT_MAX_SIZE, "BrickContext too big");

	BC->poti_avg = 0;
	adc_channel_enable(BS->adc_channel);
	simple_constructor();
}

void destructor(void) {
	simple_destructor();
	adc_channel_disable(BS->adc_channel);
}

int32_t analog_value_from_mc(const int32_t value) {
	return (uint16_t)BA->adc_channel_get_data(BS->adc_channel);
}

int32_t position_from_analog_value(const int32_t value) {
	BC->poti_avg_sum += value;

	if(BC->tick % POTI_AVERAGE == 0) {
		BC->poti_avg_sum += POTI_AVERAGE*(MAX_ADC_VALUE/MAX_ROTATIONAL_ANGLE)/2;

		if(BC->poti_avg_sum > MAX_ADC_VALUE*POTI_AVERAGE) {
			BC->poti_avg_sum = MAX_ADC_VALUE*POTI_AVERAGE;
		}

		BC->poti_avg = MAX_ROTATIONAL_ANGLE/2 -
				       SCALE(BC->poti_avg_sum/POTI_AVERAGE,
                             0,
                             MAX_ADC_VALUE,
                             0,
                             MAX_ROTATIONAL_ANGLE);
		BC->poti_avg_sum = 0;
	}

	return BC->poti_avg;
}

void tick(const uint8_t tick_type) {
	simple_tick(tick_type);
}

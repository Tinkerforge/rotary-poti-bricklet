/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_rotary_poti.h"

#include <string.h>

#define TYPE_GET_POSITION 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_POSITION_CALLBACK_PERIOD 3
#define TYPE_GET_POSITION_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_POSITION_CALLBACK_THRESHOLD 7
#define TYPE_GET_POSITION_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_POSITION 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_POSITION_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*position_func_t)(int16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*position_reached_func_t)(int16_t);
typedef void (*analog_value_reached_func_t)(uint16_t);

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPosition;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t position;
} PACKED GetPositionReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED GetAnalogValueReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetPositionCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetPositionCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetPositionCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetPositionCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED SetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED GetAnalogValueCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t position;
} PACKED PositionCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t position;
} PACKED PositionReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int rotary_poti_get_position(RotaryPoti *rotary_poti, int16_t *ret_position) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION;
	rotary_poti->answer.length = sizeof(GetPositionReturn);
	GetPosition gp;
	gp.stack_id = rotary_poti->stack_id;
	gp.type = TYPE_GET_POSITION;
	gp.length = sizeof(GetPosition);

	ipcon_device_write(rotary_poti, (char *)&gp, sizeof(GetPosition));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionReturn *gpr = (GetPositionReturn *)rotary_poti->answer.buffer;
	*ret_position = gpr->position;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE;
	rotary_poti->answer.length = sizeof(GetAnalogValueReturn);
	GetAnalogValue gav;
	gav.stack_id = rotary_poti->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue);

	ipcon_device_write(rotary_poti, (char *)&gav, sizeof(GetAnalogValue));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn *gavr = (GetAnalogValueReturn *)rotary_poti->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_position_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetPositionCallbackPeriod spcp;
	spcp.stack_id = rotary_poti->stack_id;
	spcp.type = TYPE_SET_POSITION_CALLBACK_PERIOD;
	spcp.length = sizeof(SetPositionCallbackPeriod);
	spcp.period = period;

	ipcon_device_write(rotary_poti, (char *)&spcp, sizeof(SetPositionCallbackPeriod));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_position_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	rotary_poti->answer.length = sizeof(GetPositionCallbackPeriodReturn);
	GetPositionCallbackPeriod gpcp;
	gpcp.stack_id = rotary_poti->stack_id;
	gpcp.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	gpcp.length = sizeof(GetPositionCallbackPeriod);

	ipcon_device_write(rotary_poti, (char *)&gpcp, sizeof(GetPositionCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackPeriodReturn *gpcpr = (GetPositionCallbackPeriodReturn *)rotary_poti->answer.buffer;
	*ret_period = gpcpr->period;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetAnalogValueCallbackPeriod savcp;
	savcp.stack_id = rotary_poti->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod);
	savcp.period = period;

	ipcon_device_write(rotary_poti, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	rotary_poti->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn);
	GetAnalogValueCallbackPeriod gavcp;
	gavcp.stack_id = rotary_poti->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod);

	ipcon_device_write(rotary_poti, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn *gavcpr = (GetAnalogValueCallbackPeriodReturn *)rotary_poti->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_position_callback_threshold(RotaryPoti *rotary_poti, char option, int16_t min, int16_t max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetPositionCallbackThreshold spct;
	spct.stack_id = rotary_poti->stack_id;
	spct.type = TYPE_SET_POSITION_CALLBACK_THRESHOLD;
	spct.length = sizeof(SetPositionCallbackThreshold);
	spct.option = option;
	spct.min = min;
	spct.max = max;

	ipcon_device_write(rotary_poti, (char *)&spct, sizeof(SetPositionCallbackThreshold));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_position_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	rotary_poti->answer.length = sizeof(GetPositionCallbackThresholdReturn);
	GetPositionCallbackThreshold gpct;
	gpct.stack_id = rotary_poti->stack_id;
	gpct.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	gpct.length = sizeof(GetPositionCallbackThreshold);

	ipcon_device_write(rotary_poti, (char *)&gpct, sizeof(GetPositionCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackThresholdReturn *gpctr = (GetPositionCallbackThresholdReturn *)rotary_poti->answer.buffer;
	*ret_option = gpctr->option;
	*ret_min = gpctr->min;
	*ret_max = gpctr->max;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_analog_value_callback_threshold(RotaryPoti *rotary_poti, char option, uint16_t min, uint16_t max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetAnalogValueCallbackThreshold savct;
	savct.stack_id = rotary_poti->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(rotary_poti, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_analog_value_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	rotary_poti->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn);
	GetAnalogValueCallbackThreshold gavct;
	gavct.stack_id = rotary_poti->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold);

	ipcon_device_write(rotary_poti, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn *gavctr = (GetAnalogValueCallbackThresholdReturn *)rotary_poti->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_set_debounce_period(RotaryPoti *rotary_poti, uint32_t debounce) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	SetDebouncePeriod sdp;
	sdp.stack_id = rotary_poti->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod);
	sdp.debounce = debounce;

	ipcon_device_write(rotary_poti, (char *)&sdp, sizeof(SetDebouncePeriod));

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_get_debounce_period(RotaryPoti *rotary_poti, uint32_t *ret_debounce) {
	if(rotary_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(rotary_poti);

	rotary_poti->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	rotary_poti->answer.length = sizeof(GetDebouncePeriodReturn);
	GetDebouncePeriod gdp;
	gdp.stack_id = rotary_poti->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod);

	ipcon_device_write(rotary_poti, (char *)&gdp, sizeof(GetDebouncePeriod));

	if(ipcon_answer_sem_wait_timeout(rotary_poti) != 0) {
		ipcon_sem_post_write(rotary_poti);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn *gdpr = (GetDebouncePeriodReturn *)rotary_poti->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(rotary_poti);

	return E_OK;
}

int rotary_poti_callback_position(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	PositionCallback *pc = (PositionCallback *)buffer;
	((position_func_t)rotary_poti->callbacks[pc->type])(pc->position);
	return sizeof(PositionCallback);
}

int rotary_poti_callback_analog_value(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	AnalogValueCallback *avc = (AnalogValueCallback *)buffer;
	((analog_value_func_t)rotary_poti->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback);
}

int rotary_poti_callback_position_reached(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	PositionReachedCallback *prc = (PositionReachedCallback *)buffer;
	((position_reached_func_t)rotary_poti->callbacks[prc->type])(prc->position);
	return sizeof(PositionReachedCallback);
}

int rotary_poti_callback_analog_value_reached(RotaryPoti *rotary_poti, const unsigned char *buffer) {
	AnalogValueReachedCallback *avrc = (AnalogValueReachedCallback *)buffer;
	((analog_value_reached_func_t)rotary_poti->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback);
}

void rotary_poti_register_callback(RotaryPoti *rotary_poti, uint8_t cb, void *func) {
    rotary_poti->callbacks[cb] = func;
}

void rotary_poti_create(RotaryPoti *rotary_poti, const char *uid) {
	ipcon_device_create(rotary_poti, uid);

	rotary_poti->device_callbacks[TYPE_POSITION] = rotary_poti_callback_position;
	rotary_poti->device_callbacks[TYPE_ANALOG_VALUE] = rotary_poti_callback_analog_value;
	rotary_poti->device_callbacks[TYPE_POSITION_REACHED] = rotary_poti_callback_position_reached;
	rotary_poti->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = rotary_poti_callback_analog_value_reached;
}

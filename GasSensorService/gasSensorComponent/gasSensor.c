#include "legato.h"
#include "interfaces.h"


le_result_t ma_gasSensor_Read(double *gas_value)
{
	int32_t valueMv;
	
	le_result_t res = le_adc_ReadValue("EXT_ADC0", &valueMv);

	if (res != 0)
	{
		return LE_FAULT;
	}

	LE_DEBUG("Gas ADC %d ", valueMv);

	*gas_value = valueMv/1000.0;
	
	return LE_OK;
}


COMPONENT_INIT
{
}
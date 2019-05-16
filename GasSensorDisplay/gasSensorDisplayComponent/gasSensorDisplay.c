#include "legato.h"
#include "interfaces.h"


#define GAS_SENSOR_NAME "gas/leak/value"

#define GAS_SENSOR_DATA "/app/gasSensorToDatahub/gas/leak/value"

#define GAS_SENSOR_OBS "gasSensorOffLimits"

#define GAS_SENSOR_LOWER_LIMIT 0.0000
#define GAS_SENSOR_UPPER_LIMIT 100.0000

//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the alcohol sensor value.
 */
//--------------------------------------------------------------------------------------------------
static void GasSensorUpdateHandler
(
	double timestamp,
	double value,
	void* contextPtr
)
{
	LE_DEBUG("gas sensor PM: = %lf (timestamped %lf)", value, timestamp);
}


//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the gas sensor value.
 */
//--------------------------------------------------------------------------------------------------
static void GasSensorObservationUpdateHandler
(
	double timestamp,	///< time stamp
	double value,		///< gas sensor value,
	void* contextPtr	///< not used 
)
{
	LE_INFO("Observed filtered gas sensor = %lf (timestamped %lf)", value, timestamp);	
}


COMPONENT_INIT
{
	le_result_t result;

	// This will be received from the Data Hub.
	result = io_CreateOutput(GAS_SENSOR_NAME, IO_DATA_TYPE_NUMERIC, "degrees");
	LE_ASSERT(result == LE_OK);

	// Register for notification of updates to the counter value.
	io_AddNumericPushHandler(GAS_SENSOR_NAME, GasSensorUpdateHandler, NULL);

	// Connect to the sensor
	result = admin_SetSource("/app/gasSensorDisplay/" GAS_SENSOR_NAME, GAS_SENSOR_DATA);
	LE_ASSERT(result == LE_OK);

	// Create observation (filter) for alcohol sensor. To set up the "dead band" filter,
	// lower limit assigned to high limit and vice versa (see admin.io doc for details).
	admin_CreateObs(GAS_SENSOR_OBS);
	admin_SetLowLimit(GAS_SENSOR_OBS, GAS_SENSOR_LOWER_LIMIT);
	admin_SetHighLimit(GAS_SENSOR_OBS, GAS_SENSOR_UPPER_LIMIT);
	result = admin_SetSource("/obs/" GAS_SENSOR_OBS, GAS_SENSOR_DATA);
	LE_ASSERT(result == LE_OK);
	admin_AddNumericPushHandler("/obs/" GAS_SENSOR_OBS, GasSensorObservationUpdateHandler, NULL);

	LE_ASSERT(result == LE_OK);
}

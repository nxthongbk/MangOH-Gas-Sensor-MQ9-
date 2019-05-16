/*
 * AUTO-GENERATED _componentMain.c for the gasSensorComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _gasSensorComponent_le_adc_ServiceInstanceName;
const char** le_adc_ServiceInstanceNamePtr = &_gasSensorComponent_le_adc_ServiceInstanceName;
void le_adc_ConnectService(void);
extern const char* _gasSensorComponent_ma_gasSensor_ServiceInstanceName;
const char** ma_gasSensor_ServiceInstanceNamePtr = &_gasSensorComponent_ma_gasSensor_ServiceInstanceName;
void ma_gasSensor_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t gasSensorComponent_LogSession;
le_log_Level_t* gasSensorComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _gasSensorComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _gasSensorComponent_Init(void)
{
    LE_DEBUG("Initializing gasSensorComponent component library.");

    // Advertise server-side IPC interfaces.
    ma_gasSensor_AdvertiseService();

    // Connect client-side IPC interfaces.
    le_adc_ConnectService();

    // Register the component with the Log Daemon.
    gasSensorComponent_LogSession = log_RegComponent("gasSensorComponent", &gasSensorComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_gasSensorComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif

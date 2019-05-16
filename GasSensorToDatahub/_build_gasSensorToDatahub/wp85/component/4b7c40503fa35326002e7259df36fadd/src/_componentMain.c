/*
 * AUTO-GENERATED _componentMain.c for the gasSensorToDatahubComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _gasSensorToDatahubComponent_io_ServiceInstanceName;
const char** io_ServiceInstanceNamePtr = &_gasSensorToDatahubComponent_io_ServiceInstanceName;
void io_ConnectService(void);
extern const char* _gasSensorToDatahubComponent_ma_gasSensor_ServiceInstanceName;
const char** ma_gasSensor_ServiceInstanceNamePtr = &_gasSensorToDatahubComponent_ma_gasSensor_ServiceInstanceName;
void ma_gasSensor_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t gasSensorToDatahubComponent_LogSession;
le_log_Level_t* gasSensorToDatahubComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _gasSensorToDatahubComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _gasSensorToDatahubComponent_Init(void)
{
    LE_DEBUG("Initializing gasSensorToDatahubComponent component library.");

    // Connect client-side IPC interfaces.
    io_ConnectService();
    ma_gasSensor_ConnectService();

    // Register the component with the Log Daemon.
    gasSensorToDatahubComponent_LogSession = log_RegComponent("gasSensorToDatahubComponent", &gasSensorToDatahubComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_gasSensorToDatahubComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif

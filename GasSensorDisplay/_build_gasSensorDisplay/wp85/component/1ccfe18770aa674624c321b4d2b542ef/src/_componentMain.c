/*
 * AUTO-GENERATED _componentMain.c for the gasSensorDisplayComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _gasSensorDisplayComponent_io_ServiceInstanceName;
const char** io_ServiceInstanceNamePtr = &_gasSensorDisplayComponent_io_ServiceInstanceName;
void io_ConnectService(void);
extern const char* _gasSensorDisplayComponent_admin_ServiceInstanceName;
const char** admin_ServiceInstanceNamePtr = &_gasSensorDisplayComponent_admin_ServiceInstanceName;
void admin_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t gasSensorDisplayComponent_LogSession;
le_log_Level_t* gasSensorDisplayComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _gasSensorDisplayComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _gasSensorDisplayComponent_Init(void)
{
    LE_DEBUG("Initializing gasSensorDisplayComponent component library.");

    // Connect client-side IPC interfaces.
    io_ConnectService();
    admin_ConnectService();

    // Register the component with the Log Daemon.
    gasSensorDisplayComponent_LogSession = log_RegComponent("gasSensorDisplayComponent", &gasSensorDisplayComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_gasSensorDisplayComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif

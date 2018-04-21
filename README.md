# React

Small scale reactive framework for microcontrollers and embedded devices.

_React_ is characterized by it small footprint (4KBytes code & 100Bytes RAM) and its ability to create reactive systems.  It does not follow the traditional _threading_ approach where threads continously spine polling for input.  Instead, _React_ installs a set of callbacks that activates its processes when events trigger.  _React_ uses a priority scheme that is dependent on the type of execution of the process.

## Execution States

_React_ supports the following execution states:

OnEvent:
: Processes in this execution state are processed once for each activation.

AfterDelay:
: Processes in this execution state wait for the given delay after activation before being processed once.

Periodic:
: Processes in this execution state are periodically processed after activation.

Continuous:
: Processes in this execution state are processed at most once every time a process from any of the aforementionned execution state is executed.

Sleep:
: No process can be assigned to this execution state.  Sleep is entered when no processes are ready to run and all _background_ process have executed once.  This execution state serve at reducing power consumption.


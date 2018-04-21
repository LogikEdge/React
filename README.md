# React

Small scale reactive framework for microcontrollers and embedded devices.

_React_ is characterized by it small footprint (4KBytes code & 100Bytes RAM) and its ability to create reactive systems.  It does not follow the traditional _threading_ approach where threads continously spine polling for input.  Instead, _React_ installs a set of callbacks that activates _actions_ when events trigger.  _React_ uses a priority scheme that is dependent on the execution state of the _actions_.

## Execution States

_React_ supports the following execution states:

OnEvent:
: Actions in this execution state are executed once for each activation.

AfterDelay:
: Actions in this execution state wait for the given delay after activation before being executed once.

Periodic:
: Actions in this execution state are periodically executed after activation.

Continuous:
: Actions in this execution state are processed at most once every time an _action_ from any of the aforementionned execution state is executed.

Sleep:
: No _action_ can be assigned to this execution state.  Sleep is entered when _no actions_ are ready to run and all _background actions_ have executed once.  This execution state serve at reducing power consumption.


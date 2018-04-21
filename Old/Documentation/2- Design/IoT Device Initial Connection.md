## Device Initial connecion

To simplify establishing a secure connection of new IoT device, the following procedure shall be implemented:

1) Using an installation user login, the gateway is put into 'acquire new device mode'.  This mode is active for a short duration and autonomously reverts back to "no-acquire device mode" after a short period.

2) With the gateway in 'acquire mode', physically connect the device to the gateway.  The gateway and device will exchange identity information and security codes.  This exchange follows this procedure:
    1) The device provides the following information to the gateway:
        - manifacturer identification
        - product type identification
        - product instance uniqu identification
        - device registration URL
    2) Using the provided registration URL the gateway verifies the legality of the device.  The following 3 scenarios are possible:
        - the registration URL confirms the legality of the device and the gateway performs the following:
            - the device is assigned an IoT network unique identifier;
            - the device is assign an initial transmission encryption key;
            - the device is assign an initial reception decryption key;
            - the device is added to the IoT network.
        - the registration URL does not exists or does not respond:
            - the installer is request to answer for the legality (may be disabled in the gateway preferences);
            - the process follows the above steps if the installer accepts the device.
        - the registration URL denies the installation of the device:
            - the device is refused and is powered down.
    3) Once initialy configured, the device can be disconneted from the gateway and installed in its final destination.  It will be able to communicate wirelessly using a secure channel with the gateway.
    4) The gateway goes back into 'no-acquie mode' as soon as the device is physicaly disconnected.
            






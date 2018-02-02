#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Rotary Poti Bricklet

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_rotary_poti import BrickletRotaryPoti

# Callback function for position callback
def cb_position(position):
    print("Position: " + str(position)) # Range: -150 to 150

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    rp = BrickletRotaryPoti(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register position callback to function cb_position
    rp.register_callback(rp.CALLBACK_POSITION, cb_position)

    # Set period for position callback to 0.05s (50ms)
    # Note: The position callback is only called every 0.05 seconds
    #       if the position has changed since the last call!
    rp.set_position_callback_period(50)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()

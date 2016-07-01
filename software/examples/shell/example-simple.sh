#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Rotary Poti Bricklet

# Get current position (range is -150 to 150)
tinkerforge call rotary-poti-bricklet $uid get-position

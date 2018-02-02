#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Rotary Poti Bricklet

# Handle incoming position callbacks
tinkerforge dispatch rotary-poti-bricklet $uid position &

# Set period for position callback to 0.05s (50ms)
# Note: The position callback is only called every 0.05 seconds
#       if the position has changed since the last call!
tinkerforge call rotary-poti-bricklet $uid set-position-callback-period 50

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background

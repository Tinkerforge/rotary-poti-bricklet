#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# set period for position callback to 0.05s (50ms)
# note: the position callback is only called every second if the
#       position has changed since the last call!
tinkerforge call rotary-poti-bricklet $uid set-position-callback-period 50

# handle incoming position callbacks
tinkerforge dispatch rotary-poti-bricklet $uid position

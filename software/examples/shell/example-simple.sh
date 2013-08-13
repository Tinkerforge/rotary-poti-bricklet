#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get current position (value has range -150 to 150)
tinkerforge call rotary-poti-bricklet $uid get-position

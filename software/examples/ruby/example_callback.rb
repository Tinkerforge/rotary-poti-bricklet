#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_rotary_poti'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'ABC' # Change to your UID

ipcon = IPConnection.new # Create IP connection
rp = BrickletRotaryPoti.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Set Period for position callback to 0.05s (50ms)
# Note: The position callback is only called every 50ms if the 
#       position has changed since the last call!
rp.set_position_callback_period 50

# Register position callback (parameter has range -150 to 150)
rp.register_callback(BrickletRotaryPoti::CALLBACK_POSITION) do |position|
  puts "Position: #{position}"
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect

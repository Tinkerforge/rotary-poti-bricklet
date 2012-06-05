#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_rotary_poti'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'ABC' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
rp = BrickletRotaryPoti.new UID # Create device object
ipcon.add_device rp # Add device to IP connection
# Don't use device before it is added to a connection

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
ipcon.destroy

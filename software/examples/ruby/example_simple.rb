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

# Get current position of poti (return value has range -150 to 150)
position = rp.get_position
puts "Position: #{position}"

puts 'Press key to exit'
$stdin.gets
ipcon.destroy

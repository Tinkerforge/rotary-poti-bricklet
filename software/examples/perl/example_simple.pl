#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPoti;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Rotary Poti Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $rp = Tinkerforge::BrickletRotaryPoti->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current position
my $position = $rp->get_position();
print "Position: $position\n"; # Range: -150 to 150

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();

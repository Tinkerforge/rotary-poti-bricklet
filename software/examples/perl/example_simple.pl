#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPoti;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $rp = Tinkerforge::BrickletRotaryPoti->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current position (range is -150 to 150)
my $position = $rp->get_position();
print "Position: " . $position . "\n";

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();

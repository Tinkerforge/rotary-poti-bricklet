#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPoti;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'eZj'; # Change to your UID

my $ipcon = IPConnection->new(); # Create IP connection
my $poti = BrickletRotaryPoti->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current position of poti (return value has range -150 to 150)
print "\nPosition: ".$poti->get_position()."\n";

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();

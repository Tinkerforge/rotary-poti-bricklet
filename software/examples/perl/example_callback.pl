#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPoti;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'eZj'; # Change to your UID

# Callback function for position callback (parameter has range -150 to 150)
sub cb_position
{
	my ($position) = @_;

	print "\nPosition: $position\n";
}
    
my $ipcon = IPConnection->new(); # Create IP connection
my $poti = BrickletRotaryPoti->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set Period for position callback to 0.05s (50ms)
# Note: The position callback is only called every 50ms if the 
#       position has changed since the last call!
$poti->set_position_callback_period(50);

# Register position callback to function cb_position
$poti->register_callback($poti->CALLBACK_POSITION, 'cb_position');

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();

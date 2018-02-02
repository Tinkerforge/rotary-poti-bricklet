#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPoti;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Rotary Poti Bricklet

# Callback subroutine for position callback
sub cb_position
{
    my ($position) = @_;

    print "Position: $position\n"; # Range: -150 to 150
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $rp = Tinkerforge::BrickletRotaryPoti->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register position callback to subroutine cb_position
$rp->register_callback($rp->CALLBACK_POSITION, 'cb_position');

# Set period for position callback to 0.05s (50ms)
# Note: The position callback is only called every 0.05 seconds
#       if the position has changed since the last call!
$rp->set_position_callback_period(50);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();

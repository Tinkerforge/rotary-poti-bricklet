<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPoti.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPoti;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'ABC'; // Change to your UID

# Callback function for position callback (parameter has range -150 to 150)
function cb_position($position)
{
	echo "Position: $position\n";
}

$ipcon = new IPConnection(); // Create IP connection
$poti = new BrickletRotaryPoti(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Set Period for position callback to 0.05s (50ms)
// Note: The position callback is only called every 50ms if the 
//       position has changed since the last call!
$poti->setPositionCallbackPeriod(50);

# Register position callback to function cb_position
$poti->registerCallback(BrickletRotaryPoti::CALLBACK_POSITION, 'cb_position');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>

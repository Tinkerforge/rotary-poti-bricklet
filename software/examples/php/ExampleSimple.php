<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPoti.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPoti;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Rotary Poti Bricklet

$ipcon = new IPConnection(); // Create IP connection
$rp = new BrickletRotaryPoti(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current position (range is -150 to 150)
$position = $rp->getPosition();
echo "Position: $position\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>

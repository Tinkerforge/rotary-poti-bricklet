<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPoti.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPoti;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'ABC'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$poti = new BrickletRotaryPoti(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current position of poti (return value has range -150 to 150)
$position = $poti->getPosition();

echo "Position: $position\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>

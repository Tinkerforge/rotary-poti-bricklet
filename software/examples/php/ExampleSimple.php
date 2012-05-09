<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPoti.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPoti;

$host = 'localhost';
$port = 4223;
$uid = 'ABC'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$poti = new BrickletRotaryPoti($uid); // Create device object

$ipcon->addDevice($poti); // Add device to IP connection
// Don't use device before it is added to a connection

// Get current position of poti (return value has range -150 to 150)
$position = $poti->getPosition();

echo "Position: $position\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>

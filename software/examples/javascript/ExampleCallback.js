var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Rotary Poti Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var rp = new Tinkerforge.BrickletRotaryPoti(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set period for position callback to 0.05s (50ms)
        // Note: The position callback is only called every 0.05 seconds
        //       if the position has changed since the last call!
        rp.setPositionCallbackPeriod(50);
    }
);

// Register position callback
rp.on(Tinkerforge.BrickletRotaryPoti.CALLBACK_POSITION,
    // Callback function for position callback
    function (position) {
        console.log('Position: ' + position); // Range: -150 to 150
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);

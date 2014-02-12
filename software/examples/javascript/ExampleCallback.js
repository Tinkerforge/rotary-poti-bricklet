var IPConnection = require('Tinkerforge/IPConnection');
var BrickletRotaryPoti = require('Tinkerforge/BrickletRotaryPoti');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'ek5';// Change to your UID

var ipcon = new IPConnection();// Create IP connection
var poti = new BrickletRotaryPoti(UID, ipcon);// Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        console.log('Error: '+error);        
    }
);// Connect to brickd

// Don't use device before ipcon is connected
ipcon.on(IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
        // Set Period for position callback to 0.05s (50ms)
        // Note: The position callback is only called every 50ms if the 
        // position has changed since the last call!
        poti.setPositionCallbackPeriod(50);      
    }
);

// Register position callback
poti.on(BrickletRotaryPoti.CALLBACK_POSITION,
    // Callback function for position callback (parameter has range -150 to 150)
    function(position) {
        console.log('Position: '+position);
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data',
    function(data) {
        ipcon.disconnect();
        process.exit(0);
    }
);


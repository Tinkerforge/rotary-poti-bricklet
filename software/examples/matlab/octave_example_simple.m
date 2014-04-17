function octave_example_simple
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "eZo"; % Change to your UID
    
    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    poti = java_new("com.tinkerforge.BrickletRotaryPoti", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position of poti (return value has range -150 to 150)
    position = poti.getPosition();
    fprintf('Position: %s\n', position.toString());

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end



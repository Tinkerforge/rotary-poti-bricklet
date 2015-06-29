function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "9BS"; % Change to your UID
    
    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    poti = java_new("com.tinkerforge.BrickletRotaryPoti", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position of poti (return value has range -150 to 150)
    position = poti.getPosition();
    fprintf("Position: %d\n", short2int(position));

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end

function int = short2int(short)
    if compare_versions(version(), "3.8", "<=")
        int = short.intValue();
    else
        int = short;
    end
end

function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Rotary Poti Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    rp = javaObject("com.tinkerforge.BrickletRotaryPoti", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position
    position = rp.getPosition();
    fprintf("Position: %d\n", java2int(position)); % Range: -150 to 150

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

function int = java2int(value)
    if compare_versions(version(), "3.8", "<=")
        int = value.intValue();
    else
        int = value;
    end
end

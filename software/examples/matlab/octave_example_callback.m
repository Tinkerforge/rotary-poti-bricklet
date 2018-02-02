function octave_example_callback()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Rotary Poti Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    rp = javaObject("com.tinkerforge.BrickletRotaryPoti", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register position callback to function cb_position
    rp.addPositionCallback(@cb_position);

    % Set period for position callback to 0.05s (50ms)
    % Note: The position callback is only called every 0.05 seconds
    %       if the position has changed since the last call!
    rp.setPositionCallbackPeriod(50);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for position callback
function cb_position(e)
    fprintf("Position: %d\n", java2int(e.position)); % Range: -150 to 150
end

function int = java2int(value)
    if compare_versions(version(), "3.8", "<=")
        int = value.intValue();
    else
        int = value;
    end
end

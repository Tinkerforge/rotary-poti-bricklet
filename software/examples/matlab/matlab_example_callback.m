function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRotaryPoti;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Rotary Poti Bricklet

    ipcon = IPConnection(); % Create IP connection
    rp = handle(BrickletRotaryPoti(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register position callback to function cb_position
    set(rp, 'PositionCallback', @(h, e) cb_position(e));

    % Set period for position callback to 0.05s (50ms)
    % Note: The position callback is only called every 0.05 seconds
    %       if the position has changed since the last call!
    rp.setPositionCallbackPeriod(50);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for position callback (parameter has range -150 to 150)
function cb_position(e)
    fprintf('Position: %i\n', e.position);
end

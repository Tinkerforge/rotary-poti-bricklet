function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRotaryPoti;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'eZo'; % Change to your UID
    
    ipcon = IPConnection(); % Create IP connection
    poti = BrickletRotaryPoti(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Set Period for position callback to 0.05s (50ms)
    % Note: The position callback is only called every 50ms if the 
    %       position has changed since the last call!
    poti.setPositionCallbackPeriod(1000);

    % Register position callback to function cb_position
    set(poti, 'PositionCallback', @(h, e) cb_position(e));

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end

% Callback function for position callback (parameter has range -150 to 150)
function cb_position(e)
    fprintf('Position: %g\n', e.position);
end

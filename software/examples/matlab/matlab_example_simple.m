function matlab_example_callback
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRotaryPoti;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'eZo'; % Change to your UID
    
    ipcon = IPConnection(); % Create IP connection
    poti = BrickletRotaryPoti(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position of poti (return value has range -150 to 150)
    position = poti.getPosition();
    fprintf('Position: %g\n', position);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end

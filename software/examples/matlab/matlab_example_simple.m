function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRotaryPoti;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    rp = BrickletRotaryPoti(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position (range is -150 to 150)
    position = rp.getPosition();
    fprintf('Position: %i\n', position);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRotaryPoti;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Rotary Poti Bricklet

    ipcon = IPConnection(); % Create IP connection
    rp = handle(BrickletRotaryPoti(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position
    position = rp.getPosition();
    fprintf('Position: %i\n', position); % Range: -150 to 150

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

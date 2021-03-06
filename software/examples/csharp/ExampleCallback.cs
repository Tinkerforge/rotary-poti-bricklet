using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Rotary Poti Bricklet

	// Callback function for position callback
	static void PositionCB(BrickletRotaryPoti sender, short position)
	{
		Console.WriteLine("Position: " + position); // Range: -150 to 150
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletRotaryPoti rp = new BrickletRotaryPoti(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register position callback to function PositionCB
		rp.PositionCallback += PositionCB;

		// Set period for position callback to 0.05s (50ms)
		// Note: The position callback is only called every 0.05 seconds
		//       if the position has changed since the last call!
		rp.SetPositionCallbackPeriod(50);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}

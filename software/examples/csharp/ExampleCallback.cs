using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback function for position callback (parameter has range -150 to 150) 
	static void PositionCB(short position)
	{
		System.Console.WriteLine("Position: " + position);
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletRotaryPoti poti = new BrickletRotaryPoti(UID); // Create device object
		ipcon.AddDevice(poti); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Set Period for position callback to 0.05s (50ms)
		// Note: The position callback is only called every second if the 
		//       position has changed since the last call!
		poti.SetPositionCallbackPeriod(50);

		// Register position callback to function PositionCB
		poti.RegisterCallback(new BrickletRotaryPoti.Position(PositionCB));

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
		ipcon.Destroy();
	}
}

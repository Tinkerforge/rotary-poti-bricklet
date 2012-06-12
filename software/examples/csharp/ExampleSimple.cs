using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletRotaryPoti poti = new BrickletRotaryPoti(UID); // Create device object
		ipcon.AddDevice(poti); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Get current position of poti (return value has range -150 to 150) 
		short position = poti.GetPosition();

		System.Console.WriteLine("Position: " + position);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
		ipcon.Destroy();
	}
}

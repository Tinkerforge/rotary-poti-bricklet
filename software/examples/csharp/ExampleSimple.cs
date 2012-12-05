using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletRotaryPoti poti = new BrickletRotaryPoti(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get current position of poti (return value has range -150 to 150) 
		short position = poti.GetPosition();

		System.Console.WriteLine("Position: " + position);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}

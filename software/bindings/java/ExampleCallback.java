import com.tinkerforge.BrickletRotaryPoti;
import com.tinkerforge.IPConnection;

public class ExampleCallback {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException

		BrickletRotaryPoti rp = new BrickletRotaryPoti(UID); // Create device object

		// Add device to ip connection
		ipcon.addDevice(rp); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection
		

		// Set Period for position callback to 0.05s (50ms)
		// Note: The position callback is only called every second if the 
		//       position has changed since the last call!
		rp.setPositionCallbackPeriod(50);

		// Add and implement position listener (called if position changes)
		rp.addListener(new BrickletRotaryPoti.PositionListener() {
			public void position(short position) {
				System.out.println("Position: " + position);
			}
		});
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}

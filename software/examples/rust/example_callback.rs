use std::{error::Error, io, thread};
use tinkerforge::{ip_connection::IpConnection, rotary_poti_bricklet::*};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Rotary Poti Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let rp = RotaryPotiBricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    let position_receiver = rp.get_position_callback_receiver();

    // Spawn thread to handle received callback messages.
    // This thread ends when the `rp` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for position in position_receiver {
            println!("Position: {}", position); // Range: -150 to 150
        }
    });

    // Set period for position receiver to 0.05s (50ms).
    // Note: The position callback is only called every 0.05 seconds
    //       if the position has changed since the last call!
    rp.set_position_callback_period(50);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}

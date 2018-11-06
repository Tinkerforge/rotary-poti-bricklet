use std::{error::Error, io};

use tinkerforge::{ipconnection::IpConnection, rotary_poti_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Rotary Poti Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let rotary_poti_bricklet = RotaryPotiBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get current position
    let position = rotary_poti_bricklet.get_position().recv()?;
    println!("Position: {}", position); // Range: -150 to 150

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}

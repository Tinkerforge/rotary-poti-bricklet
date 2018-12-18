package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/rotary_poti_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Rotary Poti Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	rp, _ := rotary_poti_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get current position.
	position, _ := rp.GetPosition()
	fmt.Printf("Position: \n", position) // Range: -150 to 150

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}

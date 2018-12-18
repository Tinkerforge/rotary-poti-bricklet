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

	rp.RegisterPositionCallback(func(position int16) {
		fmt.Printf("Position: %d\n", position) // Range: -150 to 150
	})

	// Set period for position receiver to 0.05s (50ms).
	// Note: The position callback is only called every 0.05 seconds
	//       if the position has changed since the last call!
	rp.SetPositionCallbackPeriod(50)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}

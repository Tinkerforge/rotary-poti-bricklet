Imports System
Imports Tinkerforge

Module ExampleSimple
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Rotary Poti Bricklet

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim rp As New BrickletRotaryPoti(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get current position
        Dim position As Short = rp.GetPosition()
        Console.WriteLine("Position: " + position.ToString()) ' Range: -150 to 150

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module

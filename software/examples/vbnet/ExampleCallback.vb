Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Rotary Poti Bricklet

    ' Callback subroutine for position callback (parameter has range -150 to 150)
    Sub PositionCB(ByVal sender As BrickletRotaryPoti, ByVal position As Short)
        Console.WriteLine("Position: " + position.ToString())
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim rp As New BrickletRotaryPoti(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register position callback to subroutine PositionCB
        AddHandler rp.Position, AddressOf PositionCB

        ' Set period for position callback to 0.05s (50ms)
        ' Note: The position callback is only called every 0.05 seconds
        '       if the position has changed since the last call!
        rp.SetPositionCallbackPeriod(50)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module

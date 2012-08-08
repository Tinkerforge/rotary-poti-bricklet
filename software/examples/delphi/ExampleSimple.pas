program ExampleSimple;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletRotaryPoti;

type
  TExample = class
  private
    ipcon: TIPConnection;
    rp: TBrickletRotaryPoti;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Hh'; { Change to your UID }

var
  e: TExample;

procedure TExample.Execute;
var position: smallint;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  rp := TBrickletRotaryPoti.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(rp);
  { Don't use device before it is added to a connection }

  { Get current position (value has range 0-100) }
  position := rp.GetPosition;
  WriteLn(Format('Position: %d', [position]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.

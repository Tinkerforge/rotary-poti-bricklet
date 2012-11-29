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
  { Create IP connection }
  ipcon := TIPConnection.Create();

  { Create device object }
  rp := TBrickletRotaryPoti.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Get current position (value has range 0-100) }
  position := rp.GetPosition;
  WriteLn(Format('Position: %d', [position]));

  WriteLn('Press key to exit');
  ReadLn;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.

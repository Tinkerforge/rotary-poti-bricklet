/*************************************************************
 * This file was automatically generated on 2011-09-20.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

namespace Tinkerforge
{
	public class BrickletRotaryPoti : Device 
	{
		private static byte TYPE_GET_POSITION = 1;
		private static byte TYPE_GET_ANALOG_VALUE = 2;
		private static byte TYPE_SET_POSITION_CALLBACK_PERIOD = 3;
		private static byte TYPE_GET_POSITION_CALLBACK_PERIOD = 4;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD = 5;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD = 6;
		private static byte TYPE_SET_POSITION_CALLBACK_THRESHOLD = 7;
		private static byte TYPE_GET_POSITION_CALLBACK_THRESHOLD = 8;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD = 9;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD = 10;
		private static byte TYPE_SET_DEBOUNCE_PERIOD = 11;
		private static byte TYPE_GET_DEBOUNCE_PERIOD = 12;
		private static byte TYPE_POSITION = 13;
		private static byte TYPE_ANALOG_VALUE = 14;
		private static byte TYPE_POSITION_REACHED = 15;
		private static byte TYPE_ANALOG_VALUE_REACHED = 16;

		public delegate void Position(short position);
		public delegate void AnalogValue(ushort value);
		public delegate void PositionReached(short position);
		public delegate void AnalogValueReached(ushort value);

		public BrickletRotaryPoti(string uid) : base(uid) 
		{
			messageCallbacks[TYPE_POSITION] = new MessageCallback(CallbackPosition);
			messageCallbacks[TYPE_ANALOG_VALUE] = new MessageCallback(CallbackAnalogValue);
			messageCallbacks[TYPE_POSITION_REACHED] = new MessageCallback(CallbackPositionReached);
			messageCallbacks[TYPE_ANALOG_VALUE_REACHED] = new MessageCallback(CallbackAnalogValueReached);
		}

		public void GetPosition(out short position)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPosition in time");
			}

			position = LEConverter.ShortFrom(4, answer);

			writeEvent.Set();
		}

		public void GetAnalogValue(out ushort value)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValue in time");
			}

			value = LEConverter.UShortFrom(4, answer);

			writeEvent.Set();
		}

		public void SetPositionCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_POSITION_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_POSITION_CALLBACK_PERIOD, false);
		}

		public void GetPositionCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPositionCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, false);
		}

		public void GetAnalogValueCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetPositionCallbackThreshold(char option, short min, short max)
		{
			byte[] data = new byte[9];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_POSITION_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)9, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(min, 5, data);
			LEConverter.To(max, 7, data);

			ipcon.Write(this, data, TYPE_SET_POSITION_CALLBACK_THRESHOLD, false);
		}

		public void GetPositionCallbackThreshold(out char option, out short min, out short max)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPositionCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			min = LEConverter.ShortFrom(5, answer);
			max = LEConverter.ShortFrom(7, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackThreshold(char option, ushort min, ushort max)
		{
			byte[] data = new byte[9];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)9, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(min, 5, data);
			LEConverter.To(max, 7, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, false);
		}

		public void GetAnalogValueCallbackThreshold(out char option, out ushort min, out ushort max)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			min = LEConverter.UShortFrom(5, answer);
			max = LEConverter.UShortFrom(7, answer);

			writeEvent.Set();
		}

		public void SetDebouncePeriod(uint debounce)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(debounce, 4, data);

			ipcon.Write(this, data, TYPE_SET_DEBOUNCE_PERIOD, false);
		}

		public void GetDebouncePeriod(out uint debounce)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_DEBOUNCE_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetDebouncePeriod in time");
			}

			debounce = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public int CallbackPosition(byte[] data)
		{
			short position = LEConverter.ShortFrom(4, data);

			((Position)callbacks[TYPE_POSITION])(position);
			return 6;
		}

		public int CallbackAnalogValue(byte[] data)
		{
			ushort value = LEConverter.UShortFrom(4, data);

			((AnalogValue)callbacks[TYPE_ANALOG_VALUE])(value);
			return 6;
		}

		public int CallbackPositionReached(byte[] data)
		{
			short position = LEConverter.ShortFrom(4, data);

			((PositionReached)callbacks[TYPE_POSITION_REACHED])(position);
			return 6;
		}

		public int CallbackAnalogValueReached(byte[] data)
		{
			ushort value = LEConverter.UShortFrom(4, data);

			((AnalogValueReached)callbacks[TYPE_ANALOG_VALUE_REACHED])(value);
			return 6;
		}

		public void RegisterCallback(System.Delegate d)
		{
			if(d.GetType() == typeof(Position))
			{
				callbacks[TYPE_POSITION] = d;
			}
			else if(d.GetType() == typeof(AnalogValue))
			{
				callbacks[TYPE_ANALOG_VALUE] = d;
			}
			else if(d.GetType() == typeof(PositionReached))
			{
				callbacks[TYPE_POSITION_REACHED] = d;
			}
			else if(d.GetType() == typeof(AnalogValueReached))
			{
				callbacks[TYPE_ANALOG_VALUE_REACHED] = d;
			}
		}
	}
}

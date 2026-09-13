import time
import serial
import pydirectinput

pydirectinput.PAUSE = 0.0001
PORT = "COM7"  # Update with your active COM port from Device Manager
BAUD = 115200  # Matched with Arduino setup

print(f"Listening on {PORT} at {BAUD} baud...")
ser = serial.Serial(PORT, BAUD, timeout=0.01)

def send_keypress(key_name):
    pydirectinput.keyDown(key_name)
    time.sleep(0.02)  # Holds key down for 20ms to allow Raylib frame capture
    pydirectinput.keyUp(key_name)

try:
    while True:
        if ser.in_waiting > 0:
            # Read all pending data at once to prevent input queue lag
            raw_data = ser.read(ser.in_waiting).decode("utf-8", errors="ignore")
            
            if "U" in raw_data:
                print("Button U -> Sending Up Arrow")
                send_keypress("up")
            elif "D" in raw_data:
                print("Button D -> Sending Down Arrow")
                send_keypress("down")
            elif "L" in raw_data:
                print("Button L -> Sending Left Arrow")
                send_keypress("left")
            elif "R" in raw_data:
                print("Button R -> Sending Right Arrow")
                send_keypress("right")
                
        time.sleep(0.001)
except KeyboardInterrupt:
    print("\nClosing connection...")
    ser.close()
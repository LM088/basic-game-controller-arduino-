# basic-game-controller-arduino-

### Hardware
Hardware code is self explanatory. For circuit, check <a href="https://www.tinkercad.com/things/5jDKkOSg34C-restored-v203-button-push-for-game">tinkercad sketch.</a> 

---

### Software
After uploading code to arduino, build snake game from raylib repo using the command
<code>g++ snake.cpp -lraylib -lm -ldl -lpthread -o snake</code>
and then execute using command 
<code>./snake</code>
Controller works by sending "L","R","U","D" back to computer, which is parsed by the python script on arduino_bridge.py. It uses libraries pynput and pyserial for serial communication and to parse keystrokes. Run command (in venv if on linux):
<code>pip install pyserial pynput</code>
Due to port forwarding issues, game was run on wsl but the script was run from windows using powershell in administrator mode. In powershell, run script using command:
<code>py arduino_bridge.py</code>

    > Note: PORT is set to COM7 in the script because arduino was connected to COM7 at the time. Edit code with your own COM port.

Once script is active, make raylib game the active window. Every button press will send a byte containing characters "L","R","U",or "D" which will be parsed by the script to process left, right, up or down keystrokes. 




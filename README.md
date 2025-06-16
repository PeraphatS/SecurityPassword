# 🔐 Password Security System (ESP32 + Keypad + OLED + Buzzer)

A simple but functional security system that accepts numeric password input via a 4x4 keypad and displays the entered digits on an OLED screen. The system uses a buzzer to provide feedback and allows clearing or checking the password using the `*` and `#` keys.

## 🎯 Features

- 📟 Keypad 4x4 for password input
- 🖥️ OLED 128x64 display for UI
- 🔊 Buzzer for audio feedback
- ✅ Password verification
- 🔁 `*` key to clear input
- 🔐 `#` key to submit password
- ❌ Lockout after 3 failed attempts

---

## 🧩 Components

| Component         | Description                      |
|------------------|----------------------------------|
| ESP32 DevKit V1   | Microcontroller board             |
| Keypad 4x4        | For password input                |
| OLED 128x64 (I2C) | Display password and status       |
| Piezo Buzzer      | Audible feedback (success/fail)   |

---

## 🔌 Wiring (ESP32)

| Module      | ESP32 Pin |
|-------------|------------|
| Keypad R1-R4 | GPIO 19, 18, 5, 17 |
| Keypad C1-C4 | GPIO 16, 4, 2, 15  |
| OLED SDA     | GPIO 21            |
| OLED SCL     | GPIO 22            |
| Buzzer (+)   | GPIO 14            |
| Buzzer (–)   | GND                |

---

## 🧠 How It Works

1. User inputs password via keypad.
2. Input is shown in real-time on OLED.
3. Press `#` to check password.
   - If correct → show “✅ Access Granted”, beep once.
   - If incorrect → show “❌ Access Denied”, beep once.
4. Press `*` to clear current input.
5. After 3 incorrect attempts, system locks and shows “🔒 Locked Out!”

---


---

## ▶️ Simulation (Wokwi)

Try this project in your browser with Wokwi:  
🔗 [Click to Simulate]([https://wokwi.com/projects/433540660767403009]) *(replace with actual link)*

---

## 📁 Files Included

- `code.ino` — Main Arduino sketch
- `README.md` — Project documentation

---

## 📜 License

This project is open-source under the MIT License.



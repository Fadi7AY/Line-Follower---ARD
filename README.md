
---

# Line Follower - ARD

This project is an **Arduino-based line-following robot** designed to follow a black line on a white surface using five infrared (IR) sensors and two DC motors.

The system reads the sensors and adjusts the motor speeds to keep the robot aligned on the line, enabling smooth and responsive navigation.

---

## 🚀 Features

✅ Reads five IR sensors for precise line detection
✅ Controls two DC motors using L298N or similar motor driver
✅ Adjusts speed dynamically for turning and straight motion
✅ Includes optional Serial Monitor output for debugging

---

## 🛠️ Components

* Arduino Uno (or compatible)
* L298N motor driver module (or similar)
* Two DC motors with wheels
* Five IR reflective sensors (connected to analog pins A0–A4)
* Power supply (battery pack or external source)
* Chassis and wiring

---

## ⚙️ Wiring Setup

| Arduino Pin | Connected To             |
| ----------- | ------------------------ |
| 5 (ENA)     | Left motor speed (PWM)   |
| 6 (IN1)     | Left motor direction 1   |
| 7 (IN2)     | Left motor direction 2   |
| 8 (IN3)     | Right motor direction 1  |
| 9 (IN4)     | Right motor direction 2  |
| 10 (ENB)    | Right motor speed (PWM)  |
| A0–A4       | IR sensors S5–S1 (input) |

---

## 🏗️ How It Works

The five IR sensors detect the black line on a white surface:

* **S3** (center) keeps the robot going straight.
* **S1 & S2** guide left turns.
* **S4 & S5** guide right turns.
* When no sensors detect the line, the robot defaults to forward motion.

The code uses **analogWrite()** for PWM motor speed control and **digitalWrite()** to set motor directions.

---

## 🔧 Setup & Upload

1. Connect all components as described in the wiring table.
2. Install the [Arduino IDE](https://www.arduino.cc/en/software).
3. Open the `line_follower.ino` sketch.
4. Select your board and port in **Tools → Board / Port**.
5. Upload the code to your Arduino.

You can open the **Serial Monitor** at 9600 baud to view sensor readings in real time (optional for debugging).

---

## 📄 License

This project is open-source under the MIT License.
Feel free to use, modify, and share!

---

If you want, I can also prepare:
✅ A badge section (build status, license, etc.)
✅ A troubleshooting section for common issues
✅ A `CONTRIBUTING.md` or issues template

Just let me know!

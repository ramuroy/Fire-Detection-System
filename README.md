# 🔥 **Fire Detection System using Arduino**  

This project is a **Fire Detection System** built using an **Arduino Uno**, an **MQ-2 smoke sensor**, an **LED**, and a **buzzer**. It detects smoke levels and provides a **local visual and audible alert**, making it useful for **fire safety and early-warning applications**.  

---

## 🛠️ **Components Used**  
- 🔹 **Arduino Uno** – Processes sensor data and controls outputs.  
- 🔹 **MQ-2 Smoke Sensor** – Detects smoke and combustible gases.  
- 🔹 **LED (+ ~220–330 Ω resistor)** – Visual alert when smoke is detected.  
- 🔹 **Buzzer** – Audible alert for fire warnings.  

---

## 🔌 **Wiring**  
| Arduino Pin | Connects to |
|-------------|-------------|
| A0 | MQ-2 **analog out (AO)** (sensor VCC → 5V, GND → GND) |
| D7 | LED **+** via a ~220–330 Ω resistor (LED − → GND) |
| D8 | Buzzer **+** (buzzer − → GND) |

> ⚠️ MQ-2 sensors need their heater to **warm up** before readings are reliable. The sketch ignores the sensor for the first ~20 s after power-on (`WARMUP_MS`) to avoid boot-time false alarms, and uses a **hysteresis band** around the trip point so the alarm latches instead of chattering. The threshold (`ALARM_ON`/`ALARM_OFF`) is **uncalibrated** — tune it per sensor and environment.

---

## ⚙️ **How It Works**  
1️⃣ After a short warm-up, the **MQ-2 sensor** continuously monitors the air.  
2️⃣ If **smoke concentration exceeds the trip point**, the **Arduino activates the LED and buzzer**.  
3️⃣ The alarm clears once the smoke level falls back below the lower threshold.  

---

## 📝 **Features**  
✅ **Detects smoke and combustible gases** using an MQ-2 sensor  
✅ **Local visual (LED) + audible (buzzer) alert**  
✅ **Sensor warm-up gate** avoids false alarms at power-on  
✅ **Hysteresis** prevents alarm chatter near the threshold  

---

## 🌍 **Applications**  
🔹 **Fire Alarm System** – Early warning for fire hazards.  
🔹 **Gas Leak Detection** – Detects combustible gases in homes and workshops.  
🔹 **Kitchen Safety** – Alerts users of excess smoke while cooking.  
🔹 **Workshop / Garage Monitoring** – A simple standalone smoke alert.  

> ℹ️ This is a **standalone local alert** (LED + buzzer) with no networking. Remote/IoT monitoring or home-automation integration would be a future extension, not part of this build.

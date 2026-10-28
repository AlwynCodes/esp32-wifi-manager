# BCA188 — Laboratory Activity 9
## ESP32 Wi-Fi Manager

| | |
|---|---|
| **Name** | Alwyn Jade Reuyan |
| **Student No.** | 2024-1316 |

---

## Practice Tasks

| # | Test | Observation |
|---|------|-------------|
| 1 | Incorrect password | ESP32 fails to connect, remains in the captive portal until the 3-minute timeout, then reboots. |
| 2 | Reset saved credentials | Holding BOOT for 3–5 s wipes the NVS-stored credentials; the `ESP32-Setup` access point reappears on the phone. |
| 3 | Change portal name | Editing the `WiFiManager` setup string and re-uploading changes the broadcasted SSID. |
| 4 | Connect to a new network | After reset, entering the correct credentials for **PLDTHOMEFIBRE** yields a successful connection with IP `192.168.1.17`. |

---

## Explanation

The ESP32 connected to a different network **without any code change** because the WiFiManager library persists the SSID and password in the chip's **NVS (Non-Volatile Storage)** partition. On each boot the library reads NVS first: if valid credentials exist it attempts a direct connection and skips the setup portal entirely. Only when NVS is empty (e.g., after a factory reset or a long BOOT press) does it fall back to broadcasting the captive portal for user input.   
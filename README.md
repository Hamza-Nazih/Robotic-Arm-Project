# Robotic Arm Project

## 🔧 Project Overview
This project involves the design and development of an **automated robotic arm** capable of recognizing and sorting colored cubes using **computer vision (OpenCV & MediaPipe)**. The robotic arm is controlled using an **Arduino-based system** with real-time feedback from sensors for precise manipulation.

## 🎯 Objectives
- Automate the sorting of colored cubes using **computer vision**.
- Enable **gesture-based control** using **MediaPipe Hand Tracking**.
- Implement **PID control** for smooth and precise movements.
- Improve efficiency in material handling and industrial automation.

## 🛠️ Technologies & Tools Used
### **Hardware:**
- **Arduino Uno** (Microcontroller)
- **Servo Motors** (Arm movement & gripper control)
- **DC Motors** (Base rotation & movement)
- **Camera Module** (For color recognition & gesture control)
- **Proximity & Touch Sensors** (Object detection & feedback)

### **Software:**
- **Arduino IDE** (Programming the microcontroller)
- **Python & OpenCV** (For image processing & color detection)
- **MediaPipe** (For real-time hand gesture recognition)
- **Fritzing/Proteus** (For circuit design and simulation)

## 🚀 Features
✅ **Color Recognition & Sorting:** Detects and sorts colored cubes into the correct bins.
✅ **Gesture-Based Control:** Uses **MediaPipe Hand Tracking** to move the robotic arm via hand gestures.
✅ **Real-Time Feedback:** Uses sensor inputs to adjust movement dynamically.
✅ **PID Control System:** Ensures smooth and precise movements of the arm.
✅ **Open-Source:** The entire project is built using **open-source hardware & software**.

## 🔧 Installation & Setup
### **1️⃣ Install Dependencies**
Ensure you have the following installed:
```bash
pip install opencv-python mediapipe numpy pyserial
```

### **2️⃣ Upload Arduino Code**
- Open **Arduino IDE**
- Upload the provided `robotic_arm.ino` script to the **Arduino Uno**

### **3️⃣ Run Python Script**
Run the **color detection and gesture control** script on your PC:
```bash
python robotic_arm_control.py
```

## 🎥 Demo
![Robotic Arm Demo](https://github.com/Hamza-Nazih/Robotic-Arm-Project/blob/main/IMG_20240211_003213.jpg)

## 🤝 Contribution
Feel free to **fork** this repository, create **issues**, or submit **pull requests** to improve this project.

## 📜 License
This project is **open-source** and available under the **MIT License**.

---
💡 **Created by:** Hamza nazih  
📌 **GitHub Repository:** https://github.com/Hamza-Nazih/Robotic-Arm-Project  
📧 **Contact:** hamzanazih07@gmail.com


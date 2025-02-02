# 🤖 Robotic Arm Project

## 📌 Table of Contents
- [Project Overview](#-project-overview)
- [Objectives](#-objectives)
- [Hardware Components](#-hardware-components)
- [Technologies & Tools Used](#-technologies--tools-used)
- [Features](#-features)
- [Installation & Setup](#-installation--setup)
- [Demo](#-demo)
- [Contribution](#-contribution)
- [License](#-license)

---

## 🔧 Project Overview
This project involves the design and development of an **automated robotic arm** capable of recognizing and sorting colored cubes using **computer vision (OpenCV & MediaPipe)**. The robotic arm is controlled using an **Arduino-based system** with real-time feedback from sensors for precise manipulation.

## 🎯 Objectives
✅ Automate the sorting of colored cubes using **computer vision**.  
✅ Enable **gesture-based control** using **MediaPipe Hand Tracking**.  
✅ Implement **PID control** for smooth and precise movements.  
✅ Improve efficiency in material handling and industrial automation.  

## 🔩 Hardware Components
The robotic arm consists of the following key hardware components:

### **Microcontroller & Processing**
- **Arduino Uno** – Main microcontroller for controlling servos & sensors.

### **Actuators & Motors**
- **Servo Motors** – For arm movement & gripper control.
- **DC Motors** – For base rotation & movement.

### **Sensors & Vision System**
- **E18-D80NK IR Proximity Sensor** – For object detection.
- **TCRT5000 Infrared Sensor** – For color and object recognition.
- **Camera Module** – Used for color recognition & gesture tracking.

### **Power & Connectivity**
- **Power Supply (5V/12V)** – To drive motors and microcontroller.
- **Breadboard & Jumper Wires** – For circuit connections.

### **Mechanical Structure**
- **DIY Plastic Robot Kit** – 4 DOF (Degrees of Freedom) robotic arm.
- **Claw Mechanism** – For gripping and releasing objects.

## 🛠️ Technologies & Tools Used
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

### 🛠️ **Hardware Setup**
- Connect all sensors and actuators as shown in the circuit diagram.
- Ensure your Arduino is properly powered (5V for logic, external power for motors).
- Test individual components before running the full system.

## 🎥 Demo
![Robotic Arm Demo](https://raw.githubusercontent.com/Hamza-Nazih/Robotic-Arm-Project/main/demo.gif)

[![Watch the Demo](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)

## 🤝 Contribution
We welcome contributions! Please follow these steps:
1. **Fork the repository**
2. **Create a new branch** (`feature-xyz`)
3. **Commit your changes** (`git commit -m 'Added new feature'`)
4. **Push to your branch** (`git push origin feature-xyz`)
5. **Submit a pull request**

🔹 Check our [Contribution Guidelines](CONTRIBUTING.md) for more details.

## 📜 License
This project is **open-source** and available under the **MIT License**.

---
💡 **Created by:** Hamza Nazih  
📌 **GitHub Repository:** [Robotic Arm Project](https://github.com/Hamza-Nazih/Robotic-Arm-Project)  
📧 **Contact:** hamza.nazih@example.com  





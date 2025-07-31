# Automated Seat Wiper

_Author - Jeet Soni_

_Date - July 31, 2025_

> Designed with women in mind because everyone deserves a clean seat.

## 🧠 The Idea

The inspiration behind **ForHer** came from a real moment.

I was visiting Canada, hanging out with some friends, and we all had to use a **portable public bathroom**. A kid went in before me, and when it was my turn, I noticed the toilet seat was **covered in droplets**. I ended up wiping the seat so **my friend could use it after me** and in that moment, it hit me:

> This is an everyday problem for **women**, especially in **unisex or public restrooms** and it’s rarely talked about.

It’s not just uncomfortable. It’s **unhygienic**, unfair, and frustrating.

Later, at home, I was also dealing with a poorly designed bathroom in my rented condo where the **toilet seat wouldn’t stay up**. We were wasting a ton of toilet paper wiping the seat constantly. I started wondering if I could build **a hands-free solution**.

That’s when I decided to prototype an **automatic toilet seat cleaner**, designed with women in mind and **ForHer** was born.

-   **Automatic**
-   **Hands-free**
-   **Affordable to build**
-   **Customizable and replaceable**

This is the **first prototype**, and I built it to learn, explore, and make a small difference.

## 🛠️ What It Does

-   Detects if a user is present using an **HC-SR04 ultrasonic sensor**
-   Waits until the user leaves and then starts a **wiping sequence** after a 10-second delay
-   A **servo motor** rotates a wiper arm (built with plastic ruler) across the toilet seat
-   Returns the wiper to its home position after cleaning

## 📦 Hardware Used

-   Arduino Uno R3 (Elegoo)
-   HC-SR04 Ultrasonic Sensor
-   MG996R Servo Motor
-   16-inch plastic wiper arm (custom-made)
-   taped servo mounting setup
-   Jumper wires

## 🧰 Software

-   Arduino C++
-   Serial Monitor for distance testing and debugging
-   MIT License (see `LICENSE`)

## 🚀 How It Works

1. **Sensor** detects presence within a distance threshold (e.g. 120 cm).
2. When the user leaves, a **10 second timer** starts.
3. After the delay, the **servo motor rotates** the wiper arm from a home position across the toilet seat.
4. The motor **returns the arm to the original position**, ready for the next use.

## 🧪 Challenges

-   Attaching the servo securely to a curved toilet surface
-   Choosing a durable wiper arm that doesn't bend (plastic ruler bent easily)
-   Ensuring the wiping arc fully covers the seat
-   Weight and torque limitations of different servo motors
-   Replacing the wiping material daily for hygiene

## 💬 I Want Your Feedback

This is just a **first prototype**. I know it's far from perfect, and it raises a lot of questions from hygiene to practicality to scaling. But I believe in solving real problems.

If you have ideas, feedback, or suggestions, feel free to **DM me** or drop a **comment** on [LinkedIn](https://linkedin.com/in/jeet-dev/).

Made with love, curiosity and care - for her, for hygiene :heart:

# Microrender
> Static Page Generation on the edge

(WIP) Platformio library for Macro-driven static page generation, including easy to setup code generation for AJAX.  
Use for Captive Portals, debug and information pages, ...  

Generates pages at compile time, stores them in program memory instead of flash, so you stay in control of all your chips RAM.

# Run Demo
Open Project in PlatformIO-IDE, choose either ESP32 or ESP8266 profile.
Copy src/secrets.example.h to src/secrets.h and fill in wifi details.
Connect corresponding microcontroller, compile, upload, monitor & run.
Visit the website under the IP written into the console.

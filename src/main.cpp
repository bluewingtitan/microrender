#include <Arduino.h>
#include "../lib/microrender/include/microrender.h"
#include "../lib/microrender/include/microrender.modules.h"
#include "ajax_demo.h"
#include "form_demo.h"
#include <WiFiClient.h>

#include "secrets.h"

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
#else
#ifdef ESP32
#include <WiFi.h>
#include <WebServer.h>
WebServer server(80);
#endif
#endif

String last_message = "there is no last message.";
unsigned long visit_count = 0;

MCR(hello_world, Hello World!,

MCR_FIXED_HEADERBAR(microrender,
    MCR_LIST_ELEMENT(<a href="https://github.com/bluewingtitan">author</a>)
    MCR_LIST_ELEMENT(<a href="/ajax">AJAX Demo</a>)
    MCR_LIST_ELEMENT(<a href="/forms">Forms Demo</a>)
)
MCR_BASE(
    MCR_HSPACE(80)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H1(HELLO, WORLD!)
            MCR_SMALL(... I hope you are doing great today!)
        )
    )
    MCR_HSPACE(20)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_TEXT(This page was fully rendered with microrender, a small, cute, static html rendering engine for c++.)
            MCR_TEXT(Microrender is perfect for microprocessors, as rendering happens during compile time.MCR_BREAK
            It makes generated html available via static functions (as return value). Rendered html gets stored in program storage instead of RAM to allow for complex pages without the biggest drawback they usually come with on microcontrollers.)
        )
        MCR_ELEMENT(
            MCR_TEXT(Microrender is specifically targeted at the <a href="https://www.esp8266.com/">ESP-8266</a>, but could be used basically on any plattform.)
            MCR_TEXT(Microrender is not meant as a fully fledged webapp framework, only as fully fledged as needed for &quot;the edge&quot;.)
        )
    )
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H3(What Microrender does:)
            MCR_ORDERED_LIST(
                MCR_LIST_ELEMENT(It prerenders macro-based descriptions of your pages during compile time.)
                MCR_LIST_ELEMENT(It supports inline html, css and javascript)
                MCR_LIST_ELEMENT(It stores the rendered page in MCR_STRONG(Program Memory) to avoid cluttering your RAM.)
            )
        )
    )
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H3(Questions and Answers)
            MCR_H4(Page generation on compile time? Does that mean, that there is no easy support for dynamic content?)
            MCR_TEXT(Quite the opposite! There is support for AJAX (even dynamic refreshes), as you are able to see <a href="/ajax">here (AJAX Demo)</a>MCR_BREAK
                    Also, there is support for forms (see <a href="/forms">this demo</a>), to allow for server-bound messaging.MCR_BREAK
                    The API behind the AJAX and forms has to be implemented by you, as microrender itself is purely focused on rendering the page itself, but building a handler is the easy part, right?
            )
            MCR_H4(Sounds great, am I allowed to use microrender for...)
            MCR_TEXT(Yes. MIT License.)
            MCR_H4(When would I want to use microrender?)
            MCR_TEXT(Any case where you would like to add simple web pages with some interactivity to a ESP-8266 or ESP32-driven project. If the project IS the website, you might want to fully build it yourself, but if it is a side-element, I can see microrender being quite nice.)
        )
    )
    MCR_HSPACE(60)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H3(ABOUT...)
            MCR_TEXT(microrender is powered by <a href="https://milligram.io/code.html">milligram</a>, a super small css framework.)
            MCR_TEXT(Besides macros for all major elements milligram supports, it allows for inline html while retaining the ability of storing the prerendered html text in program memory.)
        )
    )
)
)

void handleRoot()
{
    Serial.println("GET /");
    PGM_P html_type PSTR("text/html");
    server.send_P(200, html_type, hello_world());
}

void handle_forms_demo()
{
    Serial.println("GET /forms");
    PGM_P html_type PSTR("text/html");
    server.send_P(200, html_type, forms_demo());
}

void handle_form_submit(){
    
    String name = server.arg("form_name");
    String message = server.arg("form_message");

    Serial.println("GET /form_submit by " + name + " with message: " + message);
    last_message = name + ": " + message;
    PGM_P html_type PSTR("text/html");
    server.send_P(200, html_type, forms_demo_sent());
}

void handle_last_message(){
    Serial.println("GET /last_message");
    server.send(200, "text/plain", last_message);
}

void handle_ajax_demo()
{
    Serial.println("GET /ajax");
    visit_count++;
    PGM_P html_type PSTR("text/html");
    server.send_P(200, html_type, ajax_demo());
}

void handle_visit_count(){
    Serial.println("GET /visit_count");
    server.send(200, "text/plain", String{visit_count});
}

void setup()
{
    Serial.begin(74880);
    Serial.println("Connecting...");
    
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);

    server.on("/ajax", handle_ajax_demo);
    server.on("/visit_count", handle_visit_count);

    server.on("/forms", handle_forms_demo);
    server.on("/last_message", handle_last_message);
    server.on("/form_submit", handle_form_submit);
    server.begin();
}

void loop()
{
    server.handleClient();
}

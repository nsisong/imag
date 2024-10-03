#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/*Put your SSID & Password*/
const char* ssid = "Nsisong Phone";  // Enter SSID here
const char* password = "Nsisong1";  //Enter Password here

ESP8266WebServer server(80);



void setup() {
  Serial.begin(115200);


  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  
}

void handle_OnConnect() {
  Serial.println("Device connected...");
  server.send(200, "text/html", SendHTML()); 
}



void handle_NotFound(){
  server.send(404, "text/plain", "Not found refresh");
}

String SendHTML(){
  String ptr = "<!DOCTYPE html> <html lang=\"en\">\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Imag</title>\n";
  ptr +="<style>";
  ptr +=":root { --primarycolor:#1fa3ec}\n";
  ptr +="body.invert,body.invert a,body.invert h1{background-color:#060606;color:white;}\n";
  ptr +="body.invert .msg{background-color: #282828;border-top: 1px solid #555;border-right: 1px solid #555;border-bottom: 1px solid #555;color:#fff;}\n";
  ptr +="body.invert .q[role=img] {-webkit-filter: invert(1);filter: invert(1);}";
  ptr +=".c,body {text-align: center;font-family: verdana}\n";
  ptr +=".wrap {text-align:left;display:inline-block;min-width:260px;max-width:500px;}\n";
  ptr +="div,input,select {padding: 5px;font-size: 1em;margin: 5px 0;box-sizing: border-box;}\n";
  ptr +="div{margin: 5px 0;}\n";
  ptr +="input,button,select,.msg{border-radius:.3rem;width: 100%;}\n";
  ptr +="input[type=radio],input[type=checkbox]{width: auto;}\n";
  ptr +="button,input[type=\"button\"],input[type=\"submit\"] {border: 0;background-color: var(--primarycolor);color: #fff;line-height: 2.4rem;font-size: 1.2rem;}\n";
  ptr +="input[type=\"file\"]{border: 1px solid var(--primarycolor);}\n";
  ptr +="a {color: #000;font-weight: 700;text-decoration: none;}\n";
  ptr +="a:hover {color: var(--primarycolor);text-decoration: underline;}\n";
  ptr +=".h {display: none;}\n";
  ptr +=".q {height: 16px;margin: 0;padding: 0 5px;text-align: right;min-width: 38px;float:right;}\n";
  ptr +=".q.q-0:after {background-position-x: 0;}\n";
  ptr +=".q.q-1:after {background-position-x: -16px;}\n";
  ptr +=".q.q-2:after {background-position-x: -32px;}\n";
  ptr +=".q.q-3:after {background-position-x: -48px;}\n";
  ptr +=".q.q-4:after {background-position-x: -64px;}\n";
  ptr +=".q.l:before {background-position-x: -80px;padding-right: 5px}\n";
  ptr +=".ql .q {float: left;}\n";

  ptr +=".q:after,.q:before {content: '';width:16px;height:16px;display:inline-block;background-repeat:no-repeat;background-position: 16px 0;background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGAAAAAQCAMAAADeZIrLAAAAJFBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADHJj5lAAAAC3RSTlMAIjN3iJmqu8zd7vF8pzcAAABsSURBVHja7Y1BCsAwCASNSVo3/v+/BUEiXnIoXkoX5jAQMxTHzK9cVSnvDxwD8bFx8PhZ9q8FmghXBhqA1faxk92PsxvRc2CCCFdhQCbRkLoAQ3q/wWUBqG35ZxtVzW4Ed6LngPyBU2CobdIDQ5oPWI5nCUwAAAAASUVORK5CYII=');}\n";
  ptr +="@media (-webkit-min-device-pixel-ratio: 2),(min-resolution: 192dpi) {.q:before,.q:after {background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALwAAAAgCAMAAACfM+KhAAAALVBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAOrOgAAAADnRSTlMAESIzRGZ3iJmqu8zd7gKjCLQAAACmSURBVHgB7dDBCoMwEEXRmKlVY3L//3NLhyzqIqSUggy8uxnhCR5Mo8xLt+14aZ7wwgsvvPA/ofv9+44334UXXngvb6XsFhO/VoC2RsSv9J7x8BnYLW+AjT56ud/uePMdb7IP8Bsc/e7h8Cfk912ghsNXWPpDC4hvN+D1560A1QPORyh84VKLjjdvfPFm++i9EWq0348XXnjhhT+4dIbCW+WjZim9AKk4UZMnnCEuAAAAAElFTkSuQmCC');background-size: 95px 16px;}}\n";

  ptr +=".msg {padding: 20px;margin: 20px 0;border: 1px solid #eee;border-left-width: 5px;border-left-color: #777;}\n";

  ptr +=".msg h4 {margin-top: 0;margin-bottom: 5px;}\n";
  ptr +=".msg.P {border-left-color: var(--primarycolor);}\n";
  ptr +=".msg.P h4 {color: var(--primarycolor);}\n";
  ptr +=".msg.S {border-left-color: #5cb85c;}\n";
  ptr +=".msg.S h4 {color: #5cb85c;}\n";
  ptr +=".msg.D {border-left-color: #dc3630;}\n";
  ptr +=".msg.D h4 {color: #dc3630;}\n";

  ptr +="dt {font-weight: bold;}\n";
  ptr +="dd {margin: 0;padding: 0 0 0.5em 0;}\n";
  ptr +="td {vertical-align: top;}\n";
  ptr +="button.D{background-color:#dc3630;}\n";

  ptr +="button{transition: 0s opacity;transition-delay: 3s;transition-duration: 0s;cursor: pointer;}\n";

  ptr +="button:active{opacity: 50% !important;cursor: wait;transition-delay: 0s;}\n";

  ptr +="button:hover{opacity: 80%;}\n";
  ptr +="input:disabled {opacity: 0.5;}\n";

  ptr +="</style>\n";

  ptr +="<script>";
  ptr +="function c(l){document.getElementById('s').value=l.innerText||l.textContent;\n";
	ptr +="p = l.nextElementSibling.classList.contains('l');\n";
	ptr +="document.getElementById('p').disabled = !p;\n";
	ptr +="if(p)document.getElementById('p').focus()};\n";

  ptr +="</script>\n";
  ptr +="</head>\n";
  ptr +="<body class=\"invert\">\n";
  ptr +="<div class='wrap'>\n";

  ptr +="<img src='data:image/png;base64,   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'/>\n";
	ptr +="<hR>\n";
  
  ptr +="<form action='config_wifi.html' method='get'><button>Configure WiFi</button></form><br/>\n";
	ptr +="<form action='Config_mqtt.html' method='get'><button>Configure Mqtt</button></form><br/>\n";
	ptr +="<form action='info.html' method='get'><button>Info</button></form><br/>\n";
	ptr +="<form action='setup.html' method='get'><button>Setup</button></form><br/>\n";
	ptr +="<Hr><br/>\n";
	ptr +="<form action='about.html' method='post'><button>About</button></form><br/>\n";
	ptr +="<form action='erase' method='post'><button class='D'>Erase</button></form><br/>\n";
	ptr +="<form action='restart' method='post'><button>Restart</button></form><br/>\n";
	ptr +="<form action='/exit' method='post'><button>Exit</button></form><br/>\n";
	ptr +="<form action='/' method='post'><button>Back</button></form><br/>\n";

  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
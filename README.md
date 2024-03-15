# esp8266-Clock

Benodigheden,<br>
1 led strip 60 leds/meter adresseerbaar<br>
1 wemos d1 mini<br>
micro usb kabel en oude 5v telefoonadapter<br>
Op de volgende site staan de stl files om de ledstrip erin te verwerken.<br>
https://github.com/leonvandenbeukel/Round-LED-Clock<br>

Sluit de led strip op de wemos aan: + op de 5V uitgang, - op de Ground uitgang en de datakabel op D3.<br>
Het programma schakelt automatisch over op zomer en wintertijd, volgens de volgende code<br>
<code>#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"</code><br>

De brightness kun je zelf ook instellen, staat nu op 21:30 t/m 6:15. zachter van kleur<br>
![IMG_0252](https://github.com/renejanssen1/esp8266-Clock/assets/94928681/ba8f00e3-679d-43c7-9277-e24605a482c4)<br>
Elke 5 minuten zijn blauw gekleurd, op het voorbeeld zie je de urenwijzer bijna op 10 staan en de minuten wijzer op 51, de gele led geeft de secondes aan.<br>

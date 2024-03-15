# esp8266-Clock

Benodigheden,
1 led strip 60 leds/meter adresseerbaar
1 wemos d1 mini
micro usb kabel en oude 5v telefoonadapter

Sluit de led strip op de wemos aan: + op de 5V uitgang, - op de Ground uitgang en de datakabel op D3.
Het programma schakelt automatisch over op zomer en wintertijd, volgens de volgende code
<code>#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"</code>

De brightness kun je zelf ook instellen, staat nu op 21:30 t/m 6:15. zachter van kleur

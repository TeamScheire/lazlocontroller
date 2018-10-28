# Maak zelf een keyboard met een Arduino

Voor Team Scheire gaven we de rolstoel van Lazlo een upgrade. Met een Arduino (Leonardo) maakten we een speciale game controller, op maat van zijn rolstoel en zijn kunde.

In deze repository leggen we uit hoe je zelf een Arduino met knoppen kan gebruiken als een toetsenbord, om er bijvoorbeeld games mee te spelen.

## Wat heb je nodig?

Een [Arduino Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo). In tegenstelling tot een gewone Arduino (Uno) is de Leonardo speciaal gemaakt om je eigen toetsenborden, muizen of joysticks te bouwen. Je kan het gebruiken als een zogenaamd "HID" (Human Interface Device).

![Leonardo Arduino](img/leonardo.jpg | width=300)

Je kan ook een bord gebruiken dat een clone is van de Arduino Leonardo, zoals de (Brainbox Arduino)[https://e2cre8.be/?page_id=21], die ook handige schroefconnectors heeft.

![Brainbox Arduino](img/brainbox.jpg | width=300)

Verder heb je knoppen nodig. Met een USB kabel en kabeltjes om de knoppen aan de Arduino te bevestigen ben je helemaal klaar. Er zijn geen weerstanden nodig, omdat de pinnen van de Arduino een zogenaamde "pull-up" weerstand op hun pinnen hebben.



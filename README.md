# TP UART 

## Principe UART

Paramètres utilisés :
- Baud rate : 300 bauds
- Durée d'un bit : 1 / 300 = 3.33 ms
- Format : 1 Start bit + 8 bits + 1 Stop bit

## Outils nécessaires
```bash
sudo apt update
sudo apt install gcc-avr avr-libc avrdude make gtkterm
```

## Configuration matérielle

- **Microcontrôleur** : ATTiny85
- **TX** : PB4 (pin 3) → RX du XBee
- **GND** : ATTiny → GND du XBee
```
ATtiny85         XBee
--------         --------
PB4 (pin 3) ---> RX
GND         ---> GND
```

## Compilation et programmation
```bash
make              # Compiler
make flash        # Compiler et flasher
make clean        # Nettoyer
```

## Réception côté PC

Configurer le terminal série :
- Port : `/dev/ttyACM0`
- Baud rate : 300
- 8 bits, pas de parité, 1 stop bit
```bash
gtkterm -p /dev/ttyACM0 -s 300
```

## Résultat attendu

Le message "coucou" s'affiche.

## Dépannage

Si problème de permissions :
```bash
sudo usermod -a -G dialout $USER
```
Puis reconnectez-vous.

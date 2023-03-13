# Tp_IoT_2022_LoRa_Bluetooth

## 1. Client :
 
### 1. Récupération d'un paquet Mqtt sur test.mosquitto.org :  nomAP/ipaddr

### 2. Se connecter à une carte sur l'AP et faire une requete http donnant les valeurs nécessaire à LoRa.

### 3. Ecouter les données de LoRa.

## 2. Serveur :

### Faire le serveur servant les données au Client.

## 3. Ensuite...

### 1. Ajouter une fonction permettant de switcher entre Serveur et Client

### 2. Sur le serveur, échangez la partie LoRa par du bluetooth (ou BLE)

### 3. Refaire la partie cliente pour répondre au bluetooth

## 4. Notes Alexandre FIANDACA et Pierre JADAUD
Nous avons commencé par mettre en place un MQTT client pour transférer les données des capteurs.

Ensuite nous avons mis en place un MQTT serveur pour envoyer les données des capteurs d'une carte à une autre carte d'un autre groupe (BACHELOT et LAYEC).

Puis nous avons utilisé la connexion MQTT mis en place pour transférer 3 données :
- freq
- sf
- sb

Ces données nous ont ensuite servis à mettre en place une communication LoRa entre les 2 cartes. Pour le moment, nous transmettons des données "tests". Le but à l'avenir est d'utiliser LoRa pour envoyer les données nécessaires à une connexion Bluetooth.
Nous pourrons ensuite mettre en place une connexion Bluetooth entre un client et un serveur Bluetooth.

Dans les documents rendus vous trouverez :
- MQTT_client_variable : Client MQTT avec des variables pour "freq", "sf", "sb"
- MQTT_server : Serveur MQTT qui récupère les données du client MQTT
- MQTT_client_LoRa : Client MQTT qui envoie les données  nécessaires à une connexion LoRa puis via LoRa envoie de données "tests"
- MQTT_server_LoRa : Server MQTT qui récupère les données du client pour mettre en place la connexion LoRa. Une fois la connexion LoRa, la carte reçoit les données LoRa.
- MQTT_server_Bluetooth : Server Bluetooth que nous arrivons à avoir avec l'application BLE Scanner
- le dossier "ça morche po" : contient le début du fichier Client Bluetooth qui a comme but de se connecter au server Bluetooth

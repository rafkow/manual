NAT - network adress translate
  SNAT(Static) - translate 1 to 1 adress;

  PAT(Port Adress Translation) -

Przekierownaie portow:
  iptables -t nat -A PREROUTING -p tcp --dport 5000 -j DNAT --to-destination 10.8.0.14:5000
  iptables -t nat -A POSTROUTING -p tcp -d 10.8.0.14 --dport 5000 -j SNAT --to-source 10.8.0.1

wyświetl listę widzianych sieci WiFi
  sudo iwlist wlan0 scan

ścieżka do pliku konfiguracyjnego
  sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
  network={
     ssid="Test Wifi Network"
     psk="SecretPassWord"
  }

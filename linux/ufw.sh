ufw status
ufw enable/disable

add rule:
  ufw allow [name/port]/[-/tcp/udp]


IP forwarding:
  /etc/ufw/before.rules
  *nat
  :POSTROUTING ACCEPT [0:0]
  -A POSTROUTING -s 10.8.0.0/8 -o eth0 -j MASQUERADE
  COMMIT

  /etc/default/ufw
  DEFAULT_FORWARD_POLICY="ACCEPT"

sudo ufw allow in on tun0 to any app Samba


ufw allow 'Nginx HTTP'

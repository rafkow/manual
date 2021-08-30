plugin /usr/lib/x86_64-linux-gnu/openvpn/plugins/openvpn-plugin-auth-pam.so login

generowanie nowego klucza
root@doradca:/etc/openvpn/easy-rsa/EasyRSA-3.0.4# ./easyrsa gen-req dominik-laptop nopass

przenieś klucz do folderu z kluczami
root@doradca:/etc/openvpn/easy-rsa/EasyRSA-3.0.4# cp pki/private/milosz-laptop.key /home/rafal/client-configs/keys/

przekopiuj na serwer CA
root@doradca:/etc/openvpn/easy-rsa/EasyRSA-3.0.4# scp pki/reqs/dominik-laptop.req smyrgi@oniongeek.com:cert

podpis przez CA
./easyrsa import-req waiting/milosz-laptop.req milosz-laptop
./easyrsa sign-req client milosz-laptop

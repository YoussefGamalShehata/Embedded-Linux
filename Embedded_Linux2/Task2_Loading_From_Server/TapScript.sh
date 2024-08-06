#!bin/bash
sudo ip link delete tap0 2>/dev/null
sudo ip tuntapp add dev tap0 mode tap
sudo ip addr add 192.168.100.1/24 dev tap0
sudo ip link set tap0 up

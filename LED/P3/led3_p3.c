echo "led 3 (C-V2X) P3"
echo "if want end: ctrl + c"

for((;;));
do
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio489/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio489/value
  sleep 0.2s
done
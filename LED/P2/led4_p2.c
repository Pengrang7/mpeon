echo "led 4 (WAVE) P2"
echo "if want end: ctrl + c"

for((;;));
do
  echo 1 > /sys/class/gpio/gpio488/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio488/value
  sleep 0.3s
  echo 1 > /sys/class/gpio/gpio488/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio488/value
  sleep 0.4s
  echo 1 > /sys/class/gpio/gpio488/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio488/value
  sleep 0.3s
  echo 1 > /sys/class/gpio/gpio488/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio488/value
  sleep 0.4s
  echo 1 > /sys/class/gpio/gpio488/value
  sleep 0.2s
done

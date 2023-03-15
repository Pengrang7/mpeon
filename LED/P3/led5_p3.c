echo "led 5 (GNSS) P3"
echo "if want end: ctrl + c"

for((;;));
do
  echo 1 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 1 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 1 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 1 > /sys/class/gpio/gpio487/value
  sleep 0.4s
  echo 0 > /sys/class/gpio/gpio487/value
  sleep 0.2s
done

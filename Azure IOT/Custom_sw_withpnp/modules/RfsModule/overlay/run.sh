#!/bin/bash
export IOTHUB_DEVICE_SECURITY_TYPE='DPS'
export IOTHUB_DEVICE_DPS_ID_SCOPE='0ne0056D5AF'
export IOTHUB_DEVICE_DPS_DEVICE_ID='DE10-Nano'
export IOTHUB_DEVICE_DPS_DEVICE_KEY='7kiVRaj2q1jNmkYGH+sz8tTMkGxhRnGgwLtks+snfo6ldfGaVXhpH95jXcqTZl8s0BrPzDPGGc8nwlT+aWm0sQ=='

bash ./overlay.sh
#sleep 20

echo "Message : Application Start"
cd ..
python3.7 -u ./main.py
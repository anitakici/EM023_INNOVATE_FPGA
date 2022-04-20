#!/bin/bash
export IOTHUB_DEVICE_SECURITY_TYPE='DPS'
export IOTHUB_DEVICE_DPS_ID_SCOPE='0ne0056D5AF'
export IOTHUB_DEVICE_DPS_DEVICE_ID='DE10-Nano'
export IOTHUB_DEVICE_DPS_DEVICE_KEY='7kiVRaj2q1jNmkYGH+sz8tTMkGxhRnGgwLtks+snfo6ldfGaVXhpH95jXcqTZl8s0BrPzDPGGc8nwlT+aWm0sQ=='

overlay_dir="/sys/kernel/config/device-tree/overlays/socfpga"
overlay_dtbo="rfs-overlay.dtbo"
overlay_rbf="Module5_Sample_HW.rbf"

if [ -d $overlay_dir ];then
    rmdir $overlay_dir
fi

cp $overlay_dtbo /lib/firmware/
cp $overlay_rbf /lib/firmware/

mkdir $overlay_dir

echo $overlay_dtbo > $overlay_dir/path

sleep 30

cd ../
python3.7 -u ./main.py